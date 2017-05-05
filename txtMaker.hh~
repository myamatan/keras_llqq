void txtMaker( TString file, TString trName, TString txtName, bool isSignal, TString bkgType="Nan"){

	TString filepath = pathSet( file );

	TFile *f = new TFile(filepath);
	TTree *tr = (TTree*)f->Get( trName );

	std::ofstream fout(txtName,ios::app);

	// SetBranchStatus & SetBranchAddress 
	SetBranchEnv(tr);

	// PreSelection	
	TCut precut = "Mlljj > -1e+8";
	tr->Draw(">>elist",precut);
	TEventList *elist = (TEventList*)gROOT->FindObject("elist");

	long nEvent = elist->GetN();
	int id;
	double thres;
	
	if( isSignal ) id = 1;
	else id = 0;
/*	if( isSignal ) id = 0;
	else if( bkgType == "Z+jets" ) id = 1;
	else if( bkgType == "topQuarks" ) id = 2;
	else if( bkgType == "SMdiboson" ) id = 3;
*/	
	if( isSignal ) thres = 0.0;//0.0
	else thres = 0.975;//0.975
	std::vector<float> vec;
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
				fout << 1 << "," << 0 << "," << 0 << "," << 0 << std::endl;
			}else if( bkgType == "Z+jets" ){
				fout << 0 << "," << 1 << "," << 0 << "," << 0 << std::endl;
			}else if( bkgType == "topQuarks" ){
				fout << 0 << "," << 0 << "," << 1 << "," << 0 << std::endl;
			}else if( bkgType == "SMdiboson" ){
				fout << 0 << "," << 0 << "," << 0 << "," << 1 << std::endl;
			}
			vec.erase( vec.begin(), vec.end() );
		}
	}

/*
	for(long l=0; l<nEvent; l++){
		tr->GetEntry(elist->GetEntry(l));
		fout << MllJ << ","  << Mlljj << "," << ptll << "," << ptjj << "," << ptJ;
	       	fout << "," << sqrt(ptll*ptll+ptJ*ptJ)/MllJ << "," << sqrt(ptll*ptll+ptjj*ptjj)/Mlljj;
	       	fout << "," << mjjvbftag << "," << deltaetajjvbftag;
		fout << "," << Mll << ","  << MJ << "," << Mjj;
		fout << "," << eta_l1 << "," << eta_l2 << ","  << phi_l1 << "," << phi_l2;
		fout << "," << E_l1 << "," << E_l2 << ","  << pt_l1 << "," << pt_l2 << "," << id;
		fout << std::endl;
	}
*/
}
