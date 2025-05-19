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

    //out file
    std::string outFileName = "histSalad_"+detectorName+".root";
    TFile* outFile = new TFile(outFileName.data(), "RECREATE");

    //histograms
    TH1D* momHist = new TH1D("momHist", "momHist", 100, 0, 10000);
    TH1D* EHist = new TH1D("EHist", "EHist", 100, 0, 10000);
    TH1D* pseudoRapHist = new TH1D("pseudoRapHist", "pseudoRapHist", 100, 0, 10);
    TH1D* tHist = new TH1D("tHist", "tHist", 100, 0, 1e-6);

    TH2D* posHist = new TH2D("posHist", "posHist", 100, -10000., 10000., 100, -10000., 10000.);
    TH2D* momangleHistX = new TH2D("momangleHistX", "momangleHistX", 100, 0., 10000., 180, -90., 90.);
    TH2D* momangleHistY = new TH2D("momangleHistY", "momangleHistY", 100, 0., 10000., 180, -90., 90.);
    TH2D* rapidAngleHist = new TH2D("rapidAngleHist", "rapidAngleHist", 180, -90., 90., 100, -10., 10.);
    TH2D* rapidEnengyHist = new TH2D("rapidEnengyHist", "rapidEnengyHist", 100, 0, 10000, 100, -10., 10.);
    TH2D* rapidTimeHist = new TH2D("rapidTimeHist", "rapidTimeHist", 100, 0, 1e-6, 100, -10., 10.);
    TH2D* energyTimeHist = new TH2D("energyTimeHist", "energyTimeHist", 100, 0, 10000, 100, 0, 1e-6);


    std::vector<std::string> partSelect = {"nu_e","nu_mu","nu_tau","anti_nu_e","anti_nu_mu","anti_nu_tau"};

    Double_t absAngle = 9.09 * 3.141592 / 90;

    // Loop over the tree entries
    Long64_t nEntries = tree->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {

        tree->GetEntry(i);

        std::string pdgStr(PDG);

        if ( std::find(partSelect.begin(), partSelect.end(), pdgStr)!= partSelect.end() ){

            Double_t mom = std::sqrt((px*px)+(py*py)+(pz*pz));
            Double_t mom_xz = std::sqrt((pz*pz)+(py*py));
            Double_t angleX = (std::asin(mom_xz/mom) - absAngle);
            Double_t angleY = (std::asin(py/mom));

            Double_t pseudoRapidity = (-1.)*std::log(std::tan(angleX*0.5));

            momHist->Fill(mom);
            EHist->Fill(E);
            tHist->Fill(t);
            momangleHistX->Fill(mom,(180. / 3.141592) * angleX);
            momangleHistY->Fill(mom,(180. / 3.141592) * angleY);
            posHist->Fill(x,y);
            pseudoRapHist->Fill(pseudoRapidity);
            rapidAngleHist->Fill((180. / 3.141592) * angleX,pseudoRapidity);
            rapidEnengyHist->Fill(E,pseudoRapidity);
            rapidTimeHist->Fill(t,pseudoRapidity);
            energyTimeHist->Fill(E,t);
        }
    }

    outFile->WriteObject(momHist,"momHist");
    outFile->WriteObject(EHist,"EHist");
    outFile->WriteObject(tHist,"tHist");
    outFile->WriteObject(pseudoRapHist,"pseudoRapHist");
    outFile->WriteObject(momangleHistX,"momangleHistX");
    outFile->WriteObject(momangleHistY,"momangleHistY");
    outFile->WriteObject(posHist,"posHist");
    outFile->WriteObject(rapidEnengyHist,"rapidEnengyHist");
    outFile->WriteObject(rapidAngleHist,"rapidAngleHist");
    outFile->WriteObject(rapidTimeHist,"rapidTimeHist");
    outFile->WriteObject(energyTimeHist,"energyTimeHist");

}