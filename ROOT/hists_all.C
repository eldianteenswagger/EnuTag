void hists_all(){

    //define all tchains
    TChain* tUSVD = new TChain("tUSVD");
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

    int count = 0;

    double Elim = 10000.;
    double Ebin = 100.;

    //unite all files
    for (int i=0;i<5;i++){
        std::string fileName = "runOut"+to_string(i)+".root";

        TFile *file = TFile::Open(fileName.data());
        if (!file || file->IsZombie()) {
            continue;
        } else {

            count++;

            tUSVD->AddFile((fileName+"/USVD").c_str());
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

            file->Close();
        }


    }

    // Variables for branches
    Double_t E;
    Double_t x;
    Double_t y;
    Double_t absx;
    Double_t absy;
    Double_t absz;
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

    std::vector<TChain*> treeSelect = {tUSVD,tMiddle1,tMiddle2,tMiddle3,tMiddle4,tMiddle5,tDet1,tDet2,tDet3,tDet4,tDet5,tDSVD1,tDSVD2,tFVD,tNeutrinos};
    std::vector<std::string> treeName = {"USVD","Middle1","Middle2","Middle3","Middle4","Middle5","Det1","Det2","Det3","Det4","Det5","DSVD1","DSVD2","FVD","Neutrinos"};
    std::vector<bool> treeVD = {true,true,true,true,true,true,false,false,false,false,false,true,true,true};
    std::vector<double> pionsIntegral = {};
    std::vector<double> kaonsIntegral = {};
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

    double norm = count * 2000.;

    //outfile

    std::string ExtraOut = "./OUT/Extra.root";
    TFile* outFileExtra = new TFile(ExtraOut.data(), "RECREATE");
    TCanvas* c = new TCanvas("Canvas","Canvas",1920,1200);
    c->Clear();

    TCanvas* clog = new TCanvas("CanvasLog","CanvasLog",1920,1200);
    clog->SetLogy();

    std::map<std::string, TH1D*> histMapPions;
    std::map<std::string, TH1D*> histMapKaons;

    std::map<std::string, TH1D*> histMapPionsLim;
    std::map<std::string, TH1D*> histMapKaonsLim;

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
                neutrinoMap->SetPoint(j,nu_z,nu_x,nu_y);
                hnux->Fill(nu_x);
                hnuy->Fill(nu_y);
                hnuz->Fill(nu_z);
            }

            hnux->GetXaxis()->SetTitle("x [m]");
            hnuy->GetXaxis()->SetTitle("y [m]");
            hnuz->GetXaxis()->SetTitle("z [m]");

            //out files
            std::string outFileName = "./OUT/"+treeName[i]+".root";
            TFile* outFile = new TFile(outFileName.data(), "RECREATE");
                        
            outFile->WriteObject(hnuz,"hnux");
            outFile->WriteObject(hnuy,"hnuy");
            outFile->WriteObject(hnuz,"hnuz");

            c->Clear();
            neutrinoMap->Draw("box");
            outFileExtra->WriteObject(neutrinoMap,"neutrinoMap");
            c->Clear();
        }
        else {
            treeSelect[i]->SetBranchAddress("E", &E);
            treeSelect[i]->SetBranchAddress("x", &x);
            treeSelect[i]->SetBranchAddress("y", &y);
            treeSelect[i]->SetBranchAddress("absx", &absx);
            treeSelect[i]->SetBranchAddress("absy", &absy);
            treeSelect[i]->SetBranchAddress("absz", &absz);
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
            TH1D* habsx = new TH1D(("habsx_"+treeName[i]).c_str(), ("habsx_"+treeName[i]).c_str(), 300, 0, 30000);
            TH1D* habsy = new TH1D(("habsy_"+treeName[i]).c_str(), ("habsy_"+treeName[i]).c_str(), 400, -1000, 3000);
            TH1D* habsz = new TH1D(("habsz_"+treeName[i]).c_str(), ("habsz_"+treeName[i]).c_str(), 400, -1000, 3000);
            auto detMap = new TGraph2D();

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
            std::map<std::string, TH1D*> histMapElim;
            std::map<std::string, TH1D*> histMapEElim;

            //neutrino_map

            // Loop over the tree entries
            Long64_t nEntries = treeSelect[i]->GetEntries();
            for (Long64_t j = 0; j < nEntries; ++j) {

                treeSelect[i]->GetEntry(j);

                hE->Fill(E);
                hx->Fill(x);
                hy->Fill(y);
                habsx->Fill(absx);
                habsy->Fill(absy);
                habsz->Fill(absz);
                hpx->Fill(px);
                hpy->Fill(py);
                hpz->Fill(pz);
                ht->Fill(t);
                hID->Fill(ID);
                detMap->SetPoint(j,absz,absx,absy);

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
                        histMapE[pdgStr] = new TH1D(histNameE.c_str(), ("Energy_"+treeName[i]).c_str(), Elim/Ebin, 0, Elim);
                        histMapE[pdgStr]->SetLineWidth(2);
                        histMapE[pdgStr]->GetYaxis()->SetRangeUser(1e-8, 10.);
                        histMapE[pdgStr]->SetLineColor(colorMap[pdgStr]);
                        std::string histNameEE = "h_" + pdgStr+"_EE";
                        histMapEE[pdgStr] = new TH1D(histNameEE.c_str(), ("Spectrum_"+treeName[i]).c_str(), Elim/Ebin, 0, Elim);
                        histMapEE[pdgStr]->SetLineWidth(2);
                        histMapEE[pdgStr]->GetYaxis()->SetRangeUser(1e-6, 1000.);
                        histMapEE[pdgStr]->SetLineColor(colorMap[pdgStr]);
                        std::string histNameElim = "h_" + pdgStr+"_E_lim";
                        histMapElim[pdgStr] = new TH1D(histNameElim.c_str(), ("Energy_"+treeName[i]).c_str(), 2000/Ebin, 7500, 9500);
                        histMapElim[pdgStr]->SetLineWidth(2);
                        histMapElim[pdgStr]->GetYaxis()->SetRangeUser(1e-8, 10.);
                        histMapElim[pdgStr]->SetLineColor(colorMap[pdgStr]);
                        std::string histNameEElim = "h_" + pdgStr+"_EE_lim";
                        histMapEElim[pdgStr] = new TH1D(histNameEElim.c_str(), ("Spectrum_"+treeName[i]).c_str(), 2000/Ebin, 7500, 9500);
                        histMapEElim[pdgStr]->SetLineWidth(2);
                        histMapEElim[pdgStr]->GetYaxis()->SetRangeUser(1e-6, 1000.);
                        histMapEElim[pdgStr]->SetLineColor(colorMap[pdgStr]);
                    }        
                histMapE[pdgStr]->Fill(E);
                histMapEE[pdgStr]->Fill(E,E);
                if(abs(E-8500)<1000){
                    histMapElim[pdgStr]->Fill(E);
                    histMapEElim[pdgStr]->Fill(E,E);
                    }
                }
            }

            //graph axis titles
            hE->GetXaxis()->SetTitle("Energy [MeV]");
            hE->GetYaxis()->SetTitle("Count/POT");
            hx->GetXaxis()->SetTitle("x [mm]");
            hx->GetYaxis()->SetTitle("Count/POT");
            hy->GetXaxis()->SetTitle("y [mm]");
            hy->GetYaxis()->SetTitle("Count/POT");
            habsx->GetXaxis()->SetTitle("x [mm]");
            habsx->GetYaxis()->SetTitle("Count/POT");
            habsy->GetXaxis()->SetTitle("y [mm]");
            habsy->GetYaxis()->SetTitle("Count/POT");
            habsz->GetXaxis()->SetTitle("y [mm]");
            habsz->GetYaxis()->SetTitle("Count/POT");
            hpx->GetXaxis()->SetTitle("p_{x} [Mev/c]");
            hpx->GetYaxis()->SetTitle("Count/POT");
            hpy->GetXaxis()->SetTitle("p_{y} [Mev/c]");
            hpy->GetYaxis()->SetTitle("Count/POT");
            hpz->GetXaxis()->SetTitle("p_{z} [Mev/c]");
            hpz->GetYaxis()->SetTitle("Count/POT");

            hE->Scale(1./norm);
            hx->Scale(1./norm);
            hy->Scale(1./norm);
            habsx->Scale(1./norm);
            habsy->Scale(1./norm);
            habsz->Scale(1./norm);
            hpx->Scale(1./norm);
            hpy->Scale(1./norm);
            hpz->Scale(1./norm);
            ht->Scale(1./norm);
            hID->Scale(1./norm);

            //out files
            std::string outFileName = "./OUT/"+treeName[i]+".root";
            TFile* outFile = new TFile(outFileName.data(), "RECREATE");

            outFile->WriteObject(hE,"hE");
            outFile->WriteObject(hx,"hx");
            outFile->WriteObject(hy,"hy");
            outFile->WriteObject(habsx,"habsx");
            outFile->WriteObject(habsy,"habsy");
            outFile->WriteObject(habsz,"habsz");
            outFile->WriteObject(hpx,"hpx");
            outFile->WriteObject(hpy,"hpy");
            outFile->WriteObject(hpz,"hpy");
            outFile->WriteObject(ht,"ht");
            //outFile->WriteObject(treeSelect[i]->Get("PDG"),"hPDG");
            outFile->WriteObject(hID,"hID");

            momHist->GetXaxis()->SetTitle("|p| [Mev/c]");
            momHist->GetYaxis()->SetTitle("Count/POT");
            momangleHistX->GetXaxis()->SetTitle("|p| [Mev/c]");
            momangleHistX->GetYaxis()->SetTitle("#theta [deg]");
            momangleHistY->GetXaxis()->SetTitle("|p| [Mev/c]");
            momangleHistY->GetYaxis()->SetTitle("#theta [deg]");
            posHist->GetXaxis()->SetTitle("x [mm]");
            posHist->GetYaxis()->SetTitle("y [mm]");

            outFile->WriteObject(momHist,"momHist");
            outFile->WriteObject(momangleHistX,"momangleHistX");
            outFile->WriteObject(momangleHistY,"momangleHistY");
            outFile->WriteObject(posHist,"posHist");

            outFile->WriteObject(detMap,"detMap");

            if(treeVD[i]){
                pseudoRapHist->GetXaxis()->SetTitle("#eta");
                rapidEnengyHist->GetXaxis()->SetTitle("E [MeV]");
                rapidEnengyHist->GetYaxis()->SetTitle("#eta");
                rapidAngleHist->GetXaxis()->SetTitle("#theta [deg]");
                rapidAngleHist->GetYaxis()->SetTitle("#eta");
                rapidTimeHist->GetXaxis()->SetTitle("t [s]");
                rapidTimeHist->GetYaxis()->SetTitle("#eta");
                energyTimeHist->GetXaxis()->SetTitle("E [MeV]");
                energyTimeHist->GetYaxis()->SetTitle("t [s]");

                pseudoRapHist->Scale(1./norm);
                rapidAngleHist->Scale(1./norm);
                rapidEnengyHist->Scale(1./norm);
                rapidTimeHist->Scale(1./norm);
                energyTimeHist->Scale(1./norm);

                outFile->WriteObject(pseudoRapHist,"pseudoRapHist");
                outFile->WriteObject(rapidEnengyHist,"rapidEnengyHist");
                outFile->WriteObject(rapidAngleHist,"rapidAngleHist");
                outFile->WriteObject(rapidTimeHist,"rapidTimeHist");
                outFile->WriteObject(energyTimeHist,"energyTimeHist");
            }
            else{
                hdE->GetXaxis()->SetTitle("Energy Loss [MeV]");
                hdE->GetYaxis()->SetTitle("Count/POT");
                hdE->Scale(1./norm);
                outFile->WriteObject(hdE,"hdE");
            }

            clog->Clear();
            clog->Update();

            TLegend *legend = new TLegend(0.9, 0.9, 0.99, 0.1);
            int color = 1;
            for (auto &entry : histMapE) {
                if(entry.first=="pi+"){pionsIntegral.push_back(entry.second->Integral(7500/Ebin,9500/Ebin)*(1./norm));}
                if(entry.first=="kaon+"){kaonsIntegral.push_back(entry.second->Integral(7500/Ebin,9500/Ebin)*(1./norm));}
                entry.second->Scale(1./norm);
                entry.second->GetYaxis()->SetRangeUser(1e-6, 10.);
                entry.second->Draw((color == 1 ? "HIST" : "HIST SAME"));
                entry.second->SetStats(0);
                legend->AddEntry(entry.second, entry.first.c_str(), "l");
                entry.second->GetXaxis()->SetTitle("E [MeV]");
                entry.second->GetYaxis()->SetTitle("Count/POT");
                color++;
            }
            legend->Draw();
            clog->Update();
            outFile->WriteObject(clog,("histMapE_"+treeName[i]).c_str());
            clog->Clear();

            legend = new TLegend(0.9, 0.9, 0.99, 0.1);
            color = 1;
            for (auto &entry : histMapEE) {
                entry.second->Scale(1./norm);
                entry.second->GetYaxis()->SetRangeUser(1e-4, 1000.);
                entry.second->Draw((color == 1 ? "HIST" : "HIST SAME"));
                entry.second->SetStats(0);
                legend->AddEntry(entry.second, entry.first.c_str(), "l");
                entry.second->GetXaxis()->SetTitle("E [MeV]");
                entry.second->GetYaxis()->SetTitle("Flux/POT [MeV]");
                color++;
            }
            legend->Draw();
            clog->Update();
            outFile->WriteObject(clog,("histMapS_"+treeName[i]).c_str());
            clog->Clear();
            clog->Update();

            legend = new TLegend(0.9, 0.9, 0.99, 0.1);
            color = 1;
            for (auto &entry : histMapElim) {
                entry.second->Scale(1./norm);
                entry.second->GetYaxis()->SetRangeUser(1e-6, 10.);
                entry.second->Draw((color == 1 ? "HIST" : "HIST SAME"));
                entry.second->SetStats(0);
                legend->AddEntry(entry.second, entry.first.c_str(), "l");
                entry.second->GetXaxis()->SetTitle("E [MeV]");
                entry.second->GetYaxis()->SetTitle("Count/POT");
                color++;
            }
            legend->Draw();
            clog->Update();
            outFile->WriteObject(clog,("histMapE_"+treeName[i]).c_str());
            clog->Clear();

            legend = new TLegend(0.9, 0.9, 0.99, 0.1);
            color = 1;
            for (auto &entry : histMapEElim) {
                entry.second->Scale(1./norm);
                entry.second->GetYaxis()->SetRangeUser(1e-4, 1000.);
                entry.second->Draw((color == 1 ? "HIST" : "HIST SAME"));
                entry.second->SetStats(0);
                legend->AddEntry(entry.second, entry.first.c_str(), "l");
                entry.second->GetXaxis()->SetTitle("E [MeV]");
                entry.second->GetYaxis()->SetTitle("Flux/POT [MeV]");
                color++;
            }
            legend->Draw();
            clog->Update();
            outFile->WriteObject(clog,("histMapS_"+treeName[i]).c_str());
            clog->Clear();
            clog->Update();

            c->Update();
      
            if(treeName[i]!="FVD"){
                histMapPions.insert(std::make_pair(treeName[i],histMapE["pi+"]));
                histMapKaons.insert(std::make_pair(treeName[i],histMapE["kaon+"]));
                histMapPionsLim.insert(std::make_pair(treeName[i],histMapElim["pi+"]));
                histMapKaonsLim.insert(std::make_pair(treeName[i],histMapElim["kaon+"]));
            }

        }
    }

    //pions

    TLegend *legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    clog->Clear();
    int colorP = 0;
    gStyle->SetPalette(kSolar);
    for (int i=0;i<histMapPions.size()-1;i++) {
        histMapPions[treeName[i]]->Draw((colorP == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        histMapPions[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){histMapPions[treeName[i]]->SetLineColor(kYellow);}
        histMapPions[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        histMapPions[treeName[i]]->GetYaxis()->SetTitle("Count");
        legend->AddEntry(histMapPions[treeName[i]], treeName[i].c_str(), "l");
        clog->Update();
        colorP++;
    }
    legend->Draw();
    clog->Update();
    outFileExtra->WriteObject(clog,"pions");
    clog->Clear();
    c->Update();

    legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    clog->Clear();
    colorP = 0;
    gStyle->SetPalette(kSolar);
    for (int i=0;i<histMapPionsLim.size()-1;i++) {
        histMapPionsLim[treeName[i]]->Draw((colorP == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        histMapPionsLim[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){histMapPionsLim[treeName[i]]->SetLineColor(kYellow);}
        histMapPions[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        histMapPions[treeName[i]]->GetYaxis()->SetTitle("Energy flux [MeV]");
        legend->AddEntry(histMapPionsLim[treeName[i]], treeName[i].c_str(), "l");
        clog->Update();
        colorP++;
    }
    legend->Draw();
    clog->Update();
    outFileExtra->WriteObject(clog,"pions_lim");
    clog->Clear();
    c->Update();

    int colorK = 0;
    gStyle->SetPalette(kRust);
    legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    for (int i=0;i<histMapKaons.size()-1;i++) {
        histMapKaons[treeName[i]]->Draw((colorK == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        histMapKaons[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){histMapKaons[treeName[i]]->SetLineColor(kYellow);}
        histMapKaons[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        histMapKaons[treeName[i]]->GetYaxis()->SetTitle("Count");
        legend->AddEntry(histMapKaons[treeName[i]], treeName[i].c_str(), "l");
        clog->Update();
        colorK++;
    }
    legend->Draw();
    clog->Update();
    outFileExtra->WriteObject(clog,"kaons");
    clog->Clear();
    c->Update();

    colorK = 0;
    gStyle->SetPalette(kRust);
    legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    for (int i=0;i<histMapKaonsLim.size()-1;i++) {
        histMapKaonsLim[treeName[i]]->Draw((colorK == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        histMapKaonsLim[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){histMapKaonsLim[treeName[i]]->SetLineColor(kYellow);}
        histMapKaons[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        histMapKaons[treeName[i]]->GetYaxis()->SetTitle("Energy flux [MeV]");
        legend->AddEntry(histMapKaonsLim[treeName[i]], treeName[i].c_str(), "l");
        clog->Update();
        colorK++;
    }
    legend->Draw();
    clog->Update();
    outFileExtra->WriteObject(clog,"kaons_lim");
    clog->Clear();
    c->Update();
    c->Clear();
    TGraph* pionYield = new TGraph(pionsIntegral.size());
    TGraph* pionYieldS = new TGraph(pionsIntegral.size());
    TGraph* kaonYield = new TGraph(kaonsIntegral.size());
    TGraph* kaonYieldS = new TGraph(kaonsIntegral.size());
    std::vector<double> s={1.5, 6.7109660, 9.4318825, 11.312752, 12.990252, 15.139252, 17.070752, 17.320752, 18.820752, 19.096414, 23.785400, 26.235400, 66.235400};
    for(int i=0;i<pionsIntegral.size();++i){
        pionYield->SetPoint(i,i+1,pionsIntegral[i]);
        pionYieldS->SetPoint(i,s[i],pionsIntegral[i]);
    }
    pionYieldS->GetXaxis()->SetName("s [m]");
    pionYield->GetYaxis()->SetName("Count");
    pionYieldS->GetYaxis()->SetName("Count");
    auto axp = pionYield->GetXaxis();
    axp->SetNdivisions(pionsIntegral.size());
    for(int i=0;i<pionsIntegral.size();++i){
        axp->ChangeLabelByValue(i+1,-1,-100,-1,1,-1,treeName[i].c_str());
    }
    for(int i=0;i<kaonsIntegral.size();++i){
        kaonYield->SetPoint(i,i+1,kaonsIntegral[i]);
        kaonYieldS->SetPoint(i,s[i],kaonsIntegral[i]);
    }
    kaonYieldS->GetXaxis()->SetName("s [m]");
    kaonYield->GetYaxis()->SetName("Count");
    kaonYieldS->GetYaxis()->SetName("Count");
    auto axk = kaonYield->GetXaxis();
    axk->SetNdivisions(kaonsIntegral.size());
    for(int i=0;i<kaonsIntegral.size();++i){
        axk->ChangeLabelByValue(i+1, -1,-100,-1,1,-1,treeName[i].c_str());
    }
    outFileExtra->WriteObject(pionYield,"pionYield");
    outFileExtra->WriteObject(kaonYield,"kaonYield");
    outFileExtra->WriteObject(pionYieldS,"pionYieldS");
    outFileExtra->WriteObject(kaonYieldS,"kaonYieldS");

    std::cout<<"File count: "<<count<<std::endl;

}