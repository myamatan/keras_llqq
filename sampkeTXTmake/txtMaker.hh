void txtMaker( TString file, TString trName, TString txtName, bool isSignal, TString bkgType="Nan"){

	TString filepath = pathSet( file );

	TFile *f = new TFile(filepath);
	TTree *tr = (TTree*)f->Get( trName );


	txtName = "sample/" + txtName + ".txt";
	std::ofstream fout(txtName,ios::app);

	// SetBranchStatus & SetBranchAddress 
	SetBranchEnv(tr);

	// PreSelection	
	TCut precut = "Mlljj > -1e+8";
	tr->Draw(">>elist",precut);
	TEventList *elist = (TEventList*)gROOT->FindObject("elist");

	long nEvent = elist->GetN();
	int id;
	double thres = 0.0;
	
	if( isSignal ) id = 1;
	else id = 0;
	
	std::vector<float> vec;
	long count_N = 0;
	for(long l=0; l<nEvent; l++){
		tr->GetEntry(elist->GetEntry(l));
		if( gRandom->Rndm() > thres ){
			vec.push_back(Mlljj);
			vec.push_back(ptjj);
			vec.push_back(Mjj);
			vec.push_back(sqrt(ptll*ptll+ptjj*ptjj)/Mlljj);
			vec.push_back(ptll);
			vec.push_back(Mll);
			vec.push_back(MllJ);
			vec.push_back(ptJ);
			vec.push_back(MJ);
			vec.push_back(sqrt(ptll*ptll+ptJ*ptJ)/MllJ);
			vec.push_back(E_l1);
			vec.push_back(E_l2);
			vec.push_back(pt_l1);
			vec.push_back(pt_l2);
			vec.push_back(mjjvbftag);
			vec.push_back(deltaetajjvbftag);
			vec.push_back(eta_l1);
			vec.push_back(eta_l2);
			vec.push_back(phi_l1);
			vec.push_back(phi_l2);
			vec.push_back(id);
			for(UInt_t i=0; i<vec.size()-1; i++){
				for(UInt_t j=i+1; j<vec.size()-1; j++){
					fout << vec.at(i)*vec.at(j) << ",";
				}
				for(UInt_t j=i+1; j<vec.size()-1; j++){
					fout << vec.at(i)/(vec.at(j)+1.) << ",";
				}
				for(UInt_t j=i+1; j<vec.size()-1; j++){
					fout << vec.at(i)+vec.at(j) << ",";
				}
				for(UInt_t j=i+1; j<vec.size()-1; j++){
					fout << vec.at(i)-vec.at(j) << ",";
				}
			}
			//fout << id << std::endl;
			if( isSignal ){
				fout << weight << "," << 0 << "," << 0 << "," << 0 << std::endl;
			}else if( bkgType == "Z+jets" ){
				fout << weight << "," << 1 << "," << 0 << "," << 0 << std::endl;
			}else if( bkgType == "topQuarks" ){
				fout << weight << "," << 0 << "," << 1 << "," << 0 << std::endl;
			}else if( bkgType == "SMdiboson" ){
				fout << weight << "," << 0 << "," << 0 << "," << 1 << std::endl;
			}else if( bkgType == "data" ){
				fout << weight << "," << 0 << "," << 0 << "," << 0 << std::endl;
			}
			vec.erase( vec.begin(), vec.end() );
		}
	}

}
