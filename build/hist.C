void hist() {
    // Open the file
    TFile *file = TFile::Open("out.root");
    if (!file || file->IsZombie()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Get the Ntuple
    TTree *tree = (TTree*)file->Get("USVD");
    if (!tree) {
        std::cerr << "Ntuple 'USVD' not found!" << std::endl;
        return;
    }

    // Variables for branches
    Double_t E;
    Char_t PDG[64];

    tree->SetBranchAddress("E", &E);
    tree->SetBranchAddress("PDG", &PDG);

    // Map to store histograms by PDG name
    std::map<std::string, TH1D*> histMap;

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
        }

        // Fill the appropriate histogram
        histMap[pdgStr]->Fill(E);
    }

    //TO IMPLEMENT: Map for particle colours

    // Create canvas and legend
    TCanvas *c = new TCanvas("c", "Energies by PDG", 1000, 600);
    c->cd();

    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    int color = 1;

    for (auto &entry : histMap) {
        entry.second->SetLineColor(color++);
        entry.second->Draw((color == 2 ? "HIST" : "HIST SAME"));
        legend->AddEntry(entry.second, entry.first.c_str(), "l");
    }

    legend->Draw();
    c->Update();
}