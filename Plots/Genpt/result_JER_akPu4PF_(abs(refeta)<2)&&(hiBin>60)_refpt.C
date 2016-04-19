void result_JER_akPu4PF_(abs(refeta)<2)&&(hiBin>60)_refpt()
{
//=========Macro generated from canvas: Can_result_3/
//=========  (Mon Apr 18 01:51:08 2016) by ROOT version6.02/13
   TCanvas *Can_result_3 = new TCanvas("Can_result_3", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_3->Range(-2.301397,-0.01150186,237.5545,0.3828568);
   Can_result_3->SetFillColor(0);
   Can_result_3->SetBorderMode(0);
   Can_result_3->SetBorderSize(2);
   Can_result_3->SetFrameBorderMode(0);
   Can_result_3->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JER_akPu4PF");
   
   Double_t Graph_fx1013[11] = {
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
   Double_t Graph_fy1013[11] = {
   0.201533,
   0.1807924,
   0.1638222,
   0.1527026,
   0.1455983,
   0.1396127,
   0.1324936,
   0.1275246,
   0.1208551,
   0.111361,
   0.101509};
   Double_t Graph_fex1013[11] = {
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
   Double_t Graph_fey1013[11] = {
   0.001210121,
   0.001064656,
   0.0007792491,
   0.0006050221,
   0.0005391276,
   0.0006047772,
   0.0007226398,
   0.0008059757,
   0.0007732276,
   0.0009865119,
   0.001133505};
   TGraphErrors *gre = new TGraphErrors(11,Graph_fx1013,Graph_fy1013,Graph_fex1013,Graph_fey1013);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1013 = new TH1F("Graph_Graph1013","some title_0",100,24,216);
   Graph_Graph1013->SetMinimum(0.09013871);
   Graph_Graph1013->SetMaximum(0.2129799);
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
   
   Double_t Graph_fx1014[11] = {
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
   Double_t Graph_fy1014[11] = {
   0.201704,
   0.1810637,
   0.1637435,
   0.1529127,
   0.145786,
   0.1395459,
   0.1328861,
   0.1276571,
   0.1211253,
   0.1113063,
   0.1015174};
   Double_t Graph_fex1014[11] = {
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
   Double_t Graph_fey1014[11] = {
   0.001238588,
   0.001100704,
   0.0008074386,
   0.0006180102,
   0.000554009,
   0.0006180179,
   0.0007369454,
   0.0008187592,
   0.000799165,
   0.001018898,
   0.001154824};
   gre = new TGraphErrors(11,Graph_fx1014,Graph_fy1014,Graph_fex1014,Graph_fey1014);
   gre->SetName("Graph");
   gre->SetTitle("some title_1");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1014 = new TH1F("Graph_Graph1014","some title_1",100,24,216);
   Graph_Graph1014->SetMinimum(0.09010454);
   Graph_Graph1014->SetMaximum(0.2132006);
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
   
   Double_t Graph_fx1015[11] = {
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
   Double_t Graph_fy1015[11] = {
   0.1921533,
   0.1760359,
   0.1531047,
   0.1479934,
   0.1386839,
   0.1331024,
   0.1032505,
   0.1150351,
   0.1125641,
   0.09032358,
   0.1120236};
   Double_t Graph_fex1015[11] = {
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
   Double_t Graph_fey1015[11] = {
   0.009227063,
   0.005394178,
   0.003968234,
   0.003416336,
   0.003108639,
   0.004911309,
   0.003326206,
   0.004991794,
   0.003938178,
   0.0058286,
   0.01348543};
   gre = new TGraphErrors(11,Graph_fx1015,Graph_fy1015,Graph_fex1015,Graph_fey1015);
   gre->SetName("Graph");
   gre->SetTitle("some title_2");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   
   TH1F *Graph_Graph1015 = new TH1F("Graph_Graph1015","some title_2",100,24,216);
   Graph_Graph1015->SetMinimum(0.07280644);
   Graph_Graph1015->SetMaximum(0.2130689);
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
   
   Double_t Graph_fx1016[10] = {
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
   Double_t Graph_fy1016[10] = {
   0.3165438,
   0.2200061,
   0.1916064,
   0.1736762,
   0.1550799,
   0.1417295,
   0.1352239,
   0.1191096,
   0.1233824,
   0.06176231};
   Double_t Graph_fex1016[10] = {
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
   Double_t Graph_fey1016[10] = {
   0.01253682,
   0.005719637,
   0.004019816,
   0.005043033,
   0.006710735,
   0.008656837,
   0.01379847,
   0.02334296,
   0.03556038,
   0.01948799};
   gre = new TGraphErrors(10,Graph_fx1016,Graph_fy1016,Graph_fex1016,Graph_fey1016);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   
   TH1F *Graph_Graph1016 = new TH1F("Graph_Graph1016","Graph",100,12.96216,222.291);
   Graph_Graph1016->SetMinimum(0.01359369);
   Graph_Graph1016->SetMaximum(0.3577612);
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
   multigraph->GetXaxis()->SetTitle("refpt");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("#sigma_{Reco./Gen.}");
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
      tex = new TLatex(0.17,0.25,"Centrality:30-100%");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(26);
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
