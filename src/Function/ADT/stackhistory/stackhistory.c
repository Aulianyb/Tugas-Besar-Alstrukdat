#include "stackhistory.h"
#include <stdio.h>

void CreateEmptyHistory(StackHistory *S){
    S->TOP = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyHistory(StackHistory S){
    return (Top(S) == Nil);
}

boolean IsFullHistory(StackHistory S){
    return (Top(S) == (MaxElStack-1));
}

/* ************ Menambahkan sebuah elemen ke StackHistory ************ */
void PushHistory(StackHistory *S, Word X){
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen StackHistory ************ */
void PopHistory(StackHistory *S, Word* X){
    *X = InfoTop(*S);
    Top(*S) -= 1;
}

/* ************ Menulis seluruh elemen StackHistory ************ */
void PrintStackHistory(StackHistory S){
    for (int i = 0; i < Top(S)+1; i++){
        printf("%d. ", i+1);
        PrintKata(S.T[i]);
        printf("\n");
    }
}