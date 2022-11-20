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
    int j = 0;
    for (int i = Top(S); i > -1; i--){
        printf("%d. ", j+1);
        PrintKata(S.T[i]);
        printf("\n");
        j++;
    }
}

/* ************ Melakukan swap elemen pada stack ************ */
void SwapStackHistory(StackHistory S, StackHistory *Sout){
    Word val;
    int count = Top(S);
    for (int i = 0; i < count+1; i++){
        PopHistory(&S, &val); 
        PushHistory(Sout, val);
    }
}