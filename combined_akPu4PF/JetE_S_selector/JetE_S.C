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

//  double ptBin[] = {20,30,40,50,60,70,80,90,100,110,120,140,160,200,250,310,400,600};
  //  double ptBin[] ={60,70,80,90,100,110,120,140,160,200};
	double ptBin[] = {60,80,100}
  const int nPtBins = sizeof(ptBin)/sizeof(ptBin[0]) -1;

  double etaBin[] = {-2,-1.6,-1.2,-0.8,-0.4,0,0.4,0.8,1.2,1.6,2};
  const int nEtaBins = sizeof(etaBin)/sizeof(etaBin[0])-1;

  double absEtaBin[] = {0,1.5,2};
  const int nabsEtaBins = sizeof(absEtaBin)/sizeof(absEtaBin[0])-1;

//  int centBin[] = {0,20,60,100,200};
//  int centBin[] = {0,20,60,200};
	int centBin[] = {0,60,200}
  // int centBin[]= {0,10,20,30,40,60,100,140,200};
  const int nCentBins = sizeof(centBin) / sizeof(centBin[0]) -1;


void jetE_S(){

// use MySelector to read tree, write jtpt/refpt it into 2-d TH1  
// MySelector read 

	MySelector *qcd_Sel = new MySelector();
	TChain* ch_qcd = new TChain("nt");
	ch_qcd->Add("../source_root/mcPbqcdakPu4PF_inc.root");
	ch_qcd->Process(qcd_Sel);
	
	MySelector *bjt_Sel = new MySelector();
	TChain* ch_bjt = new TChain("nt");
	ch_bjt->Add("../source_root/mcPbbfaakPu4PF_inc.root");
	ch_bjt->Add(bjt_Sel);


}
