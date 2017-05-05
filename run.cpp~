#include "functi(nList.hh"
#include "fileList.hh"
#include "SetBranchEnv.hh"
#include "txtMaker.hh"

void run(){

	// Signal
	std::cout << "Signal sample processing .." << std::endl;
	for(int i=0; i<int(signal_list.size()); i++){
		for(int j=0; j<int(signal_TTree_list.size()); j++){
			txtMaker( signal_list.at(i), signal_TTree_list.at(j).at(0), "signal.txt", true);
		}
	}

	// Bkg
	std::cout << "Background sample processing .." << std::endl;
	for(int i=0; i<int(bkg_list.size()); i++){
		//TString bkg_filename = bkg_TTree_list.at(i).at(2) + ".txt";
		txtMaker( bkg_list.at(i), bkg_TTree_list.at(i).at(0),  "bkg.txt", false, bkg_TTree_list.at(i).at(2));
	}


}
