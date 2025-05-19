void merge(){

    //define all tchains
    TChain tUSVD("tUSVD");
    TChain tDet1("tDet1");
    TChain tDet2("tDet2");
    TChain tDet3("tDet3");
    TChain tDet4("tDet4");
    TChain tDet5("tDet5");
    TChain tDSVD1("tDSVD1");
    TChain tDSVD2("tDSVD2");
    TChain tFVD("tFVD");

    for (int i=0;i<3;i++){
        std::string fileName = "runOut"+to_string(i)+".root";
        tUSVD.AddFile((fileName+"/FVD").c_str());
    }


}