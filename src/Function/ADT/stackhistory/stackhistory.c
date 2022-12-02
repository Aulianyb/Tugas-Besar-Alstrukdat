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
void PrintStackHistory(StackHistory S, int n){
    int j = 0;
    int count = Top(S) - n;
    for (int i = Top(S); i > count; i--){
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

void DeleteGameHistory(StackHistory *SH, Word word)
{
    int count = countWordInStack(SH, word);
    // printf("\nCheckpoint 1: %d\n", count);
    for (int i = 0; i < count; i++)
    {
        // printf("Checkpoint %d", i);
        int idx = FindIdxStack(*SH, word);
        DeleteAtHistory(SH, idx);
    }
}

void DeleteAtHistory(StackHistory *SH, int idx)
{
	for(int i=idx; i<=Top(*SH); i++){
		(*SH).T[i] = (*SH).T[i+1];
	}
	Top(*SH) -= 1;
}

int FindIdxStack(StackHistory SH, Word word)
{
    int count = Top(SH);
    int i = 0;
    boolean found = false;
    while (!found)
    {
        if (isWordandWordEqual(SH.T[i], word)){
            return i;
        }
        i++;
    }
    return Nil;
}

int countWordInStack(StackHistory *SH, Word word)
{
    int ctr = 0, count = Top(*SH);
    for (int i = 0; i < count+1; i++){
        if (isWordandWordEqual(SH->T[i], word)){
            ctr++;
        }
    }
    return ctr;
}