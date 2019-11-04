#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TMath.h>
// Header file for the classes stored in the TTree if any.
#include "vector"

void miniTreeMaker(){
//cout<<"Debo1"<<endl;
gStyle->SetOptStat(0); 
vector<double>  clus_px, clus_py, clus_pz, clus_eta, clus_phi, clus_P;
Float_t pt, mcEventWeight, fjet_xsec_filteff;

//cout<<"Debo2"<<endl;

//Input File
TFile *f1 = new TFile("user.cdelitzs.JZ2W.root");        

//Output File
TFile *f2 = new TFile("user.cdelitzs.JZ2W.mini.root","RECREATE");
//cout<<"Debo3"<<endl;

//Old Tree: from here I will take some variable and populate the new tree
TTree *t1 = (TTree*)f1->Get("FlatSubstructureJetTree");
vector<double>* fjet_clus_pt= nullptr;
vector<double>* fjet_clus_eta= nullptr;
vector<double>* fjet_clus_phi= nullptr;
Float_t fjet_pt, EventInfo_mcEventWeight, fjet_xsec_filteff_numevents;
t1->SetBranchAddress("fjet_pt",&fjet_pt);
t1->SetBranchAddress("fjet_clus_pt",&fjet_clus_pt);
t1->SetBranchAddress("fjet_clus_eta",&fjet_clus_eta);
t1->SetBranchAddress("fjet_clus_phi",&fjet_clus_phi);
t1->SetBranchAddress("EventInfo_mcEventWeight",&EventInfo_mcEventWeight);
t1->SetBranchAddress("fjet_xsec_filteff_numevents",&fjet_xsec_filteff_numevents);

//Create New Tree
TTree *t2 = new TTree("FlatSubstructureJetTreeD","Tree with required variables");
t2->Branch("fjet_pt",&pt);
t2->Branch("fjet_clus_P",&clus_P);
t2->Branch("fjet_clus_px",&clus_px);
t2->Branch("fjet_clus_py",&clus_py);
t2->Branch("fjet_clus_pz",&clus_pz);
t2->Branch("EventInfo_mcEventWeight",&mcEventWeight);
t2->Branch("fjet_xsec_filteff_numevents",&fjet_xsec_filteff);
//cout<<"Debo4"<<endl;

double temp_clus_pt, temp_clus_phi, temp_clus_eta, temp_clus_px, temp_clus_py, temp_clus_pz, temp_clus_P, temp_fjet_pt;

//cout<<"Debo5"<<endl;


//cout<<"Debo6"<<endl;

//find the no. of entries to loop over the tree
Int_t nentries = (Int_t)t1->GetEntries();
cout<<"nentries: "<<nentries<<endl;
//cout<<"Debo7"<<endl;
for (Int_t i=0; i<nentries; i++) {
//cout<<"Debo8"<<endl;
//pt.clear();
clus_P.clear();
clus_px.clear();
clus_py.clear();
clus_pz.clear();

t1->GetEntry(i);
pt = fjet_pt;
mcEventWeight = EventInfo_mcEventWeight;
fjet_xsec_filteff = fjet_xsec_filteff_numevents;

for (Int_t j=0; j<fjet_clus_pt->size(); j++) {
temp_clus_pt = fjet_clus_pt->at(j);
temp_clus_phi= fjet_clus_phi->at(j);
temp_clus_eta= fjet_clus_eta->at(j);
temp_clus_px = temp_clus_pt*cos(temp_clus_phi);
temp_clus_py = temp_clus_pt*sin(temp_clus_phi);
temp_clus_pz = temp_clus_pt*sinh(temp_clus_eta);
temp_clus_P = temp_clus_pt*cosh(temp_clus_eta);

clus_P.emplace_back(temp_clus_P);
clus_px.emplace_back(temp_clus_px);
clus_py.emplace_back(temp_clus_py);
clus_pz.emplace_back(temp_clus_pz);
}
cout<<"event no.: " <<i<<" clus_px.size(): "<<clus_px.size()<<endl;
t2->Fill();
}
cout<<"newEntries: "<<(Int_t)t1->GetEntries()<<endl;
f2->Write();
delete f2;
delete f1;
}
