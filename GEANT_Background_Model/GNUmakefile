# $Id: GNUmakefile,v 1.2 2000-10-19 12:22:10 stanaka Exp $
# --------------------------------------------------------------
# GNUmakefile for examples module.  Gabriele Cosmo, 06/04/98.
# --------------------------------------------------------------

name := exampleB4a
G4TARGET := $(name)
G4EXLIB := true


CPPFLAGS  += -DKL_USE_ROOT=1 $(shell root-config --cflags)	#gianmarco
EXTRALIBS += $(shell root-config --libs)			#gianmarco
#EXTRALIBS += $(shell root-config --libs)			#gianmarco

#CPPFLAGS  = $(shell root-config --cflags)	#ADRIANO
#EXTRALIBS = $(shell rootb -config --libs)			#ADRIANO
#EXTRALIBS = $(shell root-config --libs --cflags)


ifndef G4INSTALL
G4INSTALL = /opt/applications/geant4/geant4.9.6
endif

.PHONY: all
all: lib bin

include $(G4INSTALL)/config/binmake.gmk

visclean:
	rm -f g4*.prim g4*.eps g4*.wrl
	rm -f .DAWN_*



