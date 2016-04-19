void result_JER_refpt>30_refeta()
{
//=========Macro generated from canvas: Can_result_3/
//=========  (Mon Apr 18 03:32:23 2016) by ROOT version6.02/13
   TCanvas *Can_result_3 = new TCanvas("Can_result_3", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_3->Range(-2.75,0.1470448,2.75,0.2163948);
   Can_result_3->SetFillColor(0);
   Can_result_3->SetBorderMode(0);
   Can_result_3->SetBorderSize(2);
   Can_result_3->SetFrameBorderMode(0);
   Can_result_3->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JER");
   
   Double_t Graph_fx1013[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1013[9] = {
   0.1964304,
   0.199995,
   0.1762234,
   0.1637191,
   0.1637204,
   0.1619055,
   0.1621366,
   0.1774222,
   0.1974881};
   Double_t Graph_fex1013[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1013[9] = {
   0.001088586,
   0.0008579818,
   0.0007389546,
   0.0006778743,
   0.0006623616,
   0.0006839703,
   0.0006925475,
   0.0007663547,
   0.0006550485};
   TGraphErrors *gre = new TGraphErrors(9,Graph_fx1013,Graph_fy1013,Graph_fex1013,Graph_fey1013);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1013 = new TH1F("Graph_Graph1013","some title_0",100,-2.4,2.4);
   Graph_Graph1013->SetMinimum(0.1572584);
   Graph_Graph1013->SetMaximum(0.2048161);
   Graph_Graph1013->SetDirectory(0);
   Graph_Graph1013->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1013->SetLineColor(ci);
   Graph_Graph1013->GetXaxis()->SetLabelFont(42);
   Graph_Graph1013->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1013->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1013->GetXaxis()->SetTitleFont(42);
   Graph_Graph1013->GetYaxis()->SetLabelFont(42);
   Graph_Graph1013->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1013->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1013->GetYaxis()->SetTitleFont(42);
   Graph_Graph1013->GetZaxis()->SetLabelFont(42);
   Graph_Graph1013->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1013->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1013->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1013);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1014[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1014[9] = {
   0.1774648,
   0.1900402,
   0.1728622,
   0.1594315,
   0.1616686,
   0.1596754,
   0.1572053,
   0.1719005,
   0.1852546};
   Double_t Graph_fex1014[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1014[9] = {
   0.001034568,
   0.0008428034,
   0.0007944972,
   0.0007167188,
   0.000698038,
   0.0006819227,
   0.0007036459,
   0.0007813615,
   0.0006532199};
   gre = new TGraphErrors(9,Graph_fx1014,Graph_fy1014,Graph_fex1014,Graph_fey1014);
   gre->SetName("Graph");
   gre->SetTitle("some title_1");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1014 = new TH1F("Graph_Graph1014","some title_1",100,-2.4,2.4);
   Graph_Graph1014->SetMinimum(0.1530635);
   Graph_Graph1014->SetMaximum(0.1943212);
   Graph_Graph1014->SetDirectory(0);
   Graph_Graph1014->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1014->SetLineColor(ci);
   Graph_Graph1014->GetXaxis()->SetLabelFont(42);
   Graph_Graph1014->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1014->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1014->GetXaxis()->SetTitleFont(42);
   Graph_Graph1014->GetYaxis()->SetLabelFont(42);
   Graph_Graph1014->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1014->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1014->GetYaxis()->SetTitleFont(42);
   Graph_Graph1014->GetZaxis()->SetLabelFont(42);
   Graph_Graph1014->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1014->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1014->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1014);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1015[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1015[9] = {
   0.1793567,
   0.1934791,
   0.1832575,
   0.1792053,
   0.1813256,
   0.1808114,
   0.1789014,
   0.1850247,
   0.1866053};
   Double_t Graph_fex1015[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1015[9] = {
   0.0008285283,
   0.0007980478,
   0.0006999279,
   0.0006801716,
   0.0006739484,
   0.0006805307,
   0.0006691577,
   0.0007124727,
   0.0005755};
   gre = new TGraphErrors(9,Graph_fx1015,Graph_fy1015,Graph_fex1015,Graph_fey1015);
   gre->SetName("Graph");
   gre->SetTitle("some title_2");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   
   TH1F *Graph_Graph1015 = new TH1F("Graph_Graph1015","some title_2",100,-2.4,2.4);
   Graph_Graph1015->SetMinimum(0.1766277);
   Graph_Graph1015->SetMaximum(0.1958816);
   Graph_Graph1015->SetDirectory(0);
   Graph_Graph1015->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1015->SetLineColor(ci);
   Graph_Graph1015->GetXaxis()->SetLabelFont(42);
   Graph_Graph1015->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1015->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1015->GetXaxis()->SetTitleFont(42);
   Graph_Graph1015->GetYaxis()->SetLabelFont(42);
   Graph_Graph1015->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1015->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1015->GetYaxis()->SetTitleFont(42);
   Graph_Graph1015->GetZaxis()->SetLabelFont(42);
   Graph_Graph1015->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1015->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1015->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1015);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1016[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1016[9] = {
   0.1900786,
   0.2060408,
   0.1975835,
   0.1902927,
   0.1909319,
   0.1892144,
   0.1889748,
   0.1981376,
   0.2005043};
   Double_t Graph_fex1016[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1016[9] = {
   0.000944107,
   0.0008971873,
   0.0008083318,
   0.0007775971,
   0.0007690142,
   0.0007480289,
   0.0007554324,
   0.000804848,
   0.0006590922};
   gre = new TGraphErrors(9,Graph_fx1016,Graph_fy1016,Graph_fex1016,Graph_fey1016);
   gre->SetName("Graph");
   gre->SetTitle("some title_3");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   
   TH1F *Graph_Graph1016 = new TH1F("Graph_Graph1016","some title_3",100,-2.4,2.4);
   Graph_Graph1016->SetMinimum(0.1863475);
   Graph_Graph1016->SetMaximum(0.2088099);
   Graph_Graph1016->SetDirectory(0);
   Graph_Graph1016->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1016->SetLineColor(ci);
   Graph_Graph1016->GetXaxis()->SetLabelFont(42);
   Graph_Graph1016->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1016->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1016->GetXaxis()->SetTitleFont(42);
   Graph_Graph1016->GetYaxis()->SetLabelFont(42);
   Graph_Graph1016->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1016->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1016->GetYaxis()->SetTitleFont(42);
   Graph_Graph1016->GetZaxis()->SetLabelFont(42);
   Graph_Graph1016->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1016->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1016->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1016);
   
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
   TLatex *   tex = new TLatex(0.35,0.8,"#bf{#color[2]{refpt>30}}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(24);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TPaveText *pt = new TPaveText(0.456954,0.94,0.543046,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("JER");
   pt->Draw();
   Can_result_3->Modified();
   Can_result_3->cd();
   Can_result_3->SetSelected(Can_result_3);
}
