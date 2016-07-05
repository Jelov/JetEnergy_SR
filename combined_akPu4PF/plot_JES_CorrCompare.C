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


void plot_JES_CorrCompare(){


  const std::string inFileName = "Jec_akPu4PF.root";
  TFile* inFile_p = new TFile(inFileName.c_str(), "READ");
  TH1F* meanHist_p[nabsEtaBins][nCentBins];
  TH1F* RMSHist_p[nabsEtaBins][nCentBins];
	TH1F* resolutionHist_p[nabsEtaBins][nCentBins];

	const std::string inFileName_yk1 = "./cfmcginn_revised/Jec_akPu4PF_Corr_yk1.root";
  TFile* inFile_yk1 = new TFile(inFileName_yk1.c_str(), "READ");
  TH1F* meanHist_yk1[nabsEtaBins][nCentBins];  
	TH1F* RMSHist_yk1[nabsEtaBins][nCentBins];
//  TH1F* resolutionHist_yk1[nabsEtaBins][nCentBins];

  const std::string inFileName_yk2 = "./cfmcginn_revised/Jec_akPu4PF_Corr_yk2.root";
  TFile* inFile_yk2 = new TFile(inFileName_yk2.c_str(), "READ");
  TH1F* meanHist_yk2[nabsEtaBins][nCentBins];
  TH1F* RMSHist_yk2[nabsEtaBins][nCentBins];
//  TH1F* resolutionHist_yk2[nabsEtaBins][nCentBins];


  const char* EtaRangeArr[] ={"eta0to15","eta15to20"};
  std::string EtaRange = "eta0to15";

  const char* etaselectionArr[]={"0<|#eta_{jet}|<1.5","1.5<|#eta_{jet}|<2.0"};
  std::string etaselection;

	const char* jettypeArr[]={"INC","B","csvB","FCRB"};

  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];
    cout<<"EtaRange = "<<EtaRange<<endl;
  for(Int_t iCentBins = 0; iCentBins < nCentBins; iCentBins++){
    meanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
    meanHist_yk1[iabsEtaBins][iCentBins] = (TH1F*)inFile_yk1->Get(Form("jtRecoOverGenVPt_Inc_JecClosure_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
    meanHist_yk2[iabsEtaBins][iCentBins] = (TH1F*)inFile_yk2->Get(Form("jtRecoOverGenVPt_Inc_JecClosure_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));

    RMSHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_Inc_FitSigma_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
    RMSHist_yk1[iabsEtaBins][iCentBins] = (TH1F*)inFile_yk1->Get(Form("jtRecoOverGenVPt_Inc_FitSigma_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
    RMSHist_yk2[iabsEtaBins][iCentBins] = (TH1F*)inFile_yk2->Get(Form("jtRecoOverGenVPt_Inc_FitSigma_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));


//    BmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_B_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
//    csvBmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_csvB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
//    FCRBmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
//    FCRcsvBmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRcsvB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));

  } // end for iCentBins
  } // end for iabsEtaBins

TCanvas *C_plot[nabsEtaBins];
TLegend *le[nabsEtaBins][nCentBins];
TLegend *le1[nabsEtaBins][nCentBins];
gStyle->SetOptStat(0);

// plot part
  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];
    etaselection = etaselectionArr[iabsEtaBins];

    C_plot[iabsEtaBins] = new TCanvas(Form("C_plot_%s",EtaRange.c_str()), Form("C_plot_%s",EtaRange.c_str()), 1200,400 );
    C_plot[iabsEtaBins]->Divide(3,1);

  for(Int_t iCentBins = 0; iCentBins < nCentBins; iCentBins++){
    C_plot[iabsEtaBins]->cd(iCentBins+1);
    le[iabsEtaBins][iCentBins] = new TLegend(0.65,0.65,0.88,0.88);
    le1[iabsEtaBins][iCentBins] = new TLegend(0.25,0.75,0.5,0.88);

    meanHist_p[iabsEtaBins][iCentBins]->GetXaxis()->SetRangeUser(30,600);
    meanHist_p[iabsEtaBins][iCentBins]->Draw("SAME");
    meanHist_p[iabsEtaBins][iCentBins]->SetTitle("");
    meanHist_p[iabsEtaBins][iCentBins]->SetMinimum(0.95);
    meanHist_p[iabsEtaBins][iCentBins]->SetMaximum(1.15);
	  meanHist_p[iabsEtaBins][iCentBins]->SetMarkerStyle(24);
    meanHist_p[iabsEtaBins][iCentBins]->GetXaxis()->SetTitle("genJet p_{T} (GeV)");
    meanHist_p[iabsEtaBins][iCentBins]->GetYaxis()->SetTitle("#mu_{Reco./Gen.} akPu4PF");
    meanHist_yk1[iabsEtaBins][iCentBins]->SetMarkerStyle(24);
    meanHist_yk1[iabsEtaBins][iCentBins]->SetLineColor(2);
    meanHist_yk1[iabsEtaBins][iCentBins]->SetMarkerColor(2);
    meanHist_yk1[iabsEtaBins][iCentBins]->Draw("SAME");
    meanHist_yk2[iabsEtaBins][iCentBins]->SetMarkerStyle(24);
    meanHist_yk2[iabsEtaBins][iCentBins]->SetLineColor(4);
    meanHist_yk2[iabsEtaBins][iCentBins]->SetMarkerColor(4);
    meanHist_yk2[iabsEtaBins][iCentBins]->Draw("SAME");


    le[iabsEtaBins][iCentBins]->AddEntry(meanHist_p[iabsEtaBins][iCentBins],"Inc. Jet","l");
    le[iabsEtaBins][iCentBins]->AddEntry(meanHist_yk1[iabsEtaBins][iCentBins],"Corr. Inc. Jet","l");
    le[iabsEtaBins][iCentBins]->AddEntry(meanHist_yk2[iabsEtaBins][iCentBins],"Corr.2 Inc. Jet","l");
    le[iabsEtaBins][iCentBins]->SetBorderSize(0);
    le[iabsEtaBins][iCentBins]->Draw();

    le1[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,Form("Centrality %d-%d%%",centBins[iCentBins],centBins[iCentBins+1]),"");
    le1[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,etaselection.c_str(),"");
    le1[iabsEtaBins][iCentBins]->SetBorderSize(0);
    le1[iabsEtaBins][iCentBins]->Draw();

    TLine *line = new TLine(30,1,600,1);
    line->SetLineStyle(7);
    line->Draw("SAME");

}
}



TCanvas *C_plot_res[nabsEtaBins];
TLegend *le_res[nabsEtaBins][nCentBins];
TLegend *le1_res[nabsEtaBins][nCentBins];
	
  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];
    etaselection = etaselectionArr[iabsEtaBins];

    C_plot_res[iabsEtaBins] = new TCanvas( Form("C_plot_res_%s",EtaRange.c_str()), Form("C_plot_res_%s",EtaRange.c_str()) ,1200,400 );
    C_plot_res[iabsEtaBins]->Divide(3,1);

  for(Int_t iCentBins = 0; iCentBins < nCentBins; iCentBins++){
    C_plot_res[iabsEtaBins]->cd(iCentBins+1);
    le_res[iabsEtaBins][iCentBins] = new TLegend(0.65,0.65,0.88,0.88);
    le1_res[iabsEtaBins][iCentBins] = new TLegend(0.25,0.75,0.5,0.88);

    RMSHist_p[iabsEtaBins][iCentBins]->GetXaxis()->SetRangeUser(30,600);
    RMSHist_p[iabsEtaBins][iCentBins]->Draw("SAME");
    RMSHist_p[iabsEtaBins][iCentBins]->SetTitle("");
    RMSHist_p[iabsEtaBins][iCentBins]->SetMinimum(0.05);
    RMSHist_p[iabsEtaBins][iCentBins]->SetMaximum(0.45);
    RMSHist_p[iabsEtaBins][iCentBins]->SetMarkerStyle(24);
    RMSHist_p[iabsEtaBins][iCentBins]->GetXaxis()->SetTitle("genJet p_{T} (GeV)");
    RMSHist_p[iabsEtaBins][iCentBins]->GetYaxis()->SetTitle("RMS/#mu_{Reco./Gen.} akPu4PF");
    RMSHist_yk1[iabsEtaBins][iCentBins]->SetMarkerStyle(24);
    RMSHist_yk1[iabsEtaBins][iCentBins]->SetLineColor(2);
    RMSHist_yk1[iabsEtaBins][iCentBins]->SetMarkerColor(2);
    RMSHist_yk1[iabsEtaBins][iCentBins]->Draw("SAME");
    RMSHist_yk2[iabsEtaBins][iCentBins]->SetMarkerStyle(24);
    RMSHist_yk2[iabsEtaBins][iCentBins]->SetLineColor(4);
    RMSHist_yk2[iabsEtaBins][iCentBins]->SetMarkerColor(4);
    RMSHist_yk2[iabsEtaBins][iCentBins]->Draw("SAME");


    le_res[iabsEtaBins][iCentBins]->AddEntry(RMSHist_p[iabsEtaBins][iCentBins],"Inc. Jet","l");
    le_res[iabsEtaBins][iCentBins]->AddEntry(RMSHist_yk1[iabsEtaBins][iCentBins],"Corr. Inc. Jet","l");
    le_res[iabsEtaBins][iCentBins]->AddEntry(RMSHist_yk2[iabsEtaBins][iCentBins],"Corr.2 Inc. Jet","l");
    le_res[iabsEtaBins][iCentBins]->SetBorderSize(0);
    le_res[iabsEtaBins][iCentBins]->Draw();

    le1_res[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,Form("Centrality %d-%d%%",centBins[iCentBins],centBins[iCentBins+1]),"");
    le1_res[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,etaselection.c_str(),"");
    le1_res[iabsEtaBins][iCentBins]->SetBorderSize(0);
    le1_res[iabsEtaBins][iCentBins]->Draw();
}
}




}
