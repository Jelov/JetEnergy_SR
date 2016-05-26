//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May 25 15:44:53 2016 by ROOT version 6.02/13
// from TTree nt/nt
// found on file: mcPbqcdakPu4PF_inc.root
//////////////////////////////////////////////////////////

#ifndef MySelector_h
#define MySelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

class MySelector : public TSelector {
	public :
		TTree          *fChain;   //!pointer to the analyzed TTree or TChain

		// Fixed size dimensions of array or collections stored in the TTree if any.
		const Int_t kMaxdiscr_csvV1 = 1;

		// Declaration of leaf types
		Float_t         run;
		Float_t         lumi;
		Float_t         event;
		Float_t         hltCaloJet40;
		Float_t         hltCaloJet60;
		Float_t         hltCaloJet80;
		Float_t         hltCSV60;
		Float_t         hltCSV80;
		Float_t         bProdCode;
		Float_t         cProdCode;
		Float_t         pthat;
		Float_t         pthatsample;
		Float_t         pthatweight;
		Float_t         bin;
		Float_t         vz;
		Float_t         hiHF;
		Float_t         subid;
		Float_t         refpt;
		Float_t         rawpt;
		Float_t         jtpt;
		Float_t         jtphi;
		Float_t         jteta;
		Float_t         discr_csvV1_;
		Float_t         refparton_flavorForB;
		Float_t         isPrimary;
		Float_t         refparton_flavorProcess;
		Float_t         svtxm;
		Float_t         discr_prob;
		Float_t         svtxdls;
		Float_t         svtxpt;
		Float_t         svtxntrk;
		Float_t         nsvtx;
		Float_t         nselIPtrk;
		Float_t         centrWeight;
		Float_t         weight;
		Float_t         vertexWeight;

		// List of branches
		TBranch        *b_run;   //!
		TBranch        *b_lumi;   //!
		TBranch        *b_event;   //!
		TBranch        *b_hltCaloJet40;   //!
		TBranch        *b_hltCaloJet60;   //!
		TBranch        *b_hltCaloJet80;   //!
		TBranch        *b_hltCSV60;   //!
		TBranch        *b_hltCSV80;   //!
		TBranch        *b_bProdCode;   //!
		TBranch        *b_cProdCode;   //!
		TBranch        *b_pthat;   //!
		TBranch        *b_pthatsample;   //!
		TBranch        *b_pthatweight;   //!
		TBranch        *b_bin;   //!
		TBranch        *b_vz;   //!
		TBranch        *b_hiHF;   //!
		TBranch        *b_subid;   //!
		TBranch        *b_refpt;   //!
		TBranch        *b_rawpt;   //!
		TBranch        *b_jtpt;   //!
		TBranch        *b_jtphi;   //!
		TBranch        *b_jteta;   //!
		TBranch        *b_discr_csvV1_;   //!
		TBranch        *b_refparton_flavorForB;   //!
		TBranch        *b_isPrimary;   //!
		TBranch        *b_refparton_flavorProcess;   //!
		TBranch        *b_svtxm;   //!
		TBranch        *b_discr_prob;   //!
		TBranch        *b_svtxdls;   //!
		TBranch        *b_svtxpt;   //!
		TBranch        *b_svtxntrk;   //!
		TBranch        *b_nsvtx;   //!
		TBranch        *b_nselIPtrk;   //!
		TBranch        *b_centrWeight;   //!
		TBranch        *b_weight;   //!
		TBranch        *b_vertexWeight;   //!

		int jet_type;

		//   MySelector(TTree * /*tree*/ =0) : fChain(0) { }
		MySelector(int jettype = 0 ,TTree * /*tree*/ =0) : fChain(0) { 
			jet_type = jettype;	
		}


		virtual ~MySelector() { }
		virtual Int_t   Version() const { return 2; }
		virtual void    Begin(TTree *tree);
		virtual void    SlaveBegin(TTree *tree);
		virtual void    Init(TTree *tree);
		virtual Bool_t  Notify();
		virtual Bool_t  Process(Long64_t entry);
		virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
		virtual void    SetOption(const char *option) { fOption = option; }
		virtual void    SetObject(TObject *obj) { fObject = obj; }
		virtual void    SetInputList(TList *input) { fInput = input; }
		virtual TList  *GetOutputList() const { return fOutput; }
		virtual void    SlaveTerminate();
		virtual void    Terminate();


		// VarBinning
  double ptBin[] = {20,30,40,50,60,70,80,90,100,110,120,140,160,200,250,310,400,600};
  const int nPtBins = sizeof(ptBin)/sizeof(ptBin[0]) -1;

