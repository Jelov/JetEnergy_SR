#include <TH1.h>
#include <TRandom.h>
#include <TFile.h>
#include <TCanvas.h>
#include "TF1.h"
#include "TNamed.h"
#include "TMath.h"
#include <TStyle.h>

void test_histo(){

	gStyle->SetOptStat(2211);	

	TFile *fout= new TFile("test_histo.root","RECREATE");
	TH1F *source = new TH1F("source","source hist",100,-3,3);
	source->FillRandom("gaus",1000);
	TH1F *origin = new TH1F("orgin","origin hist",50,0,2);
	origin->Sumw2();


	
	// continued...

	for (Int_t i=0;i<10000;i++) {
		origin->Fill(0.2*(source->GetRandom())+1,0.002);
	}
	TH1F *final = (TH1F*)origin->Clone("final");
  final->Sumw2();
	final->SetBinContent(42,1);
	final->SetBinError(42,1);
	TCanvas *c1 = new TCanvas("c1","c1",800,1000);
	c1->Divide(1,2);
	c1->cd(1);
	origin->Draw();
	c1->cd(2);
	final->Draw();
	c1->cd();
}
