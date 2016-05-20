#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TLegend.h>

void pthat_weight(){

//	TFile *f_bjt = new TFile("./source_root/mcPbbjtakPu4PF_inc.root");	
	TFile *f_bjt = new TFile("./source_root/mcPbbfaakPu4PF_inc.root");
	TFile *f_qcd = new TFile("./source_root/mcPbqcdakPu4PF_inc.root");

	TTree *t_bjt  =(TTree*)f_bjt->Get("nt");
	TTree *t_qcd  =(TTree*)f_qcd->Get("nt");

	TFile *f_qcd30 = new TFile("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd30/merged_HiForestAOD.root");
	TFile *f_bjt30 = new TFile("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/bjet30/merged_HiForestAOD.root");
	
	TTree *t_bjt30 =(TTree*)f_bjt30->Get("akPu4PFJetAnalyzer/t");	
	TTree *t_qcd30 =(TTree*)f_qcd30->Get("akPu4PFJetAnalyzer/t");

	int pthatbin =200;
	double pthatlow =0;
	double pthathi =200;

	TH1D *h_pthat_bjt = new TH1D("h_pthat_bjt","bjet",200,0,400);
	TH1D *h_pthat_qcd = new TH1D("h_pthat_qcd","qcd",200,0,400);

  TH1D *h_pthat_bjtW = new TH1D("h_pthat_bjtW","bjet* weight",200,0,400);
  TH1D *h_pthat_qcdW = new TH1D("h_pthat_qcdW","qcd*weight",200,0,400);

  TH1D *h_pthat30_bjt = new TH1D("h_pthat30_bjt","bjet_pthat30",200,0,400);
  TH1D *h_pthat30_qcd = new TH1D("h_pthat30_qcd","qcd_pthat30",200,0,400);	

	TH1D *h_pthat_bjtR = new TH1D("h_pthat_bjtR","bjtW/pthat30",200,0,400);
	TH1D *h_pthat_qcdR = new TH1D("h_pthat_qcdR","qcdW/pthat30",200,0,400);;

	TCanvas *c_pthat = new TCanvas("c_pthat","c_pthat");
	c_pthat->Divide(2,2);
	c_pthat->cd(1);
  t_bjt->Draw("pthat>>h_pthat_bjt","pthat<400 && abs(jteta)<2");
/*	TLegend *l_bjt = new TLegend(0.50,0.75,0.68,0.88);
	l_bjt->AddEntry((TObject*)0,"bjet","");
	l_bjt->SetBorderSize(0);
	l_bjt->Draw();
*/	
  c_pthat->cd(2);
  t_qcd->Draw("pthat>>h_pthat_qcd","pthat<400 && abs(jteta)<2");
	c_pthat->cd(3);
	gPad->SetLogy();
  t_bjt->Draw("pthat>>h_pthat_bjtW","pthatweight*(pthat<400 && abs(jteta)<2)");
//  t_bjt->Draw("pthat>>h_pthat_bjtW","pthatweight*(pthat<120 && abs(jteta)<2)");
  c_pthat->cd(4);
  gPad->SetLogy();
  t_qcd->Draw("pthat>>h_pthat_qcdW","pthatweight*(pthat<400 && abs(jteta)<2)");
//  t_qcd->Draw("pthat>>h_pthat_qcdW","pthatweight*(pthat<120 && abs(jteta)<2)");


	TCanvas *c_pthat_ratio = new TCanvas("c_pthat_ratio","c_pthat_ratio");
	c_pthat_ratio->Divide(2,2);	
	c_pthat_ratio->cd(1);
	t_bjt->Draw("pthat>>h_pthat30_bjt","(abs(jteta)<2 && pthatsample ==30)");
	c_pthat_ratio->cd(2);
  t_qcd->Draw("pthat>>h_pthat30_qcd","(abs(jteta)<2 && pthatsample ==30)");

	double N_pthat30_bjt = h_pthat30_bjt->Integral();
	double N_pthat30_qcd = h_pthat30_qcd->Integral(); 

	double N_pthat_bjtW = h_pthat_bjtW->Integral();
	double N_pthat_qcdW = h_pthat_qcdW->Integral();
 

	c_pthat_ratio->cd(3);
	h_pthat_bjtR->Divide(h_pthat_bjtW,h_pthat30_bjt,N_pthat30_bjt,N_pthat_bjtW);
	h_pthat_bjtR->SetMaximum(3);
	h_pthat_bjtR->SetMinimum(0.5);
	h_pthat_bjtR->Draw();
	c_pthat_ratio->cd(4);
  h_pthat_qcdR->Divide(h_pthat_qcdW,h_pthat30_qcd,N_pthat30_qcd,N_pthat_qcdW);
  h_pthat_qcdR->SetMaximum(3);
  h_pthat_qcdR->SetMinimum(0.5);
	h_pthat_qcdR->Draw();

	TCanvas *c_pthat1 = new TCanvas("c_pthat1","c_pthat1");	
	c_pthat1->Divide(2,1);
	c_pthat1->cd(1);
  gPad->SetLogy();
	h_pthat_bjtW->GetXaxis()->SetTitle("pthat");
	h_pthat_bjtW->Draw();
	c_pthat1->cd(2);
  gPad->SetLogy();
  h_pthat_qcdW->GetXaxis()->SetTitle("pthat");
	h_pthat_qcdW->Draw();
/*	c_pthat1->cd(3);
	h_pthat_bjtR->Draw();
	c_pthat1->cd(4);
	h_pthat_qcdR->Draw();
*/
	



}
