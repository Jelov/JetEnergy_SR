# Makefile for HEP Tutorial

C=c++
LD=c++

ROOTCFLAGS=$(shell root-config --cflags)
ROOTLIBS=$(shell root-config --libs)

CFLAGS =
LFLAGS =

RCXX=$(CFLAGS) $(ROOTCFLAGS)
RLXX=$(LFLAGS) $(ROOTLIBS)

#SRC1= MyAnalysis.o MyJet.o MyMuon.o MyElectron.o MyPhoton.o Plotter.o
SRC1 = MySelector.o

%.o: %.C %.h
    $(C) $(RCXX) -c $<

#all: example
#all: JetE_S

#example.o: example.C MyAnalysis.h
JetE_S.o: JetE_S.C MySelector.h
    $(C) $(RCXX) -c $<

JetE_S: $(SRC1) JetE_S.o
    $(LD) $(SRC1) JetE_S.o $(RLXX) -o JetE_S.x
    @echo '-> JetE_S.x created!'

clean:
    @rm -f *~
    @rm -f *.o 
    @rm -f *.x



