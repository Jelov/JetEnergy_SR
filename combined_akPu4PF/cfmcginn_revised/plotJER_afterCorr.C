// create by Cheng-Chieh Peng to show the fittting result

#include <TFile.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TH1.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TGraph.h>

#include <TObject.h>
#include <TROOT.h>


//const Int_t nCentBins = 3;
//const Int_t centBins[nCentBins+1] = {0, 10, 30, 100};

const Int_t nCentBins = 8;
const  int centBins[nCentBins+1]= {0,5,10,15,20,30,50,70,100};

double ptBin[] = {20,30,40,50,60,70,80,90,100,110,120,140,160,200,250,310,400,600};
//double ptBin[] = {40,50,60,70,80,90,100,110,120,140,160,200,260,350};
const int nPtBins = sizeof(ptBin)/sizeof(ptBin[0]) -1;

const Int_t nabsEtaBins = 2;
const Double_t absEtaBin[nabsEtaBins+1] = {0,1.5,2};


TCanvas *C_plot[2][10];
int counter=0;

void plotfit(std::string jettype, TFile *f_read, std::string his_title)
{

  const char* EtaRangeArr[] ={"eta0to15","eta15to20"};
  std::string EtaRange = "eta0to15";
  TH1F* h_reCorr[nabsEtaBins][nCentBins];
	TF1* f1_p[nabsEtaBins][nCentBins];
	TF1* f2_p[nabsEtaBins][nCentBins];
  TLegend* le[nabsEtaBins][nCentBins];

  for(Int_t iabsEtaBins =0; iabsEtaBins<nabsEtaBins;iabsEtaBins++){
      EtaRange = EtaRangeArr[iabsEtaBins];

  C_plot[iabsEtaBins][counter] = new TCanvas(Form("C_plot_%s_%s",jettype.c_str(),EtaRange.c_str()), Form("C_plot_%s_%s",jettype.c_str(),EtaRange.c_str()) );
  C_plot[iabsEtaBins][counter]->Divide(4,2);

  for(int iCentBins=0; iCentBins < nCentBins; iCentBins++)
  {
    h_reCorr[iabsEtaBins][iCentBins] = (TH1F*)f_read->Get(Form("%s_cent%dto%d_%s",jettype.c_str(), centBins[iCentBins], centBins[iCentBins+1],EtaRange.c_str()));
	  f1_p[iabsEtaBins][iCentBins]= h_reCorr[iabsEtaBins][iCentBins]->GetFunction("f1_p");
//		cout<<"f1_p[iabsEtaBins][iCentBins] par1 = "<<f1_p[iabsEtaBins][iCentBins]->GetParameter(1)<<endl;
//    cout<<"f1_p[iabsEtaBins][iCentBins] par1 = "<<f1_p[iabsEtaBins][iCentBins]->GetExpFormula() <<endl;
	
	 f2_p[iabsEtaBins][iCentBins] = (TF1*)f1_p[iabsEtaBins][iCentBins]->Clone();

//    cout<<"f2_p[iabsEtaBins][iCentBins] par1 = "<<f2_p[iabsEtaBins][iCentBins]->GetParameter(1)<<endl;
//    cout<<"f2_p[iabsEtaBins][iCentBins] par1 = "<<f2_p[iabsEtaBins][iCentBins]->GetExpFormula() <<endl;


    C_plot[iabsEtaBins][counter]->cd(iCentBins+1);
    le[iabsEtaBins][iCentBins] = new TLegend(0.2,0.75,0.45,0.88);
    le[iabsEtaBins][iCentBins]->SetBorderSize(0);
    le[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,Form("Cent %d-%d %%", centBins[iCentBins], centBins[iCentBins+1]),"");
//    le[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,"|#eta_{jet}|<2.0","");
      if(iabsEtaBins==0){le[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,"0<|#eta_{jet}|<1.5","");}
      if(iabsEtaBins==1){le[iabsEtaBins][iCentBins]->AddEntry((TObject*)0,"1.5<|#eta_{jet}|<2","");}



    h_reCorr[iabsEtaBins][iCentBins]->GetXaxis()->SetTitle("genJet p_{T} (GeV)");

		h_reCorr[iabsEtaBins][iCentBins]->GetXaxis()->SetRangeUser(30,600);

//    double ymax = h_reCorr[iabsEtaBins][iCentBins]->GetMaximum();

//    double ymin = h_reCorr[iabsEtaBins][iCentBins]->GetMinimum();

//    h_reCorr[iabsEtaBins][iCentBins]->SetMaximum( ymax + 0.45*(ymax-ymin) );
//    h_reCorr[iabsEtaBins][iCentBins]->SetMinimum( ymin - 0.1*(ymax-ymin) );
    h_reCorr[iabsEtaBins][iCentBins]->SetMaximum( 0.45 );
    h_reCorr[iabsEtaBins][iCentBins]->SetMinimum( 0.00);


    h_reCorr[iabsEtaBins][iCentBins]->SetTitle(Form("JER %s",his_title.c_str() ) );
//    h_reCorr[iabsEtaBins][iCentBins]->GetYaxis()->SetTitle("#sigma/#mu_{Reco./Gen.} akPu4PF");
    h_reCorr[iabsEtaBins][iCentBins]->GetYaxis()->SetTitle("RMS/#mu_{Reco./Gen.} akPu4PF");

    // h_reCorr[iabsEtaBins][iCentBins]->GetYaxis()->SetTitleOffset(1.4);
		h_reCorr[iabsEtaBins][iCentBins]->SetMarkerStyle(24);
    h_reCorr[iabsEtaBins][iCentBins]->SetMarkerColor(4);

		f1_p[iabsEtaBins][iCentBins]->SetParNames("C","S","N");
		
    h_reCorr[iabsEtaBins][iCentBins]->Draw();
    le[iabsEtaBins][iCentBins]->Draw();
		f2_p[iabsEtaBins][iCentBins]->SetRange(30,600);
//		f2_p[iabsEtaBins][iCentBins]->SetLineColor(6);
		f2_p[iabsEtaBins][iCentBins]->SetLineStyle(7);
		f2_p[iabsEtaBins][iCentBins]->Draw("SAME");
//    f1_p[iabsEtaBins][iCentBins]->SetLineColor(3);
    f1_p[iabsEtaBins][iCentBins]->Draw("SAME");
	


//    h_reCorr[iCentBins] = (TH1F*)f_read->Get(Form("%s_cent%dto%d_h",jettype.c_str(), centBins[iCentBins], centBins[iCentBins+1]));
//    C_plot[counter]->cd(iCentBins+1);
//    le[iCentBins] = new TLegend(0.2,0.75,0.45,0.88);
//    le[iCentBins]->SetBorderSize(0);
//    le[iCentBins]->AddEntry((TObject*)0,Form("Cent %d-%d %%", centBins[iCentBins], centBins[iCentBins+1]),"");
//    le[iCentBins]->AddEntry((TObject*)0,"|#eta_{jet}|<2.0","");

//    h_reCorr[iCentBins]->GetXaxis()->SetTitle("refpt [GeV]");
//    double ymax = h_reCorr[iCentBins]->GetMaximum();
//    double ymin = h_reCorr[iCentBins]->GetMinimum();
 //   h_reCorr[iCentBins]->SetMaximum( ymax + 0.45*(ymax-ymin) );
 //   h_reCorr[iCentBins]->SetMinimum( ymin - 0.1*(ymax-ymin) );
//    h_reCorr[iCentBins]->SetMaximum( 0.4 );
//    h_reCorr[iCentBins]->SetMinimum( 0.06 );

//		h_reCorr[iCentBins]->SetTitle(Form("JER %s",his_title.c_str() ) );
//    h_reCorr[iCentBins]->SetTitle("");
//		h_reCorr[iCentBins]->GetYaxis()->SetTitle("#sigma_{Reco./Gen.} akPu4PF");
//    h_reCorr[iCentBins]->Draw();
//    le[iCentBins]->Draw();


  }

	C_plot[iabsEtaBins][counter]->SaveAs(Form("./fitPlot/fitJER_Corr_%s_%s.pdf",his_title.c_str(),EtaRange.c_str()) );
	} // end for iabsEtaBins

	counter++;
	
}

