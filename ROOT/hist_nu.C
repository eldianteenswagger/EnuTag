void hist_nu() {
    // Open the file
    std::string inputName;
    std::string detectorName;
    std::cout << "Filename: ";
    std::cin >> inputName;
    std::cout << "Detector: ";
    std::cin >> detectorName;

    TFile *file = TFile::Open(inputName.data());
    if (!file || file->IsZombie()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Get the Ntuple
    TTree *tree = (TTree*)file->Get(detectorName.data());
    if (!tree) {
        std::cerr << "Ntuple " << detectorName << " not found!" << std::endl;
        return;
    }

    // Variables for branches
    Double_t E;
    Char_t PDG[64];

    tree->SetBranchAddress("E", &E);
    tree->SetBranchAddress("PDG", &PDG);

    //List for neutrinos only selection
    std::vector<std::string> partSelect = {"nu_e","nu_mu","nu_tau","anti_nu_e","anti_nu_mu","anti_nu_tau"};

    // Map to store histograms by PDG name
    std::map<std::string, TH1D*> histMap;

    //Color map
    std::map<std::string, int> colorMap = {
        {"nu_e", kRed},
        {"nu_mu", kGreen},
        {"nu_tau", kBlue},
        {"anti_nu_e", kMagenta},
        {"anti_nu_mu", kYellow},
        {"anti_nu_tau", kCyan}
    };

    // Loop over the tree entries
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);

        std::string pdgStr(PDG);
        if ( std::find(partSelect.begin(), partSelect.end(), pdgStr)!= partSelect.end() ){
            //cout << std::find(partSelect.begin(), partSelect.end(), pdgStr)!= partSelect.end() <<endl;
            if (histMap.find(pdgStr) == histMap.end()) {
                // Create a new histogram for this PDG
                std::string histName = "h_" + pdgStr;
                histMap[pdgStr] = new TH1D(histName.c_str(), (pdgStr + " Energy").c_str(), 1000, 0, 10000); // Adjust bins/range
                histMap[pdgStr]->SetLineWidth(2);
                histMap[pdgStr]->SetLineColor(colorMap[pdgStr]);
            }
            // Fill the appropriate histogram
            histMap[pdgStr]->Fill(E);
        }
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