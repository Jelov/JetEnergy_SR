// Cheng-Chieh Peng
// read output of runForest_PbPb_MC. 
// Analyze pt resolution in PbPb event.
// plot jtpt/refpt distribution for reftpt.
// Last Modified 2016 April. 21 


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
#include <TMath.h>
#include <TProfile.h>

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

  gStyle->SetOptFit(1111);
	cout<<"tc title = "<<tc->GetTitle()<<" ,Var = "<<Var<<" ,nVarBins = "<<nVarBins<<", Gcut = "<<Gcut<<endl;
	Can_Temp[counter] = new TCanvas(Form("Can_Temp_%i",counter));
	if(nVarBins<=9){Can_Temp[counter]->Divide(3,3);}
	else {Can_Temp[counter]->Divide(3,4);}


	TH1D *h_Ratio[nVarBins];
	TF1 *f_Ratio[nVarBins];
	double nRatiobins= 50;
	double minRatio=0;
	double maxRatio=3;

	// TLegend *legendfit[nVarBins]; 

	for(int ibin =0; ibin<nVarBins; ibin++)
	{
		Can_Temp[counter]->cd(ibin+1);
		double VarMin = VarBins_array[ibin];
		double VarMax = VarBins_array[ibin+1];

		h_Ratio[ibin] = new TH1D( Form("h_Ratio[%d]",ibin),Form("%s_%s_%i_%i",jetTitle.c_str(),Var.c_str(),(int)VarMin,(int)VarMax) ,nRatiobins,minRatio,maxRatio);  // h_Ration_%d ??
		h_Ratio[ibin]->Sumw2();

		TCut Varcut = Form("%s>%f && %s<%f", Var.c_str(), VarMin, Var.c_str(), VarMax);
		TCut allcut = Gcut && Varcut;
		cout<<"Varcut = "<<Varcut<<" ,allcut = "<<allcut<<endl;

		tc->Draw( Form("jtpt/refpt>>h_Ratio[%d]",ibin ) , allcut*"weight" );

		h_Ratio[ibin]->GetXaxis()->SetTitle(Form("%s, jtpt/refpt",Gcut.GetTitle()));
		mean[ibin]=h_Ratio[ibin]->GetMean();
		meanErr[ibin]=h_Ratio[ibin]->GetMeanError();
		sigma[ibin]=h_Ratio[ibin]->GetRMS();
		sigmaErr[ibin]=h_Ratio[ibin]->GetRMSError();
/*
		f_Ratio[ibin] = new TF1(Form("f_Ratio_%d",ibin), "gaus",0.4,1.6 );
		f_Ratio[ibin]->SetParameter(0,h_Ratio[ibin]->GetEntries()); // get number for normalization
		if(ibin==0){
			f_Ratio[ibin]->SetParameter(1,h_Ratio[ibin]->GetMean()) ;   // for mean
			f_Ratio[ibin]->SetParameter(2,h_Ratio[ibin]->GetStdDev()) ; // for sigma   
		}
		if(ibin>=1){
			f_Ratio[ibin]->SetParameter(1,mean[ibin-1]) ;   // for mean
			f_Ratio[ibin]->SetParameter(2,sigma[ibin-1]) ; // for sigma   
		} 
		h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");
		h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MRL");
		h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");
		h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");


		mean[ibin] = f_Ratio[ibin]->GetParameter(1);
		meanErr[ibin] = f_Ratio[ibin]->GetParError(1);
		sigma[ibin] = f_Ratio[ibin]->GetParameter(2);
		sigmaErr[ibin] = f_Ratio[ibin]->GetParError(2);
*/
	} // end   for(int ibin =0; ibin<nVarBins; ibin++)

//	Can_Temp[counter]->SaveAs(Form("./Plots/%s/fitPlots/fit_%s_%s_%s.pdf",Var.c_str(),Var.c_str(),jetTitle.c_str(),Gcut.GetTitle() ));

	counter++; 
}

