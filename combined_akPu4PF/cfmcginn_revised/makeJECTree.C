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
#include "getResidualJetCorr.h"
#include <TLine.h>
#include "yetkin_correction.h"


void makeJECTree(){


	int cal_corrjtpt = 3;

  TFile *f_qcd = new TFile("../source_root/mcPbqcdakPu4PF_inc.root","READ");
  TFile *f_bjt = new TFile("../source_root/mcPbbfaakPu4PF_inc.root","READ");

  TTree *tc_qcd = (TTree*)f_qcd->Get("nt");
  TTree *tc_bjt = (TTree*)f_bjt->Get("nt");

  if (cal_corrjtpt != 0 ){
    TFile *f_qcd_JEScorr;
    TTree *t_qcd_JEScorr;

    TFile *f_bjt_JEScorr;
    TTree *t_bjt_JEScorr;

    if (cal_corrjtpt == 1 ){
      f_qcd_JEScorr = new TFile("./JEScorr_root/qcd_JEScorr.root","RECREATE");
      t_qcd_JEScorr = new TTree("qcd_JEScorr","qcd jtptcorr");

      f_bjt_JEScorr = new TFile("./JEScorr_root/bjt_JEScorr.root","RECREATE");
      t_bjt_JEScorr = new TTree("bjt_JEScorr","bjt jtptcorr");
    }

    if (cal_corrjtpt == 2 ){
      f_qcd_JEScorr = new TFile("./JEScorr_root/qcd_JEScorr_yk.root","RECREATE");
      t_qcd_JEScorr = new TTree("qcd_JEScorr","qcd jtptcorr");

      f_bjt_JEScorr = new TFile("./JEScorr_root/bjt_JEScorr_yk.root","RECREATE");
      t_bjt_JEScorr = new TTree("bjt_JEScorr","bjt jtptcorr");
    }

    if (cal_corrjtpt == 3 ){
      f_qcd_JEScorr = new TFile("./JEScorr_root/qcd_JEScorr_yk2.root","RECREATE");
      t_qcd_JEScorr = new TTree("qcd_JEScorr","qcd jtptcorr");

      f_bjt_JEScorr = new TFile("./JEScorr_root/bjt_JEScorr_yk2.root","RECREATE");
      t_bjt_JEScorr = new TTree("bjt_JEScorr","bjt jtptcorr");
    }



    float bin_qcd, jtpt_qcd, jteta_qcd, refpt_qcd;
    float bin_bjt, jtpt_bjt, jteta_bjt, refpt_bjt;

    tc_qcd->SetBranchAddress("bin", &bin_qcd );
    tc_qcd->SetBranchAddress("jtpt", &jtpt_qcd);
    tc_qcd->SetBranchAddress("jteta",&jteta_qcd);
    tc_qcd->SetBranchAddress("refpt",&refpt_qcd);
    tc_bjt->SetBranchAddress("bin", &bin_bjt);
    tc_bjt->SetBranchAddress("jtpt", &jtpt_bjt);
    tc_bjt->SetBranchAddress("jteta", &jteta_bjt);
    tc_bjt->SetBranchAddress("refpt",&refpt_bjt);


    float jtptcorr_qcd;
    float jtptcorr_B;
    float jtptcorr_csvB;
    float jtptcorr_FCRB;
    //  float jtptcorr_FCRcsvB;

    t_qcd_JEScorr->Branch("jtptCorr",&jtptcorr_qcd,"jtptcorr_qcd/F");
    t_bjt_JEScorr->Branch("jtptCorrB", &jtptcorr_B,"jtptcorr_B/F");
    t_bjt_JEScorr->Branch("jtptCorrcsvB", &jtptcorr_csvB,"jtptcorr_csvB/F");
    t_bjt_JEScorr->Branch("jtptCorrFCRB", &jtptcorr_FCRB,"jtptcorr_FCRB/F");
    //  t_bjt_JEScorr->Branch("jtptCorrFCRcsvB", &jtptcorr_FCRcsvB,"jtptcorr_FCRcsvB/F");

    Bool_t initGetJESc = 1;
    if( cal_corrjtpt == 1){
      initGetJESc = initGetResidualJetCorr("RESIDUALCORR.root");
    }
    if( cal_corrjtpt == 2){
//      initGetJESc = initGetResidualJetCorr_yk();
			initGetJESc = 1;
		//	Corrections ykCorr1;
    }
		Corrections ykCorr1;
    Corrections2 ykCorr2;


    if (initGetJESc ==0){
      cout<<"fail to open correction root file, process termineated and exit"<<endl;
      return;
    }

    int qcd_nentries = (int)tc_qcd->GetEntries();
    int bjt_nentries = (int)tc_bjt->GetEntries();

    for(int ientry = 0; ientry<qcd_nentries; ientry++)
    {
      tc_qcd->GetEntry(ientry);
    if( cal_corrjtpt == 1){
      jtptcorr_qcd=getResCorrJetPt(jtpt_qcd,(int)bin_qcd,jteta_qcd,0,refpt_qcd);
    }
    if( cal_corrjtpt == 2){
//      jtptcorr_qcd=getResCorrJetPt_yk(jtpt_qcd,(int)bin_qcd,jteta_qcd,0,refpt_qcd);
				jtptcorr_qcd=jtpt_qcd*ykCorr1.factor(jtpt_qcd,jteta_qcd,(int)bin_qcd);
    }
    if( cal_corrjtpt == 3){
        jtptcorr_qcd=jtpt_qcd*ykCorr2.factor(jtpt_qcd,jteta_qcd,(int)bin_qcd);
    }

      t_qcd_JEScorr->Fill();
    }
      cout<<"qcd finish"<<endl;

    f_qcd_JEScorr->cd();
    t_qcd_JEScorr->Write("",TObject::kOverwrite);
    f_qcd_JEScorr->Close();

    for (int ientry = 0; ientry<bjt_nentries; ientry++)
    {
      tc_bjt->GetEntry(ientry);
    if( cal_corrjtpt == 1){
      jtptcorr_B=getResCorrJetPt(jtpt_bjt,(int)bin_bjt,jteta_bjt,1,refpt_bjt);
      jtptcorr_csvB=getResCorrJetPt(jtpt_bjt,(int)bin_bjt,jteta_bjt,2,refpt_bjt);
      jtptcorr_FCRB=getResCorrJetPt(jtpt_bjt,(int)bin_bjt,jteta_bjt,3,refpt_bjt);
      //    jtptcorr_FCRcsvB=getResCorrJetPt(jtpt_qcd,(int)bin_qcd,4);
    }

    if( cal_corrjtpt == 2){
    	jtptcorr_B=jtpt_bjt*ykCorr1.factor(jtpt_bjt,jteta_bjt,(int)bin_bjt);
      jtptcorr_csvB=jtpt_bjt*ykCorr1.factor(jtpt_bjt,jteta_bjt,(int)bin_bjt);
      jtptcorr_FCRB=jtpt_bjt*ykCorr1.factor(jtpt_bjt,jteta_bjt,(int)bin_bjt);


//      jtptcorr_B=getResCorrJetPt_yk(jtpt_bjt,(int)bin_bjt,jteta_bjt,1,refpt_bjt);
//      jtptcorr_csvB=getResCorrJetPt_yk(jtpt_bjt,(int)bin_bjt,jteta_bjt,2,refpt_bjt);
//      jtptcorr_FCRB=getResCorrJetPt_yk(jtpt_bjt,(int)bin_bjt,jteta_bjt,3,refpt_bjt);
      //    jtptcorr_FCRcsvB=getResCorrJetPt(jtpt_qcd,(int)bin_qcd,4);
    }
   if( cal_corrjtpt == 3){
      jtptcorr_B=jtpt_bjt*ykCorr2.factor(jtpt_bjt,jteta_bjt,(int)bin_bjt);
      jtptcorr_csvB=jtpt_bjt*ykCorr2.factor(jtpt_bjt,jteta_bjt,(int)bin_bjt);
      jtptcorr_FCRB=jtpt_bjt*ykCorr2.factor(jtpt_bjt,jteta_bjt,(int)bin_bjt);
    }

      t_bjt_JEScorr->Fill();
    }
      cout<<"bjt finish"<<endl;

    f_bjt_JEScorr->cd();
    t_bjt_JEScorr->Write("",TObject::kOverwrite);
    f_bjt_JEScorr->Close();
  } // end if (cal_corrjtpt != 0 )




}
