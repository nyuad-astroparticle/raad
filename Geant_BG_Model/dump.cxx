//Name this file "dump.cxx" and use as:
//
// root [0] .x dump.cxx(); > dump.txt
//
// Produces "dump.txt" and "dump.xml" files.
//

void dump(const char *fname = "B4.root",
          const char *nname = "B4")
{
  if (!fname || !(*fname) || !nname || !(*nname)) return; // just a precaution
  
  TFile *f = TFile::Open(fname, "READ");
  if ((!f) || f->IsZombie()) { delete f; return; } // just a precaution
  
  TTree *t; f->GetObject(nname, t);
  if (!t) { delete f; return; } // just a precaution
  
  // See:
  // http://root.cern.ch/root/html/TTreePlayer.html#TTreePlayer:Scan
  // http://root.cern.ch/root/html/TTree.html#TTree:Scan
  t->SetScanField(0);
  t->Scan("*");
 // See:
  // http://root.cern.ch/root/html/TObject.html#TObject:SaveAs
  t->SaveAs("dump.xml");
  // t->SaveAs(TString::Format("%s.xml", nname));
  
  delete f; // no longer needed (automatically deletes "t")
}

