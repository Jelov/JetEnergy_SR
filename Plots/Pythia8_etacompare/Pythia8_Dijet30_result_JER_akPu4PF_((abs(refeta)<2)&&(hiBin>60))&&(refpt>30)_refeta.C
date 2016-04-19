void Pythia8_Dijet30_result_JER_akPu4PF_((abs(refeta)<2)&&(hiBin>60))&&(refpt>30)_refeta()
{
//=========Macro generated from canvas: Can_result_3/
//=========  (Mon Apr 18 04:08:04 2016) by ROOT version6.02/13
   TCanvas *Can_result_3 = new TCanvas("Can_result_3", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_3->Range(-2.75,0.1715425,2.75,0.2926317);
   Can_result_3->SetFillColor(0);
   Can_result_3->SetBorderMode(0);
   Can_result_3->SetBorderSize(2);
   Can_result_3->SetFrameBorderMode(0);
   Can_result_3->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JER_akPu4PF");
   
   Double_t Graph_fx1007[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1007[9] = {
   0.2213775,
   0.2313726,
   0.212349,
   0.1992318,
   0.2015521,
   0.2047929,
   0.2065286,
   0.2141753,
   0.2298097};
   Double_t Graph_fex1007[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1007[9] = {
   0.001529502,
   0.001378741,
   0.001274153,
   0.001286487,
   0.00132694,
   0.001354738,
   0.001397823,
   0.001305814,
   0.001034891};
   TGraphErrors *gre = new TGraphErrors(9,Graph_fx1007,Graph_fy1007,Graph_fex1007,Graph_fey1007);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","some title_0",100,-2.4,2.4);
   Graph_Graph1007->SetMinimum(0.1944648);
   Graph_Graph1007->SetMaximum(0.236232);
   Graph_Graph1007->SetDirectory(0);
   Graph_Graph1007->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1007->SetLineColor(ci);
   Graph_Graph1007->GetXaxis()->SetLabelFont(42);
   Graph_Graph1007->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetXaxis()->SetTitleFont(42);
   Graph_Graph1007->GetYaxis()->SetLabelFont(42);
   Graph_Graph1007->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetYaxis()->SetTitleFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1007);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1008[20] = {
   -1.9,
   -1.7,
   -1.5,
   -1.2,
   -0.9,
   -0.7,
   -0.5,
   -0.3,
   -0.1,
   0.1,
   0.3,
   0.5,
   0.7,
   0.9,
   1.1,
   1.3,
   1.5,
   1.7,
   1.9,
   1};
   Double_t Graph_fy1008[20] = {
   0.2311591,
   0.2477474,
   0.2655955,
   0.2576075,
   0.2220231,
   0.206768,
   0.2064983,
   0.2020811,
   0.19917,
   0.2115871,
   0.1952014,
   0.1965805,
   0.2158946,
   0.2003286,
   0.213619,
   0.213695,
   0.2466632,
   0.2597152,
   0.2553281,
   0.2344014};
   Double_t Graph_fex1008[20] = {
   0.1,
   0.1,
   0.1,
   0.2,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   0.1,
   -1};
   Double_t Graph_fey1008[20] = {
   0.009894431,
   0.01000488,
   0.01052403,
   0.009913006,
   0.008527985,
   0.007570562,
   0.007309829,
   0.007320613,
   0.00699798,
   0.00776784,
   0.007146697,
   0.00713059,
   0.007530691,
   0.007364154,
   0.007896077,
   0.007855752,
   0.009496669,
   0.01034782,
   0.01046585,
   0.009252961};
   gre = new TGraphErrors(20,Graph_fx1008,Graph_fy1008,Graph_fex1008,Graph_fey1008);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,-2.4,2.4);
   Graph_Graph1008->SetMinimum(0.1792482);
   Graph_Graph1008->SetMaximum(0.284926);
   Graph_Graph1008->SetDirectory(0);
   Graph_Graph1008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1008->SetLineColor(ci);
   Graph_Graph1008->GetXaxis()->SetLabelFont(42);
   Graph_Graph1008->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1008->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1008->GetXaxis()->SetTitleFont(42);
   Graph_Graph1008->GetYaxis()->SetLabelFont(42);
   Graph_Graph1008->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1008->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1008->GetYaxis()->SetTitleFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1008->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1008->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1008);
   
   multigraph->Add(gre,"");
   multigraph->Draw("AP");
   multigraph->GetXaxis()->SetTitle("refeta");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("#sigma_{Reco./Gen.}");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetLabelSize(0.035);
   multigraph->GetYaxis()->SetTitleSize(0.035);
   multigraph->GetYaxis()->SetTitleFont(42);
   
   TLegend *leg = new TLegend(0.68,0.7,0.88,0.85,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","allJets","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","from chris","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 & refpt>30}}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(24);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.17,0.17,"Centrality:30-100%");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(24);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TPaveText *pt = new TPaveText(0.3743391,0.9365254,0.6256609,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("JER_akPu4PF");
   pt->Draw();
   Can_result_3->Modified();
   Can_result_3->cd();
   Can_result_3->SetSelected(Can_result_3);
}
