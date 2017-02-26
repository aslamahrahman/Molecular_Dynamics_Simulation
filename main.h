#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>

#include"types.h"

//UTILITIES
void setfiles(int args, char *argv[]);
double *create1Darray(int nx);
void readinput(void);
void printoutput(void);
void allocatememory(void);

//SIMULATION
void initialization(int initpos, int initvelocity);
void forcecalculation(void);
void energycalculation(void);
void velocityrescale(int thermotype);
void boundaryupdate(int initboundary);
void stepahead(void);
void rdfcalculation(void);
void freememory(void);

//SYSTEM PARAMETERS
int n, runs;
double dt; 
double runtime;
int thermotype, initpos, initvelocity, initboundary;
particle atom, atom0, atomhalf;
double fx, fy, fz;
double *inittemp;
double mass, rho; 
double temp, temp0; 
double pressure, ke, pe, te;
double lbox, bbox, hbox; 
double tau; 
double nu; 
double *hist, *rdf, *rbin;

//SCALING FACTORS
double sfmass;
double sfenergy, sftemp, sfpressure;
double sfl, sfp, sft;

//CONSTANTS
const double kb = 1.0;
const long double sfkb = 1.38064852e-23; //kgm+2s-2K-1
const long double sfn0 = 6.0221409e23;
const int maxbin = 200;
const double pi = 3.1415926;

//LJ PARAMETERS
double epsi, sigma, rcutoff;

//INPUT FILE
char parfile[100], initfile[100];