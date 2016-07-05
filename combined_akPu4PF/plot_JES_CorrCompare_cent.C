#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"
#include "TNamed.h"
#include "TMath.h"
#include <string>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TLine.h>


//const Int_t nCentBins = 3;
const int centBins[]= {0,10,30,100};
//int centBins[] = {0,5,10,20,30,50,100};
const int nCentBins = sizeof(centBins) / sizeof(centBins[0]) -1;



const Int_t nabsEtaBins = 1;
const Double_t absEtaBin[nabsEtaBins+1] = {0,1.5};


void plot_JES_CorrCompare_cent(){


  const std::string inFileName = "Jec_akPu4PF_cent.root";
  TFile* inFile_p = new TFile(inFileName.c_str(), "READ");
  TH1F* meanHist_p[nabsEtaBins];
  TH1F* RMSHist_p[nabsEtaBins];

	const std::string inFileName_yk1 = "./cfmcginn_revised/Jec_akPu4PF_Corr_yk1_cent.root";
  TFile* inFile_yk1 = new TFile(inFileName_yk1.c_str(), "READ");
  TH1F* meanHist_yk1[nabsEtaBins];  
	TH1F* RMSHist_yk1[nabsEtaBins];
//  TH1F* resolutionHist_yk1[nabsEtaBins][nCentBins];

  const std::string inFileName_yk2 = "./cfmcginn_revised/Jec_akPu4PF_Corr_yk2_cent.root";
  TFile* inFile_yk2 = new TFile(inFileName_yk2.c_str(), "READ");
  TH1F* meanHist_yk2[nabsEtaBins];
  TH1F* RMSHist_yk2[nabsEtaBins];
//  TH1F* resolutionHist_yk2[nabsEtaBins][nCentBins];


  const char* EtaRangeArr[] ={"eta0to15","eta15to20"};
  std::string EtaRange = "eta0to15";

  const char* etaselectionArr[]={"0<|#eta_{jet}|<1.5","1.5<|#eta_{jet}|<2.0"};
  std::string etaselection;

	std::string refptSelection="40<genJet p_{T}<60";
	const char* jettypeArr[]={"INC","B","csvB","FCRB"};

  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];
    cout<<"EtaRange = "<<EtaRange<<endl;
//  for(Int_t iCentBins = 0; iCentBins < nCentBins; iCentBins++){
		int iCentBins =0;
    meanHist_p[iabsEtaBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVcent_Inc_FitMean_akPu4PF_%s",EtaRange.c_str() ));
    meanHist_yk1[iabsEtaBins] = (TH1F*)inFile_yk1->Get(Form("jtRecoOverGenVcent_Inc_JecClosure_akPu4PF_%s",EtaRange.c_str() ));
    meanHist_yk2[iabsEtaBins] = (TH1F*)inFile_yk2->Get(Form("jtRecoOverGenVcent_Inc_JecClosure_akPu4PF_%s",EtaRange.c_str() ));
		cout<<"check1"<<endl;

    RMSHist_p[iabsEtaBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVcent_Inc_FitSigma_akPu4PF_%s", EtaRange.c_str() ));
    RMSHist_yk1[iabsEtaBins] = (TH1F*)inFile_yk1->Get(Form("jtRecoOverGenVcent_Inc_FitSigma_akPu4PF_%s", EtaRange.c_str() ));
    RMSHist_yk2[iabsEtaBins] = (TH1F*)inFile_yk2->Get(Form("jtRecoOverGenVcent_Inc_FitSigma_akPu4PF_%s", EtaRange.c_str() ));

    cout<<"check2"<<endl;

//    BmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_B_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
//    csvBmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_csvB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
//    FCRBmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
//    FCRcsvBmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRcsvB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));

//  } // end for iCentBins
  } // end for iabsEtaBins

TCanvas *C_plot[nabsEtaBins];
TLegend *le[nabsEtaBins][nCentBins];
TLegend *le1[nabsEtaBins][nCentBins];
gStyle->SetOptStat(0);

// plot part
  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];
    etaselection = etaselectionArr[iabsEtaBins];

    C_plot[iabsEtaBins] = new TCanvas(Form("C_plot_%s",EtaRange.c_str()), Form("C_plot_%s",EtaRange.c_str()), 600,600 );
    C_plot[iabsEtaBins]->Divide(1,1);

//  for(Int_t iCentBins = 0; iCentBins < nCentBins; iCentBins++){
		int iCentBins=0;
    C_plot[iabsEtaBins]->cd(iCentBins+1);
    le[iabsEtaBins][iCentBins] = new TLegend(0.65,0.65,0.88,0.88);
    le1[iabsEtaBins][iCentBins] = new TLegend(0.25,0.75,0.5,0.88);

    meanHist_p[iabsEtaBins]->GetXaxis()->SetRangeUser(0,100);
    meanHist_p[iabsEtaBins]->Draw("SAME");
    meanHist_p[iabsEtaBins]->SetTitle("");
    meanHist_p[iabsEtaBins]->SetMinimum(0.86);
    meanHist_p[iabsEtaBins]->SetMaximum(1.20);
	  meanHist_p[iabsEtaBins]->SetMarkerStyle(24);
    meanHist_p[iabsEtaBins]->GetXaxis()->SetTitle("Centrality");
