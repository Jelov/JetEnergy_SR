void Pythia8_Dijet30_result_JES_akPu4PF_((abs(refeta)<2)&&(hiBin>60))&&(refpt>30)_refeta()
{
//=========Macro generated from canvas: Can_result_2/
//=========  (Mon Apr 18 04:08:03 2016) by ROOT version6.02/13
   TCanvas *Can_result_2 = new TCanvas("Can_result_2", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_2->Range(-2.75,0.9740968,2.75,1.138162);
   Can_result_2->SetFillColor(0);
   Can_result_2->SetBorderMode(0);
   Can_result_2->SetBorderSize(2);
   Can_result_2->SetFrameBorderMode(0);
   Can_result_2->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JES_akPu4PF");
   
   Double_t Graph_fx1005[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1005[9] = {
   1.064838,
   1.047979,
   1.031742,
   1.025244,
   1.034934,
   1.039275,
   1.037788,
   1.039587,
   1.066085};
   Double_t Graph_fex1005[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1005[9] = {
   0.002645868,
   0.002512984,
   0.002003484,
   0.001787175,
   0.001798374,
   0.001820997,
   0.001867787,
   0.001979759,
   0.00185619};
   TGraphErrors *gre = new TGraphErrors(9,Graph_fx1005,Graph_fy1005,Graph_fex1005,Graph_fey1005);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","some title_0",100,-2.4,2.4);
   Graph_Graph1005->SetMinimum(1.019009);
   Graph_Graph1005->SetMaximum(1.07239);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1005->SetLineColor(ci);
   Graph_Graph1005->GetXaxis()->SetLabelFont(42);
   Graph_Graph1005->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetXaxis()->SetTitleFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetYaxis()->SetTitleFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1005);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1006[20] = {
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
   Double_t Graph_fy1006[20] = {
   1.069411,
   1.070513,
   1.011301,
   1.035222,
   1.036724,
   1.018364,
   1.04198,
   1.020078,
   1.029259,
   1.044609,
   1.03874,
   1.068158,
   1.040997,
   1.048108,
   1.032786,
   1.053243,
   1.037857,
   1.058521,
   1.100998,
   1.078658};
   Double_t Graph_fex1006[20] = {
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
   Double_t Graph_fey1006[20] = {
   0.01399064,
   0.01414066,
   0.01483164,
   0.01399455,
   0.01205881,
   0.01070609,
   0.01033787,
   0.01035296,
   0.009896843,
   0.0109851,
   0.01010715,
   0.01008437,
   0.01064937,
   0.01041456,
   0.01116612,
   0.01110952,
   0.01341817,
   0.01461283,
   0.01479181,
   0.01308327};
   gre = new TGraphErrors(20,Graph_fx1006,Graph_fy1006,Graph_fex1006,Graph_fey1006);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","Graph",100,-2.4,2.4);
   Graph_Graph1006->SetMinimum(0.9845373);
   Graph_Graph1006->SetMaximum(1.127722);
   Graph_Graph1006->SetDirectory(0);
   Graph_Graph1006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1006->SetLineColor(ci);
   Graph_Graph1006->GetXaxis()->SetLabelFont(42);
   Graph_Graph1006->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetXaxis()->SetTitleFont(42);
   Graph_Graph1006->GetYaxis()->SetLabelFont(42);
   Graph_Graph1006->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetYaxis()->SetTitleFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1006);
   
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
   
   TPaveText *pt = new TPaveText(0.3750575,0.9365254,0.6249425,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("JES_akPu4PF");
   pt->Draw();
   Can_result_2->Modified();
   Can_result_2->cd();
   Can_result_2->SetSelected(Can_result_2);
}
