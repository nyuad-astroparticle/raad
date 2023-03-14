/***********************************************************
LIGHT-1 Background Simulation > Analysis Manager
------------------------------------------------------------

Here is where we would have defined our custom Analysis
Manager, i.e. the object that takes the data and saves them
to a file. However, we are using a predefined one from 
Geant4. All this file is doing, is changing its name. Thanks 
Danish......................................................

For any help please contact Panos: po524@nyu.edu
***********************************************************/

#ifndef AnalysisManager_h
#define AnalysisManager_h

#include "G4CsvAnalysisManager.hh"

using G4AnalysisManager = G4CsvAnalysisManager;

#endif