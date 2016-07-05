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

// const Int_t nCentBins = 3;
// const Int_t centBins[nCentBins+1] = {0, 10, 30, 100};

//const Int_t nCentBins = 8;
//const Int_t centBins[nCentBins+1]= {0,5,10,15,20,30,50,70,100};
//const Int_t centBins[nCentBins+1]={100,70,50,30,20,15,10,5,0};

int centBins[] = {0,10,20,40,60,100,200};
const int nCentBins = sizeof(centBins) / sizeof(centBins[0]) -1;


//const Int_t nabsEtaBins = 2;
const Double_t absEtaBin[nabsEtaBins+1] = {0,1.5};
const int nabsEtaBins = sizeof(absEtaBin)/sizeof(absEtaBin[0])-1;


//TCanvas *c_fit = new TCanvas("c_fit","c_fit");
double para_c = 0;
double para_s = 0;

void FitSigma(TH1F* hist_p,int iter, int iabsEtaBins, double *parc, double *pars ,TH1F* histPerph_p = NULL)
{
  if(hist_p->GetEntries() == 0) return;

  TF1* f1_p = new TF1("f1_p", Form("TMath::Sqrt( [0]*[0] + [1]*[1]/x + [2]*[2]/x/x )"), 30, hist_p->GetXaxis()->GetXmax());

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

	par0 = parc[iabsEtaBins];
	par1 = pars[iabsEtaBins];

//	cout<<"initial par0 = "<<par0<<" ,par1 = "<<par1<<" ,par2 = "<<par2<<endl;
//	par2 = 8;
//	if(iter == 1)
//	par2 = 6;	
//	if(iter == 2)
//	par2 = 3;
//	if(iter == 3)
//	par2 = 0.01;	
	
  if(histPerph_p != NULL){
    par0 = histPerph_p->GetFunction("f1_p")->GetParameter(0);
    par0Err = histPerph_p->GetFunction("f1_p")->GetParError(0);
  }

//  f1_p->SetParameter(0, par0);
  if(histPerph_p != NULL) f1_p->SetParLimits(0, par0-par0Err, par0+par0Err);

  // f1_p->FixParameter(0, par0);
	par2 = 0.001* pow(3,iter);
	cout<<"initial par2 = "<<par2<<endl;
  f1_p->SetParameter(2, par2);
//	f1_p->SetParameter(2, 0.1);

  // cout<<"iabsEtaBins ="<<iabsEtaBins<<" iter ="<<iter<<" ,para_c = "<<par0<<" ,para_s = "<<par1<<endl;

	if(iter == 0){
  f1_p->SetParameter(0, par0);
  f1_p->SetParameter(1, par1);
	f1_p->SetParLimits(0, par0,999);
	f1_p->SetParLimits(1, par1,999);

	
	}
  else {
  f1_p->FixParameter(0, par0);
	f1_p->FixParameter(1, par1);
	}
  if(iter == 0){cout<<endl;}


  cout<<"\niabsEtaBins ="<<iabsEtaBins<<" iter ="<<iter<<" parameter setting ,par0 = "<<par0<<" ,par1  = "<<par1<<endl;
	// cout<<"iter = "<<iter<<endl;
  cout<<"inital Getparameter ,par0 C= "<<f1_p->GetParameter(0)<<" ,par1 S= "<<f1_p->GetParameter(1)<<" ,par2 N= "<<f1_p->GetParameter(2)<<endl;


  // hist_p->Fit("f1_p", "Q M", "", 40, hist_p->GetXaxis()->GetXmax());
//  hist_p->Fit("f1_p", "Q MR", "", 40, 400);
//  hist_p->Fit("f1_p", "Q MR", "", 40, 400);
//  hist_p->Fit("f1_p", "Q MR", "", 40, 400);
//  hist_p->Fit("f1_p", "Q MR", "", 40, 400);

  hist_p->Fit("f1_p", "Q MR", "", 70, 250);
  hist_p->Fit("f1_p", "Q MR", "", 70, 250);
  hist_p->Fit("f1_p", "Q MR", "", 70, 250);
  hist_p->Fit("f1_p", "Q MR", "", 70, 250);

//	f1_p->Draw("same");
//	return;

  cout<<"final par0 C= "<<f1_p->GetParameter(0)<<" ,par1 S= "<<f1_p->GetParameter(1)<<" ,par2 N= "<<f1_p->GetParameter(2)<<endl;


	if(iter == 0){
	parc[iabsEtaBins] = f1_p->GetParameter(0);
	pars[iabsEtaBins] = f1_p->GetParameter(1);
	// cout<<"iter 2, para_c = "<<para_c<<endl;
  cout<<"iter 0, pars  = "<<pars[iabsEtaBins]<<endl;	
	}

//  cout<<"final par0 C= "<<f1_p->GetParameter(0)<<" ,par1 S= "<<f1_p->GetParameter(1)<<" ,par2 N= "<<f1_p->GetParameter(2)<<endl;
//	if(iter == 0){cout<<endl;}


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

  TH1F* sigmaHist_p[nabsEtaBins][nCentBins];

  TH1F* BsigmaHist_p[nabsEtaBins][nCentBins];
  TH1F* csvBsigmaHist_p[nabsEtaBins][nCentBins];
  TH1F* FCRBsigmaHist_p[nabsEtaBins][nCentBins];
  TH1F* FCRcsvBsigmaHist_p[nabsEtaBins][nCentBins];

//	use the c value from pp fit 
	double c_Inc[nabsEtaBins]={0.06078,0.0682};
	double c_Bjt[nabsEtaBins]={0.05893,0.04864};
	double c_csvB[nabsEtaBins]={0.05908,0.05273};
	double c_FCRB[nabsEtaBins]={0.06177,0.05118};

	double s_Inc[nabsEtaBins]={0.9069,0.5851};
	double s_Bjt[nabsEtaBins]={0.8109,0.8608};
	double s_csvB[nabsEtaBins]={0.7714,0.8067};
	double s_FCRB[nabsEtaBins]={0.7755,0.7936};
//  TH1F* recoToGenHist_p[nCentBins];

  const char* EtaRangeArr[] ={"eta0to15","eta15to20"};
  std::string EtaRange = "eta0to15";
//  TH1F* recoToGenHist_p[nCentBins];
  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
//    if (iabsEtaBins ==1){ EtaRange = "eta15to20"; }
    EtaRange = EtaRangeArr[iabsEtaBins];
    cout<<"EtaRange = "<<EtaRange<<endl;
		cout<<"reading histograms"<<endl;
  for(Int_t iter = 0; iter < nCentBins; iter++)
//	for(Int_t iter = nCentBins-1; iter>=0; iter--)
{
    sigmaHist_p[iabsEtaBins][iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_Inc_FitSigma_akPu4PF_cent%dto%d_%s", centBins[iter+1], centBins[iter] ,EtaRange.c_str() ));
    BsigmaHist_p[iabsEtaBins][iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_B_FitSigma_akPu4PF_cent%dto%d_%s", centBins[iter+1], centBins[iter],EtaRange.c_str()));
    csvBsigmaHist_p[iabsEtaBins][iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_csvB_FitSigma_akPu4PF_cent%dto%d_%s", centBins[iter+1], centBins[iter],EtaRange.c_str()));
    FCRBsigmaHist_p[iabsEtaBins][iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRB_FitSigma_akPu4PF_cent%dto%d_%s", centBins[iter+1], centBins[iter],EtaRange.c_str()));
//    FCRcsvBsigmaHist_p[iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVPt_FCRcsvB_FitSigma_akPu4PF_cent%dto%d_h", centBins[iter], centBins[iter+1]));


//    recoToGenHist_p[iter] = (TH1F*)inFile_p->Get(Form("jtRecoOverGenVRecoPt_Inc_FitSigma_akPu4PF_cent%dto%d_h", centBins[iter], centBins[iter+1]));

//    std::cout << "iter: " << iter << std::endl;

FitSigma(sigmaHist_p[iabsEtaBins][iter],iter,iabsEtaBins,c_Inc,s_Inc);
FitSigma(BsigmaHist_p[iabsEtaBins][iter],iter,iabsEtaBins,c_Bjt,s_Bjt);
FitSigma(csvBsigmaHist_p[iabsEtaBins][iter],iter,iabsEtaBins,c_csvB,s_csvB);
FitSigma(FCRBsigmaHist_p[iabsEtaBins][iter],iter,iabsEtaBins,c_FCRB,s_FCRB);

} // end for iter(iCentBins)
} // end for iabsEtaBins

//  for(Int_t iter = nCentBins-1; iter>=0; iter--){ FitSigma(BsigmaHist_p[iabsEtaBins][iter],iter);}
//  for(Int_t iter = nCentBins-1; iter>=0; iter--){ FitSigma(csvBsigmaHist_p[iabsEtaBins][iter],iter);}
//  for(Int_t iter = nCentBins-1; iter>=0; iter--){ FitSigma(FCRBsigmaHist_p[iabsEtaBins][iter],iter);}
//    FitSigma(FCRcsvBsigmaHist_p[iter],iter);

//		c_fit->cd(iter-1);
  

		std::string outFileName = "CORR_JER.root";
//  std::string outFileName = inFileName;
//  outFileName.replace(outFileName.find(resString1), resString1.size()+1, "RESIDUALCORR.root");
	cout<<"input file : "<<inFileName<<endl;
	cout<<"output file : "<<outFileName<<endl;
  
  TFile* outFile_p = new TFile(outFileName.c_str(), "RECREATE");
  TNamed pathStr(Form("pathStr"), inFileName.c_str());
  pathStr.Write("", TObject::kOverwrite);

  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins; iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];
  
  for(Int_t iter = 0; iter < nCentBins; iter++){
    sigmaHist_p[iabsEtaBins][iter]->Write(Form("JERCorr_cent%dto%d_%s", centBins[iter+1], centBins[iter], EtaRange.c_str()), TObject::kOverwrite);
    BsigmaHist_p[iabsEtaBins][iter]->Write(Form("BJERCorr_cent%dto%d_%s", centBins[iter+1], centBins[iter], EtaRange.c_str()), TObject::kOverwrite);
    csvBsigmaHist_p[iabsEtaBins][iter]->Write(Form("csvBJERCorr_cent%dto%d_%s", centBins[iter+1], centBins[iter], EtaRange.c_str()), TObject::kOverwrite);
    FCRBsigmaHist_p[iabsEtaBins][iter]->Write(Form("FCRBJERCorr_cent%dto%d_%s", centBins[iter+1], centBins[iter],EtaRange.c_str()), TObject::kOverwrite);

//    FCRcsvBsigmaHist_p[iter]->Write(Form("FCRcsvBJERCorr_cent%dto%d_h", centBins[iter], centBins[iter+1]), TObject::kOverwrite);

 //   recoToGenHist_p[iter]->Write("", TObject::kOverwrite);
  }
}// end for iabsEtaBins
  outFile_p->Close();
  delete outFile_p;

  inFile_p->Close();
  delete inFile_p;

  return;  
}
