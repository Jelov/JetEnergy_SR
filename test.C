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

int test_fun( double *yptr, TCut cutb, const double *ptbin_ptr, TChain *tc, double xtest){

	cout<<"tc getname , "<<tc->GetName()<<" , tc gettitle = "<<tc->GetTitle() <<endl;
	cout<<"sizeof ptbin_ptr = "<<sizeof(ptbin_ptr)<<" , size of ptbin_ptr[0] = "<<sizeof(ptbin_ptr[0])<<endl;
	cout<<"ptbin_ptr[1]= "<<ptbin_ptr[1]<<endl;
	TCut cuta = "pt>10";
  cout<<"cutb = "<<cutb<<endl;
	yptr[0] = 1;
	yptr[1] = 2;
	yptr[2] = 3;
	xtest=4;
	cout<<"inside test_fun"<<endl;

	return 1;
}

int test_Darray(double **data2d){

 cout<<"data2d[0][1] = "<<data2d[0][1]<<endl;
  cout<<"data2d[1][2] = "<<data2d[1][2]<<endl;


//	int nrows=3;
//	int ncols=4;
/*
  for(int irows =0; irows < nrows; irows++)
  {
    for(int icols =0; icols < ncols; icols++)
    {
//      yarray2[irows][icols]= (irows+1)*100+ (iclos+1);
      cout<<"yptr2 = "<<yptr2[irows][icols]<<endl;

    }
    
  }

*/


	return 1;
}

