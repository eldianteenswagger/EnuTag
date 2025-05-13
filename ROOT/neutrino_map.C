void neutrino_map(){

    std::string inputName;
    std::cout << "Filename: ";
    std::cin >> inputName;

    TFile *file = TFile::Open(inputName.data());
    if (!file || file->IsZombie()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    // Get the Ntuple
    TTree *tree = (TTree*)file->Get("neutrinos");
    if (!tree) {
        std::cerr << "Ntuple not found!" << std::endl;
        return;
    }

    // Variables for branches
    Double_t x;
    Double_t y;
    Double_t z;

    tree->SetBranchAddress("nu_x", &x);
    tree->SetBranchAddress("nu_y", &z);
    tree->SetBranchAddress("nu_z", &y);

    //out file
    //std::string outFileName = "neutrinomap_"+inputName+".root";
    //TFile* outFile = new TFile(outFileName.data(), "RECREATE");

    //graph
    auto map = new TGraph2D();

    // Loop over the tree entries
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);
        map->SetPoint(i,x,y,z);
    }

    map->Draw();

    return;
}