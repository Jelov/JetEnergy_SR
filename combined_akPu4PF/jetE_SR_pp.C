
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

void fit_combine(TChain *tc, std::string Var,std::string filltype, const double * VarBins_array , const int nVarBins , TCut Gcut,  double *mean, double *meanErr, double *sigma, double *sigmaErr ){

	std::string jetTitle=tc->GetTitle();

	gStyle->SetOptFit(1111);
	cout<<"tc title = "<<tc->GetTitle()<<" ,Var = "<<Var<<" ,nVarBins = "<<nVarBins<<", Gcut = "<<Gcut<<endl;
	Can_Temp[counter] = new TCanvas(Form("Can_Temp_%i",counter));
	if(nVarBins<=9){Can_Temp[counter]->Divide(3,3);}
	else if(nVarBins<=12) {Can_Temp[counter]->Divide(3,4);}
	else if(nVarBins<=16) {Can_Temp[counter]->Divide(4,4);}
	else {Can_Temp[counter]->Divide(5,4);}


	TH1D *h_Ratio[nVarBins];
	TF1 *f_Ratio[nVarBins];
	double nRatiobins= 50;
	double minRatio=0;
	double maxRatio=3;
	if (filltype.compare("residue")==0){
		minRatio= -2;
		maxRatio=2;	
	}

	// TLegend *legendfit[nVarBins]; 

	for(int ibin =0; ibin<nVarBins; ibin++)
	{
		Can_Temp[counter]->cd(ibin+1);
		double VarMin = VarBins_array[ibin];
		double VarMax = VarBins_array[ibin+1];
		int fit_histo =0;
		//    if( Var.compare("refpt")==0 && (VarMax<=40 || VarMin >=400) ){fit_histo=0;} 


		h_Ratio[ibin] = new TH1D( Form("h_Ratio[%d]",ibin),Form("%s_%s_%i_%i",jetTitle.c_str(),Var.c_str(),(int)VarMin,(int)VarMax) ,nRatiobins,minRatio,maxRatio);  // h_Ration_%d ??
		h_Ratio[ibin]->Sumw2();

		TCut Varcut = Form("%s>%f && %s<%f", Var.c_str(), VarMin, Var.c_str(), VarMax);
		TCut allcut = Gcut && Varcut;
		cout<<"Varcut = "<<Varcut<<" ,allcut = "<<allcut<<endl;

		if (filltype.compare("residue")==0){
			tc->Draw( Form("(jtpt/refpt -1)>>h_Ratio[%d]",ibin ) , allcut*"weight" );
		}
		if (filltype.compare("ratio")==0){
			tc->Draw( Form("jtpt/refpt>>h_Ratio[%d]",ibin ) , allcut*"weight" );
		}

		double mean_temp=h_Ratio[ibin]->GetMean();
		double rms_temp=h_Ratio[ibin]->GetRMS();

		h_Ratio[ibin]->GetXaxis()->SetTitle(Form("%s, jtpt/refpt",Gcut.GetTitle()));


		if (fit_histo==1){
			if (filltype.compare("ratio")==0){
				f_Ratio[ibin] = new TF1(Form("f_Ratio_%d",ibin), "gaus",mean_temp-3*rms_temp,mean_temp+3*rms_temp );}
			if (filltype.compare("residue")==0){
				f_Ratio[ibin] = new TF1(Form("f_Ratio_%d",ibin), "gaus",-3*rms_temp,3*rms_temp );}


			f_Ratio[ibin]->SetParameter(0,h_Ratio[ibin]->GetEntries()); // get number for normalization
			if(ibin==0){
				if (filltype.compare("ratio")==0){
					f_Ratio[ibin]->SetParameter(1,h_Ratio[ibin]->GetMean()) ;   // for mean
					f_Ratio[ibin]->SetParameter(2,h_Ratio[ibin]->GetRMS()) ; // for sigma   
				}
				if (filltype.compare("residue")==0){
					f_Ratio[ibin]->SetParameter(1,h_Ratio[ibin]->GetMean()-1) ;   // for mean
					f_Ratio[ibin]->SetParameter(2,h_Ratio[ibin]->GetRMS()) ; // for sigma
				}	
			}
			if(ibin>=1){
				f_Ratio[ibin]->SetParameter(1,mean[ibin-1]) ;   // for mean
				f_Ratio[ibin]->SetParameter(2,sigma[ibin-1]) ; // for sigma   
			} 
			//		h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");
			//		h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MRL");
			h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");
			h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"WL Q MR");
			h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");
			h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");
			h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");


			if (f_Ratio[ibin]->GetProb() < .01){cout<<"f1_Ratio[ibin]->GetProb() <0.01"<<endl;}

			if(f_Ratio[ibin]->GetParError(1) > 0.05 || f_Ratio[ibin]->GetProb() < .001){
				f_Ratio[ibin] = new TF1(Form("f_Ratio_%d",ibin), "gaus",mean_temp-2*rms_temp,mean_temp+2*rms_temp );
				f_Ratio[ibin]->SetParameter(1,h_Ratio[ibin]->GetMean());
				f_Ratio[ibin]->SetParameter(2,h_Ratio[ibin]->GetRMS()) ; 	
				h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");
				h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MRL");
				h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"WL Q MR");
				h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");
				h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");
				h_Ratio[ibin]->Fit(Form("f_Ratio_%d",ibin),"MR");


			}

			/*
				 legendfit[ibin]= new TLegend(0.2,0.2,0.7,0.4);
				 legendfit[ibin]->AddEntry((TObject*)0,Form("%s",Gcut.GetTitle()),"");
				 legendfit[ibin]->SetBorderSize(0);
				 legendfit[ibin]->Draw();
				 */


			mean[ibin] = f_Ratio[ibin]->GetParameter(1);
			meanErr[ibin] = f_Ratio[ibin]->GetParError(1);
			sigma[ibin] = f_Ratio[ibin]->GetParameter(2)/mean[ibin];
			sigmaErr[ibin] = f_Ratio[ibin]->GetParError(2)/mean[ibin];


			if(mean[ibin] >=2 || meanErr[ibin] >=2){ // prevent bad value from fit
				mean[ibin]=h_Ratio[ibin]->GetMean();
				meanErr[ibin] = h_Ratio[ibin]->GetMeanError();
				sigma[ibin]=h_Ratio[ibin]->GetRMS()/mean[ibin];
				sigmaErr[ibin] =h_Ratio[ibin]->GetRMSError()/mean[ibin];

			}


		}// end if fit_histo ==1

		else if(fit_histo == 0){
			mean[ibin]=h_Ratio[ibin]->GetMean();
			meanErr[ibin] = h_Ratio[ibin]->GetMeanError();
			sigma[ibin]=h_Ratio[ibin]->GetRMS()/mean[ibin];
			sigmaErr[ibin] =h_Ratio[ibin]->GetRMSError()/mean[ibin];


		}




	} // end   for(int ibin =0; ibin<nVarBins; ibin++)

	Can_Temp[counter]->SaveAs(Form("./Plots/pp/%s/fitPlots/fit_%s_%s_%s.pdf",Var.c_str(),Var.c_str(),jetTitle.c_str(),Gcut.GetTitle() ));

	counter++; 
}

