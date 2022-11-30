#ifndef RPC_H
#define RPC_H

#include "../../random_generator.h"
#include "../ADT/mesinkata.h"
#include <stdio.h>
#include "../ADT/array.h"

boolean validRock(Word word);
/*Menghasilkan true apabila currentWord berisi kata "rock" yang valid*/

boolean validPaper(Word word);
/*Menghasilkan true apabila currentWord berisi kata "paper" yang valid*/

boolean validScissor(Word word);
/*Menghasilkan true apabila currentWord berisi kata "scissor" yang valid*/

void RockPaperScissor(int *score);
/*Memainkan permainan rock-paper-scissor dan menampilkan hasil akhir dari permainan.
  Permainan terdiri dari 11 ronde.
  Bila poin player > poin lawan, menampilkan player menang ke layar.
  Bila poin player < poin lawan, menampilkan player kalah ke layar.
  Bila poin player = poin lawan, menampilkan player dan lawan seri ke layar.*/
#endif