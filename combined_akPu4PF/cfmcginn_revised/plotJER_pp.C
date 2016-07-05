// create by Cheng-Chieh Peng to show the fittting result

#include <TFile.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TH1.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TGraph.h>

const Int_t nCentBins = 3;
const Int_t centBins[nCentBins+1] = {0, 10, 30, 100};

double ptBin[] = {40,50,60,70,80,90,100,110,120,140,160,200,260,350};
const int nPtBins = sizeof(ptBin)/sizeof(ptBin[0]) -1;

double absEtaBin[] = {0,1.5,2};
const int nabsEtaBins = sizeof(absEtaBin)/sizeof(absEtaBin[0])-1;


TCanvas *C_plot[10];
int counter=0;

void plotfit(std::string jettype, TFile *f_read, std::string his_title, std::string eta_selection,std::string jet_type)
{
	C_plot[counter] = new TCanvas(Form("C_plot_%s",jettype.c_str()), Form("C_plot_%s",jettype.c_str()) );
	C_plot[counter]->Divide(1,1);	
  TH1F* h_reCorr[nCentBins];
  TLegend* le[nCentBins];

  TF1* f1_p[nCentBins];
  TF1* f2_p[nCentBins];



  // for(int iCentBins=0; iCentBins < nCentBins; iCentBins++)
  // {
		int iCentBins=0;
    h_reCorr[iCentBins] = (TH1F*)f_read->Get(Form("%s",jettype.c_str()));
    f1_p[iCentBins]= h_reCorr[iCentBins]->GetFunction("f1_p");
 	  f2_p[iCentBins] = (TF1*)f1_p[iCentBins]->Clone();


    C_plot[counter]->cd(iCentBins+1);
    le[iCentBins] = new TLegend(0.2,0.75,0.45,0.88);
    le[iCentBins]->SetBorderSize(0);
//    le[iCentBins]->AddEntry((TObject*)0,Form("Cent %d-%d %%", centBins[iCentBins], centBins[iCentBins+1]),"");
		le[iCentBins]->AddEntry((TObject*)0,jet_type.c_str(),"");
    le[iCentBins]->AddEntry((TObject*)0,eta_selection.c_str(),"");
    h_reCorr[iCentBins]->GetXaxis()->SetTitle("genJet p_{T} (GeV)");
    h_reCorr[iCentBins]->GetXaxis()->SetRangeUser(30,600);

    double ymax = h_reCorr[iCentBins]->GetMaximum();
    double ymin = h_reCorr[iCentBins]->GetMinimum();
 //   h_reCorr[iCentBins]->SetMaximum( ymax + 0.45*(ymax-ymin) );
 //   h_reCorr[iCentBins]->SetMinimum( ymin - 0.1*(ymax-ymin) );
    h_reCorr[iCentBins]->SetMaximum( 0.2 );
    h_reCorr[iCentBins]->SetMinimum( 0.0 );

//		h_reCorr[iCentBins]->SetTitle(Fom("JER %s",his_title.c_str() ) );
    h_reCorr[iCentBins]->SetTitle("");

//    h_reCorr[iCentBins]->SetTitle(Form("JER %s",his_title.c_str() ) );
//		h_reCorr[iCentBins]->GetYaxis()->SetTitle("#sigma_{Reco./Gen.} ak4PF");
    h_reCorr[iCentBins]->GetYaxis()->SetTitle("RMS/#mu_{Reco./Gen.} ak4PF pp");
    h_reCorr[iCentBins]->SetMarkerStyle(24);
    h_reCorr[iCentBins]->SetMarkerColor(4);

    f1_p[iCentBins]->SetParNames("C","S","N");

    h_reCorr[iCentBins]->Draw();
    le[iCentBins]->Draw();

    f2_p[iCentBins]->SetRange(30,600);
    f2_p[iCentBins]->SetLineStyle(7);
    f2_p[iCentBins]->Draw("SAME");
    f1_p[iCentBins]->Draw("SAME");



  // }

	C_plot[counter]->SaveAs(Form("./fitPlot/pp/fitJER_pp_%s.pdf",his_title.c_str()) );
	counter++;
	
}

void plotJER_pp()
{
	TFile *f_read = new TFile("pp_JERfit.root","READ");
	cout<<"plot the fittting result in file : "<<"pp_JERfit.root"<<endl; 
	gStyle->SetOptFit(1112);
	gStyle->SetOptStat(0);

  const char* EtaRangeArr[] ={"eta0to15","eta15to20"};
  std::string EtaRange = "eta0to15";

  std::string eta_selection="|#eta_{jet}|<2.0";
  const char *eta_selectionArr[]={"0<|#eta_{jet}|<1.5","1.5<|#eta_{jet}|<2.0"};

  for(Int_t iabsEtaBins=0; iabsEtaBins<nabsEtaBins; iabsEtaBins++){
    EtaRange = EtaRangeArr[iabsEtaBins];
		eta_selection = eta_selectionArr[iabsEtaBins];
	

	plotfit(Form("JER_pp_%s",EtaRange.c_str()), f_read, Form("Inclusive %s",EtaRange.c_str()),eta_selection, "Inclusive jet");
  plotfit(Form("BJER_pp_%s",EtaRange.c_str()), f_read,Form("b-jet %s",EtaRange.c_str()),eta_selection, "B jet");
  plotfit(Form("csvBJER_pp_%s",EtaRange.c_str()), f_read,Form("csv_B-jet %s", EtaRange.c_str()),eta_selection, "csv>0.9 B jet");
  plotfit(Form("FCRBJER_pp_%s",EtaRange.c_str()), f_read,Form("FCR_B-jet %s",EtaRange.c_str()),eta_selection, "FCR B jet");

	} // end for iabsEtaBins
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


