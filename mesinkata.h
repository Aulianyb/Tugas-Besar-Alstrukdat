/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarakter.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int WordToInt(Word word);
/* Mengubah kata menjadi integer
   I.S. : kata sudah diakusisi
   F.S. : kata berubah menjadi bentuk integer*/

void STARTFILE();
/*Ambil Input*/

Word GetKataFirst(Word W);
//Ambil Kata Pertama

Word GetKataSecond(Word W);
//Ambil Kata Terakhir

int StringLen(char *Input);
//Return Panjang String

boolean isWordEqual(Word W, char *W2);
//Cek apakah Kata sama dengan input yang dimasukkan

Word GetLabel(Word W);
//Ambil Label dari suatu Command

Word IntToWord(int X);
//ubah INT menjadi WORD

void MergeWord(Word *W1, Word W2);
//Menggabungkan dua kata dan menyimpannya dalam W1

void Move(Word *W1, Word W2);
//Copy W2 ke W1;

void PrintKata(Word W);
//PRINT KATA

int CommandInt(Word W);
//Ambil Label dari Input Word

#endif