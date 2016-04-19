void result_JES_(refpt>30)&&(abs(refeta)<2)_hiBin()
{
//=========Macro generated from canvas: Can_result_4/
//=========  (Mon Apr 18 03:34:55 2016) by ROOT version6.02/13
   TCanvas *Can_result_4 = new TCanvas("Can_result_4", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_4->Range(-18.75,0.9176746,118.75,1.225531);
   Can_result_4->SetFillColor(0);
   Can_result_4->SetBorderMode(0);
   Can_result_4->SetBorderSize(2);
   Can_result_4->SetFrameBorderMode(0);
   Can_result_4->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JES");
   
   Double_t Graph_fx1017[4] = {
   5,
   20,
   40,
   75};
   Double_t Graph_fy1017[4] = {
   1.035502,
   0.9816769,
   0.9602828,
   0.9604594};
   Double_t Graph_fex1017[4] = {
   5,
   10,
   10,
   25};
   Double_t Graph_fey1017[4] = {
   0.001288528,
   0.0007372457,
   0.0006278209,
   0.0003654388};
   TGraphErrors *gre = new TGraphErrors(4,Graph_fx1017,Graph_fy1017,Graph_fex1017,Graph_fey1017);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1017 = new TH1F("Graph_Graph1017","some title_0",100,0,110);
   Graph_Graph1017->SetMinimum(0.9519415);
   Graph_Graph1017->SetMaximum(1.044504);
   Graph_Graph1017->SetDirectory(0);
   Graph_Graph1017->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1017->SetLineColor(ci);
   Graph_Graph1017->GetXaxis()->SetLabelFont(42);
   Graph_Graph1017->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1017->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1017->GetXaxis()->SetTitleFont(42);
   Graph_Graph1017->GetYaxis()->SetLabelFont(42);
   Graph_Graph1017->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1017->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1017->GetYaxis()->SetTitleFont(42);
   Graph_Graph1017->GetZaxis()->SetLabelFont(42);
   Graph_Graph1017->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1017->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1017->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1017);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1018[4] = {
   5,
   20,
   40,
   75};
   Double_t Graph_fy1018[4] = {
   1.038405,
   1.009849,
   0.9839795,
   0.9758844};
   Double_t Graph_fex1018[4] = {
   5,
   10,
   10,
   25};
   Double_t Graph_fey1018[4] = {
   0.001474182,
   0.0007821691,
   0.0006082474,
   0.0003260475};
   gre = new TGraphErrors(4,Graph_fx1018,Graph_fy1018,Graph_fex1018,Graph_fey1018);
   gre->SetName("Graph");
   gre->SetTitle("some title_1");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1018 = new TH1F("Graph_Graph1018","some title_1",100,0,110);
   Graph_Graph1018->SetMinimum(0.9691263);
   Graph_Graph1018->SetMaximum(1.046311);
   Graph_Graph1018->SetDirectory(0);
   Graph_Graph1018->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1018->SetLineColor(ci);
   Graph_Graph1018->GetXaxis()->SetLabelFont(42);
   Graph_Graph1018->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1018->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1018->GetXaxis()->SetTitleFont(42);
   Graph_Graph1018->GetYaxis()->SetLabelFont(42);
   Graph_Graph1018->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1018->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1018->GetYaxis()->SetTitleFont(42);
   Graph_Graph1018->GetZaxis()->SetLabelFont(42);
   Graph_Graph1018->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1018->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1018->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1018);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1019[4] = {
   5,
   20,
   40,
   75};
   Double_t Graph_fy1019[4] = {
   0.9976502,
   0.9936598,
   0.9832399,
   0.9788784};
   Double_t Graph_fex1019[4] = {
   5,
   10,
   10,
   25};
   Double_t Graph_fey1019[4] = {
   0.00115374,
   0.000745347,
   0.0006853611,
   0.0004081904};
   gre = new TGraphErrors(4,Graph_fx1019,Graph_fy1019,Graph_fex1019,Graph_fey1019);
   gre->SetName("Graph");
   gre->SetTitle("some title_2");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   
   TH1F *Graph_Graph1019 = new TH1F("Graph_Graph1019","some title_2",100,0,110);
   Graph_Graph1019->SetMinimum(0.9764368);
   Graph_Graph1019->SetMaximum(1.000837);
   Graph_Graph1019->SetDirectory(0);
   Graph_Graph1019->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1019->SetLineColor(ci);
   Graph_Graph1019->GetXaxis()->SetLabelFont(42);
   Graph_Graph1019->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1019->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1019->GetXaxis()->SetTitleFont(42);
   Graph_Graph1019->GetYaxis()->SetLabelFont(42);
   Graph_Graph1019->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1019->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1019->GetYaxis()->SetTitleFont(42);
   Graph_Graph1019->GetZaxis()->SetLabelFont(42);
   Graph_Graph1019->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1019->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1019->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1019);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1020[4] = {
   5,
   20,
   40,
   75};
   Double_t Graph_fy1020[4] = {
   1.182238,
   1.159765,
   1.077725,
   1.003998};
   Double_t Graph_fex1020[4] = {
   5,
   10,
   10,
   25};
   Double_t Graph_fey1020[4] = {
   0.001311995,
   0.0007922103,
   0.0006776127,
   0.0003929215};
   gre = new TGraphErrors(4,Graph_fx1020,Graph_fy1020,Graph_fex1020,Graph_fey1020);
   gre->SetName("Graph");
   gre->SetTitle("some title_3");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   
   TH1F *Graph_Graph1020 = new TH1F("Graph_Graph1020","some title_3",100,0,110);
   Graph_Graph1020->SetMinimum(0.9856102);
   Graph_Graph1020->SetMaximum(1.201545);
   Graph_Graph1020->SetDirectory(0);
   Graph_Graph1020->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1020->SetLineColor(ci);
   Graph_Graph1020->GetXaxis()->SetLabelFont(42);
   Graph_Graph1020->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1020->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1020->GetXaxis()->SetTitleFont(42);
   Graph_Graph1020->GetYaxis()->SetLabelFont(42);
   Graph_Graph1020->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1020->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1020->GetYaxis()->SetTitleFont(42);
   Graph_Graph1020->GetZaxis()->SetLabelFont(42);
   Graph_Graph1020->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1020->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1020->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1020);
   
   multigraph->Add(gre,"");
   multigraph->Draw("AP");
   multigraph->GetXaxis()->SetTitle("Centrality");
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
   TLatex *   tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 &rept>30}}");
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
   Can_result_4->Modified();
   Can_result_4->cd();
   Can_result_4->SetSelected(Can_result_4);
}
