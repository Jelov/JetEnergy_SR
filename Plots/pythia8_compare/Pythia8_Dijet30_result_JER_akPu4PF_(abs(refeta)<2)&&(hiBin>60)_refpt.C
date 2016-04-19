void Pythia8_Dijet30_result_JER_akPu4PF_(abs(refeta)<2)&&(hiBin>60)_refpt()
{
//=========Macro generated from canvas: Can_result_3/
//=========  (Mon Apr 18 03:09:33 2016) by ROOT version6.02/13
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
   
   Double_t Graph_fx1007[11] = {
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
   Double_t Graph_fy1007[11] = {
   0.1976721,
   0.1639212,
   0.1562002,
   0.1480066,
   0.1479035,
   0.1333827,
   0.1160421,
   0.1205967,
   0.1105508,
   0.08141581,
   0.09210746};
   Double_t Graph_fex1007[11] = {
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
   Double_t Graph_fey1007[11] = {
   0.001003849,
   0.001317066,
   0.001658995,
   0.002251738,
   0.003095601,
   0.004152981,
   0.005688263,
   0.008277583,
   0.006320737,
   0.01258781,
   0.01599127};
   TGraphErrors *gre = new TGraphErrors(11,Graph_fx1007,Graph_fy1007,Graph_fex1007,Graph_fey1007);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","some title_0",100,24,216);
   Graph_Graph1007->SetMinimum(0.0558432);
   Graph_Graph1007->SetMaximum(0.2116608);
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
   
   Double_t Graph_fx1008[10] = {
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
   Double_t Graph_fy1008[10] = {
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
   Double_t Graph_fex1008[10] = {
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
   Double_t Graph_fey1008[10] = {
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
   gre = new TGraphErrors(10,Graph_fx1008,Graph_fy1008,Graph_fex1008,Graph_fey1008);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,12.96216,222.291);
   Graph_Graph1008->SetMinimum(0.01359369);
   Graph_Graph1008->SetMaximum(0.3577612);
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
