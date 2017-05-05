#include "functionList.hh"
#include "fileList.hh"
#include "SetBranchEnv.hh"
#include "txtMaker.hh"

void run(){
	
	// Signal
	std::cout << "Signal sample processing .." << std::endl;
	for(int i=0; i<int(signal_list.size()); i++){
		for(int j=0; j<int(signal_TTree_list.size()); j++){
			txtMaker( signal_list.at(i), signal_TTree_list.at(j).at(0), signal_TTree_list.at(j).at(1), true);
		}
	}

	// Bkg
	std::cout << "Background sample processing .." << std::endl;
	for(int i=0; i<int(bkg_list.size()); i++){
		//TString bkg_filename = bkg_TTree_list.at(i).at(2) + ".txt";
		txtMaker( bkg_list.at(i), bkg_TTree_list.at(i).at(0),  "bkg", false, bkg_TTree_list.at(i).at(2));
	}
	
	// data
	std::cout << "Data sample processing .." << std::endl;
	for(int i=0; i<int(data_list.size()); i++){
		//TString bkg_filename = bkg_TTree_list.at(i).at(2) + ".txt";
		txtMaker( data_list.at(i), data_TTree_list.at(i).at(0),  "data", false, data_TTree_list.at(i).at(2));
	}


}
