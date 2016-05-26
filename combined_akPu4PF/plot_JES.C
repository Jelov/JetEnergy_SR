#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"
#include "TNamed.h"
#include "TMath.h"
#include <string>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLegend.h>

const Int_t nCentBins = 8;
const  int centBins[nCentBins+1]= {0,5,10,15,20,30,50,70,100};

const Int_t nabsEtaBins = 2;
const Double_t absEtaBin[nabsEtaBins+1] = {0,1.5,2};



void plot_JES(){


  const std::string inFileName = "Jec_akPu4PF.root";
  TFile* inFile_p = new TFile(inFileName.c_str(), "READ");
  TH1F* meanHist_p[nabsEtaBins][nCentBins];
  TH1F* BmeanHist_p[nabsEtaBins][nCentBins];
  TH1F* csvBmeanHist_p[nabsEtaBins][nCentBins];
  TH1F* FCRBmeanHist_p[nabsEtaBins][nCentBins];
  TH1F* FCRcsvBmeanHist_p[nabsEtaBins][nCentBins];

	TH1F*

  const char* EtaRangeArr[] ={"eta0to15","eta15to20"};
  std::string EtaRange = "eta0to15";

	const char*	etaselectionArr[]={"0<|#eta_{jet}|<1.5","1.5<|#eta_{jet}|<2.0"};
	std::string etaselection;

  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];
    cout<<"EtaRange = "<<EtaRange<<endl;
  for(Int_t iCentBins = 0; iCentBins < nCentBins; iCentBins++){
    meanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
    BmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_B_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
    csvBmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_csvB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
    FCRBmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));
    FCRcsvBmeanHist_p[iabsEtaBins][iCentBins] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRcsvB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str() ));


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
		
		C_plot[iabsEtaBins] = new TCanvas(Form("C_plot_%s",EtaRange.c_str()), Form("C_plot_%s",EtaRange.c_str()) );
		C_plot[iabsEtaBins]->Divide(4,2);	

  for(Int_t iCentBins = 0; iCentBins < nCentBins; iCentBins++){
		C_plot[iabsEtaBins]->cd(iCentBins+1);
		le[iabsEtaBins][iCentBins] = new TLegend(0.65,0.65,0.9,0.88);
    le1[iabsEtaBins][iCentBins] = new TLegend(0.25,0.75,0.5,0.88);
		
//		BmeanHist_p[iabsEtaBins][iCentBins]->Draw("SAME");
	
    FCRBmeanHist_p[iabsEtaBins][iCentBins]->GetXaxis()->SetRangeUser(40,310);	
		FCRBmeanHist_p[iabsEtaBins][iCentBins]->Draw("SAME");
		FCRBmeanHist_p[iabsEtaBins][iCentBins]->SetTitle("");
		FCRBmeanHist_p[iabsEtaBins][iCentBins]->SetMinimum(0.94);
    FCRBmeanHist_p[iabsEtaBins][iCentBins]->SetMaximum(1.2);		
		FCRBmeanHist_p[iabsEtaBins][iCentBins]->GetXaxis()->SetTitle("genJet p_{T} (GeV)");
    FCRBmeanHist_p[iabsEtaBins][iCentBins]->GetYaxis()->SetTitle("#mu_{Reco./Gen.} akPu4PF");
//		FCRcsvBmeanHist_p[iabsEtaBins][iCentBins]->SetMarkerStyle(1);
		FCRcsvBmeanHist_p[iabsEtaBins][iCentBins]->SetLineColor(2);
		FCRcsvBmeanHist_p[iabsEtaBins][iCentBins]->SetMarkerColor(2);
		FCRcsvBmeanHist_p[iabsEtaBins][iCentBins]->Draw("SAME");		

		le[iabsEtaBins][iCentBins]->AddEntry(FCRBmeanHist_p[iabsEtaBins][iCentBins],"FCR b-jet","l");
    le[iabsEtaBins][iCentBins]->AddEntry(FCRcsvBmeanHist_p[iabsEtaBins][iCentBins],"FCR csv b-jet","l");
		le[iabsEtaBins][iCentBins]->SetBorderSize(0);
		le[iabsEtaBins][iCentBins]->Draw();

    le1[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,Form("Centrality %d-%d%%",centBins[iCentBins],centBins[iCentBins+1]),"");
		le1[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,etaselection.c_str(),"");
    le1[iabsEtaBins][iCentBins]->SetBorderSize(0);
    le1[iabsEtaBins][iCentBins]->Draw();



  } // end for iCentBins
  } // end for iabsEtaBins


}
