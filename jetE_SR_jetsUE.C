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
		VarBinsCenter[ibin]= (VarBins_array[ibin] + VarBins_array[ibin+1]) /2/2;
		//		VarBinsErr[ibin]=0;
		VarBinsErr[ibin]=(VarBins_array[ibin+1]- VarBins_array[ibin])/2/2;
	}

	cout<<"lineKind_Arr 1 = "<<lineKind_Arr[0]<<" ,lineKind_Arr2 = "<<lineKind_Arr[1]<<endl;
	cout<<"mu_title = "<<mu_title<<" selectionC = "<< selectionC<<endl;

	Can_result[counter1] = new TCanvas(Form("Can_result_%i",counter1));
	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	TGraphErrors *gr_mean[ngr];
	legend[counter1] = new TLegend(0.65,0.7,0.85,0.85);

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

	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 &rept>30}}");
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
		VarBinsCenter[ibin]= (VarBins_array[ibin] + VarBins_array[ibin+1]) /2/2;
		//		VarBinsErr[ibin]=0;
		VarBinsErr[ibin]=(VarBins_array[ibin+1]- VarBins_array[ibin])/2/2;
	}

	cout<<"lineKind_Arr 1 = "<<lineKind_Arr[0]<<" ,lineKind_Arr2 = "<<lineKind_Arr[1]<<endl;
	cout<<"mu_title = "<<mu_title<<" selectionC = "<< selectionC<<endl;

	Can_result[counter1] = new TCanvas(Form("Can_result_%i",counter1));
	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	TGraphErrors *gr_mean[ngr];
	legend[counter1] = new TLegend(0.65,0.7,0.85,0.85);

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

	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 &refpt>30}}");
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


void Muti_Plot_ptScale(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
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
	legend[counter1] = new TLegend(0.65,0.7,0.85,0.85);

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
	mutiGR[counter1]->GetXaxis()->SetTitle("refpt"); // must after draw to create a vitual histogram like object to set title.
	mutiGR[counter1]->GetYaxis()->SetTitle("#mu_{Reco./Gen.}");
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend[counter1]->SetBorderSize(0);
	legend[counter1]->Draw();

	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 }}");
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


void Muti_Plot_ptResolution(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
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
	legend[counter1] = new TLegend(0.65,0.7,0.85,0.85);

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
	mutiGR[counter1]->GetXaxis()->SetTitle("refpt"); // must after draw to create a vitual histogram like object to set title.
	mutiGR[counter1]->GetYaxis()->SetTitle("#sigma_{Reco./Gen.}");
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend[counter1]->SetBorderSize(0);
	legend[counter1]->Draw();

	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 }}");
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