void Muti_Plot(std::string mu_title,std::string filltype,std::string etaselection,std::string selection,  const char **lineKind_Arr, TCut selectionC , std::string Var , const int ngr, const int nVarBins, double * VarBins_array , double **yArr2, double **yErrArr2)
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
	//	mutiGR[counter1] = new TMultiGraph("name",Form("%s",mu_title.c_str()));
	mutiGR[counter1] = new TMultiGraph(Form("%s",mu_title.c_str()),"");

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
	if (Var.compare("refpt") ==0)
		mutiGR[counter1]->GetXaxis()->SetTitle("genJet p_{T} (GeV)");
	if (mu_title.compare("JES") == 0)
		mutiGR[counter1]->GetYaxis()->SetTitle("#mu_{Reco./Gen.} ak4PF_pp");
	if (mu_title.compare("JER") == 0)
		mutiGR[counter1]->GetYaxis()->SetTitle("#sigma_{Reco./Gen.} ak4PF_pp");

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

	TLegend *legend1 = new TLegend(0.25,0.78,0.5,0.88);
	//	legend1->AddEntry((TObject*)0,selection.c_str(),"");
	cout<<"Var = "<<Var<<endl;
	if (Var.compare("jteta") == 0){ legend1->AddEntry((TObject*)0,"refpt>50","");}
	//	if (Var.compare("refpt") == 0){ legend1->AddEntry((TObject*)0,"|#eta_{jet}|<2.0","");}
	if (Var.compare("refpt") == 0){ legend1->AddEntry((TObject*)0,etaselection.c_str(),"");}
	legend1->SetBorderSize(0);
	legend1->Draw();

	/*	TLatex *tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0}}");
			tex->SetNDC();
			tex->SetTextFont(43);
			tex->SetTextSize(26);
			tex->SetLineWidth(2);
			tex->Draw();
			*/

	Can_result[counter1]->SaveAs(Form("./Plots/pp/%s/result_%s_%s_%s.pdf",Var.c_str(),mu_title.c_str(),selectionC.GetTitle() , Var.c_str())); 
	counter1++;
	cout<<"finish mutigraph"<<endl;
}

