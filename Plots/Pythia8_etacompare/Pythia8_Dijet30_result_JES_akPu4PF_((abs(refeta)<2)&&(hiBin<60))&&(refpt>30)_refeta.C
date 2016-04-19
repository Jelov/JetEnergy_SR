void Pythia8_Dijet30_result_JES_akPu4PF_((abs(refeta)<2)&&(hiBin<60))&&(refpt>30)_refeta()
{
//=========Macro generated from canvas: Can_result_0/
//=========  (Mon Apr 18 04:07:05 2016) by ROOT version6.02/13
   TCanvas *Can_result_0 = new TCanvas("Can_result_0", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_0->Range(-2.75,1.004834,2.75,1.496258);
   Can_result_0->SetFillColor(0);
   Can_result_0->SetBorderMode(0);
   Can_result_0->SetBorderSize(2);
   Can_result_0->SetFrameBorderMode(0);
   Can_result_0->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JES_akPu4PF");
   
   Double_t Graph_fx1001[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1001[9] = {
   1.262191,
   1.190966,
   1.138859,
   1.112101,
   1.121654,
   1.124509,
   1.131205,
   1.12619,
   1.227773};
   Double_t Graph_fex1001[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1001[9] = {
   0.006438536,
   0.005219714,
   0.004330016,
   0.004066854,
   0.004187224,
   0.00419469,
   0.0043403,
   0.004379851,
   0.004287011};
   TGraphErrors *gre = new TGraphErrors(9,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","some title_0",100,-2.4,2.4);
   Graph_Graph1001->SetMinimum(1.091975);
   Graph_Graph1001->SetMaximum(1.284689);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1002[20] = {
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
   Double_t Graph_fy1002[20] = {
   1.303629,
   1.232761,
   1.205993,
   1.151384,
   1.155051,
   1.176355,
   1.129106,
   1.145524,
   1.125659,
   1.139968,
   1.1215,
   1.161797,
   1.121625,
   1.137548,
   1.096634,
   1.143835,
   1.129499,
   1.208251,
   1.360947,
   1.391257};
   Double_t Graph_fex1002[20] = {
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
   Double_t Graph_fey1002[20] = {
   0.03973077,
   0.03413604,
   0.02611309,
   0.02574891,
   0.02163129,
   0.02497143,
   0.02265968,
   0.02311936,
   0.02080899,
   0.02306502,
   0.02189006,
   0.02727669,
   0.02524463,
   0.02605845,
   0.0247876,
   0.02748596,
   0.02663211,
   0.03237351,
   0.03472468,
   0.0379885};
   gre = new TGraphErrors(20,Graph_fx1002,Graph_fy1002,Graph_fex1002,Graph_fey1002);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,-2.4,2.4);
   Graph_Graph1002->SetMinimum(1.036106);
   Graph_Graph1002->SetMaximum(1.464985);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1002->SetLineColor(ci);
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   multigraph->Add(gre,"");
   multigraph->Draw("AP");
   multigraph->GetXaxis()->SetTitle("refeta");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("#mu_{Reco./Gen.}");
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
   TLatex *   tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 &refpt>30}}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(24);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.17,0.17,"Centrality:0-30%");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(24);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TPaveText *pt = new TPaveText(0.3750575,0.9365254,0.6249425,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("JES_akPu4PF");
   pt->Draw();
   Can_result_0->Modified();
   Can_result_0->cd();
   Can_result_0->SetSelected(Can_result_0);
}
