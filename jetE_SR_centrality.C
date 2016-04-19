// Cheng-Chieh Peng
// read output of runForest_PbPb_MC. 
// Analyze pt resolution in PbPb event.
// plot jtpt/refpt distribution for reftpt.
// Created 2016 April. 5
// Last Modified 2016 April. 5 


#include <iostream>
#include "TTree.h"
#include "TH1.h"
#include "TFile.h"
#include "TCut.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TStyle.h"
#include <TAttMarker.h>
#include <TLegend.h>
#include <TH2.h>
#include <TF2.h>
#include <TF1.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TGraphErrors.h>
#include <fstream>
#include <TLatex.h>

// Global objects
int counter;
int counter1;
TCanvas *Can_Temp[200];
TCanvas *Can_result[30];
TMultiGraph  *mutiGR[30];
TLegend *legend[30];
TLegend *legend1[30];

void fit_combine(TChain *tc, std::string Var, const double * VarBins_array , const int nVarBins , TCut Gcut,  double *mean, double *meanErr, double *sigma, double *sigmaErr ){

	std::string jetTitle=tc->GetTitle();

	cout<<"tc title = "<<tc->GetTitle()<<" ,Var = "<<Var<<" ,nVarBins = "<<nVarBins<<", Gcut = "<<Gcut<<endl;
	Can_Temp[counter] = new TCanvas(Form("Can_Temp_%i",counter));
	// might need to use if nVarBins to switch different Divide
	/*
		 if(nVarBins<=9) { Can_Temp[counter]->Divide(3,3);}
		 if( nVarBins >9 && nVarBins <=12) { Can_Temp[counter]->Divide(3,4);}
		 if( nVarBins >12 && nVarBins <=16) { Can_Temp[counter]->Divide(4,4);}
		 else {Can_Temp[counter]->Divide(5,5);}
		 */
	if(nVarBins<=9){Can_Temp[counter]->Divide(2,2);}
	else {Can_Temp[counter]->Divide(3,4);}


	TH1D *h_Ratio[nVarBins];
	TF1 *f_Ratio[nVarBins];
	double nRatiobins= 100;
	double minRatio=0;
	double maxRatio=3;

	for(int ibin =0; ibin<nVarBins; ibin++)
		//	for(int ibin =0; ibin<2; ibin++)
	{
		Can_Temp[counter]->cd(ibin+1);
		double VarMin = VarBins_array[ibin];
		double VarMax = VarBins_array[ibin+1];

		h_Ratio[ibin] = new TH1D( Form("h_Ratio[%d]",ibin),Form("%s_%s_%i_%i",jetTitle.c_str(),Var.c_str(),(int)VarMin,(int)VarMax) ,nRatiobins,minRatio,maxRatio);  // h_Ration_%d ??

		TCut Varcut = Form("%s>%f && %s<%f", Var.c_str(), VarMin, Var.c_str(), VarMax);
		TCut allcut = Gcut && Varcut;
		cout<<"Varcut = "<<Varcut<<" ,allcut = "<<allcut<<endl;

		tc->Draw( Form("jtpt/refpt>>h_Ratio[%d]",ibin ) , allcut );
		h_Ratio[ibin]->GetXaxis()->SetTitle("jtpt/refpt");

		f_Ratio[ibin] = new TF1(Form("f_Ratio_%d",ibin), "gaus",0,2 );
		f_Ratio[ibin]->SetParameter(0,h_Ratio[ibin]->GetEntries()); // get number for normalization
		f_Ratio[ibin]->SetParameter(1,h_Ratio[ibin]->GetMean()) ;   // for mean
		f_Ratio[ibin]->SetParameter(2,h_Ratio[ibin]->GetStdDev()) ; // for sigma    
		h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin));

		mean[ibin] = f_Ratio[ibin]->GetParameter(1);
		meanErr[ibin] = f_Ratio[ibin]->GetParError(1);
		sigma[ibin] = f_Ratio[ibin]->GetParameter(2);
		sigmaErr[ibin] = f_Ratio[ibin]->GetParError(2);

	} // end   for(int ibin =0; ibin<nVarBins; ibin++)

	Can_Temp[counter]->SaveAs(Form("./fitPlots/fit_%s_%s_%s.pdf",Var.c_str(),jetTitle.c_str(),Gcut.GetTitle() ));

	counter++; 
}


