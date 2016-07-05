#ifndef YETKIN_CORRECTION_H
#define YETKIN_CORRECTION_H

#include "TF1.h"
#include "TFile.h"
#include "TH1F.h"
#include <string>
#include <iostream>


static double centMinCoarse[] = {0,20,60,9999999};

class Corrections{
 public:  
  Corrections(){
    for(int i = 0; i < 3; ++i){
      f[i] = new TF1(Form("f%d",i),"1./([0]-[1]*exp(-[2]*x)+[3]/(x-[4])/(x-[4]))",0,1000);
    }    
    f[0]->SetParameters(1.01,0.08,0.01,150,15);
    f[1]->SetParameters(0.99,0.08,0.01,55,15);
    f[2]->SetParameters(0.99,0.08,0.01,5,15);
  }

  int coarseCentrality(int hiBin){
    int c = 0;
    while(hiBin > centMinCoarse[c+1]) c++;
    return c;
  }

  double factor(double pt, double eta, int hiBin){
    return f[coarseCentrality(hiBin)]->Eval(pt);
  }
  TF1* f[3];
};


class Corrections2{
 public:
  Corrections2(){

    fcent = new TF1("fcent","expo",0,200);
    fcent->SetParameters(5.63,-0.0455);

    for(int i = 0; i < 200; ++i){
      f[i] = new TF1(Form("f%d",i),"1./([0]-[1]*exp(-[2]*x)+[3]/(x-[4])/(x-[4]))",0,1000);
      f[i]->SetParameters(1.,0.08,0.01,fcent->Eval(i),15);
    }
  }

  int coarseCentrality(int hiBin){
    int c = 0;
    while(hiBin > centMinCoarse[c+1]) c++;
    return c;
  }

  double factor(double pt, double eta, int hiBin){
    return f[hiBin]->Eval(pt);
  }
  TF1* f[200];
  TF1* fcent;

};


#endif
