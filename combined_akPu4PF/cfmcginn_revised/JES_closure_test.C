// test read the correction, and applied it.
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
#include <TNtuple.h>

void JES_closure_test(){


//  TChain *tc_bjt = new TChain("nt", "akPu4PF_bjt");
//  TChain *tc_qcd = new TChain("nt", "akPu4PF_qcd");

//  tc_bjt->Add("../source_root/mcPbbjtakPu4PF_inc.root");
//  tc_qcd->Add("../source_root/mcPbqcdakPu4PF_inc.root");
//	tc_qcd->Add("./test_root/mcPbqcdakPu4PF_inc.root");

	TFile *f_qcd = new TFile("./test_root/mcPbqcdakPu4PF_inc.root"	,"READ");
	TTree *tc_qcd = (TTree*)f_qcd->Get("nt");
//	TNtuple *tc_qcd = (TNtuple*)f_qcd->Get("nt");
	TFile * f_qcd_new = new TFile("./test_root/qcd_jtptcorr.root","RECREATE");
	TTree * t_qcd_new = new TTree("qcdnew","qcd jtptcorr");
//	TNtuple *t_qcd_new = new TNtuple("qcdnew","qcd jtptcorr");	

	float jtptcorr;
	t_qcd_new->Branch("jtptcorr",&jtptcorr,"jtptcorr/F");

	float bin, jtpt;
  tc_qcd->SetBranchAddress("bin", &bin);
  tc_qcd->SetBranchAddress("jtpt", &jtpt);

//	float new_v;
//	TBranch * nb = tc_qcd->Branch("new_v",&new_v,"new_v/F");
	int nentries = (int)tc_qcd->GetEntries();

	Bool_t initGetJESc = initGetResidualJetCorr("RESIDUALCORR_WLfit.root");

	for(int ientry = 0; ientry<nentries; ientry++)
	{
//		if(ientry%100000 ==0) cout<<"ientry = "<<ientry<<endl;
		tc_qcd->GetEntry(ientry);
		jtptcorr=getResCorrJetPt(jtpt,(int)bin,0);
	//	jtptcorr=jtpt/2;
		t_qcd_new->Fill();
	}
//	tc_qcd->Write("",TObject::kOverwrite); 
	f_qcd_new->cd();
	t_qcd_new->Write("",TObject::kOverwrite); // must add kOverwrite to avoid duplicate branches
//	f_qcd_new->Close();


	tc_qcd->AddFriend("qcdnew","./test_root/qcd_jtptcorr.root");

	TCanvas *c_jtpt = new TCanvas("c_jtpt","c_jtpt");
	c_jtpt->Divide(2,2);			
	c_jtpt->cd(1);
	tc_qcd->Draw("jtpt");
	c_jtpt->cd(2);
//	t_qcd_new->Draw("jtptcorr");
	c_jtpt->cd(3);
	tc_qcd->Draw("jtptcorr");
	c_jtpt->cd(4);
	tc_qcd->Draw("jtptcorr/refpt");

  f_qcd_new->Close();


}