void jetE_SR_pp()
{

	char filename[]="JetESR_result.txt";
	fstream wout;
	wout.open (filename,ios::out|ios::app);

	counter=0;
	counter1=0;

	TChain *tc_bjt = new TChain("nt", "ak4PF_bjt");
	TChain *tc_qcd = new TChain("nt", "ak4PF_qcd");

	// tc_bjt->Add("./source_root/mcPbbjtakPu4PF_inc.root");
	tc_bjt->Add("./source_root/mcppbfaak4PF_inc.root");
	tc_qcd->Add("./source_root/mcppqcdak4PF_inc.root");

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


	//	double ptBin[] = {40,50,60,70,80,90,100,110,120,140,160,200,260,350};
	double ptBin[] = {20,30,40,50,60,70,80,90,100,110,120,140,160,200,250,310,400,600};

	//	double ptBin[] ={60,70,80,90,100,110,120,140,160,200};
	const int nPtBins = sizeof(ptBin)/sizeof(ptBin[0]) -1;

	double etaBin[] = {-2,-1.6,-1.2,-0.8,-0.4,0,0.4,0.8,1.2,1.6,2};
	const int nEtaBins = sizeof(etaBin)/sizeof(etaBin[0])-1;

	double absEtaBin[] = {0,1.5,2};
	const int nabsEtaBins = sizeof(absEtaBin)/sizeof(absEtaBin[0])-1;

	//	int centBin[] = {0,20,60,100,200};
	// int centBin[] = {0,20,60,200};
//	int centBin[]= {0,10,20,30,40,60,100,140,200};
  int centBin[] = {0,10,20,40,60,100,200};

	const int nCentBins = sizeof(centBin) / sizeof(centBin[0]) -1;

	//TFile *f_jec = TFile("Jec_akPu4PF","RECREATE");
	TH1F* jtRecoOverGenVPt_Inc_FitMean_ak4PF_pp[nabsEtaBins];
	TH1F* jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp[nabsEtaBins];

	TH1F* jtRecoOverGenVPt_B_FitMean_ak4PF_pp[nabsEtaBins];
	TH1F* jtRecoOverGenVRecoPt_B_FitMean_ak4PF_pp[nabsEtaBins];

	TH1F* jtRecoOverGenVPt_csvB_FitMean_ak4PF_pp[nabsEtaBins];
	TH1F* jtRecoOverGenVRecoPt_csvB_FitMean_ak4PF_pp[nabsEtaBins];

	TH1F* jtRecoOverGenVPt_FCRB_FitMean_ak4PF_pp[nabsEtaBins];
	TH1F* jtRecoOverGenVRecoPt_FCRB_FitMean_ak4PF_pp[nabsEtaBins];


	TH1F* jtRecoOverGenVPt_Inc_FitSigma_ak4PF_pp[nabsEtaBins];
	TH1F* jtRecoOverGenVPt_B_FitSigma_ak4PF_pp[nabsEtaBins];
	TH1F* jtRecoOverGenVPt_csvB_FitSigma_ak4PF_pp[nabsEtaBins];
	TH1F* jtRecoOverGenVPt_FCRB_FitSigma_ak4PF_pp[nabsEtaBins];


	//  TH1F* jtRecoOverGenVPt_FCRcsvB_FitMean_ak4PF_pp[nCentBins];
	//  TH1F* jtRecoOverGenVRecoPt_FCRcsvB_FitMean_ak4PF_pp[nCentBins];



	//	gStyle->SetOptFit(1111);
	//	gStyle->SetOptFit(0);
	std::string Var_refpt = "refpt";
	std::string Var_cent = "bin";
	std::string Var_jteta = "jteta";
	std::string Var_jtpt ="jtpt";

	std::string Var=Var_refpt;
	std::string fill_type = "ratio"; //ratio or residue
	//std::string fill_type = "residue"; //ratio or residue
	const char *Var_array[]={"refpt","jteta"};

	std::string measurement="JES_ak4PF_pp";
	std::string selection ="Centrality 0-100%";
	std::string eta_selection="|#eta_{jet}|<2.0";
	const char *eta_selectionArr[]={"0<|#eta_{jet}|<1.5","1.5|#eta_{jet}|<2.0"};


	//	const char *lineKind[]={"Inclusive Jets","bJets","csV>0.9 bJets","FCR bJets","FCR csV>0.9 bJets"};
	const char *lineKind[]={"Inclusive Jets","bJets","FCR bJets"};


	TCut Cut_refpt = "refpt>20";
	TCut Cut_eta2 = "abs(jteta)<2";
	TCut Light_Cut = "refparton_flavorForB != 4 && refparton_flavorForB != 5";
	TCut B_Cut = "abs(refparton_flavorForB)==5";
	TCut tempAllCut1 = Cut_eta2;
	TCut csvtag = "discr_csvV1_>0.9";
	TCut FCR_Cut = "bProdCode==1";

	TCut tempAllCut;
	TCut AllCut;
	TCut Light_AllCut;
	TCut B_AllCut;
	TCut csvB_AllCut;
	TCut csvL_Allcut;
	TCut FCRB_AllCut;
	TCut FCRcsvB_AllCut;

	double *VarBin;
	int nVarBins;
	VarBin = ptBin;
	nVarBins = nPtBins;



	for (int iVartype = 0 ; iVartype <2; iVartype++){
		Var = Var_array[iVartype];
		cout<<"Var = "<<Var<<endl;

		//	std::string Var = Var_refpt; // Var_refpt for v.s refpt plot, Var_jteta for v.s jteta plot
		if(Var.compare(Var_jtpt) ==0){
			VarBin = ptBin;
			nVarBins = nPtBins;
			tempAllCut = tempAllCut1 && Cut_refpt;
		}

		if (Var.compare(Var_refpt) == 0){
			VarBin = ptBin;
			nVarBins = nPtBins;  
			tempAllCut = tempAllCut1;
		}
		if (Var.compare(Var_jteta) == 0){
			VarBin = etaBin;
			nVarBins = nEtaBins;
			tempAllCut = tempAllCut1 && Cut_refpt ;
		}

		TCanvas *c_JES_prof = new TCanvas("c_JES_prof","c_JES_prof");
		c_JES_prof->Divide(2,2);
		TCut refpt200 = "refpt<200";
		TProfile *hf_qcd[4];
		TProfile *hf_bjt[4];
		TProfile *hf_csvbjt[4];
		// double hf_ymax =5;
		// double hf_ymin =0;

		//		for(int icentBin =0; icentBin <nCentBins ; icentBin++)
		for(int iabsEtaBins = 0 ; iabsEtaBins<nabsEtaBins; iabsEtaBins++)
		{
			eta_selection = eta_selectionArr[iabsEtaBins];
			TCut absEtaBinCut = Form("abs(jteta)>=%f && abs(jteta)<%f",absEtaBin[iabsEtaBins],absEtaBin[iabsEtaBins+1]);

			for(int icentBin =0; icentBin <1; icentBin++)	// no centbin in pp
			{
				TCut CentBinCut = Form("bin>=%d && bin<=%d",centBin[icentBin],centBin[icentBin+1]);	
				selection =Form("Centrality %i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2);

				//			AllCut = tempAllCut && CentBinCut;
				AllCut = tempAllCut &&absEtaBinCut ;
				B_AllCut = B_Cut && AllCut;
				csvB_AllCut = csvtag && B_AllCut;
				csvL_Allcut = csvtag && Light_Cut && AllCut;	
				FCRB_AllCut = FCR_Cut && B_AllCut;
				FCRcsvB_AllCut = FCR_Cut && csvB_AllCut;


				// c_JES_prof->cd(icentBin+1);
				//    gStyle->SetOptStat(0);

				// for profile plot
				/*
					 if (Var.compare(Var_refpt) == 0){
					 hf_qcd[icentBin] = new TProfile(Form("hf_qcd_%i",(int)icentBin),Form("centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 16,40,200,0,3);
					 tc_qcd->Draw(Form("jtpt/refpt:refpt>>hf_qcd_%i",(int)icentBin),(AllCut && refpt200)*"weight","prof");
					 hf_qcd[icentBin]->SetLineColor(1);
					 hf_qcd[icentBin]->SetMaximum(1.025);
					 hf_qcd[icentBin]->SetMinimum(0.96);
					 hf_qcd[icentBin]->GetXaxis()->SetTitle("refpt");
					 hf_qcd[icentBin]->GetYaxis()->SetTitle("jtpt/refpt");
					 hf_bjt[icentBin] = new TProfile(Form("hf_bjt_%i",(int)icentBin),Form("bjt_centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 16,40,200,0,3);
					 tc_bjt->Draw(Form("jtpt/refpt:refpt>>hf_bjt_%i",(int)icentBin),(B_AllCut && refpt200)*"weight","profSAME");
					 hf_bjt[icentBin]->SetLineColor(2);
					 hf_csvbjt[icentBin] = new TProfile(Form("hf_csvbjt_%i",(int)icentBin),Form("csvbjt_centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 16,40,200,0,3);
					 tc_bjt->Draw(Form("jtpt/refpt:refpt>>hf_csvbjt_%i",(int)icentBin),(csvB_AllCut && refpt200)*"weight","profSAME");
					 hf_csvbjt[icentBin]->SetLineColor(3);
					 TLegend *le_prof = new TLegend(0.65,0.75,0.85,0.88);
					 le_prof->AddEntry(hf_qcd[icentBin],"Inclusive Jet","l");
					 le_prof->AddEntry(hf_bjt[icentBin],"bJet","l");
					 le_prof->AddEntry(hf_csvbjt[icentBin],"csv>0.9 bJet","l");
					 le_prof->SetBorderSize(0);
					 le_prof->Draw();

					 }

					 if (Var.compare(Var_jteta) == 0){
					 hf_qcd[icentBin] = new TProfile(Form("hf_qcd_%i",(int)icentBin),Form("centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 10,-2,2,0,3);
					 tc_qcd->Draw(Form("jtpt/refpt:jteta>>hf_qcd_%i",(int)icentBin),(AllCut && refpt200)*"weight","prof");
					 hf_qcd[icentBin]->SetLineColor(1);
					 hf_qcd[icentBin]->SetMaximum(1.055);
					 hf_qcd[icentBin]->SetMinimum(0.955);
					 hf_qcd[icentBin]->GetXaxis()->SetTitle("jteta");
					 hf_qcd[icentBin]->GetYaxis()->SetTitle("jtpt/refpt");
					 hf_bjt[icentBin] = new TProfile(Form("hf_bjt_%i",(int)icentBin),Form("bjt_centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 10,-2,2,0,3);
					 tc_bjt->Draw(Form("jtpt/refpt:jteta>>hf_bjt_%i",(int)icentBin),(B_AllCut && refpt200)*"weight","profSAME");
					 hf_bjt[icentBin]->SetLineColor(2);
					 hf_csvbjt[icentBin] = new TProfile(Form("hf_csvbjt_%i",(int)icentBin),Form("csvbjt_centrality%i-%i%%",(int)centBin[icentBin]/2,(int)centBin[icentBin+1]/2), 10,-2,2,0,3);
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


				double Imean_pt_ak4PF_pp[nVarBins];
				double ImeanErr_pt_ak4PF_pp[nVarBins];
				double Isigma_pt_ak4PF_pp[nVarBins];
				double IsigmaErr_pt_ak4PF_pp[nVarBins];
				fit_combine(tc_qcd , Var,fill_type, VarBin , nVarBins, AllCut , Imean_pt_ak4PF_pp, ImeanErr_pt_ak4PF_pp, Isigma_pt_ak4PF_pp, IsigmaErr_pt_ak4PF_pp);

				double Bmean_pt_ak4PF_pp[nVarBins];
				double BmeanErr_pt_ak4PF_pp[nVarBins];
				double Bsigma_pt_ak4PF_pp[nVarBins];
				double BsigmaErr_pt_ak4PF_pp[nVarBins];  
				fit_combine(tc_bjt , Var,fill_type, VarBin , nVarBins, B_AllCut , Bmean_pt_ak4PF_pp, BmeanErr_pt_ak4PF_pp, Bsigma_pt_ak4PF_pp, BsigmaErr_pt_ak4PF_pp);

				double csvBmean_pt_ak4PF_pp[nVarBins];
				double csvBmeanErr_pt_ak4PF_pp[nVarBins];
				double csvBsigma_pt_ak4PF_pp[nVarBins];
				double csvBsigmaErr_pt_ak4PF_pp[nVarBins];
				fit_combine(tc_bjt , Var,fill_type, VarBin , nVarBins, csvB_AllCut , csvBmean_pt_ak4PF_pp, csvBmeanErr_pt_ak4PF_pp, csvBsigma_pt_ak4PF_pp, csvBsigmaErr_pt_ak4PF_pp);

				double FCRBmean_pt_ak4PF_pp[nVarBins];
				double FCRBmeanErr_pt_ak4PF_pp[nVarBins];
				double FCRBsigma_pt_ak4PF_pp[nVarBins];
				double FCRBsigmaErr_pt_ak4PF_pp[nVarBins];
				fit_combine(tc_bjt , Var,fill_type, VarBin , nVarBins, FCRB_AllCut , FCRBmean_pt_ak4PF_pp, FCRBmeanErr_pt_ak4PF_pp, FCRBsigma_pt_ak4PF_pp, FCRBsigmaErr_pt_ak4PF_pp);

				double FCRcsvBmean_pt_ak4PF_pp[nVarBins];
				double FCRcsvBmeanErr_pt_ak4PF_pp[nVarBins];
				double FCRcsvBsigma_pt_ak4PF_pp[nVarBins];
				double FCRcsvBsigmaErr_pt_ak4PF_pp[nVarBins];
				//	fit_combine(tc_bjt , Var,fill_type, VarBin , nVarBins, FCRcsvB_AllCut , FCRcsvBmean_pt_ak4PF_pp, FCRcsvBmeanErr_pt_ak4PF_pp, FCRcsvBsigma_pt_ak4PF_pp, FCRcsvBsigmaErr_pt_ak4PF_pp);


				double csvLmean_pt_ak4PF_pp[nVarBins];
				double csvLmeanErr_pt_ak4PF_pp[nVarBins];
				double csvLsigma_pt_ak4PF_pp[nVarBins];
				double csvLsigmaErr_pt_ak4PF_pp[nVarBins];
				//  fit_combine(tc_qcd , Var,fill_type, VarBin , nVarBins, csvL_Allcut , csvLmean_pt_ak4PF_pp, csvLmeanErr_pt_ak4PF_pp, csvLsigma_pt_ak4PF_pp, csvLsigmaErr_pt_ak4PF_pp);

				/*
					 double *mean2D_pt_ak4PF_pp[4]={Imean_pt_ak4PF_pp , Bmean_pt_ak4PF_pp,csvBmean_pt_ak4PF_pp,FCRBmean_pt_ak4PF_pp};
					 double *meanErr2D_pt_ak4PF_pp[4]={ImeanErr_pt_ak4PF_pp, BmeanErr_pt_ak4PF_pp,csvBmeanErr_pt_ak4PF_pp,FCRBmeanErr_pt_ak4PF_pp};
					 double *sigma2D_pt_ak4PF_pp[4]={Isigma_pt_ak4PF_pp,Bsigma_pt_ak4PF_pp,csvBsigma_pt_ak4PF_pp,FCRBsigma_pt_ak4PF_pp};
					 double *sigmaErr2D_pt_ak4PF_pp[4]={IsigmaErr_pt_ak4PF_pp,BsigmaErr_pt_ak4PF_pp,csvBsigmaErr_pt_ak4PF_pp,FCRBsigmaErr_pt_ak4PF_pp};
					 */

				double *mean2D_pt_ak4PF_pp[3]={Imean_pt_ak4PF_pp , Bmean_pt_ak4PF_pp,FCRBmean_pt_ak4PF_pp};
				double *meanErr2D_pt_ak4PF_pp[3]={ImeanErr_pt_ak4PF_pp, BmeanErr_pt_ak4PF_pp,FCRBmeanErr_pt_ak4PF_pp};
				double *sigma2D_pt_ak4PF_pp[3]={Isigma_pt_ak4PF_pp,Bsigma_pt_ak4PF_pp,FCRBsigma_pt_ak4PF_pp};
				double *sigmaErr2D_pt_ak4PF_pp[3]={IsigmaErr_pt_ak4PF_pp,BsigmaErr_pt_ak4PF_pp,FCRBsigmaErr_pt_ak4PF_pp};



				measurement="JES";
				Muti_Plot(measurement,fill_type,eta_selection,selection, lineKind , AllCut, Var, 3, nVarBins , VarBin , mean2D_pt_ak4PF_pp, meanErr2D_pt_ak4PF_pp);
				measurement="JER";
				Muti_Plot(measurement,fill_type,eta_selection,selection, lineKind , AllCut, Var, 3, nVarBins , VarBin , sigma2D_pt_ak4PF_pp, sigmaErr2D_pt_ak4PF_pp);


				// save output to histogram
				if(Var.compare(Var_refpt)==0) {
					jtRecoOverGenVPt_Inc_FitMean_ak4PF_pp[iabsEtaBins]= new TH1F(Form("jtRecoOverGenVPt_Inc_FitMean_ak4PF_pp_eta%i",iabsEtaBins),Form("jtRecoOverGenVPt_Inc_FitMean_ak4PF_pp_eta%i",iabsEtaBins),nVarBins,VarBin )	;
					jtRecoOverGenVPt_B_FitMean_ak4PF_pp[iabsEtaBins]= new TH1F(Form("jtRecoOverGenVPt_B_FitMean_ak4PF_pp_eta%i",iabsEtaBins),Form("jtRecoOverGenVPt_B_FitMean_ak4PF_pp_eta%i",iabsEtaBins),nVarBins,VarBin )  ;
					jtRecoOverGenVPt_csvB_FitMean_ak4PF_pp[iabsEtaBins]= new TH1F(Form("jtRecoOverGenVPt_csvB_FitMean_ak4PF_pp_eta%i",iabsEtaBins),Form("jtRecoOverGenVPt_csvB_FitMean_ak4PF_pp_eta%i",iabsEtaBins),nVarBins,VarBin )  ;
					jtRecoOverGenVPt_FCRB_FitMean_ak4PF_pp[iabsEtaBins]= new TH1F(Form("jtRecoOverGenVPt_FCRB_FitMean_ak4PF_pp_eta%i",iabsEtaBins),Form("jtRecoOverGenVPt_FCRB_FitMean_ak4PF_pp_eta%i",iabsEtaBins),nVarBins,VarBin )  ;
					//     jtRecoOverGenVPt_FCRcsvB_FitMean_ak4PF_pp[icentBin]= new TH1F(Form("jtRecoOverGenVPt_FCRcsvB_FitMean_ak4PF_pp_%i",icentBin),Form("jtRecoOverGenVPt_FCRcsvB_FitMean_ak4PF_pp_%i",icentBin),nVarBins,VarBin )  ;

					jtRecoOverGenVPt_Inc_FitSigma_ak4PF_pp[iabsEtaBins]= new TH1F(Form("jtRecoOverGenVPt_Inc_FitSigma_ak4PF_pp_eta%i",iabsEtaBins),Form("jtRecoOverGenVPt_Inc_FitSigma_ak4PF_pp_eta%i",iabsEtaBins),nVarBins,VarBin ) ;
					jtRecoOverGenVPt_B_FitSigma_ak4PF_pp[iabsEtaBins]= new TH1F(Form("jtRecoOverGenVPt_B_FitSigma_ak4PF_pp_eta%i",iabsEtaBins),Form("jtRecoOverGenVPt_B_FitSigma_ak4PF_pp_eta%i",iabsEtaBins),nVarBins,VarBin )  ;
					jtRecoOverGenVPt_csvB_FitSigma_ak4PF_pp[iabsEtaBins]= new TH1F(Form("jtRecoOverGenVPt_csvB_FitSigma_ak4PF_pp_eta%i",iabsEtaBins),Form("jtRecoOverGenVPt_csvB_FitSigma_ak4PF_pp_eta%i",iabsEtaBins),nVarBins,VarBin )  ;
					jtRecoOverGenVPt_FCRB_FitSigma_ak4PF_pp[iabsEtaBins]= new TH1F(Form("jtRecoOverGenVPt_FCRB_FitSigma_ak4PF_pp_eta%i",iabsEtaBins),Form("jtRecoOverGenVPt_FCRB_FitSigma_ak4PF_pp_eta%i",iabsEtaBins),nVarBins,VarBin )  ;


				}

				/*		if(Var.compare(Var_jtpt)==0) {
							jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp[icentBin] = new TH1F(Form("jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp_%i",icentBin),Form("jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp_%i",icentBin),nVarBins,VarBin);
							jtRecoOverGenVRecoPt_B_FitMean_ak4PF_pp[icentBin] = new TH1F(Form("jtRecoOverGenVRecoPt_B_FitMean_ak4PF_pp_%i",icentBin),Form("jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp_%i",icentBin),nVarBins,VarBin);
							jtRecoOverGenVRecoPt_csvB_FitMean_ak4PF_pp[icentBin] = new TH1F(Form("jtRecoOverGenVRecoPt_csvB_FitMean_ak4PF_pp_%i",icentBin),Form("jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp_%i",icentBin),nVarBins,VarBin);
							jtRecoOverGenVRecoPt_FCRB_FitMean_ak4PF_pp[icentBin] = new TH1F(Form("jtRecoOverGenVRecoPt_FCRB_FitMean_ak4PF_pp_%i",icentBin),Form("jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp_%i",icentBin),nVarBins,VarBin);
				//        jtRecoOverGenVRecoPt_FCRcsvB_FitMean_ak4PF_pp[icentBin] = new TH1F(Form("jtRecoOverGenVRecoPt_FCRcsvB_FitMean_ak4PF_pp_%i",icentBin),Form("jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp_%i",icentBin),nVarBins,VarBin);
				}*/

				for(int iVarBins = 0; iVarBins < nVarBins; iVarBins++){
					if(Var.compare(Var_refpt)==0) {
						jtRecoOverGenVPt_Inc_FitMean_ak4PF_pp[iabsEtaBins]->SetBinContent(iVarBins+1, Imean_pt_ak4PF_pp[iVarBins]);
						jtRecoOverGenVPt_Inc_FitMean_ak4PF_pp[iabsEtaBins]->SetBinError(iVarBins+1, ImeanErr_pt_ak4PF_pp[iVarBins]);

						jtRecoOverGenVPt_B_FitMean_ak4PF_pp[iabsEtaBins]->SetBinContent(iVarBins+1, Bmean_pt_ak4PF_pp[iVarBins]);
						jtRecoOverGenVPt_B_FitMean_ak4PF_pp[iabsEtaBins]->SetBinError(iVarBins+1, BmeanErr_pt_ak4PF_pp[iVarBins]);

						jtRecoOverGenVPt_csvB_FitMean_ak4PF_pp[iabsEtaBins]->SetBinContent(iVarBins+1, csvBmean_pt_ak4PF_pp[iVarBins]);
						jtRecoOverGenVPt_csvB_FitMean_ak4PF_pp[iabsEtaBins]->SetBinError(iVarBins+1, csvBmeanErr_pt_ak4PF_pp[iVarBins]);

						jtRecoOverGenVPt_FCRB_FitMean_ak4PF_pp[iabsEtaBins]->SetBinContent(iVarBins+1, FCRBmean_pt_ak4PF_pp[iVarBins]);
						jtRecoOverGenVPt_FCRB_FitMean_ak4PF_pp[iabsEtaBins]->SetBinError(iVarBins+1, FCRBmeanErr_pt_ak4PF_pp[iVarBins]);


						jtRecoOverGenVPt_Inc_FitSigma_ak4PF_pp[iabsEtaBins]->SetBinContent(iVarBins+1, Isigma_pt_ak4PF_pp[iVarBins]);
						jtRecoOverGenVPt_Inc_FitSigma_ak4PF_pp[iabsEtaBins]->SetBinError(iVarBins+1, IsigmaErr_pt_ak4PF_pp[iVarBins]);

						jtRecoOverGenVPt_B_FitSigma_ak4PF_pp[iabsEtaBins]->SetBinContent(iVarBins+1, Bsigma_pt_ak4PF_pp[iVarBins]);
						jtRecoOverGenVPt_B_FitSigma_ak4PF_pp[iabsEtaBins]->SetBinError(iVarBins+1, BsigmaErr_pt_ak4PF_pp[iVarBins]);

						jtRecoOverGenVPt_csvB_FitSigma_ak4PF_pp[iabsEtaBins]->SetBinContent(iVarBins+1, csvBsigma_pt_ak4PF_pp[iVarBins]);
						jtRecoOverGenVPt_csvB_FitSigma_ak4PF_pp[iabsEtaBins]->SetBinError(iVarBins+1, csvBsigmaErr_pt_ak4PF_pp[iVarBins]);

						jtRecoOverGenVPt_FCRB_FitSigma_ak4PF_pp[iabsEtaBins]->SetBinContent(iVarBins+1, FCRBsigma_pt_ak4PF_pp[iVarBins]);
						jtRecoOverGenVPt_FCRB_FitSigma_ak4PF_pp[iabsEtaBins]->SetBinError(iVarBins+1, FCRBsigmaErr_pt_ak4PF_pp[iVarBins]);



						//         jtRecoOverGenVPt_FCRcsvB_FitMean_ak4PF_pp[icentBin]->SetBinContent(iVarBins+1, FCRcsvBmean_pt_ak4PF_pp[iVarBins]);
						//          jtRecoOverGenVPt_FCRcsvB_FitMean_ak4PF_pp[icentBin]->SetBinError(iVarBins+1, FCRcsvBmeanErr_pt_ak4PF_pp[iVarBins]);
					}
					/*
						 if(Var.compare(Var_jtpt)==0) {
						 jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp[icentBin]->SetBinContent(iVarBins+1, Imean_pt_ak4PF_pp[iVarBins]);
						 jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp[icentBin]->SetBinError(iVarBins+1, ImeanErr_pt_ak4PF_pp[iVarBins]);

						 jtRecoOverGenVRecoPt_B_FitMean_ak4PF_pp[icentBin]->SetBinContent(iVarBins+1, Bmean_pt_ak4PF_pp[iVarBins]);
						 jtRecoOverGenVRecoPt_B_FitMean_ak4PF_pp[icentBin]->SetBinError(iVarBins+1, BmeanErr_pt_ak4PF_pp[iVarBins]);

						 jtRecoOverGenVRecoPt_csvB_FitMean_ak4PF_pp[icentBin]->SetBinContent(iVarBins+1, csvBmean_pt_ak4PF_pp[iVarBins]);
						 jtRecoOverGenVRecoPt_csvB_FitMean_ak4PF_pp[icentBin]->SetBinError(iVarBins+1, csvBmeanErr_pt_ak4PF_pp[iVarBins]);

						 jtRecoOverGenVRecoPt_FCRB_FitMean_ak4PF_pp[icentBin]->SetBinContent(iVarBins+1, FCRBmean_pt_ak4PF_pp[iVarBins]);
						 jtRecoOverGenVRecoPt_FCRB_FitMean_ak4PF_pp[icentBin]->SetBinError(iVarBins+1, FCRBmeanErr_pt_ak4PF_pp[iVarBins]);

				//          jtRecoOverGenVRecoPt_FCRcsvB_FitMean_ak4PF_pp[icentBin]->SetBinContent(iVarBins+1, FCRcsvBmean_pt_ak4PF_pp[iVarBins]);
				//          jtRecoOverGenVRecoPt_FCRcsvB_FitMean_ak4PF_pp[icentBin]->SetBinError(iVarBins+1, FCRcsvBmeanErr_pt_ak4PF_pp[iVarBins]);

				}*/

				}

			}// end for(icentBin)
		}// end for(iabsEtaBins)
	}// end   for (int iVartype = 0 ; iVartype <2; iVartype++{

	// write histogram into output files
	int savefile =1;
	if (savefile ==1){
		std::string EtaRange = "eta0to15";
		TFile *f_jec = new TFile("Jec_ak4PF_pp.root","RECREATE");

		for(int iabsEtaBins = 0 ; iabsEtaBins <nabsEtaBins ;iabsEtaBins++){
			if (iabsEtaBins ==1) { EtaRange ="eta15to20";}
			//	for(int icentBin =0; icentBin <nCentBins ; icentBin++){
			jtRecoOverGenVPt_Inc_FitMean_ak4PF_pp[iabsEtaBins]->Write(Form("jtRecoOverGenVPt_Inc_FitMean_ak4PF_pp_%s",EtaRange.c_str()) );	
			//		jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp[iabsEtaBins][icentBin]->Write(Form("jtRecoOverGenVRecoPt_Inc_FitMean_ak4PF_pp_cent%dto%d_h", centBin[icentBin]/2, centBin[icentBin+1]/2 ) );

			jtRecoOverGenVPt_B_FitMean_ak4PF_pp[iabsEtaBins]->Write(Form("jtRecoOverGenVPt_B_FitMean_ak4PF_pp_%s",EtaRange.c_str()) );
			//   jtRecoOverGenVRecoPt_B_FitMean_ak4PF_pp[iabsEtaBins][icentBin]->Write(Form("jtRecoOverGenVRecoPt_B_FitMean_ak4PF_pp_cent%dto%d_h", centBin[icentBin]/2, centBin[icentBin+1]/2 ) );

			jtRecoOverGenVPt_csvB_FitMean_ak4PF_pp[iabsEtaBins]->Write(Form("jtRecoOverGenVPt_csvB_FitMean_ak4PF_pp_%s",EtaRange.c_str()) );
			// jtRecoOverGenVRecoPt_csvB_FitMean_ak4PF_pp[iabsEtaBins][icentBin]->Write(Form("jtRecoOverGenVRecoPt_csvB_FitMean_ak4PF_pp_cent%dto%d_h", centBin[icentBin]/2, centBin[icentBin+1]/2 ) );

			jtRecoOverGenVPt_FCRB_FitMean_ak4PF_pp[iabsEtaBins]->Write(Form("jtRecoOverGenVPt_FCRB_FitMean_ak4PF_pp_%s",EtaRange.c_str()) );
			//    jtRecoOverGenVRecoPt_FCRB_FitMean_ak4PF_pp[iabsEtaBins][icentBin]->Write(Form("jtRecoOverGenVRecoPt_FCRB_FitMean_ak4PF_pp_cent%dto%d_h", centBin[icentBin]/2, centBin[icentBin+1]/2 ) );

			jtRecoOverGenVPt_Inc_FitSigma_ak4PF_pp[iabsEtaBins]->Write(Form("jtRecoOverGenVPt_Inc_FitSigma_ak4PF_pp_%s",EtaRange.c_str()) );
			jtRecoOverGenVPt_B_FitSigma_ak4PF_pp[iabsEtaBins]->Write(Form("jtRecoOverGenVPt_B_FitSigma_ak4PF_pp_%s",EtaRange.c_str()) );
			jtRecoOverGenVPt_csvB_FitSigma_ak4PF_pp[iabsEtaBins]->Write(Form("jtRecoOverGenVPt_csvB_FitSigma_ak4PF_pp_%s",EtaRange.c_str()) );
			jtRecoOverGenVPt_FCRB_FitSigma_ak4PF_pp[iabsEtaBins]->Write(Form("jtRecoOverGenVPt_FCRB_FitSigma_ak4PF_pp_%s",EtaRange.c_str()) );

			//    jtRecoOverGenVPt_FCRcsvB_FitMean_ak4PF_pp[icentBin]->Write(Form("jtRecoOverGenVPt_FCRcsvB_FitMean_ak4PF_pp_cent%dto%d_h", centBin[icentBin]/2, centBin[icentBin+1]/2 ) );
			//   jtRecoOverGenVRecoPt_FCRcsvB_FitMean_ak4PF_pp[icentBin]->Write(Form("jtRecoOverGenVRecoPt_FCRcsvB_FitMean_ak4PF_pp_cent%dto%d_h", centBin[icentBin]/2, centBin[icentBin+1]/2 ) );

		} // end for iabsEtaBins.

		f_jec->Write();
		f_jec->Close();
		} // end if savefile

	} // end void jet_SR()