void Muti_Plot(std::string mu_title,std::string selection,  const char **lineKind_Arr, TCut selectionC , std::string Var , const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
{ 

	char filename[]="JetESR_status.txt";
	fstream myfile;
	myfile.open (filename,ios::out|ios::app);

	double VarBinsCenter[nVarBins];
	double VarBinsErr[nVarBins];
	for (int ibin=0; ibin<nVarBins; ibin++)
	{
		VarBinsCenter[ibin]= (VarBins_array[ibin] + VarBins_array[ibin+1]) /2;
		VarBinsErr[ibin]=(VarBins_array[ibin+1]- VarBins_array[ibin])/2;
	}

	cout<<"lineKind_Arr 1 = "<<lineKind_Arr[0]<<" ,lineKind_Arr2 = "<<lineKind_Arr[1]<<endl;
	cout<<"mu_title = "<<mu_title<<" selectionC = "<< selectionC<<endl;

	Can_result[counter1] = new TCanvas(Form("Can_result_%i",counter1));
	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	TGraphErrors *gr_mean[ngr];
	legend[counter1] = new TLegend(0.65,0.75,0.85,0.88);

	double mutiGRYmax =0;
	double mutiGRYmin =999;

	for(int igr=0; igr<ngr; igr++)
	{
		gr_mean[igr] = new TGraphErrors(nVarBins, VarBinsCenter, yArr2[igr], VarBinsErr , yErrArr2[igr]);
		gr_mean[igr]->SetTitle(Form("some title_%i", igr));
		gr_mean[igr]->SetFillStyle(0);
		gr_mean[igr]->SetMarkerStyle(1);
		gr_mean[igr]->SetLineColor(igr+1);	
		gr_mean[igr]->SetMarkerColor(igr+1);
		mutiGR[counter1]->Add(gr_mean[igr]);
		legend[counter1]->AddEntry( gr_mean[igr] ,lineKind_Arr[igr],"l"); 
		double maxTemp = TMath::MaxElement(nVarBins,yArr2[igr]);
		double minTemp = TMath::MinElement(nVarBins,yArr2[igr]);
		if (maxTemp>mutiGRYmax){mutiGRYmax = maxTemp;}
    if (minTemp<mutiGRYmin){mutiGRYmin = minTemp;}

	}


	mutiGR[counter1]->Draw("AP");
	mutiGR[counter1]->GetXaxis()->SetTitle(Form("%s",Var.c_str())); // must after draw to create a vitual histogram like object to set title.
	if (mu_title.compare("JES") == 0)
		mutiGR[counter1]->GetYaxis()->SetTitle("#mu_{Reco./Gen.} akPu4PF");
	if (mu_title.compare("JER") == 0)
		mutiGR[counter1]->GetYaxis()->SetTitle("#sigma_{Reco./Gen.} akPu4PF");

	cout<<"ymax = "<<mutiGRYmax<<" , ymin = "<<mutiGRYmin<<endl;

	mutiGR[counter1]->Draw("AP"); // draw again to let all the settting on it.
	double ydiff = mutiGRYmax-mutiGRYmin;
  gPad->Modified();
	mutiGR[counter1]->SetMinimum(mutiGRYmin-ydiff*0.1);
	mutiGR[counter1]->SetMaximum(mutiGRYmax+ydiff*0.4);

	legend[counter1]->SetBorderSize(0);
/*
	TProfile *hf_qcd;
	TProfile *hf_bjt;
	TProfile *hf_csvbjt;

	if (mu_title.compare("JES")==0)
	{
  TCanvas *c_JES_prof = new TCanvas("c_JES_prof","c_JES_prof");
  c_JES_prof->Divide(2,2);
  TCut refpt200 = "refpt<200";
  hf_qcd = new TProfile("hf_qcd","hf_qcd",16,40,200,0.8,1.2);
  hf_bjt = new TProfile("hf_bjt","hf_bjt",16,40,200,0.8,1.2)
	hf_csvbjt =  new TProfile("hf_csvbjt","hf_csvbjt",16,40,200,0.8,1.2)
  
	}
*/

	legend[counter1]->Draw();

	TLegend *legend1 = new TLegend(0.3,0.75,0.6,0.88);
	legend1->AddEntry((TObject*)0,selection.c_str(),"");
	cout<<"Var = "<<Var<<endl;
	  if (Var.compare("jteta") == 0){ legend1->AddEntry((TObject*)0,"refpt>50","");}
		if (Var.compare("refpt") == 0){ legend1->AddEntry((TObject*)0,"|#eta_{jet}|<2.0","");}
	legend1->SetBorderSize(0);
	legend1->Draw();

	/*	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0}}");
			tex->SetNDC();
			tex->SetTextFont(43);
			tex->SetTextSize(26);
			tex->SetLineWidth(2);
			tex->Draw();
			*/

	Can_result[counter1]->SaveAs(Form("./Plots/%s/Simple_result_%s_%s_%s.pdf",Var.c_str(),mu_title.c_str(),selectionC.GetTitle() , Var.c_str())); 
	counter1++;
	cout<<"finish mutigraph"<<endl;
}

void jetE_SR_prof()
{

	char filename[]="JetESR_result.txt";
	fstream wout;
	wout.open (filename,ios::out|ios::app);

	counter=0;
	counter1=0;

	TChain *tc_bjt = new TChain("nt", "akPu4PF_bjt");
	TChain *tc_qcd = new TChain("nt", "akPu4PF_qcd");

	tc_bjt->Add("./source_root/mcPbbjtakPu4PF_inc.root");
	tc_qcd->Add("./source_root/mcPbqcdakPu4PF_inc.root");

	/*	TChain *tc_Hiak = new TChain("hiEvtAnalyzer/HiTree");
			tc_Hiak->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/1.root");
			tc_akPu4PF->AddFriend(tc_Hiak);
			tc_akVs4PF->AddFriend(tc_Hiak);
			tc_Hiak->Add("root://xrootd.unl.edu//store/user/rbi/merged/dgulhan-Pythia8_Dijet30_pp_TuneCUETP8M1_Hydjet_MinBias_5020GeV_RECODEBUG_758_PrivMC_forest_v28/0.root");
			tc_akPu4PF->Add("root://xrootd.unl.edu//store/user/rbi/merged/dgulhan-Pythia8_Dijet30_pp_TuneCUETP8M1_Hydjet_MinBias_5020GeV_RECODEBUG_758_PrivMC_forest_v28/0.root");
			tc_akPu4PF->AddFriend(tc_Hiak);
			*/
	//	TChain *t_temp;
	//	t_temp = tc_akPu4PF;

	double ptBin[] = {40,50,60,70,80,90,100,110,120,140,160,200};
	const int nPtBins = sizeof(ptBin)/sizeof(ptBin[0]) -1;

	double etaBin[] = {-2,-1.6,-1.2,-0.8,-0.4,0,0.4,0.8,1.2,1.6,2};
	const int nEtaBins = sizeof(etaBin)/sizeof(etaBin[0])-1;

	double centBin[] = {0,20,60,100,200};
	const int nCentBins = sizeof(centBin) / sizeof(centBin[0]) -1;

//	gStyle->SetOptFit(1111);
//	gStyle->SetOptFit(0);
	std::string Var_pt = "refpt";
	std::string Var_cent = "bin";
	std::string Var_eta = "jteta";

	std::string measurement="JES_akPu4PF";
	std::string selection ="Centrality 0-100%";
	const char *lineKind[]={"Inclusive Jets","bJets","csV>0.9 bJets","csV>0.9 lightJets"};


	TCut Cut_refpt = "refpt>50";
	TCut Cut_eta2 = "abs(jteta)<2";
	TCut Light_Cut = "refparton_flavorForB != 4 && refparton_flavorForB != 5";
	TCut B_Cut = "abs(refparton_flavorForB)==5";
	TCut tempAllCut = Cut_eta2;
	TCut csvtag = "discr_csvV1_>0.9";

	TCut AllCut;
	TCut Light_AllCut;
	TCut B_AllCut;
	TCut csvB_AllCut;
	TCut csvL_Allcut;

	double *VarBin;
	int nVarBins;

	std::string Var = Var_eta; // Var_pt for v.s refpt plot, Var_eta for v.s jteta plot
	if (Var.compare(Var_pt) == 0){
		VarBin = ptBin;
		nVarBins = nPtBins;  
		tempAllCut = tempAllCut;
	}
  if (Var.compare(Var_eta) == 0){
    VarBin = etaBin;
    nVarBins = nEtaBins;
    tempAllCut = tempAllCut && Cut_refpt ;
  }
	

	TCanvas *c_JES_prof = new TCanvas("c_JES_prof","c_JES_prof");
	c_JES_prof->Divide(2,2);
	TCut refpt200 = "refpt<200";
	TProfile *hf_qcd[4];
	TProfile *hf_bjt[4];
	TProfile *hf_csvbjt[4];

	for(int icentBin =0; icentBin <nCentBins ; icentBin++){
//		int icentBin=1;	
		TCut CentBinCut = Form("bin>=%f && bin<=%f",centBin[icentBin],centBin[icentBin+1]);	
		selection =Form("Centrality %i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2);

		AllCut = tempAllCut && CentBinCut;
		B_AllCut = B_Cut && AllCut;
		csvB_AllCut = csvtag && B_AllCut;
		csvL_Allcut = csvtag && Light_Cut && AllCut;	

		c_JES_prof->cd(icentBin+1);
//    gStyle->SetOptStat(0);
/*
	  if (Var.compare(Var_pt) == 0){
		hf_qcd[icentBin] = new TProfile(Form("hf_qcd_%i",(int)icentBin),Form("centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 16,40,200,0.8,1.2);
		tc_qcd->Draw(Form("jtpt/refpt:refpt>>hf_qcd_%i",(int)icentBin),(AllCut && refpt200)*"weight","prof");
		hf_qcd[icentBin]->SetLineColor(1);
		hf_qcd[icentBin]->SetMaximum(1.025);
		hf_qcd[icentBin]->SetMinimum(0.96);
		hf_qcd[icentBin]->GetXaxis()->SetTitle("refpt");
		hf_qcd[icentBin]->GetYaxis()->SetTitle("jtpt/refpt");
		hf_bjt[icentBin] = new TProfile(Form("hf_bjt_%i",(int)icentBin),Form("bjt_centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 16,40,200,0.8,1.2);
    tc_bjt->Draw(Form("jtpt/refpt:refpt>>hf_bjt_%i",(int)icentBin),(B_AllCut && refpt200)*"weight","profSAME");
		hf_bjt[icentBin]->SetLineColor(2);
    hf_csvbjt[icentBin] = new TProfile(Form("hf_csvbjt_%i",(int)icentBin),Form("csvbjt_centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 16,40,200,0.8,1.2);
		tc_bjt->Draw(Form("jtpt/refpt:refpt>>hf_csvbjt_%i",(int)icentBin),(csvB_AllCut && refpt200)*"weight","profSAME");
    hf_csvbjt[icentBin]->SetLineColor(3);
		TLegend *le_prof = new TLegend(0.65,0.75,0.85,0.88);
		le_prof->AddEntry(hf_qcd[icentBin],"Inclusive Jet","l");
		le_prof->AddEntry(hf_bjt[icentBin],"bJet","l");
    le_prof->AddEntry(hf_csvbjt[icentBin],"csv>0.9 bJet","l");
		le_prof->SetBorderSize(0);
		le_prof->Draw();
		
		}

    if (Var.compare(Var_eta) == 0){
    hf_qcd[icentBin] = new TProfile(Form("hf_qcd_%i",(int)icentBin),Form("centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 10,-2,2,0.8,1.2);
    tc_qcd->Draw(Form("jtpt/refpt:jteta>>hf_qcd_%i",(int)icentBin),(AllCut && refpt200)*"weight","prof");
    hf_qcd[icentBin]->SetLineColor(1);
    hf_qcd[icentBin]->SetMaximum(1.055);
    hf_qcd[icentBin]->SetMinimum(0.955);
    hf_qcd[icentBin]->GetXaxis()->SetTitle("jteta");
    hf_qcd[icentBin]->GetYaxis()->SetTitle("jtpt/refpt");
    hf_bjt[icentBin] = new TProfile(Form("hf_bjt_%i",(int)icentBin),Form("bjt_centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 10,-2,2,0.8,1.2);
    tc_bjt->Draw(Form("jtpt/refpt:jteta>>hf_bjt_%i",(int)icentBin),(B_AllCut && refpt200)*"weight","profSAME");
    hf_bjt[icentBin]->SetLineColor(2);
    hf_csvbjt[icentBin] = new TProfile(Form("hf_csvbjt_%i",(int)icentBin),Form("csvbjt_centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 10,-2,2,0.8,1.2);
    tc_bjt->Draw(Form("jtpt/refpt:jteta>>hf_csvbjt_%i",(int)icentBin),(csvB_AllCut && refpt200)*"weight","profSAME");
    hf_csvbjt[icentBin]->SetLineColor(3);
    TLegend *le_prof = new TLegend(0.65,0.75,0.85,0.88);
    le_prof->AddEntry(hf_qcd[icentBin],"Inclusive Jet","l");
    le_prof->AddEntry(hf_bjt[icentBin],"bJet","l");
    le_prof->AddEntry(hf_csvbjt[icentBin],"csv>0.9 bJet","l");
    le_prof->SetBorderSize(0);
    le_prof->Draw();

    }
*/




		double Imean_pt_akPu4PF[nVarBins];
		double ImeanErr_pt_akPu4PF[nVarBins];
		double Isigma_pt_akPu4PF[nVarBins];
		double IsigmaErr_pt_akPu4PF[nVarBins];
		fit_combine(tc_qcd , Var, VarBin , nVarBins, AllCut , Imean_pt_akPu4PF, ImeanErr_pt_akPu4PF, Isigma_pt_akPu4PF, IsigmaErr_pt_akPu4PF);

		double Bmean_pt_akPu4PF[nVarBins];
		double BmeanErr_pt_akPu4PF[nVarBins];
		double Bsigma_pt_akPu4PF[nVarBins];
		double BsigmaErr_pt_akPu4PF[nVarBins];  
		fit_combine(tc_bjt , Var, VarBin , nVarBins, B_AllCut , Bmean_pt_akPu4PF, BmeanErr_pt_akPu4PF, Bsigma_pt_akPu4PF, BsigmaErr_pt_akPu4PF);

		double csvBmean_pt_akPu4PF[nVarBins];
		double csvBmeanErr_pt_akPu4PF[nVarBins];
		double csvBsigma_pt_akPu4PF[nVarBins];
		double csvBsigmaErr_pt_akPu4PF[nVarBins];
		fit_combine(tc_bjt , Var, VarBin , nVarBins, csvB_AllCut , csvBmean_pt_akPu4PF, csvBmeanErr_pt_akPu4PF, csvBsigma_pt_akPu4PF, csvBsigmaErr_pt_akPu4PF);


		double csvLmean_pt_akPu4PF[nVarBins];
		double csvLmeanErr_pt_akPu4PF[nVarBins];
		double csvLsigma_pt_akPu4PF[nVarBins];
		double csvLsigmaErr_pt_akPu4PF[nVarBins];
		//  fit_combine(tc_qcd , Var, VarBin , nVarBins, csvL_Allcut , csvLmean_pt_akPu4PF, csvLmeanErr_pt_akPu4PF, csvLsigma_pt_akPu4PF, csvLsigmaErr_pt_akPu4PF);


		double *mean2D_pt_akPu4PF[4]={Imean_pt_akPu4PF , Bmean_pt_akPu4PF,csvBmean_pt_akPu4PF,csvLmean_pt_akPu4PF};
		double *meanErr2D_pt_akPu4PF[4]={ImeanErr_pt_akPu4PF, BmeanErr_pt_akPu4PF,csvBmeanErr_pt_akPu4PF,csvLmeanErr_pt_akPu4PF};
		double *sigma2D_pt_akPu4PF[4]={Isigma_pt_akPu4PF,Bsigma_pt_akPu4PF,csvBsigma_pt_akPu4PF,csvLsigma_pt_akPu4PF};
		double *sigmaErr2D_pt_akPu4PF[4]={IsigmaErr_pt_akPu4PF,BsigmaErr_pt_akPu4PF,csvBsigmaErr_pt_akPu4PF,csvLsigmaErr_pt_akPu4PF};

		measurement="JES";
		Muti_Plot(measurement,selection, lineKind , AllCut, Var, 3, nVarBins , VarBin , mean2D_pt_akPu4PF, meanErr2D_pt_akPu4PF);
		measurement="JER";
		Muti_Plot(measurement,selection, lineKind , AllCut, Var, 3, nVarBins , VarBin , sigma2D_pt_akPu4PF, sigmaErr2D_pt_akPu4PF);

	}// end for(icentBin)



} // end void jet_SR()

