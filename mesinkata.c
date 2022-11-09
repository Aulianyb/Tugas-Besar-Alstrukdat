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
    resetCurrWord(currentWord);
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

void resetCurrWord(Word word) {
    for (int i = 0; i < NMax; i++) {
        word.TabWord[i] = '\0';
    }
    word.Length = 0;
}

Word GetKataFirst(Word W){
    Word Kata;
    int i = 0;
    resetCurrWord(Kata);
    while ((i<W.Length) && (W.TabWord[i] != ' ')){
        if (i < NMax){
            Kata.TabWord[i] = W.TabWord[i];
            i++;
        }
    }
    Kata.Length = i;
    return Kata;
}
//Ambil Kata Pertama

Word GetKataSecond(Word W){
    Word Kata;
    int i=0;
    while ((i<W.Length) && (W.TabWord[i] != ' ')){
        i++;
    }
    i++;
    int start = i;
    Kata.Length=0; 
    while (i<W.Length){
        if (i < NMax){
            Kata.TabWord[i-start] = W.TabWord[i];
            Kata.Length++;
            i++;
        }
    }
    return Kata;
}
//Ambil Kata Terakhir

int StringLen(char *Input){
    int i=0, len=0;
    while (Input[i] != '\0'){
        i++;
        len++;
    }
    return len;
}
//Return Panjang String

boolean isWordEqual(Word W, char *W2){ 
    if (W.Length != StringLen(W2)){
        return false;
    }
    else{
        int error=0;
        for(int i=0;i < W.Length;i++){
            if(W.TabWord[i] != W2[i]){
                error++; 
            }
        }
        return (error == 0);
    }
}
//Cek apakah Kata sama dengan input yang dimasukkan

Word GetLabel(Word W){
    Word Label;
    Label.Length=0; 
    int i = 1; 
    while (i<W.Length){
        Label.TabWord[i-1] = W.TabWord[i];
        Label.Length++;
        i++;
    }
    return Label; 
}
//Ambil Label dari suatu Command

Word IntToWord(int X){
    Word Kata;
    int i=0, temp=X;
    Kata.Length=0;  
    while (X >= 10){
        Kata.TabWord[i] = (X / 10) + '0';
        Kata.Length++;
        i++;
        X %= 10; 
    }
    Kata.TabWord[i] = X + '0';
    Kata.Length++;
    return Kata;
}
//ubah INT menjadi WORD

void MergeWord(Word *W1, Word W2){
    int Len = W1->Length;
    for (int i=Len;i < Len + W2.Length;i++){
        W1->TabWord[i] = W2.TabWord[i-Len];
    }
    W1->Length += W2.Length;
}
//Menggabungkan dua kata dan menyimpannya dalam W1

void Move(Word *W1, Word W2){
    for(int i=0;i<W2.Length;i++){
        W1->TabWord[i] = W2.TabWord[i];
    }
    W1->Length = W2.Length;
}

void PrintKata(Word W){
    for (int i=0; i<W.Length ; i++){
        printf("%c", W.TabWord[i]);
    }
}

int CommandInt(Word W){
    return (WordToInt((GetLabel(GetKataSecond(currentWord))))); 
}
//PRINT KATA