//    meanHist_p[iabsEtaBins]->GetXaxis()->SetTitle("genJet p_{T} (GeV)");
    meanHist_p[iabsEtaBins]->GetYaxis()->SetTitle("#mu_{Reco./Gen.} akPu4PF");
    cout<<"check3"<<endl;

    meanHist_yk1[iabsEtaBins]->SetMarkerStyle(20);
    meanHist_yk1[iabsEtaBins]->SetLineColor(2);
    meanHist_yk1[iabsEtaBins]->SetMarkerColor(2);
    meanHist_yk1[iabsEtaBins]->Draw("SAME");
    cout<<"check4"<<endl;

    meanHist_yk2[iabsEtaBins]->SetMarkerStyle(22);
    meanHist_yk2[iabsEtaBins]->SetLineColor(4);
    meanHist_yk2[iabsEtaBins]->SetMarkerColor(4);
    meanHist_yk2[iabsEtaBins]->Draw("SAME");
    cout<<"check5"<<endl;


    le[iabsEtaBins][iCentBins]->AddEntry(meanHist_p[iabsEtaBins],"Inc. Jet","l");
    le[iabsEtaBins][iCentBins]->AddEntry(meanHist_yk1[iabsEtaBins],"Corr. Inc. Jet","l");
    le[iabsEtaBins][iCentBins]->AddEntry(meanHist_yk2[iabsEtaBins],"Corr.2 Inc. Jet","l");
    le[iabsEtaBins][iCentBins]->SetBorderSize(0);
    le[iabsEtaBins][iCentBins]->Draw();

//    le1[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,Form("Centrality %d-%d%%",centBins[iCentBins],centBins[iCentBins+1]),"");
    le1[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,etaselection.c_str(),"");
    le1[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,refptSelection.c_str(),"");
    le1[iabsEtaBins][iCentBins]->SetBorderSize(0);
    le1[iabsEtaBins][iCentBins]->Draw();
    cout<<"check6"<<endl;

    TLine *line = new TLine(0,1,100,1);
    line->SetLineStyle(7);
    line->Draw("SAME");

//}
}

    cout<<"check7"<<endl;


TCanvas *C_plot_res[nabsEtaBins];
TLegend *le_res[nabsEtaBins][nCentBins];
TLegend *le1_res[nabsEtaBins][nCentBins];
	
  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];
    etaselection = etaselectionArr[iabsEtaBins];

    C_plot_res[iabsEtaBins] = new TCanvas( Form("C_plot_res_%s",EtaRange.c_str()), Form("C_plot_res_%s",EtaRange.c_str()) ,600,600 );
    C_plot_res[iabsEtaBins]->Divide(1,1);

//  for(Int_t iCentBins = 0; iCentBins < nCentBins; iCentBins++){
		int iCentBins =0; 
   C_plot_res[iabsEtaBins]->cd(iCentBins+1);
    le_res[iabsEtaBins][iCentBins] = new TLegend(0.65,0.65,0.88,0.88);
    le1_res[iabsEtaBins][iCentBins] = new TLegend(0.25,0.75,0.5,0.88);

    RMSHist_p[iabsEtaBins]->GetXaxis()->SetRangeUser(0,100);
    RMSHist_p[iabsEtaBins]->Draw("SAME");
    RMSHist_p[iabsEtaBins]->SetTitle("");
    RMSHist_p[iabsEtaBins]->SetMinimum(0.05);
    RMSHist_p[iabsEtaBins]->SetMaximum(0.45);
    RMSHist_p[iabsEtaBins]->SetMarkerStyle(24);
    RMSHist_p[iabsEtaBins]->GetXaxis()->SetTitle("Centrality");
//    RMSHist_p[iabsEtaBins]->GetXaxis()->SetTitle("genJet p_{T} (GeV)");
    RMSHist_p[iabsEtaBins]->GetYaxis()->SetTitle("RMS/#mu_{Reco./Gen.} akPu4PF");
    RMSHist_yk1[iabsEtaBins]->SetMarkerStyle(20);
    RMSHist_yk1[iabsEtaBins]->SetLineColor(2);
    RMSHist_yk1[iabsEtaBins]->SetMarkerColor(2);
    RMSHist_yk1[iabsEtaBins]->Draw("SAME");
    RMSHist_yk2[iabsEtaBins]->SetMarkerStyle(22);
    RMSHist_yk2[iabsEtaBins]->SetLineColor(4);
    RMSHist_yk2[iabsEtaBins]->SetMarkerColor(4);
    RMSHist_yk2[iabsEtaBins]->Draw("SAME");


    le_res[iabsEtaBins][iCentBins]->AddEntry(RMSHist_p[iabsEtaBins],"Inc. Jet","l");
    le_res[iabsEtaBins][iCentBins]->AddEntry(RMSHist_yk1[iabsEtaBins],"Corr. Inc. Jet","l");
    le_res[iabsEtaBins][iCentBins]->AddEntry(RMSHist_yk2[iabsEtaBins],"Corr.2 Inc. Jet","l");
    le_res[iabsEtaBins][iCentBins]->SetBorderSize(0);
    le_res[iabsEtaBins][iCentBins]->Draw();

//    le1_res[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,Form("Centrality %d-%d%%",centBins[iCentBins],centBins[iCentBins+1]),"");
    le1_res[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,etaselection.c_str(),"");
    le1_res[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,refptSelection.c_str(),"");
    le1_res[iabsEtaBins][iCentBins]->SetBorderSize(0);
    le1_res[iabsEtaBins][iCentBins]->Draw();
//}
}




}
