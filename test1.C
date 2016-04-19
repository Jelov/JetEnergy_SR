#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TH1.h>
#include <TTree.h>
#include <TMath.h>
#include <TAxis.h>
#include <TF1.h>
#include <TF2.h>
#include <TMultiGraph.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TCut.h>
#include <TChain.h>
#include <TLatex.h>



void test1()
{


   Double_t xAxis1[20] = {7.999, 9.680157, 11.71464, 14.17672, 17.15625, 20.762, 25.12557, 30.40623, 36.79673, 44.53033, 53.88931, 65.21529, 78.92163, 95.50865, 115.5818, 139.8737, 169.2711, 204.8469, 247.8998, 300.001};

	Double_t VarBinsErr[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	Double_t yArr2[20]={1.01,1.02,1.03,1.04,1.05,1.06,1.07,1.08,1.09,1.10,1.11,1.12,1.13,1.14,1.15,1.16,1.17,1.18,1.19,1.20};
	Double_t yErrArr2[20]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0};

	TGraphErrors *grer= new TGraphErrors(20, xAxis1, yArr2, VarBinsErr , yErrArr2);
//	grer->Draw();

   TH1F *jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1 = new TH1F("jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1","",19, xAxis1);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(1,2.398936);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(2,2.032025);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(3,1.614248);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(4,1.394258);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(5,1.225166);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(6,1.105735);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(7,1.037978);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(8,1.040788);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(9,1.055099);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(10,1.031672);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(11,1.010312);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(12,0.9836517);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(13,0.978806);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(14,0.99375);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(15,0.9126923);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(16,0.99);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(17,0.963);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(18,1.005024);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinContent(19,0.8500042);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(1,0.02303629);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(2,0.01680858);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(3,0.01490298);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(4,0.01096024);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(5,0.007470704);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(6,0.006059542);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(7,0.00682269);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(8,0.009143342);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(9,0.00582305);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(10,0.005684878);
	 jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(11,0.007132027);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(12,0.009490735);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(13,0.01224357);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(14,0.01951789);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(15,0.03303506);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(16,0.05037067);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(17,0.02762095);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(18,0.03301314);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetBinError(19,0.4022433);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetMinimum(0.8701);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetMaximum(1.499);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetEntries(19);
   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->SetDirectory(0);

   jtRecoOverGenVPt_Inc_FitMean_akPu4PF_cent30to100_h_copy1->Draw("E1 P");
	  grer->Draw("P");









}
