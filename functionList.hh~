#include <iostream>
#include <fstream>
#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TCut.h"
#include "TNamed.h"
#include "TROOT.h"
#include <vector>
#include "TEventList.h"
#include "TClass.h"
#include "TFile.h"
#include "TMath.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TRandom.h"

using namespace std;

float deltaR(float eta_l1, float eta_l2, float phi_l1, float phi_l2, float eta_fatJ, float phi_fatJ){
	float eta_2lep = ( eta_l1 + eta_l2 ) / 2.;
	float phi_2lep = ( phi_l1 + phi_l2 ) / 2.;
	float dR = sqrt( pow(eta_2lep-eta_fatJ, 2) + pow(phi_2lep-phi_fatJ, 2) );
	if( dR > 3.14159 ) dR = 3.14159*2 - dR;
	return dR;
}
