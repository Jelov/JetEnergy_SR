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




void jetE_S(){

	MySelector *qcd_Sel = new MySelector();
	TChain* ch_qcd = new TChain("nt");
	ch_qcd->Add("../source_root/mcPbqcdakPu4PF_inc.root");
	ch_qcd->Process(qcd_Sel);
	
	MySelector *bjt_Sel = new MySelector();
	TChain* ch_bjt = new TChain("nt");
	ch_bjt->Add("../source_root/mcPbbfaakPu4PF_inc.root");
	ch_bjt->Add(bjt_Sel);


}
