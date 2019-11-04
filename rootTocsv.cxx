#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include <fstream>
using namespace std;

void rootTocsv(){
  TFile *f=new TFile("user.cdelitzs.JZ4W.mini.root"); // opens the root file
  TTree *tr=(TTree*)f->Get("FlatSubstructureJetTreeD"); // creates the TTree object
  tr->Scan(); // prints the content on the screen

  vector<double>* fjet_clus_P= nullptr;
  vector<double>* fjet_clus_px= nullptr;
  vector<double>* fjet_clus_py= nullptr;
  vector<double>* fjet_clus_pz= nullptr;

  tr->SetBranchAddress("fjet_clus_P",&fjet_clus_P); // for all the TTree branches you need this
  tr->SetBranchAddress("fjet_clus_px",&fjet_clus_px);
  tr->SetBranchAddress("fjet_clus_py",&fjet_clus_py);
  tr->SetBranchAddress("fjet_clus_pz",&fjet_clus_pz);

  ofstream myfile;
  myfile.open ("JZ4W.mini.txt");
  for (int i=0;i<tr->GetEntries();i++){
    // loop over the tree
    tr->GetEntry(i);
    for (Int_t j=0; j<fjet_clus_P->size(); j++) {
    cout <<fjet_clus_P->at(j)<< ", "<<fjet_clus_px->at(j)<<", "<<fjet_clus_py->at(j)<<", "<<fjet_clus_pz->at(j)<<", "; //print to the screen
    myfile <<fjet_clus_P->at(j)<< ", "<<fjet_clus_px->at(j)<<", "<<fjet_clus_py->at(j)<<", "<<fjet_clus_pz->at(j)<<", "; //write to file
}
  cout<<endl;
  myfile<<"\n";

}
 delete f;
  myfile.close();
}
