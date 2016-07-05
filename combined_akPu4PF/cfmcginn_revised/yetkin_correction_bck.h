#ifndef YETKIN_CORRECTION_H
#define YETKIN_CORRECTION_H

#include "TF1.h"
#include "TFile.h"
#include "TH1F.h"
#include <string>
#include <iostream>

/*
const Int_t resCentBins[] = {200, 60, 20, 0};
// const Int_t resCentBins[nResCentBins+1] = {200,140,100,60,40,30,20,10,0};
const Int_t nResCentBins =  sizeof(resCentBins) / sizeof(resCentBins[0]) -1;


//const Int_t nabsEtaBins = 2;
const Double_t absEtaBin[] = {0,1.5};
const int nabsEtaBins = sizeof(absEtaBin)/sizeof(absEtaBin[0])-1;
*/
//TH1F* IresidualJetCorrHists_p[nabsEtaBins][nResCentBins];
TF1* IresidualJetCorrFuncs_yk[nabsEtaBins][nResCentBins];

/*
TH1F* BresidualJetCorrHists_p[nabsEtaBins][nResCentBins];
TF1* BresidualJetCorrFuncs_p[nabsEtaBins][nResCentBins];
TH1F* csvBresidualJetCorrHists_p[nabsEtaBins][nResCentBins];
TF1* csvBresidualJetCorrFuncs_p[nabsEtaBins][nResCentBins];
TH1F* FCRBresidualJetCorrHists_p[nabsEtaBins][nResCentBins];
TF1* FCRBresidualJetCorrFuncs_p[nabsEtaBins][nResCentBins];
TH1F* FCRcsvBresidualJetCorrHists_p[nabsEtaBins][nResCentBins];
TF1* FCRcsvBresidualJetCorrFuncs_p[nabsEtaBins][nResCentBins];
*/


Bool_t initGetResidualJetCorr_yk(){



  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++)
	{
		for(Int_t iter = 0; iter < nResCentBins; iter++)
		{

    IresidualJetCorrFuncs_yk[iabsEtaBins][iter] =  new TF1(Form("f%d",iter),"1./([0]-[1]*exp(-[2]*x)+[3]/(x-[4])/(x-[4]))",0,1000); 
			if(iter==0) // hibin 60-200
			{
      	IresidualJetCorrFuncs_yk[iabsEtaBins][iter]->SetParameters(0.99,0.08,0.01,5,15);
			}
      if(iter==1) // hibin 20-60
      {
        IresidualJetCorrFuncs_yk[iabsEtaBins][iter]->SetParameters(0.99,0.08,0.01,55,15);
      }
      if(iter==2) // hibin 0-20
      {
        IresidualJetCorrFuncs_yk[iabsEtaBins][iter]->SetParameters(1.01,0.08,0.01,150,15);
      }


		}
	}

	return true;
}



Float_t getResCorrJetPt_yk(Float_t jtPt, Int_t hiBin, double jteta, Int_t type, Float_t refpt)
{


 if(jtPt < 0){
    std::cout << "Input jtpt < 0. return -999" << std::endl;
    return -999;
  }
  else if(hiBin < 0 || hiBin > 200){
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
  if(iabsEtaBins ==1){ return -997;}


  Float_t corrJtPt =-998;
//  if(type ==0){ // for Inclusive jet
  corrJtPt = jtPt*IresidualJetCorrFuncs_yk[iabsEtaBins][centPos]->Eval(jtPt);
//  }
/*
  else if(type ==1){ // for b-jet
  corrJtPt = jtPt/BresidualJetCorrFuncs_p[iabsEtaBins][centPos]->Eval(refpt);
  }
  else if(type ==2){ // for csv>0.9 b-jet
  corrJtPt = jtPt/csvBresidualJetCorrFuncs_p[iabsEtaBins][centPos]->Eval(refpt);
  }
  else if(type ==3){ // for FCR b-jet
  corrJtPt = jtPt/FCRBresidualJetCorrFuncs_p[iabsEtaBins][centPos]->Eval(refpt);
  }

  else {
    std::cout<<"Input type is wrong , use type 0~4 to get jtpt correc, REturn -999"<<std::endl;
    return -999;
  }
*/
//  need to add more choice

  return corrJtPt;


}










/*
static double centMinCoarse[] = {0,20,60,9999999};

class Corrections{
 public:  
  Corrections(){
    for(int i = 0; i < 3; ++i){
      f[i] = new TF1(Form("f%d",i),"1./([0]-[1]*exp(-[2]*x)+[3]/(x-[4])/(x-[4]))",0,1000);
    }    
    f[0]->SetParameters(1.01,0.08,0.01,150,15);
    f[1]->SetParameters(0.99,0.08,0.01,55,15);
    f[2]->SetParameters(0.99,0.08,0.01,5,15);
  }

  int coarseCentrality(int hiBin){
    int c = 0;
    while(hiBin > centMinCoarse[c+1]) c++;
    return c;
  }

  double factor(double pt, double eta, int hiBin){
    return f[coarseCentrality(hiBin)]->Eval(pt);
  }
  TF1* f[3];
}*/

#endif
