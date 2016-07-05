#include "TF1.h"
#include "yetkin_correction2.h"

#include <TFile.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TGraph.h>
#include <iostream>
#include <TObject.h>
#include <TROOT.h>


void test(){

Corrections a;
cout<<"a.factor = "<<a.factor(30, 1.5, 100)<<endl;

	}
