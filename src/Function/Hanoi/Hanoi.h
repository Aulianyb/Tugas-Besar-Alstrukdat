#ifndef __HANOI_H__
#define __HANOI_H__

#include <stdio.h>
#include <math.h>
#include "../ADT/mesinkata.h"
#include "../ADT/stack.h"

//FUNGSI KUADRAT
int power(int n1, int n2);

//FUNGSI PRINT TIANG
void printTiang(Stack S1, Stack S2, Stack S3, int n);

//FUNGSI UNTUK CEK APAKAH TOWERNYA SUDAH BERURUTAN ATAU BELUM
boolean isTowerOrdered(Stack S, int n);

//FUNGSI UNTUK PRINT DIVIDER
void printDivider(int n);

//FUNGSI UNTUK PRINT LABEL
void printLabel(int n);

/* MOVE ELEMEN DARI S1 KE S2 */
void MoveTower(Stack *S1, Stack *S2);

//MAIN GAME
void Hanoi(int *score);

#endif