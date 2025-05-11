void hist_salad() {
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
    Double_t x;
    Double_t y;
    Double_t px;
    Double_t py;
    Double_t pz;
    Double_t t;
    Char_t PDG[64];
    Int_t ID;
    Double_t dE;

    tree->SetBranchAddress("E", &E);
    tree->SetBranchAddress("x", &x);
    tree->SetBranchAddress("y", &y);
    tree->SetBranchAddress("px", &px);
    tree->SetBranchAddress("py", &py);
    tree->SetBranchAddress("pz", &pz);
    tree->SetBranchAddress("t", &t);
    tree->SetBranchAddress("PDG", &PDG);
    tree->SetBranchAddress("ID", &ID);
    tree->SetBranchAddress("dE", &dE);

    //histograms
    TH1D* momHist = new TH1D("momHist", "momHist", 100, 0, 10000);
    TH2D* momangleHist = new TH2D("momangleHist", "momangleHist", 100, -10000., 10000., 100, -7., 7.);
    TH2D* posHist = new TH2D("posHist", "posHist", 100, -10000., 10000., 100, -10000., 10000.);

    std::vector<std::string> partSelect = {"nu_e","nu_mu","nu_tau","anti_nu_e","anti_nu_mu","anti_nu_tau"};

    // Loop over the tree entries
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {

        tree->GetEntry(i);

        std::string pdgStr(PDG);

        if ( std::find(partSelect.begin(), partSelect.end(), pdgStr)!= partSelect.end() ){
            Double_t mom = std::sqrt((px*px)+(py*py)+(pz*pz));
            Double_t angle = ;
            momHist->Fill(mom);
            posHist->Fill(x,y);
        }

        // Fill the appropriate histogram
    }

    // Create canvas and legend
    TCanvas *c = new TCanvas("c", "Histogram", 1000, 600);
    c->cd();
    //momHist->SetLogy();

    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);

    posHist->Draw();
    legend->Draw();
    c->Update();
    //c->SaveAs("prova.root");
}