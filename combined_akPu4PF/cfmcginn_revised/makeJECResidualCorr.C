// modified to use for akpu4PF jet in b-jet study
#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"
#include "TNamed.h"
#include "TMath.h"

#include <string>
#include <TCanvas.h>


const std::string resString1 = "RESIDUALHIST.root";
const std::string resString2 = "RESIDUAL2HIST.root";

// const Int_t nCentBins = 8;
const Int_t centBins[] = {0, 10, 30, 100};

//const  int centBins[nCentBins+1]= {0,10,20,30,40,60,100,140,200};
//const  int centBins[nCentBins+1]= {0,5,10,15,20,30,50,70,100};
const Int_t nCentBins =  sizeof(centBins) / sizeof(centBins[0]) -1;


//const Int_t nabsEtaBins = 2;
const Double_t absEtaBin[] = {0,1.5};
const int nabsEtaBins = sizeof(absEtaBin)/sizeof(absEtaBin[0])-1;


//TCanvas *c_fit = new TCanvas("c_fit","c_fit");

void FitResidual1(TH1F* hist_p, TH1F* histPerph_p = NULL)
{
	cout<<"check a-1"<<endl;
  if(hist_p->GetEntries() == 0) return;
	cout<<"check a"<<endl;

  TF1* f1_p = new TF1("f1_p", Form("[0] + [1]/TMath::Sqrt(x) + [2]/x"), 20, hist_p->GetXaxis()->GetXmax());

  Float_t xVal0 = hist_p->GetBinCenter(1);
  Float_t xVal1 = hist_p->GetBinCenter((Int_t)(hist_p->GetNbinsX()/2));
  Float_t xVal2 = hist_p->GetBinCenter(hist_p->GetNbinsX());

  Float_t yVal0 = hist_p->GetBinContent(1);
  Float_t yVal1 = hist_p->GetBinContent((Int_t)(hist_p->GetNbinsX()/2));
  Float_t yVal2 = hist_p->GetBinContent(hist_p->GetNbinsX());

  Float_t par0 = yVal2;
  Float_t par0Err = 0;
  Float_t par1 = (yVal1 - par0)*TMath::Sqrt(xVal1);
  Float_t par2 = (yVal0 - par0 - par1/TMath::Sqrt(xVal0))*xVal0;

  if(histPerph_p != NULL){
    par0 = histPerph_p->GetFunction("f1_p")->GetParameter(0);
    par0Err = histPerph_p->GetFunction("f1_p")->GetParError(0);
  }
  cout<<"check b"<<endl;


  f1_p->SetParameter(0, par0);
  f1_p->SetParameter(1, par1);
  f1_p->SetParameter(2, par2);

  if(histPerph_p != NULL) f1_p->SetParLimits(0, par0-par0Err, par0+par0Err);
  else f1_p->SetParLimits(0, .9, 1.1);
//	f1_p->SetParLimits(1, -4, -2);
//	f1_p->SetParLimits(2, 3, 10);

  cout<<"check c"<<endl;

  //hist_p->Fit("f1_p", "WL Q M", "", 30, hist_p->GetXaxis()->GetXmax());
/*
  hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());
  hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());
  hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());
  hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());
  hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());
*/
  hist_p->Fit("f1_p", "Q M", "", 70, 250);
  hist_p->Fit("f1_p", "Q M", "", 70, 250);
  hist_p->Fit("f1_p", "Q M", "", 70, 250);
  hist_p->Fit("f1_p", "Q M", "", 70, 250);
  hist_p->Fit("f1_p", "Q M", "", 70, 250);
  cout<<"check d"<<endl;


//	hist_p->Draw(); // j

  delete f1_p;

  return;
}

