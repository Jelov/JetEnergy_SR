#ifndef GETRESIDUALJETCORR_H
#define GETRESIDUALJETCORR_H

#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"

#include <string>
#include <iostream>

const std::string residualStr = "RESIDUALCORR";

const Int_t nResCentBins = 3;
const Int_t resCentBins[nResCentBins+1] = {200, 60, 20, 0};

TFile* residualJetCorrFile_p;

TH1F* residualJetCorrHists_p[nResCentBins];
TF1* residualJetCorrFuncs_p[nResCentBins];

TH1F* BresidualJetCorrHists_p[nResCentBins];
TF1* BresidualJetCorrFuncs_p[nResCentBins];
TH1F* csvBresidualJetCorrHists_p[nResCentBins];
TF1* csvBresidualJetCorrFuncs_p[nResCentBins];
TH1F* FCRBresidualJetCorrHists_p[nResCentBins];
TF1* FCRBresidualJetCorrFuncs_p[nResCentBins];
TH1F* FCRcsvBresidualJetCorrHists_p[nResCentBins];
TF1* FCRcsvBresidualJetCorrFuncs_p[nResCentBins];


//run once before any loops
Bool_t initGetResidualJetCorr(const std::string inResCorrFileName)
{
  if(inResCorrFileName.find(residualStr) == std::string::npos){
    std::cout << "Input residual file \'" << inResCorrFileName << "\' not proper format. Give \'*RESIDUALCORR*\'. Return false." << std::endl;
    return false;
  }

  residualJetCorrFile_p = new TFile(inResCorrFileName.c_str(), "READ");

  if(residualJetCorrFile_p->IsZombie()){
    std::cout << "Input residual file \'" << inResCorrFileName << "\' is zombie. Return false" << std::endl;
    return false;
  }

  for(Int_t iter = 0; iter < nResCentBins; iter++){
    std::cout << Form("resCorr_cent%dto%d_h", resCentBins[iter+1]/2, resCentBins[iter]/2) << std::endl;

    residualJetCorrHists_p[iter] = (TH1F*)residualJetCorrFile_p->Get(Form("resCorr_cent%dto%d_h", resCentBins[iter+1]/2, resCentBins[iter]/2));    
    residualJetCorrFuncs_p[iter] = (TF1*)residualJetCorrHists_p[iter]->GetFunction("f1_p");

	// added for other types
	
    BresidualJetCorrHists_p[iter] = (TH1F*)residualJetCorrFile_p->Get(Form("BresCorr_cent%dto%d_h", resCentBins[iter+1]/2, resCentBins[iter]/2));
    BresidualJetCorrFuncs_p[iter] = (TF1*)BresidualJetCorrHists_p[iter]->GetFunction("f1_p");

    csvBresidualJetCorrHists_p[iter] = (TH1F*)residualJetCorrFile_p->Get(Form("csvBresCorr_cent%dto%d_h", resCentBins[iter+1]/2, resCentBins[iter]/2));
    csvBresidualJetCorrFuncs_p[iter] = (TF1*)csvBresidualJetCorrHists_p[iter]->GetFunction("f1_p");

    FCRBresidualJetCorrHists_p[iter] = (TH1F*)residualJetCorrFile_p->Get(Form("FCRBresCorr_cent%dto%d_h", resCentBins[iter+1]/2, resCentBins[iter]/2));
    FCRBresidualJetCorrFuncs_p[iter] = (TF1*)FCRBresidualJetCorrHists_p[iter]->GetFunction("f1_p");

//    FCRcsvBresidualJetCorrHists_p[iter] = (TH1F*)residualJetCorrFile_p->Get(Form("FCRcsvBresCorr_cent%dto%d_h", resCentBins[iter+1]/2, resCentBins[iter]/2));
//    FCRcsvBresidualJetCorrFuncs_p[iter] = (TF1*)FCRcsvBresidualJetCorrHists_p[iter]->GetFunction("f1_p");

	
  }

  return true;
}


Float_t getResCorrJetPt(Float_t jtPt, Int_t hiBin, Int_t type)
{
  if(jtPt < 0){
    std::cout << "Input jtpt < 0. return -999" << std::endl;
    return -999;
  }
  else if(hiBin < 0 || hiBin >= 200){
    std::cout << "Input hibin < 0 or >= 200. Return -999" << std::endl;
    return -999;
  }

  Int_t centPos = -1;

  for(Int_t iter = 0; iter < nResCentBins; iter++){
    if(hiBin >= resCentBins[iter+1] && hiBin < resCentBins[iter]){
      centPos = iter;
      break;
    }
  }
	Float_t corrJtPt =-998; 
	if(type ==0){ // for Inclusive jet
  corrJtPt = jtPt/residualJetCorrFuncs_p[centPos]->Eval(jtPt);
	}
	else if(type ==1){ // for b-jet
  corrJtPt = jtPt/BresidualJetCorrFuncs_p[centPos]->Eval(jtPt);	
	}
  else if(type ==2){ // for csv>0.9 b-jet
  corrJtPt = jtPt/csvBresidualJetCorrFuncs_p[centPos]->Eval(jtPt);
  }
  else if(type ==3){ // for FCR b-jet
  corrJtPt = jtPt/FCRBresidualJetCorrFuncs_p[centPos]->Eval(jtPt);
  }
//  else if(type ==4){
//  corrJtPt = jtPt/FCRcsvBresidualJetCorrFuncs_p[centPos]->Eval(jtPt);
//  }
	else { 
		std::cout<<"Input type is wrong , use type 0~4 to get jtpt correc, REturn -999"<<std::endl;
		return -999;
	}




//	need to add more choice


  return corrJtPt;
}

#endif