void Muti_Plot_centScale(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
{ 

	char filename[]="JetESR_status.txt";
	fstream myfile;
	myfile.open (filename,ios::out|ios::app);

	double VarBinsCenter[nVarBins];
	double VarBinsErr[nVarBins];
	for (int ibin=0; ibin<nVarBins; ibin++)
	{
		VarBinsCenter[ibin]= (VarBins_array[ibin] + VarBins_array[ibin+1]) /2;
		//		VarBinsErr[ibin]=0;
		VarBinsErr[ibin]=(VarBins_array[ibin+1]- VarBins_array[ibin])/2;
	}

	cout<<"lineKind_Arr 1 = "<<lineKind_Arr[0]<<" ,lineKind_Arr2 = "<<lineKind_Arr[1]<<endl;
	cout<<"mu_title = "<<mu_title<<" selectionC = "<< selectionC<<endl;

	Can_result[counter1] = new TCanvas(Form("Can_result_%i",counter1));
	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	TGraphErrors *gr_mean[ngr];
	legend[counter1] = new TLegend(0.68,0.7,0.88,0.85);

	for(int igr=0; igr<ngr; igr++)
	{
		gr_mean[igr] = new TGraphErrors(nVarBins, VarBinsCenter, yArr2[igr], VarBinsErr , yErrArr2[igr]);
		gr_mean[igr]->SetTitle(Form("some title_%i", igr));
		gr_mean[igr]->SetFillStyle(0);
		gr_mean[igr]->SetMarkerStyle(1);
		gr_mean[igr]->SetLineColor(igr+1);	
		gr_mean[igr]->SetMarkerColor(igr+1);
		mutiGR[counter1]->Add(gr_mean[igr]);
		legend[counter1]->AddEntry( gr_mean[igr] ,lineKind_Arr[igr],"l");  // not work for unknow reason

	}

	myfile<<"hello, Var = "<<Var<<"Var.compare(Centrality) = "<<Var.compare("Centrality")<<endl;

	mutiGR[counter1]->Draw("AP");
	mutiGR[counter1]->GetXaxis()->SetTitle("Centrality"); // must after draw to create a vitual histogram like object to set title.
	mutiGR[counter1]->GetYaxis()->SetTitle("#mu_{Reco./Gen.}");
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend[counter1]->SetBorderSize(0);
	legend[counter1]->Draw();

	TLatex *tex = new TLatex(0.25,0.7,"#bf{#color[2]{|#eta_{jet}|<2.0 &75<refpt<120}}");
	tex->SetNDC();
	tex->SetTextFont(43);
	tex->SetTextSize(24);
	tex->SetLineWidth(2);
	tex->Draw();

	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.pdf",mu_title.c_str(),selectionC.GetTitle() , Var.c_str())); 
	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.C",mu_title.c_str(),selectionC.GetTitle() , Var.c_str()));
	counter1++;
	cout<<"finish mutigraph"<<endl;
}


void Muti_Plot_centResolution(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
{ 

	char filename[]="JetESR_status.txt";
	fstream myfile;
	myfile.open (filename,ios::out|ios::app);

	double VarBinsCenter[nVarBins];
	double VarBinsErr[nVarBins];
	for (int ibin=0; ibin<nVarBins; ibin++)
	{
		VarBinsCenter[ibin]= (VarBins_array[ibin] + VarBins_array[ibin+1]) /2;
		//		VarBinsErr[ibin]=0;
		VarBinsErr[ibin]=(VarBins_array[ibin+1]- VarBins_array[ibin])/2;
	}

	cout<<"lineKind_Arr 1 = "<<lineKind_Arr[0]<<" ,lineKind_Arr2 = "<<lineKind_Arr[1]<<endl;
	cout<<"mu_title = "<<mu_title<<" selectionC = "<< selectionC<<endl;

	Can_result[counter1] = new TCanvas(Form("Can_result_%i",counter1));
	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	TGraphErrors *gr_mean[ngr];
	legend[counter1] = new TLegend(0.68,0.7,0.88,0.85);

	for(int igr=0; igr<ngr; igr++)
	{
		gr_mean[igr] = new TGraphErrors(nVarBins, VarBinsCenter, yArr2[igr], VarBinsErr , yErrArr2[igr]);
		gr_mean[igr]->SetTitle(Form("some title_%i", igr));
		gr_mean[igr]->SetFillStyle(0);
		gr_mean[igr]->SetMarkerStyle(1);
		gr_mean[igr]->SetLineColor(igr+1);	
		gr_mean[igr]->SetMarkerColor(igr+1);
		mutiGR[counter1]->Add(gr_mean[igr]);
		legend[counter1]->AddEntry( gr_mean[igr] ,lineKind_Arr[igr],"l");  // not work for unknow reason

	}

	myfile<<"hello, Var = "<<Var<<"Var.compare(Centrality) = "<<Var.compare("Centrality")<<endl;

	mutiGR[counter1]->Draw("AP");
	mutiGR[counter1]->GetXaxis()->SetTitle("Centrality"); // must after draw to create a vitual histogram like object to set title.
	mutiGR[counter1]->GetYaxis()->SetTitle("#sigma_{Reco./Gen.}");
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend[counter1]->SetBorderSize(0);
	legend[counter1]->Draw();

	TLatex *tex = new TLatex(0.25,0.7,"#bf{#color[2]{|#eta_{jet}|<2.0 &75<refpt<120}}");
	tex->SetNDC();
	tex->SetTextFont(43);
	tex->SetTextSize(24);
	tex->SetLineWidth(2);
	tex->Draw();

	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.pdf",mu_title.c_str(),selectionC.GetTitle() , Var.c_str())); 
	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.C",mu_title.c_str(),selectionC.GetTitle() , Var.c_str()));
	counter1++;
	cout<<"finish mutigraph"<<endl;
}

TMultiGraph *Muti_Plot(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
{ 

	char filename[]="JetESR_status.txt";
	fstream myfile;
	myfile.open (filename,ios::out|ios::app);


	// mu_titile for 1. jes, jer, 2 what jet
	// selection cut at legend title
	// light, heavy for legned line.
	// calculate VarBinCenterArr from VarBins_array, VarBinsErr
	double VarBinsCenter[nVarBins];
	double VarBinsErr[nVarBins];
	for (int ibin=0; ibin<nVarBins; ibin++)
	{
		VarBinsCenter[ibin]= (VarBins_array[ibin] + VarBins_array[ibin+1]) /2;
		//		VarBinsErr[ibin]=0;
		VarBinsErr[ibin]=(VarBins_array[ibin+1]- VarBins_array[ibin])/2;
	}

	cout<<"lineKind_Arr 1 = "<<lineKind_Arr[0]<<" ,lineKind_Arr2 = "<<lineKind_Arr[1]<<endl;
	cout<<"mu_title = "<<mu_title<<" selectionC = "<< selectionC<<endl;

	Can_result[counter1] = new TCanvas(Form("Can_result_%i",counter1));
	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	TGraphErrors *gr_mean[ngr];
	legend[counter1] = new TLegend(0.7,0.7,0.9,0.85);
	legend1[counter1] = new TLegend(0.3,0.7,0.7,0.8);

	for(int igr=0; igr<ngr; igr++)
	{
		gr_mean[igr] = new TGraphErrors(nVarBins, VarBinsCenter, yArr2[igr], VarBinsErr , yErrArr2[igr]);
		//    char *name_temp = {Form("gr_mean_%i", (int)igr)};
		//		gr_mean[igr]->SetName(Form("gr_mean_%i", (int)igr) );
		//		gr_mean[igr]->SetName(name_temp);
		gr_mean[igr]->SetTitle(Form("some title_%i", igr));
		gr_mean[igr]->SetFillStyle(0);
		gr_mean[igr]->SetMarkerStyle(1);
		gr_mean[igr]->SetLineColor(igr+1);	
		gr_mean[igr]->SetMarkerColor(igr+1);
		mutiGR[counter1]->Add(gr_mean[igr]);
		// char *name_temp = {(Form("gr_mean_%i", (int)igr)).c_str()};	
		//	  legend[counter1]->AddEntry( name_temp ,Form("sometitle2_%i", igr),"l");  // not work for unknow reason
		legend1[counter1]->SetHeader(selectionC);
		legend[counter1]->AddEntry( gr_mean[igr] ,lineKind_Arr[igr],"l");  // not work for unknow reason

	}

	myfile<<"hello, Var = "<<Var<<"Var.compare(Centrality) = "<<Var.compare("Centrality")<<endl;

	mutiGR[counter1]->Draw("AP");
	mutiGR[counter1]->GetXaxis()->SetTitle(Form("%s",Var.c_str())); // must after draw to create a vitual histogram like object to set title.
	if (Var.compare("Centrality") == 0 ){
		myfile<<"hello inside if Centrality"<<endl;
		mutiGR[counter1]->GetXaxis()->SetRangeUser(0,100);}
	mutiGR[counter1]->SetTitle("title"); // this does not work.
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend1[counter1]->SetBorderSize(0);
	legend[counter1]->SetBorderSize(0);
	legend1[counter1]->Draw();
	legend[counter1]->Draw();
	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.pdf",mu_title.c_str(),selectionC.GetTitle() , Var.c_str())); 
	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.C",mu_title.c_str(),selectionC.GetTitle() , Var.c_str()));
	counter1++;
	cout<<"finish mutigraph"<<endl;
	return mutiGR[counter1];
}


void Muti_Plot_JES_ce0to30(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
{ 

	char filename[]="JetESR_status.txt";
	fstream myfile;
	myfile.open (filename,ios::out|ios::app);

	// Double_t Xptbin_chris_mean_ce0to30[20] = {7.999, 9.680157, 11.71464, 14.17672, 17.15625, 20.762, 25.12557, 30.40623, 36.79673, 44.53033, 53.88931, 65.21529, 78.92163, 95.50865, 115.5818, 139.8737, 169.2711, 204.8469, 247.8998, 300.001};
  Double_t Xptbin_chris_mean_ce0to30[21] = {-2,-1.8,-1.6,-1.4,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.4,1.6,1.8,2};

	Double_t Xpt_chris_mean_ce0to30[20];
	Double_t XErrpt_chris_mean_ce0to30[20];
	for (int ibin =0; ibin<20;ibin++){
		Xpt_chris_mean_ce0to30[ibin]= (Xptbin_chris_mean_ce0to30[ibin+1] +Xptbin_chris_mean_ce0to30[ibin])/2;
		XErrpt_chris_mean_ce0to30[ibin]= (Xptbin_chris_mean_ce0to30[ibin+1] -Xptbin_chris_mean_ce0to30[ibin])/2;
	}
//	double ypt_chris_mean_ce0to30[19]={2.614117,2.282987,2.04587,1.74664,1.548742,1.396857,1.275476,1.194122,1.140162,1.120749,1.075858,1.05422,1.009865,0.9785294,0.945,0.99,0.9000001,1.163599,1.15};
//	double yerrpt_chris_mean_ce0to30[19]={0.03932904,0.02605798,0.0244768,0.02502056,0.02119035,0.02074938,0.01284258,0.01424918,0.01133906,0.01246782,0.01578119,0.0227899,0.03189043,0.02962023,0.0438062,0.05302978,0.01194279,0.009490237,0.01854081};
  double ypt_chris_mean_ce0to30[20]={1.303629,1.232761,1.205993,1.151384,1.155051,1.176355,1.129106,1.145524,1.125659,1.139968,1.1215,1.161797,1.121625,1.137548,1.096634,1.143835,1.129499,1.208251,1.360947,1.391257};
  double yerrpt_chris_mean_ce0to30[20]={0.03973077,0.03413604,0.02611309,0.02574891,0.02163129,0.02497143,0.02265968,0.02311936,0.02080899,0.02306502,0.02189006,0.02727669,0.02524463,0.02605845,0.0247876,0.02748596,0.02663211,0.03237351,0.03472468,0.0379885};

	TGraphErrors *gr_chris_JESpt_ce0to30= new TGraphErrors(20,Xpt_chris_mean_ce0to30,ypt_chris_mean_ce0to30,XErrpt_chris_mean_ce0to30,yerrpt_chris_mean_ce0to30);

	gr_chris_JESpt_ce0to30->SetFillStyle(0);
	gr_chris_JESpt_ce0to30->SetMarkerStyle(1);
	gr_chris_JESpt_ce0to30->SetLineColor(ngr+1);
	gr_chris_JESpt_ce0to30->SetMarkerColor(ngr+1);


	double VarBinsCenter[nVarBins];
	double VarBinsErr[nVarBins];
	for (int ibin=0; ibin<nVarBins; ibin++)
	{
		VarBinsCenter[ibin]= (VarBins_array[ibin] + VarBins_array[ibin+1]) /2;
		//		VarBinsErr[ibin]=0;
		VarBinsErr[ibin]=(VarBins_array[ibin+1]- VarBins_array[ibin])/2;
	}

	cout<<"lineKind_Arr 1 = "<<lineKind_Arr[0]<<" ,lineKind_Arr2 = "<<lineKind_Arr[1]<<endl;
	cout<<"mu_title = "<<mu_title<<" selectionC = "<< selectionC<<endl;

	Can_result[counter1] = new TCanvas(Form("Can_result_%i",counter1));
	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	TGraphErrors *gr_mean[ngr];
	legend[counter1] = new TLegend(0.62,0.7,0.82,0.85);

	for(int igr=0; igr<ngr; igr++)
	{
		gr_mean[igr] = new TGraphErrors(nVarBins, VarBinsCenter, yArr2[igr], VarBinsErr , yErrArr2[igr]);
		gr_mean[igr]->SetTitle(Form("some title_%i", igr));
		gr_mean[igr]->SetFillStyle(0);
		gr_mean[igr]->SetMarkerStyle(1);
		gr_mean[igr]->SetLineColor(igr+1);	
		gr_mean[igr]->SetMarkerColor(igr+1);
		mutiGR[counter1]->Add(gr_mean[igr]);
		legend[counter1]->AddEntry( gr_mean[igr] ,lineKind_Arr[igr],"l");  // not work for unknow reason

	}

	mutiGR[counter1]->Add(gr_chris_JESpt_ce0to30);
	legend[counter1]->AddEntry(gr_chris_JESpt_ce0to30,"from chris","l");

	myfile<<"hello, Var = "<<Var<<"Var.compare(Centrality) = "<<Var.compare("Centrality")<<endl;

	mutiGR[counter1]->Draw("AP");
	mutiGR[counter1]->GetXaxis()->SetTitle(Form("%s",Var.c_str())); // must after draw to create a vitual histogram like object to set title.
	mutiGR[counter1]->GetYaxis()->SetTitle("#mu_{Reco./Gen.}");
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend[counter1]->SetBorderSize(0);
	legend[counter1]->Draw();

	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 &refpt>30}}");
	tex->SetNDC();
	tex->SetTextFont(43);
	tex->SetTextSize(26);
	tex->SetLineWidth(2);
	tex->Draw();
  tex = new TLatex(0.17,0.25,"Centrality:0-30%");
	tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(26);
  tex->SetLineWidth(2);
  tex->Draw();


	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.pdf",mu_title.c_str(),selectionC.GetTitle() , Var.c_str())); 
	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.C",mu_title.c_str(),selectionC.GetTitle() , Var.c_str()));
	counter1++;
	cout<<"finish mutigraph"<<endl;
}


void Muti_Plot_JES_ce30to100(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
{ 

	char filename[]="JetESR_status.txt";
	fstream myfile;
	myfile.open (filename,ios::out|ios::app);

	// Double_t Xptbin_chris_mean_ce0to30[20] = {7.999, 9.680157, 11.71464, 14.17672, 17.15625, 20.762, 25.12557, 30.40623, 36.79673, 44.53033, 53.88931, 65.21529, 78.92163, 95.50865, 115.5818, 139.8737, 169.2711, 204.8469, 247.8998, 300.001};
  Double_t Xptbin_chris_mean_ce30to100[21] = {-2,-1.8,-1.6,-1.4,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.4,1.6,1.8,2};

	Double_t Xpt_chris_mean_ce30to100[20];
	Double_t XErrpt_chris_mean_ce30to100[20];
	for (int ibin =0; ibin<20;ibin++){
		Xpt_chris_mean_ce30to100[ibin]= (Xptbin_chris_mean_ce30to100[ibin+1] +Xptbin_chris_mean_ce30to100[ibin])/2;
		XErrpt_chris_mean_ce30to100[ibin]= (Xptbin_chris_mean_ce30to100[ibin+1] -Xptbin_chris_mean_ce30to100[ibin])/2;
	}
//	double ypt_chris_mean_ce0to30[19]={2.614117,2.282987,2.04587,1.74664,1.548742,1.396857,1.275476,1.194122,1.140162,1.120749,1.075858,1.05422,1.009865,0.9785294,0.945,0.99,0.9000001,1.163599,1.15};
//	double yerrpt_chris_mean_ce0to30[19]={0.03932904,0.02605798,0.0244768,0.02502056,0.02119035,0.02074938,0.01284258,0.01424918,0.01133906,0.01246782,0.01578119,0.0227899,0.03189043,0.02962023,0.0438062,0.05302978,0.01194279,0.009490237,0.01854081};
  double ypt_chris_mean_ce30to100[20]={1.069411,1.070513,1.011301,1.035222,1.036724,1.018364,1.04198,1.020078,1.029259,1.044609,1.03874,1.068158,1.040997,1.048108,1.032786,1.053243,1.037857,1.058521,1.100998,1.078658};
  double yerrpt_chris_mean_ce30to100[20]={0.01399064,0.01414066,0.01483164,0.01399455,0.01205881,0.01070609,0.01033787,0.01035296,0.009896843,0.0109851,0.01010715,0.01008437,0.01064937,0.01041456,0.01116612,0.01110952,0.01341817,0.01461283,0.01479181,0.01308327};

	TGraphErrors *gr_chris_JESpt_ce30to100= new TGraphErrors(20,Xpt_chris_mean_ce30to100,ypt_chris_mean_ce30to100,XErrpt_chris_mean_ce30to100,yerrpt_chris_mean_ce30to100);

	gr_chris_JESpt_ce30to100->SetFillStyle(0);
	gr_chris_JESpt_ce30to100->SetMarkerStyle(1);
	gr_chris_JESpt_ce30to100->SetLineColor(ngr+1);
	gr_chris_JESpt_ce30to100->SetMarkerColor(ngr+1);


	double VarBinsCenter[nVarBins];
	double VarBinsErr[nVarBins];
	for (int ibin=0; ibin<nVarBins; ibin++)
	{
		VarBinsCenter[ibin]= (VarBins_array[ibin] + VarBins_array[ibin+1]) /2;
		//		VarBinsErr[ibin]=0;
		VarBinsErr[ibin]=(VarBins_array[ibin+1]- VarBins_array[ibin])/2;
	}

	cout<<"lineKind_Arr 1 = "<<lineKind_Arr[0]<<" ,lineKind_Arr2 = "<<lineKind_Arr[1]<<endl;
	cout<<"mu_title = "<<mu_title<<" selectionC = "<< selectionC<<endl;

	Can_result[counter1] = new TCanvas(Form("Can_result_%i",counter1));
	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	TGraphErrors *gr_mean[ngr];
	legend[counter1] = new TLegend(0.62,0.7,0.82,0.85);

	for(int igr=0; igr<ngr; igr++)
	{
		gr_mean[igr] = new TGraphErrors(nVarBins, VarBinsCenter, yArr2[igr], VarBinsErr , yErrArr2[igr]);
		//    char *name_temp = {Form("gr_mean_%i", (int)igr)};
		//		gr_mean[igr]->SetName(Form("gr_mean_%i", (int)igr) );
		//		gr_mean[igr]->SetName(name_temp);
		gr_mean[igr]->SetTitle(Form("some title_%i", igr));
		gr_mean[igr]->SetFillStyle(0);
		gr_mean[igr]->SetMarkerStyle(1);
		gr_mean[igr]->SetLineColor(igr+1);	
		gr_mean[igr]->SetMarkerColor(igr+1);
		mutiGR[counter1]->Add(gr_mean[igr]);
		legend[counter1]->AddEntry( gr_mean[igr] ,lineKind_Arr[igr],"l");  // not work for unknow reason

	}

	mutiGR[counter1]->Add(gr_chris_JESpt_ce30to100);
	legend[counter1]->AddEntry(gr_chris_JESpt_ce30to100,"from chris","l");

	myfile<<"hello, Var = "<<Var<<"Var.compare(Centrality) = "<<Var.compare("Centrality")<<endl;

	mutiGR[counter1]->Draw("AP");
	mutiGR[counter1]->GetXaxis()->SetTitle(Form("%s",Var.c_str())); // must after draw to create a vitual histogram like object to set title.
	mutiGR[counter1]->GetYaxis()->SetTitle("#mu_{Reco./Gen.}");
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend[counter1]->SetBorderSize(0);
	legend[counter1]->Draw();

	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 & refpt>30}}");
	tex->SetNDC();
	tex->SetTextFont(43);
	tex->SetTextSize(26);
	tex->SetLineWidth(2);
	tex->Draw();
  tex = new TLatex(0.17,0.25,"Centrality:30-100%");
	tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(26);
  tex->SetLineWidth(2);
  tex->Draw();


	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.pdf",mu_title.c_str(),selectionC.GetTitle() , Var.c_str())); 
	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.C",mu_title.c_str(),selectionC.GetTitle() , Var.c_str()));
	counter1++;
	cout<<"finish mutigraph"<<endl;
}


void Muti_Plot_JER_ce0to30(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
{ 

	char filename[]="JetESR_status.txt";
	fstream myfile;
	myfile.open (filename,ios::out|ios::app);

	// Double_t Xptbin_chris_mean_ce0to30[20] = {7.999, 9.680157, 11.71464, 14.17672, 17.15625, 20.762, 25.12557, 30.40623, 36.79673, 44.53033, 53.88931, 65.21529, 78.92163, 95.50865, 115.5818, 139.8737, 169.2711, 204.8469, 247.8998, 300.001};
  Double_t Xptbin_chris_mean_ce0to30[21] = {-2,-1.8,-1.6,-1.4,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.4,1.6,1.8,2};

	Double_t Xpt_chris_mean_ce0to30[20];
	Double_t XErrpt_chris_mean_ce0to30[20];
	for (int ibin =0; ibin<20;ibin++){
		Xpt_chris_mean_ce0to30[ibin]= (Xptbin_chris_mean_ce0to30[ibin+1] +Xptbin_chris_mean_ce0to30[ibin])/2;
		XErrpt_chris_mean_ce0to30[ibin]= (Xptbin_chris_mean_ce0to30[ibin+1] -Xptbin_chris_mean_ce0to30[ibin])/2;
	}
//	double ypt_chris_mean_ce0to30[19]={2.614117,2.282987,2.04587,1.74664,1.548742,1.396857,1.275476,1.194122,1.140162,1.120749,1.075858,1.05422,1.009865,0.9785294,0.945,0.99,0.9000001,1.163599,1.15};
//	double yerrpt_chris_mean_ce0to30[19]={0.03932904,0.02605798,0.0244768,0.02502056,0.02119035,0.02074938,0.01284258,0.01424918,0.01133906,0.01246782,0.01578119,0.0227899,0.03189043,0.02962023,0.0438062,0.05302978,0.01194279,0.009490237,0.01854081};
  double ypt_chris_mean_ce0to30[20]={0.3775948,0.3621174,0.3175088,0.3012355,0.2877171,0.3214521,0.3062906,0.290515,0.2798917,0.3108987,0.2959602,0.3324433,0.318869,0.3350273,0.3149909,0.3498084,0.3180699,0.3774354,0.398101,0.4182954};
  double yerrpt_chris_mean_ce0to30[20]={0.03634148,0.02440305,0.01853123,0.01826765,0.01532295,0.0177536,0.01610338,0.01638466,0.01473966,0.01639629,0.01553578,0.01945342,0.0179949,0.01863211,0.01768351,0.01973211,0.01897051,0.02330566,0.02484717,0.02731119};

	TGraphErrors *gr_chris_JERpt_ce0to30= new TGraphErrors(20,Xpt_chris_mean_ce0to30,ypt_chris_mean_ce0to30,XErrpt_chris_mean_ce0to30,yerrpt_chris_mean_ce0to30);

	gr_chris_JERpt_ce0to30->SetFillStyle(0);
	gr_chris_JERpt_ce0to30->SetMarkerStyle(1);
	gr_chris_JERpt_ce0to30->SetLineColor(ngr+1);
	gr_chris_JERpt_ce0to30->SetMarkerColor(ngr+1);


	double VarBinsCenter[nVarBins];
	double VarBinsErr[nVarBins];
	for (int ibin=0; ibin<nVarBins; ibin++)
	{
		VarBinsCenter[ibin]= (VarBins_array[ibin] + VarBins_array[ibin+1]) /2;
		//		VarBinsErr[ibin]=0;
		VarBinsErr[ibin]=(VarBins_array[ibin+1]- VarBins_array[ibin])/2;
	}

	cout<<"lineKind_Arr 1 = "<<lineKind_Arr[0]<<" ,lineKind_Arr2 = "<<lineKind_Arr[1]<<endl;
	cout<<"mu_title = "<<mu_title<<" selectionC = "<< selectionC<<endl;

	Can_result[counter1] = new TCanvas(Form("Can_result_%i",counter1));
	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	TGraphErrors *gr_mean[ngr];
	legend[counter1] = new TLegend(0.62,0.7,0.82,0.85);

	for(int igr=0; igr<ngr; igr++)
	{
		gr_mean[igr] = new TGraphErrors(nVarBins, VarBinsCenter, yArr2[igr], VarBinsErr , yErrArr2[igr]);
		gr_mean[igr]->SetTitle(Form("some title_%i", igr));
		gr_mean[igr]->SetFillStyle(0);
		gr_mean[igr]->SetMarkerStyle(1);
		gr_mean[igr]->SetLineColor(igr+1);	
		gr_mean[igr]->SetMarkerColor(igr+1);
		mutiGR[counter1]->Add(gr_mean[igr]);
		legend[counter1]->AddEntry( gr_mean[igr] ,lineKind_Arr[igr],"l");  // not work for unknow reason

	}

	mutiGR[counter1]->Add(gr_chris_JERpt_ce0to30);
	legend[counter1]->AddEntry(gr_chris_JERpt_ce0to30,"from chris","l");

	myfile<<"hello, Var = "<<Var<<"Var.compare(Centrality) = "<<Var.compare("Centrality")<<endl;

	mutiGR[counter1]->Draw("AP");
	mutiGR[counter1]->GetXaxis()->SetTitle(Form("%s",Var.c_str())); // must after draw to create a vitual histogram like object to set title.
	mutiGR[counter1]->GetYaxis()->SetTitle("#sigma_{Reco./Gen.}");
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend[counter1]->SetBorderSize(0);
	legend[counter1]->Draw();

	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 & refpt>30}}");
	tex->SetNDC();
	tex->SetTextFont(43);
	tex->SetTextSize(26);
	tex->SetLineWidth(2);
	tex->Draw();
  tex = new TLatex(0.17,0.25,"Centrality:0-30%");
	tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(26);
  tex->SetLineWidth(2);
  tex->Draw();


	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.pdf",mu_title.c_str(),selectionC.GetTitle() , Var.c_str())); 
	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.C",mu_title.c_str(),selectionC.GetTitle() , Var.c_str()));
	counter1++;
	cout<<"finish mutigraph"<<endl;
}


