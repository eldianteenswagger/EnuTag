void hists_all(){

    //define all tchains
    TChain* tUSVD1 = new TChain("tUSVD1");
    TChain* tUSVD2 = new TChain("tUSVD2");
    TChain* tMiddle1 = new TChain("tMiddle1");
    TChain* tMiddle2 = new TChain("tMiddle2");
    TChain* tMiddle3 = new TChain("tMiddle3");
    TChain* tMiddle4 = new TChain("tMiddle4");
    TChain* tMiddle5 = new TChain("tMiddle5");
    TChain* tDet1 = new TChain("tDet1");
    TChain* tDet2 = new TChain("tDet2");
    TChain* tDet3 = new TChain("tDet3");
    TChain* tDet4 = new TChain("tDet4");
    TChain* tDet5 = new TChain("tDet5");
    TChain* tDSVD1 = new TChain("tDSVD1");
    TChain* tDSVD2 = new TChain("tDSVD2");
    TChain* tFVD = new TChain("tFVD");
    TChain* tNeutrinos = new TChain("tNeutrinos");

    //unite all files
    for (int i=0;i<1;i++){
        std::string fileName = "runOut"+to_string(i)+".root";
        tUSVD1->AddFile((fileName+"/USVD_1").c_str());
        tUSVD2->AddFile((fileName+"/USVD_2").c_str());
        tMiddle1->AddFile((fileName+"/Middle_1").c_str());
        tMiddle2->AddFile((fileName+"/Middle_2").c_str());
        tMiddle3->AddFile((fileName+"/Middle_3").c_str());
        tMiddle4->AddFile((fileName+"/Middle_4").c_str());
        tMiddle5->AddFile((fileName+"/Middle_5").c_str());
        tDet1->AddFile((fileName+"/Det_1").c_str());
        tDet2->AddFile((fileName+"/Det_2").c_str());
        tDet3->AddFile((fileName+"/Det_3").c_str());
        tDet4->AddFile((fileName+"/Det_4").c_str());
        tDet5->AddFile((fileName+"/Det_5").c_str());
        tDSVD1->AddFile((fileName+"/DSVD_1").c_str());
        tDSVD2->AddFile((fileName+"/DSVD_2").c_str());
        tFVD->AddFile((fileName+"/FVD").c_str());
        tNeutrinos->AddFile((fileName+"/neutrinos").c_str());
    }

    // Variables for branches
    Double_t E;
    Double_t x;
    Double_t y;
    Double_t px;
    Double_t py;
    Double_t pz;
    Double_t t;
    Char_t PDG[64];
    Int_t ID;
    Double_t dE;
    Double_t nu_x;
    Double_t nu_y;
    Double_t nu_z;

    //random stuff
    std::vector<std::string> partSelect = {"nu_e","nu_mu","nu_tau","anti_nu_e","anti_nu_mu","anti_nu_tau"};
    Double_t absAngle = 9.09 * 3.141592 / 90;

    std::vector<TChain*> treeSelect = {tUSVD1,tUSVD2,tMiddle1,tMiddle2,tMiddle3,tMiddle4,tMiddle5,tDet1,tDet2,tDet3,tDet4,tDet5,tDSVD1,tDSVD2,tFVD,tNeutrinos};
    std::vector<std::string> treeName = {"USVD1","USVD2","Middle1","Middle2","Middle3","Middle4","Middle5","Det1","Det2","Det3","Det4","Det5","DSVD1","DSVD2","FVD","Neutrinos"};
    std::vector<bool> treeVD = {true,true,true,true,true,true,true,false,false,false,false,false,true,true,true};
    std::map<std::string, int> colorMap = {
        {"nu_e", kGray},
        {"nu_mu", kGray},
        {"nu_tau", kGray},
        {"anti_nu_e", kGray+1},
        {"anti_nu_mu", kGray+1},
        {"anti_nu_tau", kGray+1},
        {"gamma", kYellow},
        {"neutron", kGreen},
        {"anti_neutron", kGreen+1},
        {"pi+", kRed},
        {"pi-", kBlue},
        {"kaon+", kOrange},
        {"kaon-", kCyan},
        {"kaon0L", kBlack},
        {"kaon0S", kBlack},
        {"proton", kMagenta},
        {"e-", kBlue+2},
        {"e+", kRed+2}
    };

    //outfile

    std::string PDFout = "outMacro_1000.pdf";
    TCanvas* c = new TCanvas("Canvas");
    c->Print((PDFout+"[").c_str());
    c->Clear();

    TCanvas* clog = new TCanvas("CanvasLog");
    clog->SetLogy();


    for(int i = 0; i<treeSelect.size();++i){

        if(treeName[i]=="Neutrinos"){
            treeSelect[i]->SetBranchAddress("nu_x", &nu_x);
            treeSelect[i]->SetBranchAddress("nu_y", &nu_y);
            treeSelect[i]->SetBranchAddress("nu_z", &nu_z);

            auto neutrinoMap = new TGraph2D();
            TH1D* hnux = new TH1D("hnux", "hnux", 500, -1., 19.);
            TH1D* hnuy = new TH1D("hnuy", "hnuy", 100, -2., 2.);
            TH1D* hnuz = new TH1D("hnuz", "hnuz", 150, -2., 4.);

            // Loop over the tree entries
            Long64_t nEntries = treeSelect[i]->GetEntries();
            for (Long64_t j = 0; j < nEntries; ++j) {
                treeSelect[i]->GetEntry(j);
                neutrinoMap->SetPoint(j,nu_x,nu_y,nu_z);
                hnux->Fill(nu_x);
                hnuy->Fill(nu_y);
                hnuz->Fill(nu_z);
            }

            clog->Clear();
            c->Clear();
            c->Update();

            hnux->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            hnuy->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            hnuz->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            neutrinoMap->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
        }
        else {
            treeSelect[i]->SetBranchAddress("E", &E);
            treeSelect[i]->SetBranchAddress("x", &x);
            treeSelect[i]->SetBranchAddress("y", &y);
            treeSelect[i]->SetBranchAddress("px", &px);
            treeSelect[i]->SetBranchAddress("py", &py);
            treeSelect[i]->SetBranchAddress("pz", &pz);
            treeSelect[i]->SetBranchAddress("t", &t);
            treeSelect[i]->SetBranchAddress("PDG", &PDG);
            treeSelect[i]->SetBranchAddress("ID", &ID);
            treeSelect[i]->SetBranchAddress("dE", &dE);

            //ALL HISTS
            //stat_hists
            TH1D* hE = new TH1D(("hE_"+treeName[i]).c_str(), ("hE_"+treeName[i]).c_str(), 100, 0, 10000);
            TH1D* hx = new TH1D(("hx_"+treeName[i]).c_str(), ("hx_"+treeName[i]).c_str(), 100, -500., 500.);
            TH1D* hy = new TH1D(("hy_"+treeName[i]).c_str(), ("hy_"+treeName[i]).c_str(), 100, -500., 500.);
            if(treeName[i]=="FVD"){
                hx = new TH1D(("hx_"+treeName[i]).c_str(), ("hx_"+treeName[i]).c_str(), 100, -20000., 20000.);
                hy = new TH1D(("hy_"+treeName[i]).c_str(), ("hy_"+treeName[i]).c_str(), 100, -20000., 20000.);
            }
            TH1D* hpx = new TH1D(("hpx_"+treeName[i]).c_str(), ("hpx_"+treeName[i]).c_str(), 100, 0, 10000);
            TH1D* hpy = new TH1D(("hpy_"+treeName[i]).c_str(), ("hpy_"+treeName[i]).c_str(), 100, 0, 10000);
            TH1D* hpz = new TH1D(("hpz_"+treeName[i]).c_str(), ("hpz_"+treeName[i]).c_str(), 100, 0, 10000);
            TH1D* ht = new TH1D(("ht_"+treeName[i]).c_str(), ("ht_"+treeName[i]).c_str(), 100, 0, 1e-6);
            //TH1C* hPDG = new TH1C();
            TH1I* hID = new TH1I(("hID_"+treeName[i]).c_str(), ("hID_"+treeName[i]).c_str(),500,-250,250);
            TH1D* hdE = new TH1D(("hdE_"+treeName[i]).c_str(), ("hdE_"+treeName[i]).c_str(), 40, 0, 2);
            //spectrum_histogram
            //neutrino_histograms
            TH1D* momHist = new TH1D(("momHist_"+treeName[i]).c_str(), ("momHist_"+treeName[i]).c_str(), 100, 0, 10000);
            TH2D* momangleHistX = new TH2D(("momangleHistX_"+treeName[i]).c_str(), ("momangleHistX_"+treeName[i]).c_str(), 100, 0., 10000., 180, -90., 90.);
            TH2D* momangleHistY = new TH2D(("momangleHistY_"+treeName[i]).c_str(), ("momangleHistY_"+treeName[i]).c_str(), 100, 0., 10000., 180, -90., 90.);
            TH2D* posHist = new TH2D(("posHist_"+treeName[i]).c_str(), ("posHist_"+treeName[i]).c_str(), 100, -500., 500., 100, -500., 500.);
            if(treeName[i]=="FVD"){posHist = new TH2D(("posHist_"+treeName[i]).c_str(), ("posHist_"+treeName[i]).c_str(), 100, -20000., 20000., 100, -20000., 20000.);}

            TH1D* pseudoRapHist = new TH1D(("pseudoRapHist_"+treeName[i]).c_str(), ("pseudoRapHist_"+treeName[i]).c_str(), 100, 0, 10);
            TH2D* rapidAngleHist = new TH2D(("rapidAngleHist_"+treeName[i]).c_str(), ("rapidAngleHist_"+treeName[i]).c_str(), 180, -90., 90., 100, -10., 10.);
            TH2D* rapidEnengyHist = new TH2D(("rapidEnengyHist_"+treeName[i]).c_str(), ("rapidEnengyHist_"+treeName[i]).c_str(), 100, 0, 10000, 100, -10., 10.);
            TH2D* rapidTimeHist = new TH2D(("rapidTimeHist_"+treeName[i]).c_str(), ("rapidTimeHist_"+treeName[i]).c_str(), 100, 0, 1e-6, 100, -10., 10.);
            TH2D* energyTimeHist = new TH2D(("energyTimeHist_"+treeName[i]).c_str(), ("energyTimeHist_"+treeName[i]).c_str(), 100, 0, 10000, 100, 0, 1e-6);

            std::map<std::string, TH1D*> histMapE;
            std::map<std::string, TH1D*> histMapEE;

            //neutrino_map

            // Loop over the tree entries
            Long64_t nEntries = treeSelect[i]->GetEntries();
            for (Long64_t j = 0; j < nEntries; ++j) {

                treeSelect[i]->GetEntry(j);

                hE->Fill(E);
                hx->Fill(x);
                hy->Fill(y);
                hpx->Fill(px);
                hpy->Fill(py);
                hpz->Fill(pz);
                ht->Fill(t);
                //hPDG->Fill(PDG);
                hID->Fill(ID);

                //neutrino stuff
                std::string pdgStr(PDG);

                if ( (std::find(partSelect.begin(), partSelect.end(), pdgStr)!= partSelect.end()) ){

                    Double_t mom = std::sqrt((px*px)+(py*py)+(pz*pz));
                    Double_t mom_xz = std::sqrt((pz*pz)+(py*py));
                    Double_t angleX = (std::asin(mom_xz/mom) - absAngle);
                    Double_t angleY = (std::asin(py/mom));
                    momHist->Fill(mom);
                    momangleHistX->Fill(mom,(180. / 3.141592) * angleX);
                    momangleHistY->Fill(mom,(180. / 3.141592) * angleY);
                    posHist->Fill(x,y);
                    if(treeVD[i]){
                        Double_t pseudoRapidity = (-1.)*std::log(std::tan(angleX*0.5));
                        pseudoRapHist->Fill(pseudoRapidity);
                        rapidAngleHist->Fill((180. / 3.141592) * angleX,pseudoRapidity);
                        rapidEnengyHist->Fill(E,pseudoRapidity);
                        rapidTimeHist->Fill(t,pseudoRapidity);
                        energyTimeHist->Fill(E,t);
                    }
                }

                if(!treeVD[i]){hdE->Fill(dE);}
                if(colorMap.find(pdgStr) != colorMap.end()){
                    if (histMapE.find(pdgStr) == histMapE.end()) {
                        // Create a new histogram for this PDG
                        std::string histNameE = "h_" + pdgStr+"_E";
                        histMapE[pdgStr] = new TH1D(histNameE.c_str(), ("Energy_"+treeName[i]).c_str(), 100, 0, 10000);
                        histMapE[pdgStr]->SetLineWidth(2);
                        histMapE[pdgStr]->GetYaxis()->SetRangeUser(1e-1, 10000.);
                        histMapE[pdgStr]->SetLineColor(colorMap[pdgStr]);
                        std::string histNameEE = "h_" + pdgStr+"_EE";
                        histMapEE[pdgStr] = new TH1D(histNameEE.c_str(), ("Spectrum_"+treeName[i]).c_str(), 100, 0, 10000);
                        histMapEE[pdgStr]->SetLineWidth(2);
                        histMapEE[pdgStr]->GetYaxis()->SetRangeUser(1e-1, 10000.);
                        histMapEE[pdgStr]->SetLineColor(colorMap[pdgStr]);
                    }        
                histMapE[pdgStr]->Fill(E);
                histMapEE[pdgStr]->Fill(E,E/1000);
                }
            }

            //out files
            /*std::string outFileName = "./OUT/"+treeName[i]+".root";
            TFile* outFile = new TFile(outFileName.data(), "RECREATE");

            outFile->WriteObject(hE,"hE");
            outFile->WriteObject(hx,"hx");
            outFile->WriteObject(hy,"hy");
            outFile->WriteObject(hpx,"hpx");
            outFile->WriteObject(hpy,"hpy");
            outFile->WriteObject(hpz,"hpy");
            outFile->WriteObject(ht,"ht");
            //outFile->WriteObject(treeSelect[i]->Get("PDG"),"hPDG");
            outFile->WriteObject(hID,"hID");

            outFile->WriteObject(momHist,"momHist");
            outFile->WriteObject(momangleHistX,"momangleHistX");
            outFile->WriteObject(momangleHistY,"momangleHistY");
            outFile->WriteObject(posHist,"posHist");

            if(treeVD[i]){
                outFile->WriteObject(pseudoRapHist,"pseudoRapHist");
                outFile->WriteObject(rapidEnengyHist,"rapidEnengyHist");
                outFile->WriteObject(rapidAngleHist,"rapidAngleHist");
                outFile->WriteObject(rapidTimeHist,"rapidTimeHist");
                outFile->WriteObject(energyTimeHist,"energyTimeHist");
            }
            else{outFile->WriteObject(hdE,"hdE");}*/

            c->Clear();
            hE->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            hx->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            hy->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            hpx->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            hpy->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            hpz->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            ht->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            treeSelect[i]->Draw("PDG");
            c->Print(PDFout.c_str());
            c->Clear();
            hID->Draw();
            c->Print(PDFout.c_str());
            c->Clear();

            momHist->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            momangleHistX->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            momangleHistY->Draw();
            c->Print(PDFout.c_str());
            c->Clear();
            if(treeVD[i]){
                pseudoRapHist->Draw();
                c->Print(PDFout.c_str());
                c->Clear();
                rapidEnengyHist->Draw();
                c->Print(PDFout.c_str());
                c->Clear();
                rapidAngleHist->Draw();
                c->Print(PDFout.c_str());
                c->Clear();
                rapidTimeHist->Draw();
                c->Print(PDFout.c_str());
                c->Clear();
                energyTimeHist->Draw();
                c->Print(PDFout.c_str());
                c->Clear();
                posHist->Draw();
                c->Print(PDFout.c_str());
                c->Clear();
            }
            else {
                hdE->Draw();
                c->Print(PDFout.c_str());
                c->Clear();
            }
            clog->Clear();
            clog->Update();

            TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
            int color = 1;
            for (auto &entry : histMapE) {
                entry.second->Draw((color == 1 ? "HIST" : "HIST SAME"));
                legend->AddEntry(entry.second, entry.first.c_str(), "l");
                color++;
            }
            legend->Draw();
            clog->Update();
            clog->Print(PDFout.c_str());
            clog->Clear();

            legend = new TLegend(0.7, 0.7, 0.9, 0.9);
            color = 1;
            for (auto &entry : histMapEE) {
                entry.second->Draw((color == 1 ? "HIST" : "HIST SAME"));
                legend->AddEntry(entry.second, entry.first.c_str(), "l");
                color++;
            }
            legend->Draw();
            clog->Update();
            clog->Print(PDFout.c_str());
            clog->Clear();
            c->Update();
            
        }
    }

    c->Print((PDFout+"]").c_str());
}