void test()
{
/*
	TH1F *h1 = new TH1F("tH1","",10,0,10);
	TLegend *leg = new TLegend(0.1,0.5,0.5,0.9);
	TCanvas *c = new TCanvas();
	c->cd();
	leg->AddEntry(Form("tH%i",1),"test");
	h1->Draw();
	leg->Draw("same");
	*/
/*
 TCanvas *c2 = new TCanvas("c2","c2",600,400);
   TGraph *g[3];
   Double_t x[10] = {0,1,2,3,4,5,6,7,8,9};
   Double_t y[10] = {1,2,3,4,5,5,4,3,2,1};
   TMultiGraph *mg = new TMultiGraph();
   for (int i=0; i<3; i++) {
      g[i] = new TGraph(10, x, y);
      g[i]->SetMarkerStyle(20);
      g[i]->SetMarkerColor(i+2);
      for (int j=0; j<10; j++) y[j] = y[j]-1;
      mg->Add(g[i]);
   }
   mg->Draw("APL");
   mg->GetXaxis()->SetTitle("E_{#gamma} (GeV)");
   mg->GetYaxis()->SetTitle("Coefficients");
   // Change the axis limits
   gPad->Modified();
   mg->GetXaxis()->SetLimits(1.5,7.5);
   mg->SetMinimum(0.);
   mg->SetMaximum(10.);
*/




/*
	TMultiGraph *mugr = new TMultiGraph();
	mugr->Draw("APL");
  mugr->GetXaxis()->SetTitle("E_{#gamma} (GeV)");
*/

	int ntype=2;
	const int npoints=3;
//	double *yarray2[2];
//	double **yarray2;
	double data1[npoints]={1,2,3};
	double data2[npoints]={11,12,13};
//	double *data2d[2]={data1,data2};
	double *data2d[ntype];
  data2d[0]=data1;
	data2d[1]=data2;
	// yarray2 = new double *[ncols];
	 cout<<"in main"<<endl;
	cout<<"data2d[0][1] = "<<data2d[0][1]<<endl;
  cout<<"data2d[1][2] = "<<data2d[1][2]<<endl;
	
	int aaa = test_Darray(data2d);

/*
	for(int irows =0; irows < ntype; irows++)
	 {
		for(int icols =0; icols < npoints; icols++)
		{
	//		yarray2[irows][icols]= (irows+1)*100+ (icols+1);
			cout<<"yarray2 = "<<data2d[ntype][npoints]<<endl;	
		
		}	
	}
*/

	// int aaa = test_Darray(yarray2);
	cout<<"after calling 2d function"<<endl;



/*
  TChain *tc_akPu4PF = new TChain("akPu4PFJetAnalyzer/t", "akPu4PFJetAnalyzer");
//  tc_akPu4PF->AddFriend("HiEvtAnalyzer/HiTree");
  tc_akPu4PF->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");
	TChain *tc_akpuHi = new TChain("hiEvtAnalyzer/HiTree");
	tc_akpuHi->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");
	tc_akPu4PF->AddFriend(tc_akpuHi);
*/
//	tc_akPu4PF->AddFriend("hiEvtAnalyzer/HiTree","/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");
//tc_akPu4PF->AddFriend("hiEvtAnalyzer/HiTree");

  TChain *tc_akPu4PF = new TChain("akPu4PFJetAnalyzer/t", "akPu4PF");
  TChain *tc_akVs4PF = new TChain("akVs4PFJetAnalyzer/t", "akVs4PF");
  TChain *tc_akPu4Calo = new TChain("akPu4CaloJetAnalyzer/t", "akPu4Calo");
  TChain *tc_akVs4Calo = new TChain("akVs4CaloJetAnalyzer/t", "akVs4Calo");

  TChain *tc_Hiak = new TChain("hiEvtAnalyzer/HiTree");

  tc_Hiak->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");
	
//	tc_Hiak->Add("root://xrootd.unl.edu//store/user/rbi/merged/dgulhan-Pythia8_Dijet30_pp_TuneCUETP8M1_Hydjet_MinBias_5020GeV_RECODEBUG_758_PrivMC_forest_v28/0.root");

//tc_akPu4PF->Add("root://xrootd.unl.edu//store/user/rbi/merged/dgulhan-Pythia8_Dijet30_pp_TuneCUETP8M1_Hydjet_MinBias_5020GeV_RECODEBUG_758_PrivMC_forest_v28/0.root");

  tc_akPu4PF->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");
  tc_akVs4PF->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");
  tc_akPu4Calo->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");
  tc_akVs4Calo->Add("/mnt/hadoop/store/user/kjung/Pythia6_PbPb_5TeV_MC_fromMatt/qcd80/*.root");

  tc_akPu4PF->AddFriend(tc_Hiak);
//  tc_akVs4PF->AddFriend(tc_Hiak);
//  tc_akPu4Calo->AddFriend(tc_Hiak);
//  tc_akVs4Calo->AddFriend(tc_Hiak);



	TCanvas *c_friend = new TCanvas("c_friend","c_friend");
//	c_friend->Divide(2,2);
	c_friend->cd(1);
	tc_akPu4PF->Draw("hiBin");

 	TLegend* leg = new TLegend(0.6, 0.6, .8, .8);
   TH1* h = new TH1F("", "", 1, 0, 1);
   leg->AddEntry(h, "Histogram \"h\"", "l");
//   leg->AddEntry((TObject*)0, "", "");
   leg->AddEntry((TObject*)0, "Some text", "");
   leg->AddEntry((TObject*)0, "", "");
//   leg->AddEntry(h, "Histogram \"h\" again", "l");
	 leg->SetBorderSize(0);
   leg->Draw();

 	 TLegend* leg1 = new TLegend(0.2, 0.2, .3, .3);
   TH1* h1 = new TH1F("", "", 1, 0, 1);
   leg1->AddEntry(h1, "Histogram \"h\"", "l");
//   leg->AddEntry((TObject*)0, "", "");
   leg1->AddEntry((TObject*)0, "Some text", "");
   leg1->AddEntry((TObject*)0, "", "");
//   leg->AddEntry(h, "Histogram \"h\" again", "l");
   leg1->Draw();



/*
	c_friend->cd(2);
	tc_akPu4PF->Draw("hiBin","refpt>30");
	c_friend->cd(3);
	tc_akPu4PF->Draw("refpt","refpt>30");
  c_friend->cd(4);
  tc_akPu4PF->Draw("refpt","refpt>30 && hiBin>40");
*/
/*
  TCanvas *c_friend1 = new TCanvas("c_friend1","c_friend1");
  c_friend1->Divide(2,2);
  c_friend1->cd(1);
  tc_akPu4Calo->Draw("hiBin");
  c_friend1->cd(2);
  tc_akPu4Calo->Draw("hiBin","refpt>30");
  c_friend1->cd(3);
  tc_akPu4Calo->Draw("refpt","refpt>30");
  c_friend1->cd(4);
  tc_akPu4Calo->Draw("refpt","refpt>30 && hiBin>40");
*/


/*
	double ptBin1[4] = {30,40,50,60};
	double x1[3]={0,0,0};
	double xtest=-1; // not work
	cout<<"x1[0] = "<<x1[0]<<" , x1[0] = "<<x1[1]<<" , xtest= "<<xtest<<endl;
	TCut cut= "eta<5";
	int funtest = test_fun(x1,cut,ptBin1, tc_akPu4PF, xtest);	
  cout<<"x1[0] = "<<x1[0]<<" , x1[0] = "<<x1[1]<<" , xtest= "<<xtest<<endl;


	int nBins=2;
	int ibin=1;
	TF1 *f1[nBins];
	f1[ibin] = new TF1(Form("f1_%d",ibin), "gaus",0,2 );
	f1[ibin]->SetParameter(0,100);
	f1[ibin]->SetParameter(1,1);
	f1[ibin]->SetParameter(2,0.3);
	f1[ibin]->Draw();


	// test TMultiGraph with TLegend

	const int nJetA=2;
	const int nPtBins=3;
	int n=3;
	double fit_Rmean_pt[nJetA][nPtBins];
	double fit_RmeanErr_pt[nJetA][nPtBins];

	for(int iJetA=0; iJetA<nJetA; iJetA++)
	{
		for (int ibin=0;ibin<nPtBins;ibin++)
		{
			fit_Rmean_pt[iJetA][ibin]=1+0.3*iJetA*iJetA+0.1*ibin;
			fit_RmeanErr_pt[iJetA][ibin]=0.1*iJetA*iJetA+0.05*ibin*ibin;
		}

	}

  double ptBin[nPtBins+1] = {30,40,50,60};
  double ptbin_gr[nPtBins];
  double ptbinErr_gr[nPtBins];
  for (int ibin=0; ibin<nPtBins; ibin++)
  {
    ptbin_gr[ibin]=(ptBin[ibin]+ptBin[ibin])/2;
    ptbinErr_gr[ibin]=0;
    //        ptbin_gr_error= ; 
  }

  gStyle->SetEndErrorSize(3);
  TGraphErrors *gr_meanR_pt[nJetA];
  gr_meanR_pt[0] = new TGraphErrors(n,ptbin_gr,fit_Rmean_pt[0],ptbinErr_gr,fit_RmeanErr_pt[0]);
	gr_meanR_pt[0]->SetName("gr_meanR_pt_0");
  gr_meanR_pt[0]->SetLineColor(1);
  gr_meanR_pt[0]->SetMarkerColor(1);
  gr_meanR_pt[0]->SetMarkerStyle(2);
  //      gr_meanR_pt[0]->Draw("AC*");
  gr_meanR_pt[1] = new TGraphErrors(n,ptbin_gr,fit_Rmean_pt[1],ptbinErr_gr,fit_RmeanErr_pt[1]);
  gr_meanR_pt[1]->SetName("gr_meanR_pt_1");
  gr_meanR_pt[1]->SetLineColor(2);
  gr_meanR_pt[1]->SetMarkerColor(2);
  gr_meanR_pt[1]->SetMarkerStyle(3);

  TMultiGraph *mg_Rmean_pt = new TMultiGraph();
  mg_Rmean_pt->Add(gr_meanR_pt[0]);
  mg_Rmean_pt->Add(gr_meanR_pt[1]);
  mg_Rmean_pt->Draw("ALP");
  TLegend *leg_Rmean_pt = new TLegend(0.6,0.7,0.9,0.9);
  leg_Rmean_pt->AddEntry("gr_meanR_pt_0", "tc_akPu4PF","l");
  leg_Rmean_pt->AddEntry("gr_meanR_pt_1", "tc_akPu4PF","l");
	leg_Rmean_pt->Draw();

*/
}