  double etaBin[] = {-2,-1.6,-1.2,-0.8,-0.4,0,0.4,0.8,1.2,1.6,2};
  const int nEtaBins = sizeof(etaBin)/sizeof(etaBin[0])-1;

  double absEtaBin[] = {0,1.5,2};
  const int nabsEtaBins = sizeof(absEtaBin)/sizeof(absEtaBin[0])-1;

  int centBin[]= {0,10,20,30,40,60,100,200};
  const int nCentBins = sizeof(centBin) / sizeof(centBin[0]) -1;


		// TH1F

	TH1F* jtRecoOverGenVPt_Inc_FitMean_akPu4PF[nabsEtaBins][nCentBins][nPtBins];




		ClassDef(MySelector,0);
};

#endif

#ifdef MySelector_cxx
void MySelector::Init(TTree *tree)
{
	// The Init() function is called when the selector needs to initialize
	// a new tree or chain. Typically here the branch addresses and branch
	// pointers of the tree will be set.
	// It is normally not necessary to make changes to the generated
	// code, but the routine can be extended by the user if needed.
	// Init() will be called many times when running on PROOF
	// (once per file to be processed).

	// Set branch addresses and branch pointers
	if (!tree) return;
	fChain = tree;
	fChain->SetMakeClass(1);

	fChain->SetBranchAddress("run", &run, &b_run);
	fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
	fChain->SetBranchAddress("event", &event, &b_event);
	fChain->SetBranchAddress("hltCaloJet40", &hltCaloJet40, &b_hltCaloJet40);
	fChain->SetBranchAddress("hltCaloJet60", &hltCaloJet60, &b_hltCaloJet60);
	fChain->SetBranchAddress("hltCaloJet80", &hltCaloJet80, &b_hltCaloJet80);
	fChain->SetBranchAddress("hltCSV60", &hltCSV60, &b_hltCSV60);
	fChain->SetBranchAddress("hltCSV80", &hltCSV80, &b_hltCSV80);
	fChain->SetBranchAddress("bProdCode", &bProdCode, &b_bProdCode);
	fChain->SetBranchAddress("cProdCode", &cProdCode, &b_cProdCode);
	fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
	fChain->SetBranchAddress("pthatsample", &pthatsample, &b_pthatsample);
	fChain->SetBranchAddress("pthatweight", &pthatweight, &b_pthatweight);
	fChain->SetBranchAddress("bin", &bin, &b_bin);
	fChain->SetBranchAddress("vz", &vz, &b_vz);
	fChain->SetBranchAddress("hiHF", &hiHF, &b_hiHF);
	fChain->SetBranchAddress("subid", &subid, &b_subid);
	fChain->SetBranchAddress("refpt", &refpt, &b_refpt);
	fChain->SetBranchAddress("rawpt", &rawpt, &b_rawpt);
	fChain->SetBranchAddress("jtpt", &jtpt, &b_jtpt);
	fChain->SetBranchAddress("jtphi", &jtphi, &b_jtphi);
	fChain->SetBranchAddress("jteta", &jteta, &b_jteta);
	fChain->SetBranchAddress("discr_csvV1_", &discr_csvV1_, &b_discr_csvV1_);
	fChain->SetBranchAddress("refparton_flavorForB", &refparton_flavorForB, &b_refparton_flavorForB);
	fChain->SetBranchAddress("isPrimary", &isPrimary, &b_isPrimary);
	fChain->SetBranchAddress("refparton_flavorProcess", &refparton_flavorProcess, &b_refparton_flavorProcess);
	fChain->SetBranchAddress("svtxm", &svtxm, &b_svtxm);
	fChain->SetBranchAddress("discr_prob", &discr_prob, &b_discr_prob);
	fChain->SetBranchAddress("svtxdls", &svtxdls, &b_svtxdls);
	fChain->SetBranchAddress("svtxpt", &svtxpt, &b_svtxpt);
	fChain->SetBranchAddress("svtxntrk", &svtxntrk, &b_svtxntrk);
	fChain->SetBranchAddress("nsvtx", &nsvtx, &b_nsvtx);
	fChain->SetBranchAddress("nselIPtrk", &nselIPtrk, &b_nselIPtrk);
	fChain->SetBranchAddress("centrWeight", &centrWeight, &b_centrWeight);
	fChain->SetBranchAddress("weight", &weight, &b_weight);
	fChain->SetBranchAddress("vertexWeight", &vertexWeight, &b_vertexWeight);
}

Bool_t MySelector::Notify()
{
	// The Notify() function is called when a new file is opened. This
	// can be either for a new TTree in a TChain or when when a new TTree
	// is started when using PROOF. It is normally not necessary to make changes
	// to the generated code, but the routine can be extended by the
	// user if needed. The return value is currently not used.

	return kTRUE;
}

#endif // #ifdef MySelector_cxx
