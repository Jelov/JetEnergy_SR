#ifndef GETRESIDUALJETCORR_H
#define GETRESIDUALJETCORR_H

#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"

#include <string>
#include <iostream>

const std::string residualStr = "RESIDUALCORR";

const Int_t nResCentBins = 8;
//const Int_t resCentBins[nResCentBins+1] = {200, 60, 20, 0};
const Int_t resCentBins[nResCentBins+1] = {200,140,100,60,40,30,20,10,0};

const Int_t nabsEtaBins = 2;
const Double_t absEtaBin[nabsEtaBins+1] = {0,1.5,2};



TFile* residualJetCorrFile_p;

TH1F* IresidualJetCorrHists_p[nabsEtaBins][nResCentBins];
TF1* IresidualJetCorrFuncs_p[nabsEtaBins][nResCentBins];

TH1F* BresidualJetCorrHists_p[nabsEtaBins][nResCentBins];
TF1* BresidualJetCorrFuncs_p[nabsEtaBins][nResCentBins];
TH1F* csvBresidualJetCorrHists_p[nabsEtaBins][nResCentBins];
TF1* csvBresidualJetCorrFuncs_p[nabsEtaBins][nResCentBins];
TH1F* FCRBresidualJetCorrHists_p[nabsEtaBins][nResCentBins];
TF1* FCRBresidualJetCorrFuncs_p[nabsEtaBins][nResCentBins];
TH1F* FCRcsvBresidualJetCorrHists_p[nabsEtaBins][nResCentBins];
TF1* FCRcsvBresidualJetCorrFuncs_p[nabsEtaBins][nResCentBins];


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

  const char* EtaRangeArr[] ={"eta0to15","eta15to20"};
  std::string EtaRange = "eta0to15";
  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];

  for(Int_t iter = 0; iter < nResCentBins; iter++){
    std::cout << Form("resCorr_cent%dto%d_%s", resCentBins[iter+1]/2, resCentBins[iter]/2, EtaRange.c_str() ) << std::endl;

    IresidualJetCorrHists_p[iabsEtaBins][iter] = (TH1F*)residualJetCorrFile_p->Get(Form("IresCorr_cent%dto%d_%s", resCentBins[iter+1]/2, resCentBins[iter]/2, EtaRange.c_str() ));    
    IresidualJetCorrFuncs_p[iter] = (TF1*)IresidualJetCorrHists_p[iter]->GetFunction("f1_p");

	// added for other types
	
    BresidualJetCorrHists_p[iabsEtaBins][iter] = (TH1F*)residualJetCorrFile_p->Get(Form("BresCorr_cent%dto%d_%s", resCentBins[iter+1]/2, resCentBins[iter]/2,EtaRange.c_str()));
    BresidualJetCorrFuncs_p[iter] = (TF1*)BresidualJetCorrHists_p[iter]->GetFunction("f1_p");

    csvBresidualJetCorrHists_p[iabsEtaBins][iter] = (TH1F*)residualJetCorrFile_p->Get(Form("csvBresCorr_cent%dto%d_%s", resCentBins[iter+1]/2, resCentBins[iter]/2,EtaRange.c_str()));
    csvBresidualJetCorrFuncs_p[iter] = (TF1*)csvBresidualJetCorrHists_p[iter]->GetFunction("f1_p");

    FCRBresidualJetCorrHists_p[iabsEtaBins][iter] = (TH1F*)residualJetCorrFile_p->Get(Form("FCRBresCorr_cent%dto%d_%s", resCentBins[iter+1]/2, resCentBins[iter]/2,EtaRange.c_str()));
    FCRBresidualJetCorrFuncs_p[iabsEtaBins][iter] = (TF1*)FCRBresidualJetCorrHists_p[iter]->GetFunction("f1_p");

//    FCRcsvBresidualJetCorrHists_p[iter] = (TH1F*)residualJetCorrFile_p->Get(Form("FCRcsvBresCorr_cent%dto%d_h", resCentBins[iter+1]/2, resCentBins[iter]/2));
//    FCRcsvBresidualJetCorrFuncs_p[iter] = (TF1*)FCRcsvBresidualJetCorrHists_p[iter]->GetFunction("f1_p");

	
  }
	} // end for iabsEtaBins
  return true;
}


Float_t getResCorrJetPt(Float_t jtPt, Int_t hiBin, double jteta, Int_t type)
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

	Int_t iabsEtaBins = 0; // set default to 0, correct all other eta with eta<1.5 correction
	if(abs(jteta)<=1.5 && abs(jteta) >0 ){ iabsEtaBins =0; }
	else if( abs(jteta)<2 && abs(jteta)>1.5 ){iabsEtaBins =1; }



	Float_t corrJtPt =-998; 
	if(type ==0){ // for Inclusive jet
  corrJtPt = jtPt/residualJetCorrFuncs_p[iabsEtaBins][centPos]->Eval(jtPt);
	}
	else if(type ==1){ // for b-jet
  corrJtPt = jtPt/BresidualJetCorrFuncs_p[iabsEtaBins][centPos]->Eval(jtPt);	
	}
  else if(type ==2){ // for csv>0.9 b-jet
  corrJtPt = jtPt/csvBresidualJetCorrFuncs_p[iabsEtaBins][centPos]->Eval(jtPt);
  }
  else if(type ==3){ // for FCR b-jet
  corrJtPt = jtPt/FCRBresidualJetCorrFuncs_p[iabsEtaBins][centPos]->Eval(jtPt);
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
