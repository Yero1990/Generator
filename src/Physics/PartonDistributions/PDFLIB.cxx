//____________________________________________________________________________
/*
 Copyright (c) 2003-2018, The GENIE Collaboration
 For the full text of the license visit http://copyright.genie-mc.org
 or see $GENIE/LICENSE

 Author: Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         University of Liverpool & STFC Rutherford Appleton Lab 

 Disabled PDFLIB - Only LHAPDFv5 support left / to clean-up before next
 release. Experimenting in LHAPDFv6

*/
//____________________________________________________________________________

#include <cstdlib>

#include <TSystem.h>
#include <TMath.h>

#include "Framework/Conventions/GBuild.h"
#include "Physics/PartonDistributions/PDFLIB.h"
#include "Framework/Messenger/Messenger.h"

#ifdef __GENIE_LHAPDF5_ENABLED__
//
// include the LHAPDF C++ wrapper
//
#include "LHAPDF/LHAPDF.h"
//#else
//
// the actual PDFLIB fortran calls
//
//extern "C" {
// void pdfset_ (const char param[20][20], double val[20]);
// void structm_ (double *, double *, double *, double *, double *, 
//                double *, double *, double *, double *, double *, double *);
//}
#endif

using namespace genie;

//____________________________________________________________________________
PDFLIB::PDFLIB() :
PDFModelI("genie::PDFLIB")
{
  this->Initialize();
}
//____________________________________________________________________________
PDFLIB::PDFLIB(string config) :
PDFModelI("genie::PDFLIB", config)
{
  LOG("PDF", pDEBUG) << "PDFLIB configuration:\n " << this->GetConfig();  

  this->Initialize();
}
//____________________________________________________________________________
PDFLIB::~PDFLIB() 
{ 

}
//____________________________________________________________________________
void PDFLIB::Initialize(void) const
{
#ifdef __GENIE_LHAPDF5_ENABLED__
  //
  // LHAPDF
  //
  bool lhapath_ok = true;
  const char * lhapath = gSystem->Getenv("LHAPATH");
  if(!lhapath) lhapath_ok = false;
  else {
      void *dirp = gSystem->OpenDirectory(lhapath);
      if (dirp) gSystem->FreeDirectory(dirp);
      else lhapath_ok = false;
  }
  if(!lhapath_ok) {
   LOG("PDF", pFATAL) 
     << "\n"
     << "** LHAPDF won't be able to read-in the PDF data. \n"
     << "** The LHAPATH env. variable is not properly (or at all) defined. \n"
     << "** Please, set LHAPATH to <lhapdf_top_dir>/PDFsets/ \n"
     << "** See http://projects.hepforge.org/lhapdf/ for more details. \n\n";
   gAbortingInErr = true;
   exit(1);
  }

/*
#else
  //
  // PDFLIB
  //
  char   param[20][20];
  double val[20];
  strcpy(param[0], "Init0");
  pdfset_(param, val); // call pdfset from the fortran PDFLIB library
*/
#endif
}
//____________________________________________________________________________
void PDFLIB::SetPDFSetFromConfig(void) const
{
// Get PDF spec (particle type, pdf group/set) from configuration registry.
// For definitions, have a look at PDFLIB and LHAPDF manuals

#ifdef __GENIE_LHAPDF5_ENABLED__
  //
  // LHAPDF
  //
  string name   = "";
  int    type   = 0;
  int    memset = 0;

  this->GetParam("name_lhapdf",   name);
  this->GetParam("type_lhapdf",   type);
  this->GetParam("memset_lhapdf", memset);

  LHAPDF::SetType stype = (type==0) ? LHAPDF::LHPDF :  LHAPDF::LHGRID;

  LHAPDF::initPDFByName(name, stype, memset);
  LHAPDF::extrapolate(false);

/*
#else
  //
  // PDFLIB
  //
  int nptype = -1; // particle type
  int ngroup = -1; // PDF author group
  int nset   = -1; // PDF set --within PDF author group--

  fConfig->Get("nptype_pdflib", nptype);
  fConfig->Get("ngroup_pdflib", ngroup);
  fConfig->Get("nset_pdflib",   nset  );

  char   param[20][20];
  double val[20];

  strcpy(param[0],"Nptype");
  val[0] = nptype;
  strcpy(param[1],"Ngroup");
  val[1] = ngroup;
  strcpy(param[2],"Nset");
  val[2] = nset;

  pdfset_(param, val);
*/

#endif
}
//____________________________________________________________________________
double PDFLIB::UpValence(double x, double Q2) const
{
  return AllPDFs(x,Q2).uval;
}
//____________________________________________________________________________
double PDFLIB::DownValence(double x, double Q2) const
{
  return AllPDFs(x,Q2).dval;
}
//____________________________________________________________________________
double PDFLIB::UpSea(double x, double Q2) const
{
  return AllPDFs(x,Q2).usea;
}
//____________________________________________________________________________
double PDFLIB::DownSea(double x, double Q2) const
{
  return AllPDFs(x,Q2).dsea;
}
//____________________________________________________________________________
double PDFLIB::Strange(double x, double Q2) const
{
  return AllPDFs(x,Q2).str;
}
//____________________________________________________________________________
double PDFLIB::Charm(double x, double Q2) const
{
  return AllPDFs(x,Q2).chm;
}
//____________________________________________________________________________
double PDFLIB::Bottom(double x, double Q2) const
{
  return AllPDFs(x,Q2).bot;
}
//____________________________________________________________________________
double PDFLIB::Top(double x, double Q2) const
{
  return AllPDFs(x,Q2).top;
}
//____________________________________________________________________________
double PDFLIB::Gluon(double x, double Q2) const
{
  return AllPDFs(x,Q2).gl;
}
//____________________________________________________________________________
PDF_t PDFLIB::AllPDFs(double x, double Q2) const
{
  PDF_t pdf;

#ifdef __GENIE_LHAPDF5_ENABLED__
  //
  // LHAPDF
  //

  // QCD scale
  double Q = TMath::Sqrt( TMath::Abs(Q2) ); 

  vector<double> pdfs = LHAPDF::xfx(x, Q);
  pdf.uval = pdfs[8] - pdfs[4];
  pdf.dval = pdfs[7] - pdfs[5];
  pdf.usea = pdfs[4];
  pdf.dsea = pdfs[5];
  pdf.str  = pdfs[9];
  pdf.chm  = pdfs[10];
  pdf.bot  = pdfs[11];
  pdf.top  = pdfs[12];
  pdf.gl   = pdfs[6];;

/*
#else
  //
  // PDFLIB
  //

  double uval, dval, usea, dsea, str, chm, bot, top, gl;

  // call structm from the fortran PDFLIB library
  structm_(&x, &q, &uval, &dval, &usea, &dsea, &str, &chm, &bot, &top, &gl);

  pdf.uval = uval;
  pdf.dval = dval;
  pdf.usea = usea;
  pdf.dsea = dsea;
  pdf.str  = str;
  pdf.chm  = chm;
  pdf.bot  = bot;
  pdf.top  = top;
  pdf.gl   = gl;
*/

#endif

  return pdf;                                               
}
//____________________________________________________________________________
void PDFLIB::Configure(const Registry & config)
{
  Algorithm::Configure(config);

  this->Initialize();         
  this->SetPDFSetFromConfig();

  fAllowReconfig=false;
}
//____________________________________________________________________________
void PDFLIB::Configure(string config)
{
  Algorithm::Configure(config);

  this->Initialize();          
  this->SetPDFSetFromConfig(); 

  fAllowReconfig=false;
}
//____________________________________________________________________________
