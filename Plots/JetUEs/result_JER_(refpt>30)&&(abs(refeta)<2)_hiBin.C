void result_JER_(refpt>30)&&(abs(refeta)<2)_hiBin()
{
//=========Macro generated from canvas: Can_result_5/
//=========  (Mon Apr 18 03:34:56 2016) by ROOT version6.02/13
   TCanvas *Can_result_5 = new TCanvas("Can_result_5", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_5->Range(-18.75,0.1191023,118.75,0.2896426);
   Can_result_5->SetFillColor(0);
   Can_result_5->SetBorderMode(0);
   Can_result_5->SetBorderSize(2);
   Can_result_5->SetFrameBorderMode(0);
   Can_result_5->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JER");
   
   Double_t Graph_fx1021[4] = {
   5,
   20,
   40,
   75};
   Double_t Graph_fy1021[4] = {
   0.2330506,
   0.2030063,
   0.1750241,
   0.154632};
   Double_t Graph_fex1021[4] = {
   5,
   10,
   10,
   25};
   Double_t Graph_fey1021[4] = {
   0.0009539742,
   0.0005826364,
   0.000518237,
   0.0003153906};
   TGraphErrors *gre = new TGraphErrors(4,Graph_fx1021,Graph_fy1021,Graph_fex1021,Graph_fey1021);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1021 = new TH1F("Graph_Graph1021","some title_0",100,0,110);
   Graph_Graph1021->SetMinimum(0.1463478);
   Graph_Graph1021->SetMaximum(0.2419733);
   Graph_Graph1021->SetDirectory(0);
   Graph_Graph1021->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1021->SetLineColor(ci);
   Graph_Graph1021->GetXaxis()->SetLabelFont(42);
   Graph_Graph1021->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1021->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1021->GetXaxis()->SetTitleFont(42);
   Graph_Graph1021->GetYaxis()->SetLabelFont(42);
   Graph_Graph1021->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1021->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1021->GetYaxis()->SetTitleFont(42);
   Graph_Graph1021->GetZaxis()->SetLabelFont(42);
   Graph_Graph1021->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1021->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1021->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1021);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1022[4] = {
   5,
   20,
   40,
   75};
   Double_t Graph_fy1022[4] = {
   0.2652418,
   0.2121337,
   0.1695054,
   0.1426324};
   Double_t Graph_fex1022[4] = {
   5,
   10,
   10,
   25};
   Double_t Graph_fey1022[4] = {
   0.001145327,
   0.0006289135,
   0.0005151438,
   0.0002746151};
   gre = new TGraphErrors(4,Graph_fx1022,Graph_fy1022,Graph_fex1022,Graph_fey1022);
   gre->SetName("Graph");
   gre->SetTitle("some title_1");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1022 = new TH1F("Graph_Graph1022","some title_1",100,0,110);
   Graph_Graph1022->SetMinimum(0.1299549);
   Graph_Graph1022->SetMaximum(0.27879);
   Graph_Graph1022->SetDirectory(0);
   Graph_Graph1022->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1022->SetLineColor(ci);
   Graph_Graph1022->GetXaxis()->SetLabelFont(42);
   Graph_Graph1022->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1022->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1022->GetXaxis()->SetTitleFont(42);
   Graph_Graph1022->GetYaxis()->SetLabelFont(42);
   Graph_Graph1022->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1022->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1022->GetYaxis()->SetTitleFont(42);
   Graph_Graph1022->GetZaxis()->SetLabelFont(42);
   Graph_Graph1022->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1022->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1022->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1022);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1023[4] = {
   5,
   20,
   40,
   75};
   Double_t Graph_fy1023[4] = {
   0.2065581,
   0.1933696,
   0.1834086,
   0.1734488};
   Double_t Graph_fex1023[4] = {
   5,
   10,
   10,
   25};
   Double_t Graph_fey1023[4] = {
   0.0008394321,
   0.0005095656,
   0.0005038132,
   0.0003136371};
   gre = new TGraphErrors(4,Graph_fx1023,Graph_fy1023,Graph_fex1023,Graph_fey1023);
   gre->SetName("Graph");
   gre->SetTitle("some title_2");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   
   TH1F *Graph_Graph1023 = new TH1F("Graph_Graph1023","some title_2",100,0,110);
   Graph_Graph1023->SetMinimum(0.1697089);
   Graph_Graph1023->SetMaximum(0.2108237);
   Graph_Graph1023->SetDirectory(0);
   Graph_Graph1023->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1023->SetLineColor(ci);
   Graph_Graph1023->GetXaxis()->SetLabelFont(42);
   Graph_Graph1023->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1023->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1023->GetXaxis()->SetTitleFont(42);
   Graph_Graph1023->GetYaxis()->SetLabelFont(42);
   Graph_Graph1023->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1023->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1023->GetYaxis()->SetTitleFont(42);
   Graph_Graph1023->GetZaxis()->SetLabelFont(42);
   Graph_Graph1023->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1023->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1023->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1023);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1024[4] = {
   5,
   20,
   40,
   75};
   Double_t Graph_fy1024[4] = {
   0.2394475,
   0.2065524,
   0.1837728,
   0.1713707};
   Double_t Graph_fex1024[4] = {
   5,
   10,
   10,
   25};
   Double_t Graph_fey1024[4] = {
   0.001146141,
   0.0006646736,
   0.0005635506,
   0.0003171318};
   gre = new TGraphErrors(4,Graph_fx1024,Graph_fy1024,Graph_fex1024,Graph_fey1024);
   gre->SetName("Graph");
   gre->SetTitle("some title_3");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   
   TH1F *Graph_Graph1024 = new TH1F("Graph_Graph1024","some title_3",100,0,110);
   Graph_Graph1024->SetMinimum(0.1640996);
   Graph_Graph1024->SetMaximum(0.2475476);
   Graph_Graph1024->SetDirectory(0);
   Graph_Graph1024->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1024->SetLineColor(ci);
   Graph_Graph1024->GetXaxis()->SetLabelFont(42);
   Graph_Graph1024->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1024->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1024->GetXaxis()->SetTitleFont(42);
   Graph_Graph1024->GetYaxis()->SetLabelFont(42);
   Graph_Graph1024->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1024->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1024->GetYaxis()->SetTitleFont(42);
   Graph_Graph1024->GetZaxis()->SetLabelFont(42);
   Graph_Graph1024->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1024->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1024->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1024);
   
   multigraph->Add(gre,"");
   multigraph->Draw("AP");
   multigraph->GetXaxis()->SetTitle("Centrality");
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
   TLatex *   tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 &refpt>30}}");
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
   Can_result_5->Modified();
   Can_result_5->cd();
   Can_result_5->SetSelected(Can_result_5);
}
