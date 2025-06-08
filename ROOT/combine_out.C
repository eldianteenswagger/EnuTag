#include <fstream>
void combine_out(){

    int nJobs = 2;
    int fileCount;
    double Ebin = 100.;

    ofstream txtFile;
    txtFile.open("outMerge/verbose_out.txt");

    std::vector<std::string> treeName = {"USVD","Middle1","Middle2","Middle3","Middle4","Middle5","Det1","Det2","Det3","Det4","Det5","DSVD1","DSVD2","FVD","Neutrinos","Extra"};
    std::vector<bool> treeVD = {true,true,true,true,true,true,false,false,false,false,false,true,true,true,false};

    std::vector<double> s={1.5, 6.7109660, 9.4318825, 11.312752, 12.990252, 15.139252, 17.070752, 17.320752, 18.820752, 19.096414, 23.785400, 26.235400, 66.235400};

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

    std::string outFileName = "";  
    std::string inFileName = "";

    std::map<std::string, TH1D*> pionsHist;
    std::map<std::string, TH1D*> kaonsHist;
    std::map<std::string, TH1D*> pionsSpectrum;
    std::map<std::string, TH1D*> kaonsSpectrum;
    std::map<std::string, TH1D*> pionsHist_lim;
    std::map<std::string, TH1D*> kaonsHist_lim;
    std::map<std::string, TH1D*> pionsSpectrum_lim;
    std::map<std::string, TH1D*> kaonsSpectrum_lim;

    TH1D* p_before = nullptr;
    TH1D* p_after = nullptr;

    //TFile* pdfOut = new TFile("outMerge/StraordinariDiAprile.pdf","RECREATE");
    std::string pdfOut = "outMerge/StraordinariDiAprile.pdf";
    TCanvas* cOpen = new TCanvas();
    cOpen->Print((pdfOut+"[").c_str());
    
    for(int d = 0; d<treeName.size(); ++d){
        fileCount = 0;
        //defining out file
        outFileName = "outMerge/"+treeName[d]+"_merge.root";
        TFile* outFile = new TFile(outFileName.data(), "RECREATE");
        
        if(treeName[d]=="Neutrinos"){

            TH1D* hnux_TOT = nullptr;
            TH1D* hnuy_TOT = nullptr;
            TH1D* hnuz_TOT = nullptr;

            TH2D* hnuxy_TOT = nullptr;
            TH2D* hnuzy_TOT = nullptr;
            TH2D* hnuxz_TOT = nullptr;

            TH2D* hnui_TOT = nullptr;

            //take entries
            for(int j = 0; j<nJobs; ++j){
                inFileName = "./OUT/"+treeName[d]+"_"+j+".root";
                TFile *file = TFile::Open(inFileName.data());
                if (!file || file->IsZombie()){continue;}
                fileCount++;

                //sum 1dhists
                TH1D* hnux_local = (TH1D*)file->Get("hnux");
                if(!hnux_TOT){
                    hnux_TOT = (TH1D*)hnux_local->Clone("hnux_TOT");
                    hnux_TOT->SetDirectory(0);
                    hnux_TOT->Reset();
                }
                hnux_TOT->Add(hnux_local);
                TH1D* hnuy_local = (TH1D*)file->Get("hnuy");
                if(!hnuy_TOT){
                    hnuy_TOT = (TH1D*)hnuy_local->Clone("hnuy_TOT");
                    hnuy_TOT->SetDirectory(0);
                    hnuy_TOT->Reset();
                }
                hnuy_TOT->Add(hnuy_local);
                TH1D* hnuz_local = (TH1D*)file->Get("hnuz");
                if(!hnuz_TOT){
                    hnuz_TOT = (TH1D*)hnuz_local->Clone("hnuz_TOT");
                    hnuz_TOT->SetDirectory(0);
                    hnuz_TOT->Reset();
                }
                hnuz_TOT->Add(hnuz_local);

                //sum 2dhists
                TH2D* hnuxy_local = (TH2D*)file->Get("hnuxy");
                if(!hnuxy_TOT){
                    hnuxy_TOT = (TH2D*)hnuxy_local->Clone("hnuxy_TOT");
                    hnuxy_TOT->SetDirectory(0);
                    hnuxy_TOT->Reset();
                }
                hnuxy_TOT->Add(hnuxy_local);
                TH2D* hnuzy_local = (TH2D*)file->Get("hnuzy");
                if(!hnuzy_TOT){
                    hnuzy_TOT = (TH2D*)hnuzy_local->Clone("hnuzy_TOT");
                    hnuzy_TOT->SetDirectory(0);
                    hnuzy_TOT->Reset();
                }
                hnuzy_TOT->Add(hnuzy_local);
                TH2D* hnuxz_local = (TH2D*)file->Get("hnuxz");
                if(!hnuxz_TOT){
                    hnuxz_TOT = (TH2D*)hnuxz_local->Clone("hnuxz_TOT");
                    hnuxz_TOT->SetDirectory(0);
                    hnuxz_TOT->Reset();
                }
                hnuxz_TOT->Add(hnuxz_local);
                TH2D* hnui_local = (TH2D*)file->Get("hnui");
                if(!hnui_TOT){
                    hnui_TOT = (TH2D*)hnui_local->Clone("hnui_TOT");
                    hnui_TOT->SetDirectory(0);
                    hnui_TOT->Reset();
                }
                hnui_TOT->Add(hnui_local);
                file->Close();
                //if(j%100==0)std::cout<<"Neutrinos: "<<j/100<<" %"<<endl;
            }

            //out
            TCanvas* cNu = new TCanvas("nu","nu",1920,1200);
            hnux_TOT->Scale(1./fileCount);
            hnux_TOT->SetStats(1);
            hnux_TOT->SetTitle("Neutrino x");
            hnuy_TOT->Scale(1./fileCount);
            hnuy_TOT->SetStats(1);
            hnuy_TOT->SetTitle("Neutrino y");
            hnuz_TOT->Scale(1./fileCount);
            hnuz_TOT->SetStats(1);
            hnuz_TOT->SetTitle("Neutrino z");
            hnuxy_TOT->Scale(1./fileCount);
            hnuxy_TOT->SetStats(1);
            hnuxy_TOT->SetTitle("Neutrino production, xy");
            hnuxy_TOT->Draw();
            cNu->Update();
            cNu->Print(pdfOut.c_str());
            hnuzy_TOT->Scale(1./fileCount);
            hnuzy_TOT->SetStats(1);
            hnuzy_TOT->SetTitle("Neutrino production, zy");
            hnuzy_TOT->Draw();
            cNu->Update();
            cNu->Print(pdfOut.c_str());
            hnuxz_TOT->Scale(1./fileCount);
            hnuxz_TOT->SetStats(1);
            hnuxz_TOT->SetTitle("Neutrino production, xz");
            hnuxz_TOT->Draw();
            cNu->Update();
            cNu->Print(pdfOut.c_str());
            hnui_TOT->SetStats(0);
            hnui_TOT->SetTitle("Neutrino impacts on FVD");
            hnui_TOT->Draw();
            cNu->Update();
            cNu->Print(pdfOut.c_str());

            outFile->WriteObject(hnux_TOT,"hnux");
            outFile->WriteObject(hnuy_TOT,"hnuy");
            outFile->WriteObject(hnuz_TOT,"hnuz");
            outFile->WriteObject(hnuxy_TOT,"hnuxy");
            outFile->WriteObject(hnuzy_TOT,"hnuzy");
            outFile->WriteObject(hnuxz_TOT,"hnuxz");
            outFile->WriteObject(hnui_TOT,"hnui");


            txtFile<<treeName[d]<<": "<<fileCount<<"\n";

            outFile->Close();


        }else if(treeName[d]=="Extra"){

            std::vector<double> pionsInts(s.size(),0);
            std::vector<double> kaonsInts(s.size(),0);
            std::vector<double> x(s.size(),0);

            for(int j = 0; j<nJobs; ++j){
                inFileName = "./OUT/"+treeName[d]+"_"+j+".root";
                TFile *file = TFile::Open(inFileName.data());
                if (!file || file->IsZombie()){continue;}
                TTree *tree = (TTree*)file->Get("pkIntegrals");
                if (!tree) {continue;}
                fileCount++;
                double intp, intk;
                int id;
                tree->SetBranchAddress("intp", &intp);
                tree->SetBranchAddress("intk", &intk);
                tree->SetBranchAddress("id", &id);
                int nEntries = tree->GetEntries();
                for (int i = 0; i < nEntries; ++i) {
                    tree->GetEntry(i);
                    pionsInts[i]+=intp;
                    kaonsInts[i]+=intk;
                    if(j==0){x[i]=i+1;}
                }
            }
            for(int i=0;i<pionsInts.size();++i){
                pionsInts[i]/=fileCount;
                kaonsInts[i]/=fileCount;
                txtFile<<treeName[i]<<": pi+ "<<pionsInts[i]<<" k+ "<<kaonsInts[i]<<"\n";
            }

            TGraph* pGraph = new TGraph(pionsInts.size(), &x[0], &pionsInts[0]);
            TGraph* kGraph = new TGraph(pionsInts.size(), &x[0], &kaonsInts[0]);
            TGraph* pGraphS = new TGraph(pionsInts.size(), &s[0], &pionsInts[0]);
            TGraph* kGraphS = new TGraph(pionsInts.size(), &s[0], &kaonsInts[0]);

            TCanvas *c1 = new TCanvas("c1", "Pion/Kaon yields", 1920, 1200);
            pGraph->SetStats(0);
            kGraph->SetStats(0);
            pGraph->SetMarkerStyle(21);
            pGraph->SetLineStyle(0);
            pGraph->SetMarkerColor(colorMap["pi+"]);
            kGraph->SetMarkerStyle(21);
            kGraph->SetLineStyle(0);
            kGraph->SetMarkerColor(colorMap["pi-"]);
            pGraph->SetTitle("Pion/Kaon yields");
            c1->SetLogy();
            pGraph->GetYaxis()->SetRangeUser(1e-5,10.);
            kGraph->GetYaxis()->SetRangeUser(1e-5,10.);
            pGraph->GetYaxis()->SetTitle("Yield/POT");
            c1->SetGrid();
            pGraph->Draw("AP");
            kGraph->Draw("P SAME");
            c1->Print(pdfOut.c_str());
            outFile->WriteObject(c1,"pk");
            TCanvas *c2 = new TCanvas("c2", "Pion/Kaon yields 2", 1920, 1200);
            pGraphS->SetStats(0);
            pGraphS->SetMarkerStyle(21);
            pGraphS->SetLineStyle(0);
            pGraphS->SetMarkerColor(colorMap["pi+"]);
            kGraphS->SetStats(0);
            kGraphS->SetMarkerStyle(21);
            kGraphS->SetLineStyle(0);
            kGraphS->SetMarkerColor(colorMap["pi-"]);
            pGraphS->SetTitle("Pion/Kaon yields (S)");
            c2->SetLogy();
            pGraphS->GetYaxis()->SetRangeUser(1e-5,10.);
            kGraphS->GetYaxis()->SetRangeUser(1e-5,10.);
            pGraphS->GetXaxis()->SetTitle("S [m]");
            pGraphS->GetYaxis()->SetTitle("Yield/POT");
            c2->SetGrid();
            pGraphS->Draw("AP");
            kGraphS->Draw("P SAME");
            c2->Print(pdfOut.c_str());
            outFile->WriteObject(c2,"pkS");

            txtFile<<treeName[d]<<": "<<fileCount<<"\n";

            outFile->Close();

        }else{

            TH1D* hE_TOT = nullptr;
            TH1D* hx_TOT = nullptr;
            TH1D* hy_TOT = nullptr;

            TH1D* habsx_TOT = nullptr;
            TH1D* habsy_TOT = nullptr;
            TH1D* habsz_TOT = nullptr;

            TH1D* hpx_TOT = nullptr;
            TH1D* hpy_TOT = nullptr;
            TH1D* hpz_TOT = nullptr;
            TH1D* ht_TOT = nullptr;
            TH1D* hdE_TOT = nullptr;

            //neutrino_histograms
            TH1D* momHist_TOT = nullptr;
            TH2D* momangleHistX_TOT = nullptr;
            TH2D* momangleHistY_TOT = nullptr;
            TH2D* posHist_TOT = nullptr;

            TH1D* pseudoRapHist_TOT = nullptr;
            TH2D* rapidAngleHist_TOT = nullptr;
            TH2D* rapidEnengyHist_TOT = nullptr;
            TH2D* rapidTimeHist_TOT = nullptr;
            TH2D* energyTimeHist_TOT = nullptr;

            std::map<std::string, TH1D*> histMapE_TOT;
            std::map<std::string, TH1D*> histMapEE_TOT;
            std::map<std::string, TH1D*> histMapE_lim_TOT;
            std::map<std::string, TH1D*> histMapEE_lim_TOT;

            for(auto& pt : colorMap){
               histMapE_TOT.insert(std::make_pair(pt.first,nullptr));
               histMapEE_TOT.insert(std::make_pair(pt.first,nullptr));
               histMapE_lim_TOT.insert(std::make_pair(pt.first,nullptr));
               histMapEE_lim_TOT.insert(std::make_pair(pt.first,nullptr));
            }

            for(int j = 0; j<nJobs; ++j){
                inFileName = "./OUT/"+treeName[d]+"_"+j+".root";
                TFile *file = TFile::Open(inFileName.data());
                if (!file || file->IsZombie()){continue;}
                fileCount++;
            
                //sum hists
                TH1D* hE_local = (TH1D*)file->Get("hE");
                if(!hE_TOT){
                    hE_TOT = (TH1D*)hE_local->Clone("hE_TOT");
                    hE_TOT->SetDirectory(0);
                    hE_TOT->Reset();
                }
                hE_TOT->Add(hE_local);

                TH1D* hx_local = (TH1D*)file->Get("hx");
                if(!hx_TOT){
                    hx_TOT = (TH1D*)hx_local->Clone("hx_TOT");
                    hx_TOT->SetDirectory(0);
                    hx_TOT->Reset();
                }
                hx_TOT->Add(hx_local);

                TH1D* hy_local = (TH1D*)file->Get("hy");
                if(!hy_TOT){
                    hy_TOT = (TH1D*)hy_local->Clone("hy_TOT");
                    hy_TOT->SetDirectory(0);
                    hy_TOT->Reset();
                }
                hy_TOT->Add(hy_local);

                TH1D* habsx_local = (TH1D*)file->Get("habsx");
                if(!habsx_TOT){
                    habsx_TOT = (TH1D*)habsx_local->Clone("habsx_TOT");
                    habsx_TOT->SetDirectory(0);
                    habsx_TOT->Reset();
                }
                habsx_TOT->Add(habsx_local);

                TH1D* habsy_local = (TH1D*)file->Get("habsy");
                if(!habsy_TOT){
                    habsy_TOT = (TH1D*)habsy_local->Clone("habsy_TOT");
                    habsy_TOT->SetDirectory(0);
                    habsy_TOT->Reset();
                }
                habsy_TOT->Add(habsy_local);

                TH1D* habsz_local = (TH1D*)file->Get("habsz");
                if(!habsz_TOT){
                    habsz_TOT = (TH1D*)habsz_local->Clone("habsz_TOT");
                    habsz_TOT->SetDirectory(0);
                    habsz_TOT->Reset();
                }
                habsz_TOT->Add(habsz_local);

                TH1D* hpx_local = (TH1D*)file->Get("hpx");
                if(!hpx_TOT){
                    hpx_TOT = (TH1D*)hpx_local->Clone("hpx_TOT");
                    hpx_TOT->SetDirectory(0);
                    hpx_TOT->Reset();
                }
                hpx_TOT->Add(hpx_local);

                TH1D* hpy_local = (TH1D*)file->Get("hpy");
                if(!hpy_TOT){
                    hpy_TOT = (TH1D*)hpy_local->Clone("hpy_TOT");
                    hpy_TOT->SetDirectory(0);
                    hpy_TOT->Reset();
                }
                hpy_TOT->Add(hpy_local);

                TH1D* hpz_local = (TH1D*)file->Get("hpz");
                if(!hpz_TOT){
                    hpz_TOT = (TH1D*)hpz_local->Clone("hpz_TOT");
                    hpz_TOT->SetDirectory(0);
                    hpz_TOT->Reset();
                }
                hpz_TOT->Add(hpz_local);

                TH1D* ht_local = (TH1D*)file->Get("ht");
                if(!ht_TOT){
                    ht_TOT = (TH1D*)ht_local->Clone("ht_TOT");
                    ht_TOT->SetDirectory(0);
                    ht_TOT->Reset();
                }
                ht_TOT->Add(ht_local);

                TH1D* hdE_local = (TH1D*)file->Get("hdE");
                if(hdE_local){
                    if(!hdE_TOT){
                        hdE_TOT = (TH1D*)hdE_local->Clone("hdE_TOT");
                        hdE_TOT->SetDirectory(0);
                        hdE_TOT->Reset();
                    }
                    hdE_TOT->Add(hdE_local);
                }

                TH1D* momHist_local = (TH1D*)file->Get("momHist");
                if(!momHist_TOT){
                    momHist_TOT = (TH1D*)momHist_local->Clone("momHist_TOT");
                    momHist_TOT->SetDirectory(0);
                    momHist_TOT->Reset();
                }
                momHist_TOT->Add(momHist_local);

                TH2D* momangleHistX_local = (TH2D*)file->Get("momangleHistX");
                if(!momangleHistX_TOT){
                    momangleHistX_TOT = (TH2D*)momangleHistX_local->Clone("momangleHistX_TOT");
                    momangleHistX_TOT->SetDirectory(0);
                    momangleHistX_TOT->Reset();
                }
                momangleHistX_TOT->Add(momangleHistX_local);

                TH2D* momangleHistY_local = (TH2D*)file->Get("momangleHistY");
                if(!momangleHistY_TOT){
                    momangleHistY_TOT = (TH2D*)momangleHistY_local->Clone("momangleHistY_TOT");
                    momangleHistY_TOT->SetDirectory(0);
                    momangleHistY_TOT->Reset();
                }
                momangleHistY_TOT->Add(momangleHistY_local);

                TH2D* posHist_local = (TH2D*)file->Get("posHist");
                if(!posHist_TOT){
                    posHist_TOT = (TH2D*)posHist_local->Clone("posHist_TOT");
                    posHist_TOT->SetDirectory(0);
                    posHist_TOT->Reset();
                }
                posHist_TOT->Add(posHist_local);

                TH1D* pseudoRapHist_local = (TH1D*)file->Get("pseudoRapHist");
                if(pseudoRapHist_local){
                    if(!pseudoRapHist_TOT){
                        pseudoRapHist_TOT = (TH1D*)pseudoRapHist_local->Clone("pseudoRapHist_TOT");
                        pseudoRapHist_TOT->SetDirectory(0);
                        pseudoRapHist_TOT->Reset();
                    }
                    pseudoRapHist_TOT->Add(pseudoRapHist_local);
                }

                TH2D* rapidAngleHist_local = (TH2D*)file->Get("rapidAngleHist");
                if(rapidAngleHist_local){
                    if(!rapidAngleHist_TOT){
                        rapidAngleHist_TOT = (TH2D*)rapidAngleHist_local->Clone("rapidAngleHist_TOT");
                        rapidAngleHist_TOT->SetDirectory(0);
                        rapidAngleHist_TOT->Reset();
                    }
                    rapidAngleHist_TOT->Add(rapidAngleHist_local);
                }

                TH2D* rapidEnengyHist_local = (TH2D*)file->Get("rapidEnengyHist");
                if(rapidEnengyHist_local){
                    if(!rapidEnengyHist_TOT){
                        rapidEnengyHist_TOT = (TH2D*)rapidEnengyHist_local->Clone("rapidEnengyHist_TOT");
                        rapidEnengyHist_TOT->SetDirectory(0);
                        rapidEnengyHist_TOT->Reset();
                    }
                    rapidEnengyHist_TOT->Add(rapidEnengyHist_local);
                }

                TH2D* rapidTimeHist_local = (TH2D*)file->Get("rapidTimeHist");
                if(rapidTimeHist_local){
                    if(!rapidTimeHist_TOT){
                        rapidTimeHist_TOT = (TH2D*)rapidTimeHist_local->Clone("rapidTimeHist_TOT");
                        rapidTimeHist_TOT->SetDirectory(0);
                        rapidTimeHist_TOT->Reset();
                    }
                    rapidTimeHist_TOT->Add(rapidTimeHist_local);
                }

                TH2D* energyTimeHist_local = (TH2D*)file->Get("energyTimeHist");
                if(energyTimeHist_local){
                    if(!energyTimeHist_TOT){
                        energyTimeHist_TOT = (TH2D*)energyTimeHist_local->Clone("energyTimeHist_TOT");
                        energyTimeHist_TOT->SetDirectory(0);
                        energyTimeHist_TOT->Reset();
                    }
                    energyTimeHist_TOT->Add(energyTimeHist_local);
                }
                //multi hists

                for(auto& entry : histMapE_TOT){
                    TString hName("HISTS_"+entry.first);
                    TH1D* h = (TH1D*)file->Get(hName);
                    if(h){
                        if(!entry.second){
                            entry.second = (TH1D*)h->Clone(entry.first.c_str());
                            entry.second->SetDirectory(0);
                            entry.second->Reset();
                        }
                        entry.second->Add(h);
                    }
                }
                for(auto& entry : histMapE_lim_TOT){
                    TString hName("HISTS_LIM_"+entry.first);
                    TH1D* h = (TH1D*)file->Get(hName);
                    if(h){
                        if(!entry.second){
                            entry.second = (TH1D*)h->Clone(entry.first.c_str());
                            entry.second->SetDirectory(0);
                            entry.second->Reset();
                        }
                        entry.second->Add(h);
                    }
                }
                for(auto& entry : histMapEE_TOT){
                    TString hName("SPECTRA_"+entry.first);
                    TH1D* h = (TH1D*)file->Get(hName);
                    if(h){
                        if(!entry.second){
                            entry.second = (TH1D*)h->Clone(entry.first.c_str());
                            entry.second->SetDirectory(0);
                            entry.second->Reset();
                        }
                        entry.second->Add(h);
                    }
                }
                for(auto& entry : histMapEE_lim_TOT){
                    TString hName("SPECTRA_LIM_"+entry.first);
                    TH1D* h = (TH1D*)file->Get(hName);
                    if(h){
                        if(!entry.second){
                            entry.second = (TH1D*)h->Clone(entry.first.c_str());
                            entry.second->SetDirectory(0);
                            entry.second->Reset();
                        }
                        entry.second->Add(h);
                    }
                }

                //if(j%100==0)std::cout<<treeName[d]<<": "<<j/100<<" %"<<endl;
            
            }
            
            //out
            hE_TOT->Scale(1./fileCount);
            hE_TOT->SetStats(1);
            hE_TOT->SetTitle("Energy");
            outFile->WriteObject(hE_TOT,"hE");

            hx_TOT->Scale(1./fileCount);
            hx_TOT->SetStats(1);
            hx_TOT->SetTitle("X on detector");
            outFile->WriteObject(hx_TOT,"hx");

            hy_TOT->Scale(1./fileCount);
            hy_TOT->SetStats(1);
            hy_TOT->SetTitle("Y on detector");
            outFile->WriteObject(hy_TOT,"hy");

            habsx_TOT->Scale(1./fileCount);
            habsx_TOT->SetStats(1);
            habsx_TOT->SetTitle("AbsX");
            outFile->WriteObject(habsx_TOT,"habsx");

            habsy_TOT->Scale(1./fileCount);
            habsy_TOT->SetStats(1);
            habsy_TOT->SetTitle("AbsY");
            outFile->WriteObject(habsy_TOT,"habsy");

            habsz_TOT->Scale(1./fileCount);
            habsz_TOT->SetStats(1);
            habsz_TOT->SetTitle("AbsZ");
            outFile->WriteObject(habsz_TOT,"habsz");

            hpx_TOT->Scale(1./fileCount);
            hpx_TOT->SetStats(1);
            hpx_TOT->SetTitle("pX");
            outFile->WriteObject(hpx_TOT,"hpx");

            hpy_TOT->Scale(1./fileCount);
            hpy_TOT->SetStats(1);
            hpy_TOT->SetTitle("pY");
            outFile->WriteObject(hpy_TOT,"hpy");

            hpz_TOT->Scale(1./fileCount);
            hpz_TOT->SetStats(1);
            hpz_TOT->SetTitle("pZ");
            outFile->WriteObject(hpz_TOT,"hpz");

            ht_TOT->Scale(1./fileCount);
            ht_TOT->SetStats(1);
            ht_TOT->SetTitle("Time");
            outFile->WriteObject(ht_TOT,"ht");

            if(hdE_TOT){
                hdE_TOT->Scale(1./fileCount);
                hdE_TOT->SetStats(1);
                hdE_TOT->SetTitle("dE");
                outFile->WriteObject(hdE_TOT,"hdE");
            }
            
            momHist_TOT->Scale(1./fileCount);
            momHist_TOT->SetStats(1);
            momHist_TOT->SetTitle("Momentum");
            outFile->WriteObject(momHist_TOT,"momHist");

            momangleHistX_TOT->Scale(1./fileCount);
            momangleHistX_TOT->SetStats(1);
            momangleHistX_TOT->SetTitle("Mom. vs X");
            outFile->WriteObject(momangleHistX_TOT,"momangleHistX_TOT");

            momangleHistY_TOT->Scale(1./fileCount);
            momangleHistY_TOT->SetStats(1);
            momangleHistY_TOT->SetTitle("Mom. vs Y");
            outFile->WriteObject(momangleHistY_TOT,"momangleHistY_TOT");

            posHist_TOT->Scale(1./fileCount);
            posHist_TOT->SetStats(1);
            posHist_TOT->SetTitle("Position");
            outFile->WriteObject(posHist_TOT,"posHist");

            if(pseudoRapHist_TOT){
                pseudoRapHist_TOT->Scale(1./fileCount);
                pseudoRapHist_TOT->SetStats(1);
                pseudoRapHist_TOT->SetTitle("Pseudorapidity");
                outFile->WriteObject(pseudoRapHist_TOT,"pseudoRapHist");
            }

            if(rapidAngleHist_TOT){
                rapidAngleHist_TOT->Scale(1./fileCount);
                rapidAngleHist_TOT->SetStats(1);
                rapidAngleHist_TOT->SetTitle("Pseudorapidity vs Angle");
                outFile->WriteObject(rapidAngleHist_TOT,"rapidAngleHist");
            }

            if(rapidEnengyHist_TOT){
                rapidEnengyHist_TOT->Scale(1./fileCount);
                rapidEnengyHist_TOT->SetStats(1);
                rapidEnengyHist_TOT->SetTitle("Pseudorapidity vs Energy");
                outFile->WriteObject(rapidEnengyHist_TOT,"rapidEnengyHist");
            }
            
            if(rapidTimeHist_TOT){
                rapidTimeHist_TOT->Scale(1./fileCount);
                rapidTimeHist_TOT->SetStats(1);
                rapidTimeHist_TOT->SetTitle("Pseudorapidity vs Time");
                outFile->WriteObject(rapidTimeHist_TOT,"rapidTimeHist");
            }

            if(energyTimeHist_TOT){
                energyTimeHist_TOT->Scale(1./fileCount);
                energyTimeHist_TOT->SetStats(1);
                energyTimeHist_TOT->SetTitle("Time vs Energy");
                outFile->WriteObject(energyTimeHist_TOT,"energyTimeHist");
            }

            //multi_hist out
            TCanvas* c = new TCanvas("Canvas","Canvas",1920,1200);
            c->SetLogy();

            TLegend *legend = new TLegend(0.9, 0.9, 0.99, 0.1);
            int aa = 1;
            for (auto &entry : histMapE_TOT) {
                if(!entry.second){continue;}
                entry.second->Scale(1./fileCount);
                entry.second->GetYaxis()->SetRangeUser(1e-6, 100.);
                entry.second->SetTitle(("Particle count ["+treeName[d]+"]").c_str());
                if(entry.first=="pi+"){pionsHist.insert(std::make_pair(treeName[d],entry.second));}
                if(entry.first=="kaon+"){kaonsHist.insert(std::make_pair(treeName[d],entry.second));}
                if(entry.first=="e+"){
                    if(treeName[d]=="Middle4"){p_before = (TH1D*)entry.second->Clone("pi before");}
                    if(treeName[d]=="Middle5"){p_after = (TH1D*)entry.second->Clone("pi after");}
                }

                entry.second->Draw((aa==1 ? "HIST" : "HIST SAME"));
                legend->AddEntry(entry.second, entry.first.c_str(), "l");
                ++aa;
            }
            legend->Draw();
            c->Update();
            c->Print(pdfOut.c_str());
            outFile->WriteObject(c,"histMapE_TOT");
            c->Clear();

            legend = new TLegend(0.9, 0.9, 0.99, 0.1);
            aa = 1;
            for (auto &entry : histMapEE_TOT) {
                if(!entry.second){continue;}
                entry.second->Scale(1./fileCount);
                entry.second->SetTitle(("Particle flux ["+treeName[d]+"]").c_str());
                entry.second->GetYaxis()->SetRangeUser(1e-4, 10000.);
                if(entry.first=="pi+"){pionsSpectrum.insert(std::make_pair(treeName[d],entry.second));}
                if(entry.first=="kaon+"){kaonsSpectrum.insert(std::make_pair(treeName[d],entry.second));}
                entry.second->Draw((aa==1 ? "HIST" : "HIST SAME"));
                legend->AddEntry(entry.second, entry.first.c_str(), "l");
                ++aa;
            }
            legend->Draw();
            c->Update();
            c->Print(pdfOut.c_str());
            outFile->WriteObject(c,"histMapEE_TOT");
            c->Clear();

            legend = new TLegend(0.9, 0.9, 0.99, 0.1);
            aa = 1;
            for (auto &entry : histMapE_lim_TOT) {
                if(!entry.second){continue;}
                entry.second->Scale(1./fileCount);
                entry.second->GetYaxis()->SetRangeUser(1e-6, 100.);
                entry.second->SetTitle(("Particle count ["+treeName[d]+" lim]").c_str());
                if(entry.first=="pi+"){pionsHist_lim.insert(std::make_pair(treeName[d],entry.second));}
                if(entry.first=="kaon+"){kaonsHist_lim.insert(std::make_pair(treeName[d],entry.second));}
                entry.second->Draw((aa==1 ? "HIST" : "HIST SAME"));
                legend->AddEntry(entry.second, entry.first.c_str(), "l");
                ++aa;
            }
            legend->Draw();
            c->Update();
            c->Print(pdfOut.c_str());
            outFile->WriteObject(c,"histMapElim_TOT");
            c->Clear();

            legend = new TLegend(0.9, 0.9, 0.99, 0.1);
            aa = 1;
            for (auto &entry : histMapEE_lim_TOT) {
                if(!entry.second){continue;}
                entry.second->Scale(1./fileCount);
                entry.second->GetYaxis()->SetRangeUser(1e-4, 10000.);
                entry.second->SetTitle(("Particle flux ["+treeName[d]+" lim]").c_str());
                if(entry.first=="pi+"){pionsSpectrum_lim.insert(std::make_pair(treeName[d],entry.second));}
                if(entry.first=="kaon+"){kaonsSpectrum_lim.insert(std::make_pair(treeName[d],entry.second));}
                entry.second->Draw((aa==1 ? "HIST" : "HIST SAME"));
                legend->AddEntry(entry.second, entry.first.c_str(), "l");
                ++aa;
            }
            legend->Draw();
            c->Update();
            c->Print(pdfOut.c_str());
            outFile->WriteObject(c,"histMapEElim_TOT");
            c->Clear();

            txtFile<<treeName[d]<<": "<<fileCount<<"\n";

            delete hE_TOT;
            delete hx_TOT;
            delete hy_TOT;
            delete habsx_TOT;
            delete habsy_TOT;
            delete habsz_TOT;
            delete hpx_TOT;
            delete hpy_TOT;
            delete hpz_TOT;
            delete ht_TOT;
            delete hdE_TOT;
            delete momHist_TOT;
            delete momangleHistX_TOT;
            delete momangleHistY_TOT;
            delete posHist_TOT;
            delete pseudoRapHist_TOT;
            delete rapidAngleHist_TOT;
            delete rapidEnengyHist_TOT;
            delete rapidTimeHist_TOT;
            delete energyTimeHist_TOT;

            outFile->Close();

        }
    }

    std::string finalOutName = "outMerge/Spectra_merge.root";
    TFile *finalOut = new TFile(finalOutName.data(),"RECREATE");
    TCanvas *clog = new TCanvas("CanvasLog","CanvasLog",1920,1200);
    clog->SetLogy();

    //pion stuff
    int colorP = 0;
    TLegend *legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    clog->Clear();
    gStyle->SetPalette(kSolar);
    for (int i=0;i<pionsHist.size()-1;i++) {
        pionsHist[treeName[i]]->Draw((colorP == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        pionsHist[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){pionsHist[treeName[i]]->SetLineColor(kYellow);}
        pionsHist[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        pionsHist[treeName[i]]->GetYaxis()->SetTitle("Count");
        pionsHist[treeName[i]]->SetTitle("Pions count");
        legend->AddEntry(pionsHist[treeName[i]], treeName[i].c_str(), "f");
        clog->Update();
        colorP++;
    }
    legend->Draw();
    clog->Update();
    finalOut->WriteObject(clog,"pions");
    clog->Print(pdfOut.c_str());
    clog->Clear();
    cOpen->Update();

    colorP = 0;
    legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    clog->Update();
    gStyle->SetPalette(kSolar);
    for (int i=0;i<pionsSpectrum.size()-1;i++) {
        pionsSpectrum[treeName[i]]->Draw((colorP == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        pionsSpectrum[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){pionsSpectrum[treeName[i]]->SetLineColor(kYellow);}
        pionsSpectrum[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        pionsSpectrum[treeName[i]]->GetYaxis()->SetTitle("Count");
        pionsSpectrum[treeName[i]]->SetTitle("Pions flux");
        legend->AddEntry(pionsSpectrum[treeName[i]], treeName[i].c_str(), "f");
        clog->Update();
        colorP++;
    }
    legend->Draw();
    clog->Update();
    finalOut->WriteObject(clog,"pions_flux");
    clog->Print(pdfOut.c_str());
    clog->Clear();
    cOpen->Update();

    colorP = 0;
    legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    clog->Update();
    gStyle->SetPalette(kSolar);
    for (int i=0;i<pionsHist_lim.size()-1;i++) {
        pionsHist_lim[treeName[i]]->Draw((colorP == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        pionsHist_lim[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){pionsHist_lim[treeName[i]]->SetLineColor(kYellow);}
        pionsHist_lim[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        pionsHist_lim[treeName[i]]->GetYaxis()->SetTitle("Count");
        pionsHist_lim[treeName[i]]->SetTitle("Pions count [lim]");
        legend->AddEntry(pionsHist_lim[treeName[i]], treeName[i].c_str(), "f");
        clog->Update();
        colorP++;
    }
    legend->Draw();
    clog->Update();
    finalOut->WriteObject(clog,"pions_lim");
    clog->Print(pdfOut.c_str());
    clog->Clear();
    cOpen->Update();

    colorP = 0;
    legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    clog->Update();
    gStyle->SetPalette(kSolar);
    for (int i=0;i<pionsSpectrum_lim.size()-1;i++) {
        pionsSpectrum_lim[treeName[i]]->Draw((colorP == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        pionsSpectrum_lim[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){pionsSpectrum_lim[treeName[i]]->SetLineColor(kYellow);}
        pionsSpectrum_lim[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        pionsSpectrum_lim[treeName[i]]->GetYaxis()->SetTitle("Count");
        pionsSpectrum_lim[treeName[i]]->SetTitle("Pions flux [lim]");
        legend->AddEntry(pionsSpectrum_lim[treeName[i]], treeName[i].c_str(), "f");
        clog->Update();
        colorP++;
    }
    legend->Draw();
    clog->Update();
    finalOut->WriteObject(clog,"pions_flux_lim");
    clog->Print(pdfOut.c_str());
    clog->Clear();
    cOpen->Update();

    //kaon stuff
    TCanvas *clog2 = new TCanvas("CanvasLog2","CanvasLog2",1920,1200);
    clog2->SetLogy();

    int colorK = 0;
    legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    clog2->Clear();
    gStyle->SetPalette(kRust);
    for (int i=0;i<kaonsHist.size()-1;i++) {
        kaonsHist[treeName[i]]->Draw((colorP == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        kaonsHist[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){kaonsHist[treeName[i]]->SetLineColor(kYellow);}
        kaonsHist[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        kaonsHist[treeName[i]]->GetYaxis()->SetTitle("Count");
        kaonsHist[treeName[i]]->SetTitle("Kaons count");
        legend->AddEntry(kaonsHist[treeName[i]], treeName[i].c_str(), "f");
        clog2->Update();
        colorK++;
    }
    legend->Draw();
    clog2->Update();
    finalOut->WriteObject(clog2,"kaons");
    clog2->Print(pdfOut.c_str());
    clog2->Clear();
    cOpen->Update();

    colorK = 0;
    clog2 = new TCanvas("CanvasLog2","CanvasLog2",1920,1200);
    clog2->SetLogy();
    legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    clog2->Update();
    gStyle->SetPalette(kRust);
    for (int i=0;i<kaonsSpectrum.size()-1;i++) {
        kaonsSpectrum[treeName[i]]->Draw((colorP == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        kaonsSpectrum[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){kaonsSpectrum[treeName[i]]->SetLineColor(kYellow);}
        kaonsSpectrum[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        kaonsSpectrum[treeName[i]]->GetYaxis()->SetTitle("Count");
        kaonsSpectrum[treeName[i]]->SetTitle("Kaons flux");
        legend->AddEntry(kaonsSpectrum[treeName[i]], treeName[i].c_str(), "f");
        clog2->Update();
        colorK++;
    }
    legend->Draw();
    clog2->Update();
    finalOut->WriteObject(clog2,"kaons_flux");
    clog2->Print(pdfOut.c_str());
    clog2->Clear();
    cOpen->Update();

    colorK = 0;
    clog2 = new TCanvas("CanvasLog2","CanvasLog2",1920,1200);
    clog2->SetLogy();
    legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    clog2->Update();
    gStyle->SetPalette(kRust);
    for (int i=0;i<kaonsHist_lim.size()-1;i++) {
        kaonsHist_lim[treeName[i]]->Draw((colorP == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        kaonsHist_lim[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){kaonsHist_lim[treeName[i]]->SetLineColor(kYellow);}
        kaonsHist_lim[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        kaonsHist_lim[treeName[i]]->GetYaxis()->SetTitle("Count");
        kaonsHist_lim[treeName[i]]->SetTitle("Kaons count [lim]");
        legend->AddEntry(kaonsHist_lim[treeName[i]], treeName[i].c_str(), "f");
        clog2->Update();
        colorK++;
    }
    legend->Draw();
    clog2->Update();
    finalOut->WriteObject(clog2,"kaons_lim");
    clog2->Print(pdfOut.c_str());
    clog2->Clear();
    cOpen->Update();

    colorK = 0;
    clog2 = new TCanvas("CanvasLog2","CanvasLog2",1920,1200);
    clog2->SetLogy();
    legend = new TLegend(0.9, 0.9, 0.99, 0.1);
    clog2->Update();
    gStyle->SetPalette(kRust);
    for (int i=0;i<kaonsSpectrum_lim.size()-1;i++) {
        kaonsSpectrum_lim[treeName[i]]->Draw((colorP == 0 ? "HIST PFC PLC" : (treeName[i]=="DSVD1" ? "HIST SAME PFC" : "HIST SAME PFC PLC")));
        kaonsSpectrum_lim[treeName[i]]->SetStats(0);
        if(treeName[i]=="DSVD1"){kaonsSpectrum_lim[treeName[i]]->SetLineColor(kYellow);}
        kaonsSpectrum_lim[treeName[i]]->GetXaxis()->SetTitle("E [MeV]");
        kaonsSpectrum_lim[treeName[i]]->GetYaxis()->SetTitle("Count");
        kaonsSpectrum_lim[treeName[i]]->SetTitle("Kaons flux [lim]");
        legend->AddEntry(kaonsSpectrum_lim[treeName[i]], treeName[i].c_str(), "f");
        clog2->Update();
        colorK++;
    }
    legend->Draw();
    clog2->Update();
    finalOut->WriteObject(clog2,"kaons_flux_lim");
    clog2->Print(pdfOut.c_str());
    clog2->Clear();
    cOpen->Update();

    //positron cut
    TCanvas *cpi = new TCanvas("cpi","cpi",1920,1200);
    TLegend* pLeg = new TLegend(0.6,0.7,0.9,0.9);
    cpi->SetLogy();
    cpi->SetGrid();
    p_before->SetTitle("Positron cut");
    p_before->SetLineColor(kRed-6);
    p_before->SetLineWidth(3);
    Double_t p_before_tot = p_before->Integral();
    Double_t p_before_lim = p_before->Integral(7500/Ebin,9500/Ebin);
    p_after->SetTitle("Positron cut");
    p_after->SetLineColor(kRed);
    p_after->SetLineWidth(3);
    Double_t p_after_tot = p_after->Integral();
    Double_t p_after_lim = p_after->Integral(7500/Ebin,9500/Ebin);

    pLeg->AddEntry(p_before, "Before Pb", "l");
    pLeg->AddEntry(p_after, "After Pb", "l");

    p_before->Draw("HIST");
    p_after->Draw("HIST SAME");
    pLeg->Draw();
    cpi->Update();
    finalOut->WriteObject(clog2,"kaons_lim");
    cpi->Print(pdfOut.c_str());

    txtFile<<p_after_tot<<" "<<p_before_tot<<"\n";
    txtFile<<p_after_lim<<" "<<p_before_lim<<"\n";

    cOpen->Print((pdfOut+"]").c_str());
    finalOut->Close();
    txtFile.close();
}