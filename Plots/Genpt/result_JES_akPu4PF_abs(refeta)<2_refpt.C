void result_JES_akPu4PF_abs(refeta)<2_refpt()
{
//=========Macro generated from canvas: Can_result_0/
//=========  (Sun Apr 17 19:19:04 2016) by ROOT version6.02/13
   TCanvas *Can_result_0 = new TCanvas("Can_result_0", "",10,32,700,500);
   gStyle->SetOptFit(1);
   Can_result_0->Range(9.999998,0.9358876,230,0.9930149);
   Can_result_0->SetFillColor(0);
   Can_result_0->SetBorderMode(0);
   Can_result_0->SetBorderSize(2);
   Can_result_0->SetFrameBorderMode(0);
   Can_result_0->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("name");
   multigraph->SetTitle("title");
   
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
   0.9723946,
   0.9587994,
   0.9560621,
   0.9664893,
   0.9745267,
   0.9765667,
   0.9787555,
   0.980204,
   0.9823471,
   0.982663,
   0.9838406};
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
   0.001336807,
   0.001179489,
   0.000963172,
   0.0007377676,
   0.0006635932,
   0.0007451992,
   0.0008701069,
   0.001026977,
   0.0009319902,
   0.00127801,
   0.001384188};
   gre = new TGraphErrors(11,Graph_fx1002,Graph_fy1002,Graph_fex1002,Graph_fey1002);
   gre->SetName("Graph");
   gre->SetTitle("some title_1");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","some title_1",100,24,216);
   Graph_Graph1002->SetMinimum(0.9520864);
   Graph_Graph1002->SetMaximum(0.9882374);
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
   0.9691917,
   0.9490252,
   0.94969,
   0.9603047,
   0.9543856,
   0.95104,
   0.9553062,
   0.9705362,
   0.964243,
   0.978039,
   0.960648};
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
   0.007636518,
   0.00534749,
   0.004465468,
   0.003957761,
   0.003691487,
   0.004473187,
   0.004308811,
   0.006146991,
   0.005153261,
   0.00685829,
   0.01148489};
   gre = new TGraphErrors(11,Graph_fx1003,Graph_fy1003,Graph_fex1003,Graph_fey1003);
   gre->SetName("Graph");
   gre->SetTitle("some title_2");
   gre->SetFillColor(1);
   gre->SetFillStyle(0);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","some title_2",100,24,216);
   Graph_Graph1003->SetMinimum(0.9395558);
   Graph_Graph1003->SetMaximum(0.9890193);
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
   
   TPaveText *pt = new TPaveText(0.3750575,0.9365254,0.6249425,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText("JES_akPu4PF");
   pt->Draw();
   Can_result_0->Modified();
   Can_result_0->cd();
   Can_result_0->SetSelected(Can_result_0);
}
