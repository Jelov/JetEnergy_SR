#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"
#include "TNamed.h"
#include "TMath.h"

#include <string>
#include <TCanvas.h>

void fitJER_test(){

  TF1* f1_p = new TF1("f1_p", Form("TMath::Sqrt([0]*[0] + [1]*[1]/x + [2]*[2]/x/x )"), 30, 200);



}
