void result_JES_akPu4PF_(abs(refeta)<2)&&(hiBin<60)_refpt()
{
//=========Macro generated from canvas: Can_result_0/
//=========  (Mon Apr 18 01:47:29 2016) by ROOT version6.02/13
   TCanvas *Can_result_0 = new TCanvas("Can_result_0", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_0->Range(-2.301397,0.6989975,237.5545,1.288799);
   Can_result_0->SetFillColor(0);
   Can_result_0->SetBorderMode(0);
   Can_result_0->SetBorderSize(2);
   Can_result_0->SetFrameBorderMode(0);
   Can_result_0->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JES_akPu4PF");
   
   Double_t Graph_fx1001[11] = {
   45,
   55,
   65,
   75,
   85,
   95,
   105,
   115,
   130,
   150,
   180};
   Double_t Graph_fy1001[11] = {
   1.044968,
   0.9902417,
   0.9862708,
   0.9913152,
   1.00051,
   0.9947328,
   0.9940934,
   0.9995079,
   0.9949567,
   0.988489,
   0.9903746};
   Double_t Graph_fex1001[11] = {
   5,
   5,
   5,
   5,
   5,
   5,
   5,
   5,
   10,
   10,
   20};
   Double_t Graph_fey1001[11] = {
   0.003155895,
   0.002702704,
   0.002221946,
   0.001653683,
   0.001470758,
   0.001599085,
   0.001882216,
   0.002207199,
   0.00194886,
   0.002686045,
   0.002945486};
   TGraphErrors *gre = new TGraphErrors(11,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","some title_0",100,24,216);
   Graph_Graph1001->SetMinimum(0.9776414);
   Graph_Graph1001->SetMaximum(1.054531);
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
   
   Double_t Graph_fx1002[11] = {
   45,
   55,
   65,
   75,
   85,
   95,
   105,
   115,
   130,
   150,
   180};
   Double_t Graph_fy1002[11] = {
   1.042561,
   0.9887651,
   0.9861084,
   0.9912943,
   1.000794,
   0.995111,
   0.9950192,
   0.9997594,
   0.9948106,
   0.9886561,
   0.9930381};
   Double_t Graph_fex1002[11] = {
   5,
   5,
   5,
   5,
   5,
   5,
   5,
   5,
   10,
   10,
   20};
   Double_t Graph_fey1002[11] = {
   0.003206995,
   0.002776433,
   0.002280801,
   0.001696203,
   0.001511421,
   0.001639943,
   0.001929688,
   0.002270706,
   0.002000514,
   0.002763128,
   0.003030556};
   gre = new TGraphErrors(11,Graph_fx1002,Graph_fy1002,Graph_fex1002,Graph_fey1002);
   gre->SetName("Graph");
   gre->SetTitle("some title_1");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","some title_1",100,24,216);
   Graph_Graph1002->SetMinimum(0.9776336);
   Graph_Graph1002->SetMaximum(1.051962);
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
   
   Double_t Graph_fx1003[11] = {
   45,
   55,
   65,
   75,
   85,
   95,
   105,
   115,
   130,
   150,
   180};
   Double_t Graph_fy1003[11] = {
   1.003569,
   0.9743181,
   1.018689,
   0.9677638,
   0.9541322,
   0.967296,
   0.9662005,
   0.9555524,
   0.977346,
   1.016482,
   0.9733103};
   Double_t Graph_fex1003[11] = {
   5,
   5,
   5,
   5,
   5,
   5,
   5,
   5,
   10,
   10,
   20};
   Double_t Graph_fey1003[11] = {
   0.02400541,
   0.01340013,
   0.01239611,
   0.009549069,
   0.008570019,
   0.01227275,
   0.01789703,
   0.02463403,
   0.01729983,
   0.03692004,
   0.1938853};
   gre = new TGraphErrors(11,Graph_fx1003,Graph_fy1003,Graph_fex1003,Graph_fey1003);
   gre->SetName("Graph");
   gre->SetTitle("some title_2");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","some title_2",100,24,216);
   Graph_Graph1003->SetMinimum(0.7406479);
   Graph_Graph1003->SetMaximum(1.205973);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1003->SetLineColor(ci);
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1004[10] = {
   33.60148,
   40.66353,
   49.20982,
   59.5523,
   72.06846,
   87.21514,
   105.5452,
   127.7278,
   154.5724,
   187.059};
   Double_t Graph_fy1004[10] = {
   1.194122,
   1.140162,
   1.120749,
   1.075858,
   1.05422,
   1.009865,
   0.9785294,
   0.945,
   0.99,
   0.9000001};
   Double_t Graph_fex1004[10] = {
   3.19525,
   3.8668,
   4.67949,
   5.66299,
   6.85317,
   8.29351,
   10.03657,
   12.14595,
   14.6987,
   17.7879};
   Double_t Graph_fey1004[10] = {
   0.01424918,
   0.01133906,
   0.01246782,
   0.01578119,
   0.0227899,
   0.03189043,
   0.02962023,
   0.0438062,
   0.05302978,
   0.01194279};
   gre = new TGraphErrors(10,Graph_fx1004,Graph_fy1004,Graph_fex1004,Graph_fey1004);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,12.96216,222.291);
   Graph_Graph1004->SetMinimum(0.8560259);
   Graph_Graph1004->SetMaximum(1.240403);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1004->SetLineColor(ci);
   Graph_Graph1004->GetXaxis()->SetLabelFont(42);
   Graph_Graph1004->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1004);
   
   multigraph->Add(gre,"");
   multigraph->Draw("AP");
   multigraph->GetXaxis()->SetTitle("refpt");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("#mu_{Reco./Gen.}");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetLabelSize(0.035);
   multigraph->GetYaxis()->SetTitleSize(0.035);
   multigraph->GetYaxis()->SetTitleFont(42);
   
   TLegend *leg = new TLegend(0.65,0.7,0.85,0.85,NULL,"brNDC");
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
   entry=leg->AddEntry("Graph","lightJets","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","bJets","l");
   entry->SetLineColor(3);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","from chris","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0}}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(26);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.17,0.25,"Centrality:0-30%");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(26);
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
