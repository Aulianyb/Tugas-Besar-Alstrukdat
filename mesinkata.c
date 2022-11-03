#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
	/* Mengabaikan satu atau beberapa BLANK
   	I.S. : currentChar sembarang
   	F.S. : currentChar ≠ BLANK atau currentChar = MARK */
	while (currentChar == BLANK){
		ADV();
	}
}


void STARTWORD(){
	/* I.S. : currentChar sembarang
   	F.S. : EndWord = true, dan currentChar = MARK;
    atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
    currentChar karakter pertama sesudah karakter terakhir kata */
    START();
   	IgnoreBlanks();
   	if (currentChar == MARK){
   		EndWord = true;
   	} 
   	else {
   		EndWord = false;
   		CopyWord();
   	}
}


void ADVWORD(){
	/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   	F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
    currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
    Jika currentChar = MARK, EndWord = true.
   	Proses : Akuisisi kata menggunakan procedure SalinWord */
   	IgnoreBlanks();
   	if(currentChar == MARK){
   		EndWord = true;
   	}
   	else{
   		CopyWord();
   		IgnoreBlanks();
   	}
}

void CopyWord(){
	/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	int i = 0;
	while ((currentChar != MARK) && (currentChar != '\n')){
		if (i < NMax){
			currentWord.TabWord[i] = currentChar;
			i++;
		}
		ADV();
	}
	currentWord.Length = i; 
}

int WordToInt(Word word)
{
    int hasil = 0;
    hasil += word.TabWord[0] - 48;
    if (word.Length > 1)
    {
        for (int i = 1; i < word.Length; i++)
        {
            hasil *= 10;
            hasil += word.TabWord[i] - 48;
        }
    }
    return hasil;
}

void STARTFILE()
{
    START();
    if (currentChar == '\0')
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}
