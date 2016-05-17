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

const Int_t nCentBins = 4;
const Int_t centBins[nCentBins+1] = {0, 10, 30, 50, 100};

//TCanvas *c_fit = new TCanvas("c_fit","c_fit");
double para_c = 0;
double para_s = 0;

void FitSigma(TH1F* hist_p,int iter, TH1F* histPerph_p = NULL)
{
  if(hist_p->GetEntries() == 0) return;

  TF1* f1_p = new TF1("f1_p", Form("TMath::Sqrt( [0]*[0] + [1]*[1]/x + [2]*[2]/x/x )"), 40, hist_p->GetXaxis()->GetXmax());

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

//	cout<<"initial par0 = "<<par0<<" ,par1 = "<<par1<<" ,par2 = "<<par2<<endl;
	par2 = 8;
	if(iter == 1)
	par2 = 6;	
	if(iter == 2)
	par2 = 5;
	if(iter == 3)
	par2 = 0.01;	
	
  if(histPerph_p != NULL){
    par0 = histPerph_p->GetFunction("f1_p")->GetParameter(0);
    par0Err = histPerph_p->GetFunction("f1_p")->GetParError(0);
  }

  f1_p->SetParameter(0, par0);
  if(histPerph_p != NULL) f1_p->SetParLimits(0, par0-par0Err, par0+par0Err);
  // else f1_p->SetParLimits(0, .9, 1.05);
	if(iter == 3){
	f1_p->SetParLimits(0, .00001, 1.05);
  f1_p->SetParameter(1, par1);
	}
  else {
	cout<<"iter ="<<iter<<" ,para_c = "<<para_c<<" ,para_s = "<<para_s<<endl;
//	f1_p->SetParLimits(0, para_c, para_c);
//	f1_p->SetParLimits(1, para_s, para_s);	
	f1_p->FixParameter(0, para_c);
	f1_p->FixParameter(1, para_s);
	}	
  f1_p->SetParameter(2, par2);

	cout<<"iter = "<<iter<<endl;
  cout<<"inital par0 C= "<<f1_p->GetParameter(0)<<" ,par1 S= "<<f1_p->GetParameter(1)<<" ,par2 N= "<<f1_p->GetParameter(2)<<endl;


  hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());
  hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());
  hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());
  hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());
  hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());

	if(iter == 3){
	para_c = f1_p->GetParameter(0);
	para_s = f1_p->GetParameter(1);
	cout<<"iter 3, para_c = "<<para_c<<endl;
  cout<<"iter 3, para_s = "<<para_s<<endl;	
	}
  cout<<"final par0 C= "<<f1_p->GetParameter(0)<<" ,par1 S= "<<f1_p->GetParameter(1)<<" ,par2 N= "<<f1_p->GetParameter(2)<<endl;
	if(iter == 0){cout<<endl;}


//	hist_p->Draw(); // j

  delete f1_p;

  return;
}

//void makeJECResidualCorr(const std::string inFileName)
void fitJER_afterCorr()
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

	const std::string inFileName = "Jec_akPu4PF_Corr.root";
  TFile* inFile_p = new TFile(inFileName.c_str(), "READ");
  TH1F* sigmaHist_p[nCentBins];

  TH1F* BsigmaHist_p[nCentBins];
  TH1F* csvBsigmaHist_p[nCentBins];
  TH1F* FCRBsigmaHist_p[nCentBins];
  TH1F* FCRcsvBsigmaHist_p[nCentBins];

//  TH1F* recoToGenHist_p[nCentBins];

//  for(Int_t iter = 0; iter < nCentBins; iter++)
	for(Int_t iter = nCentBins-1; iter>=0; iter--)
{
    sigmaHist_p[iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_Inc_FitSigma_akPu4PF_cent%dto%d_h", centBins[iter], centBins[iter+1]));
    BsigmaHist_p[iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_B_FitSigma_akPu4PF_cent%dto%d_h", centBins[iter], centBins[iter+1]));
    csvBsigmaHist_p[iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_csvB_FitSigma_akPu4PF_cent%dto%d_h", centBins[iter], centBins[iter+1]));
    FCRBsigmaHist_p[iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRB_FitSigma_akPu4PF_cent%dto%d_h", centBins[iter], centBins[iter+1]));
//    FCRcsvBsigmaHist_p[iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRcsvB_FitSigma_akPu4PF_cent%dto%d_h", centBins[iter], centBins[iter+1]));


//    recoToGenHist_p[iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVRecoPt_Inc_FitSigma_akPu4PF_cent%dto%d_h", centBins[iter], centBins[iter+1]));

//    std::cout << "iter: " << iter << std::endl;

    FitSigma(sigmaHist_p[iter],iter);
}
  for(Int_t iter = nCentBins-1; iter>=0; iter--){ FitSigma(BsigmaHist_p[iter],iter);}
  for(Int_t iter = nCentBins-1; iter>=0; iter--){ FitSigma(csvBsigmaHist_p[iter],iter);}
  for(Int_t iter = nCentBins-1; iter>=0; iter--){ FitSigma(FCRBsigmaHist_p[iter],iter);}
//    FitSigma(FCRcsvBsigmaHist_p[iter],iter);

//		c_fit->cd(iter-1);
  

		std::string outFileName = "CORR_JER.root";
//  std::string outFileName = inFileName;
//  outFileName.replace(outFileName.find(resString1), resString1.size()+1, "RESIDUALCORR.root");
	cout<<"input file : "<<inFileName<<endl;
	cout<<"output file : "<<outFileName<<endl;
  
  TFile* outFile_p = new TFile(outFileName.c_str(), "UPDATE");
  TNamed pathStr(Form("pathStr"), inFileName.c_str());
  pathStr.Write("", TObject::kOverwrite);
  
  for(Int_t iter = 0; iter < nCentBins; iter++){
    sigmaHist_p[iter]->Write(Form("JERCorr_cent%dto%d_h", centBins[iter], centBins[iter+1]), TObject::kOverwrite);
    BsigmaHist_p[iter]->Write(Form("BJERCorr_cent%dto%d_h", centBins[iter], centBins[iter+1]), TObject::kOverwrite);
    csvBsigmaHist_p[iter]->Write(Form("csvBJERCorr_cent%dto%d_h", centBins[iter], centBins[iter+1]), TObject::kOverwrite);
    FCRBsigmaHist_p[iter]->Write(Form("FCRBJERCorr_cent%dto%d_h", centBins[iter], centBins[iter+1]), TObject::kOverwrite);
//    FCRcsvBsigmaHist_p[iter]->Write(Form("FCRcsvBJERCorr_cent%dto%d_h", centBins[iter], centBins[iter+1]), TObject::kOverwrite);

 //   recoToGenHist_p[iter]->Write("", TObject::kOverwrite);
  }
  outFile_p->Close();
  delete outFile_p;

  inFile_p->Close();
  delete inFile_p;

  return;  
}
