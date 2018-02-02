/**
 * 
 * main.cc for analysis of simulated transfer reactions
 * 
 * 
 **/


#include "main.h"

#include "LibPerso.h"

using namespace std;





Int_t main(Int_t argc, char **argv){
  
  
  
  
  
  
  // if root shall stop the program before it finished, comment this in
  TApplication *theApp=new TApplication("theApp",  0, 0);
  
  
  cout << "Welcome to troja analyzer" << endl;
  
  
  if(argc < 2){
    cout << "No input arguments given. Please add:" << endl;
    cout << "\t-i [root file name]\tinput root file name" << endl;
    cout << "\t-o [root file name]\toutput root file name" << endl;
    cout << "\t-n [integer]\t\tnumber of events to analyze" << endl;
    return -1;
  }
  
  std::vector<TString> targets;
  TString inputFile;
  TString outputFile;
  
  Int_t maxevents = -1;
  
  bool inpi=false, inpo=false;
  
  for(int i = 1; i < argc; ++i){
    TString str = argv[i];
    if(str.EqualTo("-n")){
        maxevents = std::atoi(argv[++i]);
	cout << "Analyzing " << maxevents << " events" << endl;
    }
    else if(str.EqualTo("-i")){
        inputFile = argv[++i];
	cout << "Input filename: " << inputFile << endl;
	inpi=true;
    }
    else if(str.EqualTo("-o")){
        outputFile = argv[++i];
	cout << "Output filename: " << outputFile << endl;
	inpo=true;
    }
    else{
        targets.push_back(str);
    }
  }
  
  if(!inpi){
    cout << "No input file given. Please add:" << endl;
    cout << "\t-i [root file name]\tinput root file name" << endl;
    return 0;
  }
  if(!inpo){
    cout << "No output file given. Please add:" << endl;
    cout << "\t-o [root file name]\toutput root file name" << endl;
    return 0;
  }
  
  
  TRandom3* randomizer = new TRandom3();
  randomizer->SetSeed(0); 
  
  TChain *tree = new TChain("Exp");
  
  tree->Add(inputFile);
  
  tree->SetBranchAddress("RegionIDs", &RegionIDs);
  tree->SetBranchAddress("GR_V830", &GR_V830);
  tree->SetBranchAddress("IPR", &IPR);
  tree->SetBranchAddress("Scaler", &Scaler);
  tree->SetBranchAddress("Time", &Time);
  tree->SetBranchAddress("ChkSum", &ChkSum);
  tree->SetBranchAddress("FERA_Type", &FERA_Type);
  tree->SetBranchAddress("FERA_Ch", &FERA_Ch);
  tree->SetBranchAddress("FERA_Mid", &FERA_Mid);
  tree->SetBranchAddress("EVENT", &EVENT);
  tree->SetBranchAddress("GR", &GR);
  tree->SetBranchAddress("GF", &GF);
  tree->SetBranchAddress("LAS", &LAS);
  
  tree->SetBranchAddress("GR_WIRE_X1", &GR_WIRE_X1);
  tree->SetBranchAddress("GR_WIRE_U1", &GR_WIRE_U1);
  tree->SetBranchAddress("GR_WIRE_X2", &GR_WIRE_X2);
  tree->SetBranchAddress("GR_WIRE_U2", &GR_WIRE_U2);
  
  tree->SetBranchAddress("GR_TDC_X1", &GR_TDC_X1);
  tree->SetBranchAddress("GR_TDC_U1", &GR_TDC_U1);
  tree->SetBranchAddress("GR_TDC_X2", &GR_TDC_X2);
  tree->SetBranchAddress("GR_TDC_U2", &GR_TDC_U2);
  
  tree->SetBranchAddress("LAS_WIRE_X1", &LAS_WIRE_X1);
  tree->SetBranchAddress("LAS_WIRE_U1", &LAS_WIRE_U1);
  tree->SetBranchAddress("LAS_WIRE_V1", &LAS_WIRE_V1);
  tree->SetBranchAddress("LAS_WIRE_X2", &LAS_WIRE_X2);
  tree->SetBranchAddress("LAS_WIRE_U2", &LAS_WIRE_U2);
  tree->SetBranchAddress("LAS_WIRE_V2", &LAS_WIRE_V2);
  
  tree->SetBranchAddress("LAS_TDC_X1", &LAS_TDC_X1);
  tree->SetBranchAddress("LAS_TDC_U1", &LAS_TDC_U1);
  tree->SetBranchAddress("LAS_TDC_V1", &LAS_TDC_V1);
  tree->SetBranchAddress("LAS_TDC_X2", &LAS_TDC_X2);
  tree->SetBranchAddress("LAS_TDC_U2", &LAS_TDC_U2);
  tree->SetBranchAddress("LAS_TDC_V2", &LAS_TDC_V2);
  
  tree->SetBranchAddress("V1190_QTC", &V1190_QTC);

  TStopwatch* watch = new TStopwatch();
  watch->Start();
  
  Int_t events = tree->GetEntries();
  
  cout << "found " << events << " in tree" << endl;
  
  
  if(maxevents>0 && maxevents<events){
    events=maxevents;
  }
  
  for(Int_t ev=0; ev<events; ev++){
    
    tree->GetEntry(ev);
    cout << "GR_TDC_X1[0] = " << GR_TDC_X1[0] << endl;
  }
  

 
  cout << "Test successful" << endl;
  
  
  watch->Stop();
  cout << "Took: real time " << watch->RealTime() << "sec., CPU time " << watch->CpuTime() << " sec." << endl;
  cout << endl;
  
  delete theApp;  

    
  return 0;
}


