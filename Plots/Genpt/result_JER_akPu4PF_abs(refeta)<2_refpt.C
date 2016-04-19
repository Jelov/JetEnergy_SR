void result_JER_akPu4PF_abs(refeta)<2_refpt()
{
//=========Macro generated from canvas: Can_result_1/
//=========  (Sun Apr 17 19:19:05 2016) by ROOT version6.02/13
   TCanvas *Can_result_1 = new TCanvas("Can_result_1", "",10,32,700,500);
   gStyle->SetOptFit(1);
   Can_result_1->Range(9.999998,0.06205995,230,0.277741);
   Can_result_1->SetFillColor(0);
   Can_result_1->SetBorderMode(0);
   Can_result_1->SetBorderSize(2);
   Can_result_1->SetFrameBorderMode(0);
   Can_result_1->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("title");
   
   Double_t Graph_fx1004[11] = {
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
   Double_t Graph_fy1004[11] = {
   0.22252,
   0.2017296,
   0.1835532,
   0.1707598,
   0.1621391,
   0.1549453,
   0.146909,
   0.1413561,
   0.1327695,
   0.1217537,
   0.1113111};
   Double_t Graph_fex1004[11] = {
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
   Double_t Graph_fey1004[11] = {
   0.001078297,
   0.000975685,
   0.0007877409,
   0.0005974871,
   0.0005266091,
   0.0005866521,
   0.0006981051,
   0.000803275,
   0.000750861,
   0.0009750485,
   0.001058723};
   TGraphErrors *gre = new TGraphErrors(11,Graph_fx1004,Graph_fy1004,Graph_fex1004,Graph_fey1004);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","some title_0",100,24,216);
   Graph_Graph1004->SetMinimum(0.09891782);
   Graph_Graph1004->SetMaximum(0.2349329);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
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
   
   Double_t Graph_fx1005[11] = {
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
   Double_t Graph_fy1005[11] = {
   0.2228142,
   0.2016548,
   0.1835789,
   0.1709823,
   0.1625917,
   0.1549621,
   0.1468825,
   0.1416538,
   0.1329398,
   0.1217049,
   0.111343};
   Double_t Graph_fex1005[11] = {
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
   Double_t Graph_fey1005[11] = {
   0.001104449,
   0.001011728,
   0.0008136297,
   0.0006116493,
   0.0005409397,
   0.0006013654,
   0.0007079863,
   0.0008234017,
   0.0007745504,
   0.001005551,
   0.001088881};
   gre = new TGraphErrors(11,Graph_fx1005,Graph_fy1005,Graph_fex1005,Graph_fey1005);
   gre->SetName("Graph");
   gre->SetTitle("some title_1");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","some title_1",100,24,216);
   Graph_Graph1005->SetMinimum(0.09888765);
   Graph_Graph1005->SetMaximum(0.2352851);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);

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
   
   Double_t Graph_fx1006[11] = {
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
   Double_t Graph_fy1006[11] = {
   0.2407204,
   0.1846531,
   0.1655701,
   0.1613371,
   0.1513567,
   0.1453373,
   0.1233306,
   0.1299407,
   0.1267032,
   0.09744427,
   0.1097338};
   Double_t Graph_fex1006[11] = {
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
   Double_t Graph_fey1006[11] = {
   0.007609523,
   0.004433219,
   0.003579932,
   0.003080741,
   0.00302941,
   0.003986084,
   0.003848406,
   0.006083907,
   0.004656451,
   0.005973271,
   0.01184488};
   gre = new TGraphErrors(11,Graph_fx1006,Graph_fy1006,Graph_fex1006,Graph_fey1006);
   gre->SetName("Graph");
   gre->SetTitle("some title_2");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","some title_2",100,24,216);
   Graph_Graph1006->SetMinimum(0.07578511);
   Graph_Graph1006->SetMaximum(0.2640158);
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
   multigraph->GetXaxis()->SetTitle("refpt");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetLabelSize(0.035);
   multigraph->GetYaxis()->SetTitleSize(0.035);
   multigraph->GetYaxis()->SetTitleFont(42);
   
   TLegend *leg = new TLegend(0.3,0.7,0.7,0.8,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","abs(refeta)<2","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.7,0.7,0.9,0.85,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("Graph","allJets","l");
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
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.3743391,0.9365254,0.6256609,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText("JER_akPu4PF");
   pt->Draw();
   Can_result_1->Modified();
   Can_result_1->cd();
   Can_result_1->SetSelected(Can_result_1);
}