void plotJER_afterCorr()
{
	TFile *f_read = new TFile("CORR_JER.root","READ");
	cout<<"plot the fittting result in file : "<<"CORR_JER.root"<<endl;

/*	
	TStyle *MyStyle = new TStyle("MyStyle","My Root Styles");
	MyStyle->SetMarkerStyle(
  MyStyle->SetTitleOffset(1.5, "y");
	MyStyle->SetOptFit(1112);
	MyStyle->SetOptStat(0);
  gROOT->SetStyle("MyStyle");
*/
	gStyle->SetMarkerStyle(24);
	gStyle->SetOptFit(1112);
	gStyle->SetOptStat(0);



	plotfit("JERCorr", f_read, "Inclusice");
	cout<<"check1"<<endl;
  plotfit("BJERCorr", f_read,"b-jet");
	cout<<"check2"<<endl;
  plotfit("csvBJERCorr", f_read,"csv B-jet");
  cout<<"check3"<<endl;
  plotfit("FCRBJERCorr", f_read,"FCR B-jet");
  cout<<"check4"<<endl;


//  plotfit("FCRcsvBJERCorr", f_read,"FCR csv B-jet");


/*
	TCanvas *C_plot = new TCanvas("C_plot","C_plot");
	C_plot->Divide(2,2);
	TH1F* h_reCorr[nCentBins];
	TLegend* le[nCentBins];
	for(int iCentBins=0; iCentBins < nCentBins; iCentBins++)
	{
		h_reCorr[iCentBins] = (TH1F*)f_read->Get(Form("resCorr_cent%dto%d_h", centBins[iCentBins], centBins[iCentBins+1]));
		C_plot->cd(iCentBins+1);
		le[iCentBins] = new TLegend(0.2,0.75,0.45,0.88);
		le[iCentBins]->SetBorderSize(0);
		le[iCentBins]->AddEntry((TObject*)0,Form("Cent %d-%d %%", centBins[iCentBins], centBins[iCentBins+1]),"");
		h_reCorr[iCentBins]->GetXaxis()->SetTitle("refpt [GeV]");
		double ymax = h_reCorr[iCentBins]->GetMaximum();
		double ymin = h_reCorr[iCentBins]->GetMinimum();
		h_reCorr[iCentBins]->SetMaximum( ymax + 0.45*(ymax-ymin) );
		h_reCorr[iCentBins]->SetMinimum( ymin - 0.1*(ymax-ymin) );
		h_reCorr[iCentBins]->Draw();	
		le[iCentBins]->Draw();
	}
*/
	// plotting difference

/*	
	TF1 * residualJetCorrFuncs_p[nCentBins];
	double ptBinCenter[nPtBins];
	double ptBinErr[nPtBins];
	double corrFactor[nCentBins][nPtBins];
	double hist_Value[nCentBins][nPtBins];
	double closure[nCentBins][nPtBins];	
	TGraph *gr_closure[nCentBins];
	TCanvas *c_closure = new TCanvas("c_closure","c_closure");
	c_closure->Divide(2,2);
	TLegend* le1[nCentBins];

	
	for(int iCentBins=0; iCentBins < nCentBins; iCentBins++)
	{
		c_closure->cd(iCentBins+1);
//	  h_reCorr[iCentBins] = (TH1F*)f_read->Get(Form("resCorr_cent%dto%d_h", centBins[iCentBins], centBins[iCentBins+1]));
		residualJetCorrFuncs_p[iCentBins] = (TF1*)h_reCorr[iCentBins]->GetFunction("f1_p");
		for(int iPtBins =0; iPtBins<nPtBins ; iPtBins++)
		{
			ptBinCenter[iPtBins] = (ptBin[iPtBins]+ptBin[iPtBins+1])/2;
			ptBinErr[iPtBins] = (ptBin[iPtBins+1]-ptBin[iPtBins])/2;
			corrFactor[iCentBins][iPtBins] = residualJetCorrFuncs_p[iCentBins]->Eval(ptBinCenter[iPtBins]);
			hist_Value[iCentBins][iPtBins] = h_reCorr[iCentBins]->GetBinContent(iPtBins+1);
			closure[iCentBins][iPtBins] = corrFactor[iCentBins][iPtBins] -hist_Value[iCentBins][iPtBins];	
			cout<<"corrFactor ["<<iCentBins<<"]"<<"["<<iPtBins<<"] = "<< corrFactor[iCentBins][iPtBins]<<endl;
		}
		cout<<endl;
		gr_closure[iCentBins] = new TGraph(nPtBins, ptBinCenter, closure[iCentBins]);
		gr_closure[iCentBins]->SetTitle("JEC closre"); 
		gr_closure[iCentBins]->GetXaxis()->SetTitle("refpt");
		gr_closure[iCentBins]->Draw("AP*l");
    le1[iCentBins] = new TLegend(0.6,0.75,0.88,0.88);
    le1[iCentBins]->SetBorderSize(0);
    le1[iCentBins]->AddEntry((TObject*)0,Form("Cent %d-%d %%", centBins[iCentBins], centBins[iCentBins+1]),"");
	  le1[iCentBins]->Draw();

	
	}
*/

}