//void makeJECResidualCorr(const std::string inFileName)
void makeJECResidualCorr()
{
/*
  Bool_t isRes1 = false;
  if(inFileName.find(resString1.c_str()) != std::string::npos) isRes1 = true;

  Bool_t isRes2 = false;
  if(inFileName.find(resString2.c_str()) != std::string::npos) isRes2 = true;

  if(!isRes1 && !isRes2){
    std::cout << "Input file not residual. return" << std::endl; 
    return;
  }
*/ 
//	c_fit->Divide(2,2);

	const std::string inFileName = "Jec_akPu4PF.root";
  TFile* inFile_p = new TFile(inFileName.c_str(), "READ");

  TH1F* meanHist_p[nabsEtaBins][nCentBins];
  TH1F* BmeanHist_p[nabsEtaBins][nCentBins];
  TH1F* csvBmeanHist_p[nabsEtaBins][nCentBins];
  TH1F* FCRBmeanHist_p[nabsEtaBins][nCentBins];

//  TH1F* FCRcsvBmeanHist_p[nCentBins];

	const char* EtaRangeArr[] ={"eta0to15","eta15to20"};
	std::string EtaRange = "eta0to15";
//  TH1F* recoToGenHist_p[nCentBins];
	for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
//		if (iabsEtaBins ==1){	EtaRange = "eta15to20";	}
		EtaRange = EtaRangeArr[iabsEtaBins];
		cout<<"EtaRange = "<<EtaRange<<endl;


  for(Int_t iter = 0; iter < nCentBins; iter++){
    meanHist_p[iabsEtaBins][iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent%dto%d_%s", centBins[iter], centBins[iter+1],EtaRange.c_str() ));
    BmeanHist_p[iabsEtaBins][iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_B_FitMean_akPu4PF_cent%dto%d_%s", centBins[iter], centBins[iter+1],EtaRange.c_str() ));
    csvBmeanHist_p[iabsEtaBins][iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_csvB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iter], centBins[iter+1],EtaRange.c_str() ));
    FCRBmeanHist_p[iabsEtaBins][iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRB_FitMean_akPu4PF_cent%dto%d_%s", centBins[iter], centBins[iter+1],EtaRange.c_str() ));
//    FCRcsvBmeanHist_p[iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRcsvB_FitMean_akPu4PF_cent%dto%d_h", centBins[iter], centBins[iter+1]));

		TCanvas *c_test = new TCanvas("c_test","c_test");
	  meanHist_p[iabsEtaBins][iter]->Draw();

//    recoToGenHist_p[iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVRecoPt_Inc_FitMean_akPu4PF_cent%dto%d_h", centBins[iter], centBins[iter+1]));

    std::cout << "iter: " << iter << std::endl;

    FitResidual1(meanHist_p[iabsEtaBins][iter]);
		cout<<"check1"<<endl;
    FitResidual1(BmeanHist_p[iabsEtaBins][iter]);
    FitResidual1(csvBmeanHist_p[iabsEtaBins][iter]);
    FitResidual1(FCRBmeanHist_p[iabsEtaBins][iter]);
		cout<<"check2"<<endl;
//    FitResidual1(FCRcsvBmeanHist_p[iter]);

//		c_fit->cd(iter-1);
  } // end for iter
	}	// end for iabsEtaBins

		std::string outFileName = "RESIDUALCORR.root";
//  std::string outFileName = inFileName;
//  outFileName.replace(outFileName.find(resString1), resString1.size()+1, "RESIDUALCORR.root");
	cout<<"input file : "<<inFileName<<endl;
	cout<<"output file : "<<outFileName<<endl;
  
  TFile* outFile_p = new TFile(outFileName.c_str(), "UPDATE");
  TNamed pathStr(Form("pathStr"), inFileName.c_str());
  pathStr.Write("", TObject::kOverwrite);
 
  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins; iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];
 
  for(Int_t iter = 0; iter < nCentBins; iter++){
    meanHist_p[iabsEtaBins][iter]->Write(Form("IresCorr_cent%dto%d_%s", centBins[iter], centBins[iter+1],EtaRange.c_str()), TObject::kOverwrite);
    BmeanHist_p[iabsEtaBins][iter]->Write(Form("BresCorr_cent%dto%d_%s", centBins[iter], centBins[iter+1],EtaRange.c_str()), TObject::kOverwrite);
    csvBmeanHist_p[iabsEtaBins][iter]->Write(Form("csvBresCorr_cent%dto%d_%s", centBins[iter], centBins[iter+1],EtaRange.c_str()), TObject::kOverwrite);
    FCRBmeanHist_p[iabsEtaBins][iter]->Write(Form("FCRBresCorr_cent%dto%d_%s", centBins[iter], centBins[iter+1],EtaRange.c_str()), TObject::kOverwrite);
//    FCRcsvBmeanHist_p[iter]->Write(Form("FCRcsvBresCorr_cent%dto%d_h", centBins[iter], centBins[iter+1]), TObject::kOverwrite);

 //   recoToGenHist_p[iter]->Write("", TObject::kOverwrite);
  } // end for iter
	} // end for iabsEtaBins
  outFile_p->Close();
  delete outFile_p;

  inFile_p->Close();
  delete inFile_p;

  return;  
}