void Muti_Plot_etaScale(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
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
	legend[counter1] = new TLegend(0.68,0.5,0.88,0.65);

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
	mutiGR[counter1]->GetXaxis()->SetTitle("refeta"); // must after draw to create a vitual histogram like object to set title.
	mutiGR[counter1]->GetYaxis()->SetTitle("#mu_{Reco./Gen.}");
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend[counter1]->SetBorderSize(0);
	legend[counter1]->Draw();

	TLatex *tex = new TLatex(0.35,0.65,"#bf{#color[2]{refpt>30}}");
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


void Muti_Plot_etaResolution(std::string mu_title, const char **lineKind_Arr, TCut selectionC , std::string Var ,  const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
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
	legend[counter1] = new TLegend(0.65,0.7,0.85,0.85);

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
	mutiGR[counter1]->GetXaxis()->SetTitle("refeta"); // must after draw to create a vitual histogram like object to set title.
	mutiGR[counter1]->GetYaxis()->SetTitle("#sigma_{Reco./Gen.}");
	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	//	Can_result[counter1]->BuildLegend(0.7,0.7,0.9,0.9);
	legend[counter1]->SetBorderSize(0);
//	legend[counter1]->Draw();

	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{refpt>30}}");
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


void jetE_SR_jetsUE()
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
	const char*lineKindJet[]={"akPu4PF","akVs4PF","akPu4Calo","akVs4Calo"};


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
	////  compare different Jet_pt

  AllCut = Cut_eta2;
  Light_AllCut = Light_Cut && AllCut;
  Heavy_AllCut = Heavy_Cut && AllCut;

	double Imean_pt_akPu4PF[nPtBins];
	double ImeanErr_pt_akPu4PF[nPtBins];
	double Isigma_pt_akPu4PF[nPtBins];
	double IsigmaErr_pt_akPu4PF[nPtBins];
	fit_combine(tc_akPu4PF , Var_pt, ptBin , nPtBins, AllCut , Imean_pt_akPu4PF, ImeanErr_pt_akPu4PF, Isigma_pt_akPu4PF, IsigmaErr_pt_akPu4PF);


	double Imean_pt_akVs4PF[nPtBins];
	double ImeanErr_pt_akVs4PF[nPtBins];
	double Isigma_pt_akVs4PF[nPtBins];
	double IsigmaErr_pt_akVs4PF[nPtBins];
	fit_combine(tc_akVs4PF , Var_pt, ptBin , nPtBins, AllCut , Imean_pt_akVs4PF, ImeanErr_pt_akVs4PF, Isigma_pt_akVs4PF, IsigmaErr_pt_akVs4PF);

	double Imean_pt_akPu4Calo[nPtBins];
	double ImeanErr_pt_akPu4Calo[nPtBins];
	double Isigma_pt_akPu4Calo[nPtBins];
	double IsigmaErr_pt_akPu4Calo[nPtBins];
	fit_combine(tc_akPu4Calo , Var_pt, ptBin , nPtBins, AllCut , Imean_pt_akPu4Calo, ImeanErr_pt_akPu4Calo, Isigma_pt_akPu4Calo, IsigmaErr_pt_akPu4Calo);

	double Imean_pt_akVs4Calo[nPtBins];
	double ImeanErr_pt_akVs4Calo[nPtBins];
	double Isigma_pt_akVs4Calo[nPtBins];
	double IsigmaErr_pt_akVs4Calo[nPtBins];
	fit_combine(tc_akVs4Calo , Var_pt, ptBin , nPtBins, AllCut , Imean_pt_akVs4Calo, ImeanErr_pt_akVs4Calo, Isigma_pt_akVs4Calo, IsigmaErr_pt_akVs4Calo);


	double *mean2D_pt[4]={Imean_pt_akPu4PF,Imean_pt_akVs4PF,Imean_pt_akPu4Calo,Imean_pt_akVs4Calo};
	double *meanErr2D_pt[4]={ImeanErr_pt_akPu4PF,ImeanErr_pt_akVs4PF,ImeanErr_pt_akPu4Calo,ImeanErr_pt_akVs4Calo};
	double *sigma2D_pt[4]={Isigma_pt_akPu4PF,Isigma_pt_akVs4PF,Isigma_pt_akPu4Calo,Isigma_pt_akVs4Calo};
	double *sigmaErr2D_pt[4]={IsigmaErr_pt_akPu4PF,IsigmaErr_pt_akVs4PF,IsigmaErr_pt_akPu4Calo,IsigmaErr_pt_akVs4Calo};

	measurement="JES";

	Muti_Plot_ptScale(measurement, lineKindJet , AllCut, Var_pt, 4, nPtBins , ptBin , mean2D_pt, meanErr2D_pt);
	measurement="JER";
	Muti_Plot_ptResolution(measurement, lineKindJet , AllCut, Var_pt, 4, nPtBins , ptBin , sigma2D_pt, sigmaErr2D_pt);

	// end //


	////  compare different Jet_eta

	
  AllCut = Cut_pt30;
  Light_AllCut = Light_Cut && AllCut;
  Heavy_AllCut = Heavy_Cut && AllCut;

	double Imean_eta_akPu4PF[nEtaBins];
	double ImeanErr_eta_akPu4PF[nEtaBins];
	double Isigma_eta_akPu4PF[nEtaBins];
	double IsigmaErr_eta_akPu4PF[nEtaBins];
	fit_combine(tc_akPu4PF , Var_eta, etaBin , nEtaBins, AllCut , Imean_eta_akPu4PF, ImeanErr_eta_akPu4PF, Isigma_eta_akPu4PF, IsigmaErr_eta_akPu4PF);


	double Imean_eta_akVs4PF[nEtaBins];
	double ImeanErr_eta_akVs4PF[nEtaBins];
	double Isigma_eta_akVs4PF[nEtaBins];
	double IsigmaErr_eta_akVs4PF[nEtaBins];
	fit_combine(tc_akVs4PF , Var_eta, etaBin , nEtaBins, AllCut , Imean_eta_akVs4PF, ImeanErr_eta_akVs4PF, Isigma_eta_akVs4PF, IsigmaErr_eta_akVs4PF);

	double Imean_eta_akPu4Calo[nEtaBins];
	double ImeanErr_eta_akPu4Calo[nEtaBins];
	double Isigma_eta_akPu4Calo[nEtaBins];
	double IsigmaErr_eta_akPu4Calo[nEtaBins];
	fit_combine(tc_akPu4Calo , Var_eta, etaBin , nEtaBins, AllCut , Imean_eta_akPu4Calo, ImeanErr_eta_akPu4Calo, Isigma_eta_akPu4Calo, IsigmaErr_eta_akPu4Calo);

	double Imean_eta_akVs4Calo[nEtaBins];
	double ImeanErr_eta_akVs4Calo[nEtaBins];
	double Isigma_eta_akVs4Calo[nEtaBins];
	double IsigmaErr_eta_akVs4Calo[nEtaBins];
	fit_combine(tc_akVs4Calo , Var_eta, etaBin , nEtaBins, AllCut , Imean_eta_akVs4Calo, ImeanErr_eta_akVs4Calo, Isigma_eta_akVs4Calo, IsigmaErr_eta_akVs4Calo);


	double *mean2D_eta[4]={Imean_eta_akPu4PF,Imean_eta_akVs4PF,Imean_eta_akPu4Calo,Imean_eta_akVs4Calo};
	double *meanErr2D_eta[4]={ImeanErr_eta_akPu4PF,ImeanErr_eta_akVs4PF,ImeanErr_eta_akPu4Calo,ImeanErr_eta_akVs4Calo};
	double *sigma2D_eta[4]={Isigma_eta_akPu4PF,Isigma_eta_akVs4PF,Isigma_eta_akPu4Calo,Isigma_eta_akVs4Calo};
	double *sigmaErr2D_eta[4]={IsigmaErr_eta_akPu4PF,IsigmaErr_eta_akVs4PF,IsigmaErr_eta_akPu4Calo,IsigmaErr_eta_akVs4Calo};

	measurement="JES";

	Muti_Plot_etaScale(measurement, lineKindJet , AllCut, Var_eta, 4, nEtaBins , etaBin , mean2D_eta, meanErr2D_eta);
	measurement="JER";
	Muti_Plot_etaResolution(measurement, lineKindJet , AllCut, Var_eta, 4, nEtaBins , etaBin , sigma2D_eta, sigmaErr2D_eta);

	// end //


  ////  compare different Jet_cent


  AllCut = Cut_pt30 && Cut_eta2;
  Light_AllCut = Light_Cut && AllCut;
  Heavy_AllCut = Heavy_Cut && AllCut;

  double Imean_cent_akPu4PF[nCentBins];
  double ImeanErr_cent_akPu4PF[nCentBins];
  double Isigma_cent_akPu4PF[nCentBins];
  double IsigmaErr_cent_akPu4PF[nCentBins];
  fit_combine(tc_akPu4PF , Var_cent, centBin , nCentBins, AllCut , Imean_cent_akPu4PF, ImeanErr_cent_akPu4PF, Isigma_cent_akPu4PF, IsigmaErr_cent_akPu4PF);


  double Imean_cent_akVs4PF[nCentBins];
  double ImeanErr_cent_akVs4PF[nCentBins];
  double Isigma_cent_akVs4PF[nCentBins];
  double IsigmaErr_cent_akVs4PF[nCentBins];
  fit_combine(tc_akVs4PF , Var_cent, centBin , nCentBins, AllCut , Imean_cent_akVs4PF, ImeanErr_cent_akVs4PF, Isigma_cent_akVs4PF, IsigmaErr_cent_akVs4PF);

  double Imean_cent_akPu4Calo[nCentBins];
  double ImeanErr_cent_akPu4Calo[nCentBins];
  double Isigma_cent_akPu4Calo[nCentBins];
  double IsigmaErr_cent_akPu4Calo[nCentBins];
  fit_combine(tc_akPu4Calo , Var_cent, centBin , nCentBins, AllCut , Imean_cent_akPu4Calo, ImeanErr_cent_akPu4Calo, Isigma_cent_akPu4Calo, IsigmaErr_cent_akPu4Calo);

  double Imean_cent_akVs4Calo[nCentBins];
  double ImeanErr_cent_akVs4Calo[nCentBins];
  double Isigma_cent_akVs4Calo[nCentBins];
  double IsigmaErr_cent_akVs4Calo[nCentBins];
  fit_combine(tc_akVs4Calo , Var_cent, centBin , nCentBins, AllCut , Imean_cent_akVs4Calo, ImeanErr_cent_akVs4Calo, Isigma_cent_akVs4Calo, IsigmaErr_cent_akVs4Calo);


  double *mean2D_cent[4]={Imean_cent_akPu4PF,Imean_cent_akVs4PF,Imean_cent_akPu4Calo,Imean_cent_akVs4Calo};
  double *meanErr2D_cent[4]={ImeanErr_cent_akPu4PF,ImeanErr_cent_akVs4PF,ImeanErr_cent_akPu4Calo,ImeanErr_cent_akVs4Calo};
  double *sigma2D_cent[4]={Isigma_cent_akPu4PF,Isigma_cent_akVs4PF,Isigma_cent_akPu4Calo,Isigma_cent_akVs4Calo};
  double *sigmaErr2D_cent[4]={IsigmaErr_cent_akPu4PF,IsigmaErr_cent_akVs4PF,IsigmaErr_cent_akPu4Calo,IsigmaErr_cent_akVs4Calo};

  measurement="JES";

  Muti_Plot_centScale(measurement, lineKindJet , AllCut, Var_cent, 4, nCentBins , centBin , mean2D_cent, meanErr2D_cent);
  measurement="JER";
  Muti_Plot_centResolution(measurement, lineKindJet , AllCut, Var_cent, 4, nCentBins , centBin , sigma2D_cent, sigmaErr2D_cent);

  // end //



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

