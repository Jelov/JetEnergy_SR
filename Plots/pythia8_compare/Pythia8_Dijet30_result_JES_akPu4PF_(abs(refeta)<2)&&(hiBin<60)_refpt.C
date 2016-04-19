void Pythia8_Dijet30_result_JES_akPu4PF_(abs(refeta)<2)&&(hiBin<60)_refpt()
{
//=========Macro generated from canvas: Can_result_0/
//=========  (Mon Apr 18 03:08:51 2016) by ROOT version6.02/13
   TCanvas *Can_result_0 = new TCanvas("Can_result_0", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_0->Range(-2.301397,0.8279985,237.5545,1.26843);
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
   1.132365,
   1.079309,
   1.042055,
   1.025155,
   0.9995262,
   1.02025,
   0.973018,
   1.018909,
   0.9981036,
   0.9843534,
   0.9854584};
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
   0.002571103,
   0.003499966,
   0.004687881,
   0.006400845,
   0.008658934,
   0.01091157,
   0.01273323,
   0.0197218,
   0.01826243,
   0.04289345,
   0.05054027};
   TGraphErrors *gre = new TGraphErrors(11,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","some title_0",100,24,216);
   Graph_Graph1001->SetMinimum(0.9149163);
   Graph_Graph1001->SetMaximum(1.154938);
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
   
   Double_t Graph_fx1002[10] = {
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
   Double_t Graph_fy1002[10] = {
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
   Double_t Graph_fex1002[10] = {
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
   Double_t Graph_fey1002[10] = {
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
   gre = new TGraphErrors(10,Graph_fx1002,Graph_fy1002,Graph_fex1002,Graph_fey1002);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,12.96216,222.291);
   Graph_Graph1002->SetMinimum(0.8560259);
   Graph_Graph1002->SetMaximum(1.240403);
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
   entry=leg->AddEntry("Graph","from chris","l");
   entry->SetLineColor(2);
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
