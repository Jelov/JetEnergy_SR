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




void JetE_S(){


  double ptBin[] = {20,30,40,50,60,70,80,90,100,110,120,140,160,200,250,310,400,600};
  const int nPtBins = sizeof(ptBin)/sizeof(ptBin[0]) -1;

//  double etaBin[] = {-2,-1.6,-1.2,-0.8,-0.4,0,0.4,0.8,1.2,1.6,2};
//  const int nEtaBins = sizeof(etaBin)/sizeof(etaBin[0])-1;

  double etaBin[] = {-2,-1.6,-1.2,-0.8,-0.4,0,0.4,0.8,1.2,1.6,2};
  const int nEtaBins = sizeof(etaBin)/sizeof(etaBin[0])-1;

  double absEtaBin[] = {0,1.5,2};
  const int nabsEtaBins = sizeof(absEtaBin)/sizeof(absEtaBin[0])-1;

  int centBin[]= {0,10,20,30,40,60,100,200};
  const int nCentBins = sizeof(centBin) / sizeof(centBin[0]) -1;

  TFile *f_qcd = new TFile("../source_root/mcPbqcdakPu4PF_inc.root","READ");
  TFile *f_bjt = new TFile("../source_root/mcPbbfaakPu4PF_inc.root","READ");

  TTree *tc_qcd = (TTree*)f_qcd->Get("nt");
  TTree *tc_bjt = (TTree*)f_bjt->Get("nt");

	TH3F *h3_JES_Inc = new TH3F("h3_JES_Inc",nPtBins,ptBin,nEtaBins,etaBin,nCentBins,centBin);

	tc_qcd->Draw("jtpt/refpt:");



}

