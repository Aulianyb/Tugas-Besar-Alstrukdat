#ifndef CONSOLE_H
#define CONSOLE_H

#include "mesinkata.h"
#include "mesinkarakter.h"
#include "array.h"
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

void loadGAME(char* filename, TabGame *listGame);
// Melakukan pembacaan file

void startGAME(TabGame *listGame);
// Melakukan pembacaan file config

void saveGAME(char* filename, TabGame listGame);
// Melakukan penyimpanan pada file

#endif