float Mlljj;
float MllJ;
float ptll;
float ptjj;
float ptJ;
float Mll;
float MJ;
float Mjj;
float mjjvbftag;
float deltaetajjvbftag;
float eta_l1;
float eta_l2;
float phi_l1;
float phi_l2;
float E_l1;
float E_l2;
float pt_l1;
float pt_l2;
float weight;

void SetBranchEnv(TTree *tr){

	//tr->SetBranchStatus("*",0);
	//tr->SetBranchStatus("Muons___NominalAuxDyn.pt",1);

	tr->SetBranchAddress("Mlljj", &Mlljj);
	tr->SetBranchAddress("MllJ", &MllJ);
	tr->SetBranchAddress("ptll", &ptll);
	tr->SetBranchAddress("ptjj", &ptjj);
	tr->SetBranchAddress("ptJ", &ptJ);
	tr->SetBranchAddress("Mll", &Mll);
	tr->SetBranchAddress("MJ", &MJ);
	tr->SetBranchAddress("Mjj", &Mjj);
	tr->SetBranchAddress("mjjvbftag", &mjjvbftag);
	tr->SetBranchAddress("deltaetajjvbftag", &deltaetajjvbftag);
	tr->SetBranchAddress("eta_l1", &eta_l1);
	tr->SetBranchAddress("eta_l2", &eta_l2);
	tr->SetBranchAddress("phi_l1", &phi_l1);
	tr->SetBranchAddress("phi_l2", &phi_l2);
	tr->SetBranchAddress("E_l1", &E_l1);
	tr->SetBranchAddress("E_l2", &E_l2);
	tr->SetBranchAddress("pt_l1", &pt_l1);
	tr->SetBranchAddress("pt_l2", &pt_l2);
	
	tr->SetBranchAddress("weight", &weight);

}
