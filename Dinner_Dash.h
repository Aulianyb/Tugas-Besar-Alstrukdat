#ifndef DINNER_DASH_H
#define DINNER_DASH_H

#include <stdio.h>
#include "boolean.h"
#include "array_pesanan.h"
#include "queue_cook.h"
#include "random_generator.h"
#include "mesinkata.h"

boolean isCook(Word Kata);
/* Mengembalikan apakah kata input merupakan "COOK" atau bukan */

boolean isServe(Word Kata);
/* Mengembalikan apakah kata input merupakan "SERVE" atau bukan*/

void buat_pesanan(Tab *T, int label);
/* Membuat Pesanan berdasarkan input */

void Dinner_Dash();
//MAIN GAME

#endif