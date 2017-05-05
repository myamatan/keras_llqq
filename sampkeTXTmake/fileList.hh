// Pre path
TString prePath = "/Users/masahiroyamatani/icepp/physics/diBoson/output/";

// Signal
std::vector<TString> signal_list = { "output_inclusive_spin2/submitDir_sp2_signal/data-minitree/RS_G_ZZ.root" };
std::vector<std::vector<TString> >signal_TTree_list = {
	{"GZZllqqc10m0500_Nominal","RSG0500"},
	{"GZZllqqc10m0600_Nominal","RSG0600"},
	{"GZZllqqc10m0700_Nominal","RSG0700"},
	{"GZZllqqc10m0800_Nominal","RSG0800"},				
	{"GZZllqqc10m0900_Nominal","RSG0900"},
	{"GZZllqqc10m1000_Nominal","RSG1000"},
	{"GZZllqqc10m1100_Nominal","RSG1100"},
	{"GZZllqqc10m1200_Nominal","RSG1200"},
	{"GZZllqqc10m1300_Nominal","RSG1300"},
	{"GZZllqqc10m1400_Nominal","RSG1400"},
	{"GZZllqqc10m1500_Nominal","RSG1500"},
	{"GZZllqqc10m1600_Nominal","RSG1600"},
	{"GZZllqqc10m1700_Nominal","RSG1700"},
	{"GZZllqqc10m1800_Nominal","RSG1800"},
	{"GZZllqqc10m1900_Nominal","RSG1900"},
	{"GZZllqqc10m2000_Nominal","RSG2000"},
	{"GZZllqqc10m2200_Nominal","RSG2200"},
	{"GZZllqqc10m2400_Nominal","RSG2400"},
	{"GZZllqqc10m2600_Nominal","RSG2600"},
	{"GZZllqqc10m2800_Nominal","RSG2800"},
	{"GZZllqqc10m3000_Nominal","RSG3000"},
	{"GZZllqqc10m3500_Nominal","RSG3500"},
	{"GZZllqqc10m4000_Nominal","RSG4000"},
	{"GZZllqqc10m4500_Nominal","RSG4500"},
	{"GZZllqqc10m5000_Nominal","RSG5000"}
};
// BackGround
std::vector<TString> bkg_list = {
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZeeB_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZeeC_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZeeL_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZeeHPT_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZmumuB_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZmumuC_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZmumuL_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZmumuHPT_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZtautauB_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZtautauC_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZtautauL_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZtautauHPT_v221.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ttbar.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/singletop_Wt.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/singletop_s.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/singletop_t.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/ZZ_improved.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/WW_improved.root",
	"output_inclusive_spin2/submitDir_sp2_mc/data-minitree/WZ_improved.root"
};
std::vector<std::vector<TString> > bkg_TTree_list = {
	{"Z_Nominal","ZeeB_v221","Z+jets"},
	{"Z_Nominal","ZeeC_v221","Z+jets"},
	{"Z_Nominal","ZeeL_v221","Z+jets"},
	{"Z_Nominal","ZeeHPT_v221","Z+jets"},
	{"Z_Nominal","ZmumuB_v221","Z+jets"},
	{"Z_Nominal","ZmumuC_v221","Z+jets"},
	{"Z_Nominal","ZmumuL_v221","Z+jets"},
	{"Z_Nominal","ZmumuHPT_v221","Z+jets"},
	{"Z_Nominal","ZtautauB_v221","Z+jets"},
	{"Z_Nominal","ZtautauC_v221","Z+jets"},
	{"Z_Nominal","ZtautauL_v221","Z+jets"},
	{"Z_Nominal","ZtautauHPT_v221","Z+jets"},
	{"ttbar_Nominal","ttbar","topQuarks"},
	{"stopWt_Nominal","stopWt","topQuarks"},
	{"stops_Nominal","stops","topQuarks"},
	{"stopt_Nominal","stopt","topQuarks"},
	{"ZZ_Nominal","ZZ_improved","SMdiboson"},
	{"WW_Nominal","WW_improved","SMdiboson"},
	{"WZ_Nominal","WZ_improved","SMdiboson"}
};

// Data
std::vector<TString> data_list = {
	"output_inclusive_spin2/submitDir_sp2_data/data-minitree/data15.root",
	"output_inclusive_spin2/submitDir_sp2_data/data-minitree/data16.root",
};
std::vector<std::vector<TString> > data_TTree_list = {
	{"data_Nominal","data15","data"},
	{"data_Nominal","data16","data"}
};


// Tuple for signal and Bkg list
std::vector<std::tuple<TString, TString, std::vector<TString>, std::vector<std::vector<TString> >, Color_t> > fileType = {
	make_tuple("Signal", "RSG", signal_list, signal_TTree_list, kBlue),
	make_tuple("Bkg", "Bkg", bkg_list, bkg_TTree_list, kRed),
	make_tuple("data", "data", data_list, data_TTree_list, kBlack)
};

// Path adder
TString pathSet(TString list){
	TString path = prePath + list;
	return path;
}

