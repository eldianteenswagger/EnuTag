void hist() {
    // Open the file
    TFile *file = TFile::Open("out.root");
    if (!file || file->IsZombie()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Get the Ntuple
    TTree *tree = (TTree*)file->Get("DSVD_2");
    if (!tree) {
        std::cerr << "Ntuple 'DSVD_2' not found!" << std::endl;
        return;
    }

    // Variables for branches
    Double_t E;
    Char_t PDG[64];

    tree->SetBranchAddress("E", &E);
    tree->SetBranchAddress("PDG", &PDG);

    // Map to store histograms by PDG name
    std::map<std::string, TH1D*> histMap;

    //Color map
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

    // Loop over the tree entries
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);

        std::string pdgStr(PDG);

        if (histMap.find(pdgStr) == histMap.end()) {
            // Create a new histogram for this PDG
            std::string histName = "h_" + pdgStr;
            histMap[pdgStr] = new TH1D(histName.c_str(), (pdgStr + " Energy").c_str(), 10000, 0, 10000); // Adjust bins/range
            histMap[pdgStr]->SetLineWidth(2);
            histMap[pdgStr]->SetLineColor(colorMap[pdgStr]);
        }

        // Fill the appropriate histogram
        histMap[pdgStr]->Fill(E);
    }

    // Create canvas and legend
    TCanvas *c = new TCanvas("c", "Energies by PDG", 1000, 600);
    c->cd();
    c->SetLogy();

    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    int color = 1;

    for (auto &entry : histMap) {
        //entry.second->SetLineColor(color++);
        entry.second->Draw((color == 2 ? "HIST" : "HIST SAME"));
        legend->AddEntry(entry.second, entry.first.c_str(), "l");
    }
    legend->Draw();
    c->Update();
}