void Muti_Plot_JER_ce30to100(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
{ 

	char filename[]="JetESR_status.txt";
	fstream myfile;
	myfile.open (filename,ios::out|ios::app);

	// Double_t Xptbin_chris_mean_ce0to30[20] = {7.999, 9.680157, 11.71464, 14.17672, 17.15625, 20.762, 25.12557, 30.40623, 36.79673, 44.53033, 53.88931, 65.21529, 78.92163, 95.50865, 115.5818, 139.8737, 169.2711, 204.8469, 247.8998, 300.001};
  Double_t Xptbin_chris_mean_ce30to100[21] = {-2,-1.8,-1.6,-1.4,-1,-0.8,-0.6,-0.4,-0.2,0,0.2,0.4,0.6,0.8,1,1.2,1.4,1.6,1.8,2};

	Double_t Xpt_chris_mean_ce30to100[20];
	Double_t XErrpt_chris_mean_ce30to100[20];
	for (int ibin =0; ibin<20;ibin++){
		Xpt_chris_mean_ce30to100[ibin]= (Xptbin_chris_mean_ce30to100[ibin+1] +Xptbin_chris_mean_ce30to100[ibin])/2;
		XErrpt_chris_mean_ce30to100[ibin]= (Xptbin_chris_mean_ce30to100[ibin+1] -Xptbin_chris_mean_ce30to100[ibin])/2;
	}
//	double ypt_chris_mean_ce0to30[19]={2.614117,2.282987,2.04587,1.74664,1.548742,1.396857,1.275476,1.194122,1.140162,1.120749,1.075858,1.05422,1.009865,0.9785294,0.945,0.99,0.9000001,1.163599,1.15};
//	double yerrpt_chris_mean_ce0to30[19]={0.03932904,0.02605798,0.0244768,0.02502056,0.02119035,0.02074938,0.01284258,0.01424918,0.01133906,0.01246782,0.01578119,0.0227899,0.03189043,0.02962023,0.0438062,0.05302978,0.01194279,0.009490237,0.01854081};
  double ypt_chris_mean_ce30to100[20]={0.2311591,0.2477474,0.2655955,0.2576075,0.2220231,0.206768,0.2064983,0.2020811,0.19917,0.2115871,0.1952014,0.1965805,0.2158946,0.2003286,0.213619,0.213695,0.2466632,0.2597152,0.2553281,0.2344014};
  double yerrpt_chris_mean_ce30to100[20]={0.009894431,0.01000488,0.01052403,0.009913006,0.008527985,0.007570562,0.007309829,0.007320613,0.00699798,0.00776784,0.007146697,0.00713059,0.007530691,0.007364154,0.007896077,0.007855752,0.009496669,0.01034782,0.01046585,0.009252961};

	TGraphErrors *gr_chris_JERpt_ce30to100= new TGraphErrors(20,Xpt_chris_mean_ce30to100,ypt_chris_mean_ce30to100,XErrpt_chris_mean_ce30to100,yerrpt_chris_mean_ce30to100);

	gr_chris_JERpt_ce30to100->SetFillStyle(0);
	gr_chris_JERpt_ce30to100->SetMarkerStyle(1);
	gr_chris_JERpt_ce30to100->SetLineColor(ngr+1);
	gr_chris_JERpt_ce30to100->SetMarkerColor(ngr+1);


	double VarBinsCenter[nVarBins];
	double VarBinsErr[nVarBins];
	for (int ibin=0; ibin<nVarBins; ibin++)
	{
		VarBinsCenter[ibin]= (VarBins_array[ibin] + VarBins_array[ibin+1]) /2;
		//		VarBinsErr[ibin]=0;
		VarBinsErr[ibin]=(VarBins_array[ibin+1]- VarBins_array[ibin])/2;
	}

	cout<<"lineKind_Arr 1 = "<<lineKind_Arr[0]<<" ,lineKind_Arr2 = "<<lineKind_Arr[1]<<endl;
	cout<<"mu_title = "<<mu_title<<" selectionC = "<< selectionC<<endl;

	Can_result[counter1] = new TCanvas(Form("Can_result_%i",counter1));
	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	TGraphErrors *gr_mean[ngr];
	legend[counter1] = new TLegend(0.62,0.7,0.82,0.85);

	for(int igr=0; igr<ngr; igr++)
	{
		gr_mean[igr] = new TGraphErrors(nVarBins, VarBinsCenter, yArr2[igr], VarBinsErr , yErrArr2[igr]);
		//    char *name_temp = {Form("gr_mean_%i", (int)igr)};
		//		gr_mean[igr]->SetName(Form("gr_mean_%i", (int)igr) );
		//		gr_mean[igr]->SetName(name_temp);
		gr_mean[igr]->SetTitle(Form("some title_%i", igr));
		gr_mean[igr]->SetFillStyle(0);
		gr_mean[igr]->SetMarkerStyle(1);
		gr_mean[igr]->SetLineColor(igr+1);	
		gr_mean[igr]->SetMarkerColor(igr+1);
		mutiGR[counter1]->Add(gr_mean[igr]);
		legend[counter1]->AddEntry( gr_mean[igr] ,lineKind_Arr[igr],"l");  // not work for unknow reason

	}

	mutiGR[counter1]->Add(gr_chris_JERpt_ce30to100);
	legend[counter1]->AddEntry(gr_chris_JERpt_ce30to100,"from chris","l");

	myfile<<"hello, Var = "<<Var<<"Var.compare(Centrality) = "<<Var.compare("Centrality")<<endl;

	mutiGR[counter1]->Draw("AP");
	mutiGR[counter1]->GetXaxis()->SetTitle(Form("%s",Var.c_str())); // must after draw to create a vitual histogram like object to set title.
	mutiGR[counter1]->GetYaxis()->SetTitle("#sigma_{Reco./Gen.}");
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend[counter1]->SetBorderSize(0);
	legend[counter1]->Draw();

	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0} & refpt>30}");
	tex->SetNDC();
	tex->SetTextFont(43);
	tex->SetTextSize(26);
	tex->SetLineWidth(2);
	tex->Draw();
  tex = new TLatex(0.17,0.25,"Centrality:30-100%");
	tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(26);
  tex->SetLineWidth(2);
  tex->Draw();


	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.pdf",mu_title.c_str(),selectionC.GetTitle() , Var.c_str())); 
	Can_result[counter1]->SaveAs(Form("./Plots/result_%s_%s_%s.C",mu_title.c_str(),selectionC.GetTitle() , Var.c_str()));
	counter1++;
	cout<<"finish mutigraph"<<endl;
}


