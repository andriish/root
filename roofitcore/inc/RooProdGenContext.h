/*****************************************************************************
 * Project: BaBar detector at the SLAC PEP-II B-factory
 * Package: RooFitCore
 *    File: $Id$
 * Authors:
 *   WV, Wouter Verkerke, UC Santa Barbara, verkerke@slac.stanford.edu
 *   DK, David Kirkby, Stanford University, kirkby@hep.stanford.edu
 * History:
 *   11-Oct-2001 WV Created initial version
 *
 * Copyright (C) 2001 University of California
 *****************************************************************************/
#ifndef ROO_PROD_GEN_CONTEXT
#define ROO_PROD_GEN_CONTEXT

#include "TList.h"
#include "RooFitCore/RooAbsGenContext.hh"
#include "RooFitCore/RooArgSet.hh"

class RooProdPdf;
class RooDataSet;
class RooRealIntegral;
class RooAcceptReject;
class TRandom;
class TIterator;

class RooProdGenContext : public RooAbsGenContext {
public:
  RooProdGenContext(const RooProdPdf &model, const RooArgSet &vars, const RooDataSet *prototype= 0,
		Bool_t _verbose= kFALSE);
  virtual ~RooProdGenContext();
  virtual RooDataSet *generate(Int_t nEvents= 0) const;


protected:

  RooProdGenContext(const RooProdGenContext& other) ;

  const RooDataSet *_prototype;  // Prototype data set
  const RooProdPdf *_pdf ;       // Original PDF
  TList _gcList ;                // List of component generator contexts

  ClassDef(RooProdGenContext,0) // Context for generating a dataset from a PDF
};

#endif
