void result_JES_abs(refeta)<2_refpt()
{
//=========Macro generated from canvas: Can_result_0/
//=========  (Mon Apr 18 03:27:43 2016) by ROOT version6.02/13
   TCanvas *Can_result_0 = new TCanvas("Can_result_0", "",18,40,700,500);
   gStyle->SetOptFit(1);
   Can_result_0->Range(9.999998,0.9272406,230,1.133117);
   Can_result_0->SetFillColor(0);
   Can_result_0->SetBorderMode(0);
   Can_result_0->SetBorderSize(2);
   Can_result_0->SetFrameBorderMode(0);
   Can_result_0->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("JES");
   
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
   0.9732904,
   0.9593214,
   0.9562515,
   0.96652,
   0.97454,
   0.9763317,
   0.9784283,
   0.9800401,
   0.9819675,
   0.9815876,
   0.9835479};
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
   0.001304104,
   0.001148053,
   0.0009369201,
   0.000719469,
   0.0006462799,
   0.0007282932,
   0.0008495261,
   0.0009999426,
   0.0009085157,
   0.001246467,
   0.001348662};
   TGraphErrors *gre = new TGraphErrors(11,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
   gre->SetName("Graph");
   gre->SetTitle("some title_0");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","some title_0",100,24,216);
   Graph_Graph1001->SetMinimum(0.9523564);
   Graph_Graph1001->SetMaximum(0.9878548);
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
   0.9750911,
   0.9730877,
   0.9754324,
   0.9825526,
   0.9891584,
   0.9920413,
   0.9950365,
   0.997003,
   0.9982245,
   0.9991004,
   1.001424};
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
   0.001301967,
   0.001174973,
   0.0009683419,
   0.0007261027,
   0.0006433609,
   0.0007244695,
   0.0008353996,
   0.0009868874,
   0.0008856689,
   0.001188998,
   0.001272469};
   gre = new TGraphErrors(11,Graph_fx1002,Graph_fy1002,Graph_fex1002,Graph_fey1002);
   gre->SetName("Graph");
   gre->SetTitle("some title_1");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","some title_1",100,24,216);
   Graph_Graph1002->SetMinimum(0.9688344);
   Graph_Graph1002->SetMaximum(1.005775);
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
   1.0127,
   0.9750756,
   0.9602517,
   0.9697537,
   0.9805084,
   0.9810086,
   0.9799298,
   0.9798168,
   0.9791287,
   0.9761261,
   0.9782279};
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
   0.001479278,
   0.001276082,
   0.001030296,
   0.000791591,
   0.0007100935,
   0.0007966822,
   0.0009319081,
   0.001104439,
   0.001001764,
   0.001387942,
   0.001569517};
   gre = new TGraphErrors(11,Graph_fx1003,Graph_fy1003,Graph_fex1003,Graph_fey1003);
   gre->SetName("Graph");
   gre->SetTitle("some title_2");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","some title_2",100,24,216);
   Graph_Graph1003->SetMinimum(0.9537256);
   Graph_Graph1003->SetMaximum(1.019675);
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
   1.1033,
   1.081203,
   1.065553,
   1.066193,
   1.067518,
   1.062462,
   1.056986,
   1.052111,
   1.046662,
   1.036212,
   1.032538};
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
   0.001742494,
   0.001466463,
   0.001149172,
   0.0008532221,
   0.0007469682,
   0.0008185497,
   0.0009402211,
   0.001111109,
   0.0009945553,
   0.001339758,
   0.001516852};
   gre = new TGraphErrors(11,Graph_fx1004,Graph_fy1004,Graph_fex1004,Graph_fey1004);
   gre->SetName("Graph");
   gre->SetTitle("some title_3");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","some title_3",100,24,216);
   Graph_Graph1004->SetMinimum(1.023619);
   Graph_Graph1004->SetMaximum(1.112445);
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
   TLatex *   tex = new TLatex(0.35,0.8,"#bf{#color[2]{|#eta_{jet}|<2.0 }}");
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
   Can_result_0->Modified();
   Can_result_0->cd();
   Can_result_0->SetSelected(Can_result_0);
}
