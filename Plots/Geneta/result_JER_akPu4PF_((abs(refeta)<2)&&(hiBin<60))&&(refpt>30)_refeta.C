void result_JER_akPu4PF_((abs(refeta)<2)&&(hiBin<60))&&(refpt>30)_refeta()
{
//=========Macro generated from canvas: Can_result_1/
//=========  (Mon Apr 18 02:26:32 2016) by ROOT version6.02/13
   TCanvas *Can_result_1 = new TCanvas("Can_result_1", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_1->Range(-2.75,0.1093464,2.75,0.5423059);
   Can_result_1->SetFillColor(0);
   Can_result_1->SetBorderMode(0);
   Can_result_1->SetBorderSize(2);
   Can_result_1->SetFrameBorderMode(0);
   Can_result_1->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JER_akPu4PF");
   
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
   0.2483554,
   0.2339282,
   0.2070486,
   0.1981023,
   0.1963694,
   0.1958725,
   0.1990972,
   0.2121883,
   0.2352835};
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
   0.002360366,
   0.001873557,
   0.001434054,
   0.001386567,
   0.001270468,
   0.001336275,
   0.001384821,
   0.001474045,
   0.001403281};
   TGraphErrors *gre = new TGraphErrors(9,Graph_fx1005,Graph_fy1005,Graph_fex1005,Graph_fey1005);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","some title_0",100,-2.4,2.4);
   Graph_Graph1005->SetMinimum(0.1889182);
   Graph_Graph1005->SetMaximum(0.2563338);
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
   
   Double_t Graph_fx1006[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1006[9] = {
   0.2483428,
   0.2343109,
   0.2079035,
   0.1975382,
   0.1965403,
   0.1952335,
   0.199101,
   0.2125401,
   0.2362833};
   Double_t Graph_fex1006[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1006[9] = {
   0.002414827,
   0.001917465,
   0.00147297,
   0.001417986,
   0.001311648,
   0.00136453,
   0.001426189,
   0.001529518,
   0.001474344};
   gre = new TGraphErrors(9,Graph_fx1006,Graph_fy1006,Graph_fex1006,Graph_fey1006);
   gre->SetName("Graph");
   gre->SetTitle("some title_1");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","some title_1",100,-2.4,2.4);
   Graph_Graph1006->SetMinimum(0.1881801);
   Graph_Graph1006->SetMaximum(0.2564465);
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
   
   Double_t Graph_fx1007[9] = {
   -1.8,
   -1.4,
   -1,
   -0.6,
   -0.2,
   0.2,
   0.6,
   1,
   1.6};
   Double_t Graph_fy1007[9] = {
   0.418398,
   0.2304004,
   0.2000461,
   0.2045532,
   0.1759315,
   0.2100241,
   0.23379,
   0.1992789,
   0.21308};
   Double_t Graph_fex1007[9] = {
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.2,
   0.4};
   Double_t Graph_fey1007[9] = {
   0.06486794,
   0.01728162,
   0.01825244,
   0.01191012,
   0.007545138,
   0.0123686,
   0.01252722,
   0.01196076,
   0.009915428};
   gre = new TGraphErrors(9,Graph_fx1007,Graph_fy1007,Graph_fex1007,Graph_fey1007);
   gre->SetName("Graph");
   gre->SetTitle("some title_2");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","some title_2",100,-2.4,2.4);
   Graph_Graph1007->SetMinimum(0.1368984);
   Graph_Graph1007->SetMaximum(0.5147539);
   Graph_Graph1007->SetDirectory(0);
   Graph_Graph1007->SetStats(0);

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
   
   Double_t Graph_fx1008[20] = {
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
   Double_t Graph_fy1008[20] = {
   0.3775948,
   0.3621174,
   0.3175088,
   0.3012355,
   0.2877171,
   0.3214521,
   0.3062906,
   0.290515,
   0.2798917,
   0.3108987,
   0.2959602,
   0.3324433,
   0.318869,
   0.3350273,
   0.3149909,
   0.3498084,
   0.3180699,
   0.3774354,
   0.398101,
   0.4182954};
   Double_t Graph_fex1008[20] = {
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
   Double_t Graph_fey1008[20] = {
   0.03634148,
   0.02440305,
   0.01853123,
   0.01826765,
   0.01532295,
   0.0177536,
   0.01610338,
   0.01638466,
   0.01473966,
   0.01639629,
   0.01553578,
   0.01945342,
   0.0179949,
   0.01863211,
   0.01768351,
   0.01973211,
   0.01897051,
   0.02330566,
   0.02484717,
   0.02731119};
   gre = new TGraphErrors(20,Graph_fx1008,Graph_fy1008,Graph_fex1008,Graph_fey1008);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,-2.4,2.4);
   Graph_Graph1008->SetMinimum(0.2471066);
   Graph_Graph1008->SetMaximum(0.463652);
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
   TLatex *   tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 & refpt>30}}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(24);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.17,0.17,"Centrality:0-30%");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(24);
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
   Can_result_1->Modified();
   Can_result_1->cd();
   Can_result_1->SetSelected(Can_result_1);
}
