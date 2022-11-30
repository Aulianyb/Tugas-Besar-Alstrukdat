#ifndef CONSOLE_H
#define CONSOLE_H

#include "Function/ADT/mesinkata.h"
#include "Function/ADT/mesinkarakter.h"
#include "Function/ADT/array.h"
#include "Function/ADT/stackhistory/stackhistory.h"
#include "Function/ADT/map/map.h"
#include "Function/ADT/arrayofmap/arrayofmap.h"
#include "random_generator.h"
#include <stdio.h>
#include <stdlib.h>

#define FILEMARK '\n'

static FILE *fptr;
static int retval;

void quit();
/* keluar dari program */

/* ----- IMPLEMENTASI MESINKATA UNTUK FUNGSI LOAD -----*/
void startLOAD(char* filename);
 
void IgnoreFILEMARK();

void ADVWORDLOAD();

void CopyWORDLOAD();

void ADVLOAD();

/* ----- IMPLEMENTASI FILE HANDLING DALAM PROGRAM -----*/
char* wordToString(Word word);
// Melakukan convert dari ADT Word ke string

int wordtoInt(Word word);
// Melakukan convert dari ADT Word ke integer

void loadGAME(char* filename, TabGame *listGame, StackHistory *SH, TabScore *TS);
// Melakukan pembacaan file

void startGAME(TabGame *listGame, StackHistory *SH, TabScore *TS);
// Melakukan pembacaan file config

void saveGAME(char* filename, TabGame listGame, StackHistory SH, TabScore TS);
// Melakukan penyimpanan pada file

#endif