void jetE_SR_centrality()
{

	char filename[]="JetESR_result.txt";
	fstream wout;
	wout.open (filename,ios::out|ios::app);


	counter=0;
	counter1=0;

	TChain *tc_akPu4PF = new TChain("akPu4PFJetAnalyzer/t", "akPu4PF");
	TChain *tc_akVs4PF = new TChain("akVs4PFJetAnalyzer/t", "akVs4PF");
	TChain *tc_akPu4Calo = new TChain("akPu4CaloJetAnalyzer/t", "akPu4Calo");
	TChain *tc_akVs4Calo = new TChain("akVs4CaloJetAnalyzer/t", "akVs4Calo");

	TChain *tc_Hiak = new TChain("hiEvtAnalyzer/HiTree");
	
		 tc_Hiak->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");

		 tc_akPu4PF->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");
		 tc_akVs4PF->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");
		 tc_akPu4Calo->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");
		 tc_akVs4Calo->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");

		 tc_akPu4PF->AddFriend(tc_Hiak);
		 tc_akVs4PF->AddFriend(tc_Hiak);
		 tc_akPu4Calo->AddFriend(tc_Hiak);
		 tc_akVs4Calo->AddFriend(tc_Hiak);
		 

/*
	tc_Hiak->Add("root://xrootd.unl.edu//store/user/rbi/merged/dgulhan-Pythia8_Dijet30_pp_TuneCUETP8M1_Hydjet_MinBias_5020GeV_RECODEBUG_758_PrivMC_forest_v28/0.root");

	tc_akPu4PF->Add("root://xrootd.unl.edu//store/user/rbi/merged/dgulhan-Pythia8_Dijet30_pp_TuneCUETP8M1_Hydjet_MinBias_5020GeV_RECODEBUG_758_PrivMC_forest_v28/0.root");
	tc_akPu4PF->AddFriend(tc_Hiak);
*/
	const int nJetA=4;

	TChain *t_temp[nJetA]={tc_akPu4PF,tc_akVs4PF,tc_akPu4Calo,tc_akVs4Calo};
	//	t_temp[0]=tc_akPu4PF;
	//	TChain *t_temp;
	//	t_temp = tc_akPu4PF;

	double ptBin[] = {40,50,60,70,80,90,100,110,120,140,160,200};
	const int nPtBins = sizeof(ptBin)/sizeof(ptBin[0]) -1;

	double etaBin[] = {-2,-1.6,-1.2,-0.8,-0.4,0,0.4,0.8,1.2,2};
	const int nEtaBins = sizeof(etaBin)/sizeof(etaBin[0])-1;

	double centBin[] = {0,20,60,100,200};
	const int nCentBins = sizeof(centBin) / sizeof(centBin[0]) -1;

	double centBin1[nCentBins+1];
	for (int iCentBin =0; iCentBin < nCentBins+1 ; iCentBin ++){
		centBin1[iCentBin]= centBin[iCentBin]/2;
		cout<<"centBin1, iCentBin = "<<iCentBin<<" , = "<<centBin1[iCentBin]<<endl;
	}

	double fit_Rmean_pt[nJetA][nPtBins];
	double fit_RmeanErr_pt[nJetA][nPtBins];
	double fit_Rsigma_pt[nJetA][nPtBins];
	double fit_RsigmaErr_pt[nJetA][nPtBins];


	TH1D *hRatio[nPtBins];
	TF1 *f1[nPtBins];

	/*
		 TCanvas *C_pt_spectrum = new TCanvas("C_pt_spectrum","C_pt_spectrum");
		 C_pt_spectrum->Divide(2,1);
		 C_pt_spectrum->cd(1);
		 tc_akPu4PF->Draw("refpt","refpt>0");
		 C_pt_spectrum->cd(2);
		 tc_akPu4PF->Draw("jtpt","refpt>0");
		 */
	TCanvas *C_ptRatio[nJetA] ;
	//  TCanvas *C_ptRatio = new TCanvas("C_ptRatio","C_ptRatio");
	// C_ptRatio->Divide(4,3);
	gStyle->SetOptFit(1111);

	std::string Var_pt = "refpt";
	std::string Var_cent = "hiBin";
	std::string Var_eta = "refeta";
	std::string measurement="JES_akPu4PF";

	const char *lineKind[]={"allJets","lightJets","bJets"};

	TCut Cut_eta2 = "abs(refeta)<2";
	TCut Cut_pt30 = "refpt>30";
	TCut Light_Cut = "refparton_flavorForB != 4 && refparton_flavorForB != 5";
	TCut Heavy_Cut = "abs(refparton_flavorForB)==5";
	TCut AllCut = Cut_eta2;
	TCut Light_AllCut = Light_Cut && AllCut;
	TCut Heavy_AllCut = Heavy_Cut && AllCut;


	//////////////////////
	//// Gen JetPt
	/////////////////////

	//// centrality 0-100% ////
	/*
		 double Imean_pt_akPu4PF[nPtBins];
		 double ImeanErr_pt_akPu4PF[nPtBins];
		 double Isigma_pt_akPu4PF[nPtBins];
		 double IsigmaErr_pt_akPu4PF[nPtBins];
		 fit_combine(tc_akPu4PF , Var_pt, ptBin , nPtBins, AllCut , Imean_pt_akPu4PF, ImeanErr_pt_akPu4PF, Isigma_pt_akPu4PF, IsigmaErr_pt_akPu4PF);

		 wout<<"\ncut = "<<AllCut<<endl;
		 wout<<Form("double Imean_pt_akPu4PF[%d]={",nPtBins);
		 for(int ibin =0; ibin<nPtBins; ibin++){wout<<Imean_pt_akPu4PF[ibin];
		 if (ibin!=nPtBins-1) {wout<<","; } }
		 wout<<"};"<<endl;

		 wout<<Form("double ImeanErr_pt_akPu4PF[%d]={",nPtBins);
		 for(int ibin =0; ibin<nPtBins; ibin++){wout<<ImeanErr_pt_akPu4PF[ibin];
		 if (ibin!=nPtBins-1) {wout<<","; } }
		 wout<<"};"<<endl;

		 double Lmean_pt_akPu4PF[nPtBins];
		 double LmeanErr_pt_akPu4PF[nPtBins];
		 double Lsigma_pt_akPu4PF[nPtBins];
		 double LsigmaErr_pt_akPu4PF[nPtBins];  
		 fit_combine(tc_akPu4PF , Var_pt, ptBin , nPtBins, Light_AllCut , Lmean_pt_akPu4PF, LmeanErr_pt_akPu4PF, Lsigma_pt_akPu4PF, LsigmaErr_pt_akPu4PF);

		 double Hmean_pt_akPu4PF[nPtBins];
		 double HmeanErr_pt_akPu4PF[nPtBins];
		 double Hsigma_pt_akPu4PF[nPtBins];
		 double HsigmaErr_pt_akPu4PF[nPtBins];  
		 fit_combine(tc_akPu4PF , Var_pt, ptBin , nPtBins, Heavy_AllCut , Hmean_pt_akPu4PF, HmeanErr_pt_akPu4PF, Hsigma_pt_akPu4PF, HsigmaErr_pt_akPu4PF);

		 double *mean2D_pt_akPu4PF[3]={Imean_pt_akPu4PF,Lmean_pt_akPu4PF,Hmean_pt_akPu4PF};
		 double *meanErr2D_pt_akPu4PF[3]={ImeanErr_pt_akPu4PF,LmeanErr_pt_akPu4PF,HmeanErr_pt_akPu4PF};
		 double *sigma2D_pt_akPu4PF[3]={Isigma_pt_akPu4PF,Lsigma_pt_akPu4PF,Hsigma_pt_akPu4PF};
		 double *sigmaErr2D_pt_akPu4PF[3]={IsigmaErr_pt_akPu4PF,LsigmaErr_pt_akPu4PF,HsigmaErr_pt_akPu4PF};

		 measurement="JES_akPu4PF";

		 TMultiGraph *Gr_JESpt_akPu4PF =  Muti_Plot(measurement, lineKind , AllCut, Var_pt, 3, nPtBins , ptBin , mean2D_pt_akPu4PF, meanErr2D_pt_akPu4PF);
		 measurement="JER_akPu4PF";
		 TMultiGraph *Gr_JERpt_akPu4PF =  Muti_Plot(measurement, lineKind , AllCut, Var_pt, 3, nPtBins , ptBin , sigma2D_pt_akPu4PF, sigmaErr2D_pt_akPu4PF);
		 */

	//// centrality 0-30% ////
/*
	TCut cut_hibin060 ="hiBin<60";
	AllCut = Cut_eta2 && cut_hibin060 && Cut_pt30;
	Light_AllCut = Light_Cut && AllCut;
	Heavy_AllCut = Heavy_Cut && AllCut;

	double Imean_pt_akPu4PF_ce0to30[nEtaBins];
	double ImeanErr_pt_akPu4PF_ce0to30[nEtaBins];
	double Isigma_pt_akPu4PF_ce0to30[nEtaBins];
	double IsigmaErr_pt_akPu4PF_ce0to30[nEtaBins];
	fit_combine(tc_akPu4PF , Var_eta, etaBin , nEtaBins, AllCut , Imean_pt_akPu4PF_ce0to30, ImeanErr_pt_akPu4PF_ce0to30, Isigma_pt_akPu4PF_ce0to30, IsigmaErr_pt_akPu4PF_ce0to30);

	double Lmean_pt_akPu4PF_ce0to30[nEtaBins];
	double LmeanErr_pt_akPu4PF_ce0to30[nEtaBins];
	double Lsigma_pt_akPu4PF_ce0to30[nEtaBins];
	double LsigmaErr_pt_akPu4PF_ce0to30[nEtaBins];  
	fit_combine(tc_akPu4PF , Var_eta, etaBin , nEtaBins, Light_AllCut , Lmean_pt_akPu4PF_ce0to30, LmeanErr_pt_akPu4PF_ce0to30, Lsigma_pt_akPu4PF_ce0to30, LsigmaErr_pt_akPu4PF_ce0to30);

	double Hmean_pt_akPu4PF_ce0to30[nEtaBins];
	double HmeanErr_pt_akPu4PF_ce0to30[nEtaBins];
	double Hsigma_pt_akPu4PF_ce0to30[nEtaBins];
	double HsigmaErr_pt_akPu4PF_ce0to30[nEtaBins];  
	fit_combine(tc_akPu4PF , Var_eta, etaBin , nEtaBins, Heavy_AllCut , Hmean_pt_akPu4PF_ce0to30, HmeanErr_pt_akPu4PF_ce0to30, Hsigma_pt_akPu4PF_ce0to30, HsigmaErr_pt_akPu4PF_ce0to30);

	double *mean2D_pt_akPu4PF_ce0to30[3]={Imean_pt_akPu4PF_ce0to30,Lmean_pt_akPu4PF_ce0to30,Hmean_pt_akPu4PF_ce0to30};
	double *meanErr2D_pt_akPu4PF_ce0to30[3]={ImeanErr_pt_akPu4PF_ce0to30,LmeanErr_pt_akPu4PF_ce0to30,HmeanErr_pt_akPu4PF_ce0to30};
	double *sigma2D_pt_akPu4PF_ce0to30[3]={Isigma_pt_akPu4PF_ce0to30,Lsigma_pt_akPu4PF_ce0to30,Hsigma_pt_akPu4PF_ce0to30};
	double *sigmaErr2D_pt_akPu4PF_ce0to30[3]={IsigmaErr_pt_akPu4PF_ce0to30,LsigmaErr_pt_akPu4PF_ce0to30,HsigmaErr_pt_akPu4PF_ce0to30};

	measurement="JES_akPu4PF";

	Muti_Plot_JES_ce0to30(measurement, lineKind , AllCut, Var_eta, 3, nEtaBins , etaBin , mean2D_pt_akPu4PF_ce0to30, meanErr2D_pt_akPu4PF_ce0to30);

  measurement="JER_akPu4PF";

  Muti_Plot_JER_ce0to30(measurement, lineKind , AllCut, Var_eta, 3, nEtaBins , etaBin , sigma2D_pt_akPu4PF_ce0to30, sigmaErr2D_pt_akPu4PF_ce0to30);

//// end of centrality 0-30% ///

	
	//// centrality 30-100% ////

	TCut cut_hibin60200 ="hiBin>60";
	AllCut = Cut_eta2 && cut_hibin60200 && Cut_pt30;
	Light_AllCut = Light_Cut && AllCut;
	Heavy_AllCut = Heavy_Cut && AllCut;

	double Imean_pt_akPu4PF_ce30to100[nEtaBins];
	double ImeanErr_pt_akPu4PF_ce30to100[nEtaBins];
	double Isigma_pt_akPu4PF_ce30to100[nEtaBins];
	double IsigmaErr_pt_akPu4PF_ce30to100[nEtaBins];
	fit_combine(tc_akPu4PF , Var_eta, etaBin , nEtaBins, AllCut , Imean_pt_akPu4PF_ce30to100, ImeanErr_pt_akPu4PF_ce30to100, Isigma_pt_akPu4PF_ce30to100, IsigmaErr_pt_akPu4PF_ce30to100);

	double Lmean_pt_akPu4PF_ce30to100[nEtaBins];
	double LmeanErr_pt_akPu4PF_ce30to100[nEtaBins];
	double Lsigma_pt_akPu4PF_ce30to100[nEtaBins];
	double LsigmaErr_pt_akPu4PF_ce30to100[nEtaBins];  
	fit_combine(tc_akPu4PF , Var_eta, etaBin , nEtaBins, Light_AllCut , Lmean_pt_akPu4PF_ce30to100, LmeanErr_pt_akPu4PF_ce30to100, Lsigma_pt_akPu4PF_ce30to100, LsigmaErr_pt_akPu4PF_ce30to100);

	double Hmean_pt_akPu4PF_ce30to100[nEtaBins];
	double HmeanErr_pt_akPu4PF_ce30to100[nEtaBins];
	double Hsigma_pt_akPu4PF_ce30to100[nEtaBins];
	double HsigmaErr_pt_akPu4PF_ce30to100[nEtaBins];  
	fit_combine(tc_akPu4PF , Var_eta, etaBin , nEtaBins, Heavy_AllCut , Hmean_pt_akPu4PF_ce30to100, HmeanErr_pt_akPu4PF_ce30to100, Hsigma_pt_akPu4PF_ce30to100, HsigmaErr_pt_akPu4PF_ce30to100);

	double *mean2D_pt_akPu4PF_ce30to100[3]={Imean_pt_akPu4PF_ce30to100,Lmean_pt_akPu4PF_ce30to100,Hmean_pt_akPu4PF_ce30to100};
	double *meanErr2D_pt_akPu4PF_ce30to100[3]={ImeanErr_pt_akPu4PF_ce30to100,LmeanErr_pt_akPu4PF_ce30to100,HmeanErr_pt_akPu4PF_ce30to100};
	double *sigma2D_pt_akPu4PF_ce30to100[3]={Isigma_pt_akPu4PF_ce30to100,Lsigma_pt_akPu4PF_ce30to100,Hsigma_pt_akPu4PF_ce30to100};
	double *sigmaErr2D_pt_akPu4PF_ce30to100[3]={IsigmaErr_pt_akPu4PF_ce30to100,LsigmaErr_pt_akPu4PF_ce30to100,HsigmaErr_pt_akPu4PF_ce30to100};

	measurement="JES_akPu4PF";

	Muti_Plot_JES_ce30to100(measurement, lineKind , AllCut, Var_eta, 3, nEtaBins , etaBin , mean2D_pt_akPu4PF_ce30to100, meanErr2D_pt_akPu4PF_ce30to100);

  measurement="JER_akPu4PF";

  Muti_Plot_JER_ce30to100(measurement, lineKind , AllCut, Var_eta, 3, nEtaBins , etaBin , sigma2D_pt_akPu4PF_ce30to100, sigmaErr2D_pt_akPu4PF_ce30to100);

//// end of centrality 30-100% ///

	//  TMultiGraph *Gr_JESpt_akPu4PF_ce0to30 =  Muti_Plot(measurement, lineKind , AllCut, Var_pt, 3, nPtBins , ptBin , mean2D_pt_akPu4PF_ce0to30, meanErr2D_pt_akPu4PF_ce0to30);

	//	measurement="JER_akPu4PF";
	//  TMultiGraph *Gr_JERpt_akPu4PF_ce0to30 =  Muti_Plot(measurement, lineKind , AllCut, Var_pt, 3, nPtBins , ptBin , sigma2D_pt_akPu4PF_ce0to30, sigmaErr2D_pt_akPu4PF_ce0to30);
/*


	/*

	////  compare different Jet

	double Imean_pt_akVs4PF[nPtBins];
	double ImeanErr_pt_akVs4PF[nPtBins];
	double Isigma_pt_akVs4PF[nPtBins];
	double IsigmaErr_pt_akVs4PF[nPtBins];
	fit_combine(tc_akVs4PF , Var_pt, ptBin , nPtBins, Cut_eta2 , Imean_pt_akVs4PF, ImeanErr_pt_akVs4PF, Isigma_pt_akVs4PF, IsigmaErr_pt_akVs4PF);

	double Imean_pt_akPu4Calo[nPtBins];
	double ImeanErr_pt_akPu4Calo[nPtBins];
	double Isigma_pt_akPu4Calo[nPtBins];
	double IsigmaErr_pt_akPu4Calo[nPtBins];
	fit_combine(tc_akPu4Calo , Var_pt, ptBin , nPtBins, Cut_eta2 , Imean_pt_akPu4Calo, ImeanErr_pt_akPu4Calo, Isigma_pt_akPu4Calo, IsigmaErr_pt_akPu4Calo);

	double Imean_pt_akVs4Calo[nPtBins];
	double ImeanErr_pt_akVs4Calo[nPtBins];
	double Isigma_pt_akVs4Calo[nPtBins];
	double IsigmaErr_pt_akVs4Calo[nPtBins];
	fit_combine(tc_akVs4Calo , Var_pt, ptBin , nPtBins, Cut_eta2 , Imean_pt_akVs4Calo, ImeanErr_pt_akVs4Calo, Isigma_pt_akVs4Calo, IsigmaErr_pt_akVs4Calo);


	double *mean2D_pt[4]={Imean_pt_akPu4PF,Imean_pt_akVs4PF,Imean_pt_akPu4Calo,Imean_pt_akVs4Calo};
	double *meanErr2D_pt[4]={ImeanErr_pt_akPu4PF,ImeanErr_pt_akVs4PF,ImeanErr_pt_akPu4Calo,ImeanErr_pt_akVs4Calo};
	double *sigma2D_pt[4]={Isigma_pt_akPu4PF,Isigma_pt_akVs4PF,Isigma_pt_akPu4Calo,Isigma_pt_akVs4Calo};
	double *sigmaErr2D_pt[4]={IsigmaErr_pt_akPu4PF,IsigmaErr_pt_akVs4PF,IsigmaErr_pt_akPu4Calo,IsigmaErr_pt_akVs4Calo};

	//TMultiGraph *Muti_Plot(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)

	// const char *lineKind[]={"allJets","lightJets","bJets"};
	const char*lineKindJet[]={"akPu4PF","akVs4PF","akPu4Calo","akVs4Calo"};
	measurement="JES";

	TMultiGraph *Gr_JESpt =  Muti_Plot(measurement, lineKindJet , Cut_eta2, Var_pt, 4, nPtBins , ptBin , mean2D_pt, meanErr2D_pt);
	measurement="JER";
	TMultiGraph *Gr_JERpt =  Muti_Plot(measurement, lineKindJet , Cut_eta2, Var_pt, 4, nPtBins , ptBin , sigma2D_pt, sigmaErr2D_pt);




*/




	////////////////
	// Centrality //
	////////////////


	Cut_eta2 = "abs(refeta)<2";
	TCut Cut_ptmid = "refpt> 75 && refpt < 120";
	AllCut = Cut_ptmid && Cut_eta2;
	Light_AllCut = Light_Cut && Cut_ptmid && Cut_eta2;
	Heavy_AllCut = Heavy_Cut && Cut_ptmid && Cut_eta2;

	double Imean_cent_akPu4PF[nCentBins];
	double ImeanErr_cent_akPu4PF[nCentBins];
	double Isigma_cent_akPu4PF[nCentBins];
	double IsigmaErr_cent_akPu4PF[nCentBins];
	fit_combine(tc_akPu4PF , Var_cent, centBin , nCentBins, AllCut , Imean_cent_akPu4PF, ImeanErr_cent_akPu4PF, Isigma_cent_akPu4PF, IsigmaErr_cent_akPu4PF);

	double Lmean_cent_akPu4PF[nCentBins];
	double LmeanErr_cent_akPu4PF[nCentBins];
	double Lsigma_cent_akPu4PF[nCentBins];
	double LsigmaErr_cent_akPu4PF[nCentBins];
	fit_combine(tc_akPu4PF , Var_cent, centBin , nCentBins, Light_AllCut , Lmean_cent_akPu4PF, LmeanErr_cent_akPu4PF, Lsigma_cent_akPu4PF, LsigmaErr_cent_akPu4PF);

	double Hmean_cent_akPu4PF[nCentBins];
	double HmeanErr_cent_akPu4PF[nCentBins];
	double Hsigma_cent_akPu4PF[nCentBins];
	double HsigmaErr_cent_akPu4PF[nCentBins];
	fit_combine(tc_akPu4PF , Var_cent, centBin , nCentBins, Heavy_AllCut , Hmean_cent_akPu4PF, HmeanErr_cent_akPu4PF, Hsigma_cent_akPu4PF, HsigmaErr_cent_akPu4PF);

	double *mean2D_cent_akPu4PF[3]={Imean_cent_akPu4PF,Lmean_cent_akPu4PF,Hmean_cent_akPu4PF};
	double *meanErr2D_cent_akPu4PF[3]={ImeanErr_cent_akPu4PF,LmeanErr_cent_akPu4PF,HmeanErr_cent_akPu4PF};
	double *sigma2D_cent_akPu4PF[3]={Isigma_cent_akPu4PF,Lsigma_cent_akPu4PF,Hsigma_cent_akPu4PF};
	double *sigmaErr2D_cent_akPu4PF[3]={IsigmaErr_cent_akPu4PF,LsigmaErr_cent_akPu4PF,HsigmaErr_cent_akPu4PF};

	//  const char *lineKind[]={"allJets","lightJets","bJets"};
	measurement="JES_akPu4PF";
	std::string st_cent="Centrality";

	Muti_Plot_centScale(measurement, lineKind , AllCut, st_cent, 3, nCentBins , centBin1 , mean2D_cent_akPu4PF, meanErr2D_cent_akPu4PF);
	measurement="JER_akPu4PF";
	Muti_Plot_centResolution(measurement, lineKind , AllCut, st_cent, 3, nCentBins , centBin1 , sigma2D_cent_akPu4PF, sigmaErr2D_cent_akPu4PF);

/*

	////////////////////
	// Gen Eta				//
	////////////////////


	//  Cut_eta2 = "abs(refeta)<2";	
	TCut Cut_pt30 = "refpt>30";
	AllCut = Cut_pt30;
	Light_AllCut = Light_Cut && Cut_pt30;
	Heavy_AllCut = Heavy_Cut && Cut_pt30;

	double Imean_eta_akPu4PF[nEtaBins];
	double ImeanErr_eta_akPu4PF[nEtaBins];
	double Isigma_eta_akPu4PF[nEtaBins];
	double IsigmaErr_eta_akPu4PF[nEtaBins];
	fit_combine(tc_akPu4PF , Var_eta, etaBin , nEtaBins, AllCut , Imean_eta_akPu4PF, ImeanErr_eta_akPu4PF, Isigma_eta_akPu4PF, IsigmaErr_eta_akPu4PF);

	double Lmean_eta_akPu4PF[nEtaBins];
	double LmeanErr_eta_akPu4PF[nEtaBins];
	double Lsigma_eta_akPu4PF[nEtaBins];
	double LsigmaErr_eta_akPu4PF[nEtaBins];
	fit_combine(tc_akPu4PF , Var_eta, etaBin , nEtaBins, Light_AllCut , Lmean_eta_akPu4PF, LmeanErr_eta_akPu4PF, Lsigma_eta_akPu4PF, LsigmaErr_eta_akPu4PF);

	double Hmean_eta_akPu4PF[nEtaBins];
	double HmeanErr_eta_akPu4PF[nEtaBins];
	double Hsigma_eta_akPu4PF[nEtaBins];
	double HsigmaErr_eta_akPu4PF[nEtaBins];
	fit_combine(tc_akPu4PF , Var_eta, etaBin , nEtaBins, Heavy_AllCut , Hmean_eta_akPu4PF, HmeanErr_eta_akPu4PF, Hsigma_eta_akPu4PF, HsigmaErr_eta_akPu4PF);

	double *mean2D_eta_akPu4PF[3]={Imean_eta_akPu4PF,Lmean_eta_akPu4PF,Hmean_eta_akPu4PF};
	double *meanErr2D_eta_akPu4PF[3]={ImeanErr_eta_akPu4PF,LmeanErr_eta_akPu4PF,HmeanErr_eta_akPu4PF};
	double *sigma2D_eta_akPu4PF[3]={Isigma_eta_akPu4PF,Lsigma_eta_akPu4PF,Hsigma_eta_akPu4PF};
	double *sigmaErr2D_eta_akPu4PF[3]={IsigmaErr_eta_akPu4PF,LsigmaErr_eta_akPu4PF,HsigmaErr_eta_akPu4PF};

	//  const char *lineKind[]={"allJets","lightJets","bJets"};
	measurement="JES_akPu4PF";
	TMultiGraph *Gr_JESeta_akPu4PF =  Muti_Plot(measurement, lineKind , AllCut, Var_eta, 3, nEtaBins , etaBin , mean2D_eta_akPu4PF, meanErr2D_eta_akPu4PF);
	measurement="JER_akPu4PF";
	TMultiGraph *Gr_JEReta_akPu4PF =  Muti_Plot(measurement, lineKind , AllCut, Var_eta, 3, nEtaBins , etaBin , sigma2D_eta_akPu4PF, sigmaErr2D_eta_akPu4PF);


	////////////////////



	*/





		/*
			 double ptbin_gr[nPtBins];
			 double ptbinErr_gr[nPtBins];
			 for (int ibin=0; ibin<nPtBins; ibin++)
			 {
			 ptbin_gr[ibin]=(ptBin[ibin]+ptBin[ibin])/2;
			 ptbinErr_gr[ibin]=0;
		//				ptbin_gr_error= ;	
		}

		TCanvas *c_result = new TCanvas("c_result","c_result");
		c_result->Divide(1,2);
		c_result->cd(1);
		// TGraph *gr_mean = new TGraph(nPtBins,ptbin_gr,fit_mean); 
		int n= nPtBins;

		//			TGraph *gr_mean = new TGraph(n,ptbin_gr,fit_mean); 
		*/
		/*
			 TGraph *gr_meanR_pt[nJetA];
			 TGraphErrors *gr_meanR_pt[nJetA];
			 gr_meanR_pt[0] = new TGraph(n,ptbin_gr,fit_Rmean_pt[0]);
			 gr_meanR_pt[0]->SetLineColor(1);
		//			gr_meanR_pt[0]->Draw("AC*");
		gr_meanR_pt[1] = new TGraph(n,ptbin_gr,fit_Rmean_pt[1]);
		gr_meanR_pt[1]->SetLineColor(2);
		//      gr_meanR_pt[1]->Draw("CP*");  					
		gr_meanR_pt[2] = new TGraph(n,ptbin_gr,fit_Rmean_pt[2]);
		gr_meanR_pt[2]->SetLineColor(3);
		//      gr_meanR_pt[2]->Draw("CP*");
		gr_meanR_pt[3] = new TGraph(n,ptbin_gr,fit_Rmean_pt[3]);
		gr_meanR_pt[3]->SetLineColor(4);
		//      gr_meanR_pt[3]->Draw("CP*");
		*/
		/*
			 gStyle->SetEndErrorSize(3);
			 TGraphErrors *gr_meanR_pt[nJetA];
			 gr_meanR_pt[0] = new TGraphErrors(n,ptbin_gr,Imean,ptbinErr_gr,ImeanErr);
			 gr_meanR_pt[0]->SetName("gr_meanR_pt_0");
			 gr_meanR_pt[0]->SetLineColor(1);
			 gr_meanR_pt[0]->SetMarkerColor(1);
		//  gr_meanR_pt[0]->SetMarkerStyle(2);	
		//      gr_meanR_pt[0]->Draw("AC*");
		*/
		/*
			 gr_meanR_pt[1] = new TGraphErrors(n,ptbin_gr,fit_Rmean_pt[1],ptbinErr_gr,fit_RmeanErr_pt[1]);
			 gr_meanR_pt[1]->SetName("gr_meanR_pt_1");
			 gr_meanR_pt[1]->SetLineColor(2);
			 gr_meanR_pt[1]->SetMarkerColor(2);
		//  gr_meanR_pt[1]->SetMarkerStyle(3);
		//      gr_meanR_pt[1]->Draw("CP*");            
		gr_meanR_pt[2] = new TGraphErrors(n,ptbin_gr,fit_Rmean_pt[2],ptbinErr_gr,fit_RmeanErr_pt[2]);
		gr_meanR_pt[2]->SetName("gr_meanR_pt_2");
		gr_meanR_pt[2]->SetLineColor(3);
		gr_meanR_pt[2]->SetMarkerColor(3);
		//  gr_meanR_pt[2]->SetMarkerStyle(4);
		//      gr_meanR_pt[2]->Draw("CP*");
		gr_meanR_pt[3] = new TGraphErrors(n,ptbin_gr,fit_Rmean_pt[3],ptbinErr_gr,fit_RmeanErr_pt[3]);
		gr_meanR_pt[3]->SetName("gr_meanR_pt_3");
		gr_meanR_pt[3]->SetLineColor(4);
		gr_meanR_pt[3]->SetMarkerColor(4);
		//  gr_meanR_pt[3]->SetMarkerStyle(5);
		*/

		//      gr_meanR_pt[3]->Draw("CP*");
		/*
			 TMultiGraph *mg_Rmean_pt = new TMultiGraph();
			 mg_Rmean_pt->Add(gr_meanR_pt[0]);
		//	mg_Rmean_pt->Add(gr_meanR_pt[1]);
		//	mg_Rmean_pt->Add(gr_meanR_pt[2]);
		//	mg_Rmean_pt->Add(gr_meanR_pt[3]);
		mg_Rmean_pt->Draw("ALP");
		*/

		//  TChain *t_temp[nJetA]={tc_akPu4PF,tc_akVs4PF,tc_akPu4Calo,tc_akVs4Calo};

		/*
			 TLegend *leg_Rmean_pt = new TLegend(0.7,0.7,0.9,0.9);
		//	leg_Rmean_pt->SetHeader();
		leg_Rmean_pt->AddEntry("gr_meanR_pt_0", "tc_akPu4PF","l");
		leg_Rmean_pt->AddEntry("gr_meanR_pt_1", "tc_akPu4PF","l");
		leg_Rmean_pt->AddEntry("gr_meanR_pt_2", "tc_akPu4PF","l");
		leg_Rmean_pt->AddEntry("gr_meanR_pt_3", "tc_akPu4PF","l");
		leg_Rmean_pt->Draw();
		*/


		//			gr_mean->SetTitle("mean");
		//			gr_mean->Draw("AC*");

		//	c_result->cd(2);					
		// TGraph *gr_sigma = new TGraph(n,ptbin_gr,fit_sigma);
		// gr_sigma->SetTitle("sigma");
		// gr_sigma->Draw("AC*");



		////////////////
		//	eta part  //
		////////////////
















} // end void pt_resolution()

