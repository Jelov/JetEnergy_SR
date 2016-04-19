void result_JES_refpt>30_refeta()
{
//=========Macro generated from canvas: Can_result_2/
//=========  (Mon Apr 18 03:32:22 2016) by ROOT version6.02/13
   TCanvas *Can_result_2 = new TCanvas("Can_result_2", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_2->Range(-2.75,0.9375327,2.75,1.095739);
   Can_result_2->SetFillColor(0);
   Can_result_2->SetBorderMode(0);
   Can_result_2->SetBorderSize(2);
   Can_result_2->SetFrameBorderMode(0);
   Can_result_2->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JES");
   
   Double_t Graph_fx1009[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1009[9] = {
   1.001043,
   0.9612578,
   0.9599752,
   0.9606048,
   0.9661683,
   0.9672415,
   0.9634596,
   0.967264,
   0.9807513};
   Double_t Graph_fex1009[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1009[9] = {
   0.001191731,
   0.001077263,
   0.0008688377,
   0.0007667148,
   0.0007487907,
   0.0007458895,
   0.000765941,
   0.0008817624,
   0.0007954899};
   TGraphErrors *gre = new TGraphErrors(9,Graph_fx1009,Graph_fy1009,Graph_fex1009,Graph_fey1009);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1009 = new TH1F("Graph_Graph1009","some title_0",100,-2.4,2.4);
   Graph_Graph1009->SetMinimum(0.9547935);
   Graph_Graph1009->SetMaximum(1.006548);
   Graph_Graph1009->SetDirectory(0);
   Graph_Graph1009->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1009->SetLineColor(ci);
   Graph_Graph1009->GetXaxis()->SetLabelFont(42);
   Graph_Graph1009->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1009->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1009->GetXaxis()->SetTitleFont(42);
   Graph_Graph1009->GetYaxis()->SetLabelFont(42);
   Graph_Graph1009->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1009->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1009->GetYaxis()->SetTitleFont(42);
   Graph_Graph1009->GetZaxis()->SetLabelFont(42);
   Graph_Graph1009->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1009->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1009->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1009);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1010[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1010[9] = {
   1.022267,
   0.9858001,
   0.9805916,
   0.9745934,
   0.9765386,
   0.9773937,
   0.9762218,
   0.9845476,
   1.002412};
   Double_t Graph_fex1010[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1010[9] = {
   0.001075827,
   0.001031987,
   0.0008583338,
   0.0007516334,
   0.0007427975,
   0.0007362501,
   0.0007435038,
   0.0008583196,
   0.0007457734};
   gre = new TGraphErrors(9,Graph_fx1010,Graph_fy1010,Graph_fex1010,Graph_fey1010);
   gre->SetName("Graph");
   gre->SetTitle("some title_1");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1010 = new TH1F("Graph_Graph1010","some title_1",100,-2.4,2.4);
   Graph_Graph1010->SetMinimum(0.9688917);
   Graph_Graph1010->SetMaximum(1.028292);
   Graph_Graph1010->SetDirectory(0);
   Graph_Graph1010->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1010->SetLineColor(ci);
   Graph_Graph1010->GetXaxis()->SetLabelFont(42);
   Graph_Graph1010->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1010->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1010->GetXaxis()->SetTitleFont(42);
   Graph_Graph1010->GetYaxis()->SetLabelFont(42);
   Graph_Graph1010->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1010->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1010->GetYaxis()->SetTitleFont(42);
   Graph_Graph1010->GetZaxis()->SetLabelFont(42);
   Graph_Graph1010->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1010->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1010->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1010);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1011[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1011[9] = {
   0.9788466,
   0.9815905,
   0.9860956,
   0.9872733,
   0.9849312,
   0.9841643,
   0.9829952,
   0.9889903,
   0.9811901};
   Double_t Graph_fex1011[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1011[9] = {
   0.001126385,
   0.001113243,
   0.0009524393,
   0.0008714465,
   0.0008507426,
   0.0008546559,
   0.0008748245,
   0.0009684905,
   0.000786814};
   gre = new TGraphErrors(9,Graph_fx1011,Graph_fy1011,Graph_fex1011,Graph_fey1011);
   gre->SetName("Graph");
   gre->SetTitle("some title_2");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   
   TH1F *Graph_Graph1011 = new TH1F("Graph_Graph1011","some title_2",100,-2.4,2.4);
   Graph_Graph1011->SetMinimum(0.9764963);
   Graph_Graph1011->SetMaximum(0.9911827);
   Graph_Graph1011->SetDirectory(0);
   Graph_Graph1011->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1011->SetLineColor(ci);
   Graph_Graph1011->GetXaxis()->SetLabelFont(42);
   Graph_Graph1011->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1011->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1011->GetXaxis()->SetTitleFont(42);
   Graph_Graph1011->GetYaxis()->SetLabelFont(42);
   Graph_Graph1011->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1011->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1011->GetYaxis()->SetTitleFont(42);
   Graph_Graph1011->GetZaxis()->SetLabelFont(42);
   Graph_Graph1011->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1011->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1011->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1011);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1012[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1012[9] = {
   1.066893,
   1.068274,
   1.070731,
   1.063643,
   1.055811,
   1.054239,
   1.059227,
   1.073106,
   1.067976};
   Double_t Graph_fex1012[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1012[9] = {
   0.00121424,
   0.00117939,
   0.001035925,
   0.0009383662,
   0.0009126745,
   0.0009213667,
   0.0009412671,
   0.001059626,
   0.0008480708};
   gre = new TGraphErrors(9,Graph_fx1012,Graph_fy1012,Graph_fex1012,Graph_fey1012);
   gre->SetName("Graph");
   gre->SetTitle("some title_3");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   
   TH1F *Graph_Graph1012 = new TH1F("Graph_Graph1012","some title_3",100,-2.4,2.4);
   Graph_Graph1012->SetMinimum(1.051233);
   Graph_Graph1012->SetMaximum(1.076251);
   Graph_Graph1012->SetDirectory(0);
   Graph_Graph1012->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1012->SetLineColor(ci);
   Graph_Graph1012->GetXaxis()->SetLabelFont(42);
   Graph_Graph1012->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1012->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1012->GetXaxis()->SetTitleFont(42);
   Graph_Graph1012->GetYaxis()->SetLabelFont(42);
   Graph_Graph1012->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1012->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1012->GetYaxis()->SetTitleFont(42);
   Graph_Graph1012->GetZaxis()->SetLabelFont(42);
   Graph_Graph1012->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1012->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1012->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1012);
   
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
   
   TLegend *leg = new TLegend(0.68,0.5,0.88,0.65,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","akPu4PF","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","akVs4PF","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","akPu4Calo","l");
   entry->SetLineColor(3);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","akVs4Calo","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.35,0.65,"#bf{#color[2]{refpt>30}}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(24);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TPaveText *pt = new TPaveText(0.4576724,0.94,0.5423276,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("JES");
   pt->Draw();
   Can_result_2->Modified();
   Can_result_2->cd();
   Can_result_2->SetSelected(Can_result_2);
}
