#include <stdio.h>
#include "../ADT/mesinkata.h"
#include "../ADT/stack.h"

void printTiang(Stack S1, Stack S2, Stack S3){
    for (int i=4;i>=0;i--){
        if (i > Top(S1)){
            printf("    |    ");
        }
        else{
            PrintKata(graph(S1.T[i]));
        }
        
        if (i > Top(S2)){
            printf("    |    ");
        }
        else{
            PrintKata(graph(S2.T[i]));
        }

        if (i > Top(S3)){
            printf("    |    ");
        }
        else{
            PrintKata(graph(S3.T[i]));
        }
        
        printf("\n");
    }
}

Stack *AssignTiang(Word input, Stack *S1, Stack *S2, Stack *S3){
    if ((WordToInt(input)) == 1){
            return S1;
        }
        else if((WordToInt(input)) == 2){
            return S2;
        }
        else if((WordToInt(input)) == 3){
            return S3;
        }
}

/* MOVE ELEMEN DARI S1 KE S2 */
void MoveTower(Stack *S1, Stack *S2){
    infotype temp;
    Pop(S1, &temp);
    Push(S2, temp);
}

int main(){
    printf("\n\n");
    printf("+ = + = + = + = + = + = + = + = + = + = + = + =\n\n");
    printf("          _____ _____      _____ ___ \n");
    printf("         |_   _/ _ \\ \\    / / __| _ \\ \n");
    printf("           | || (_) \\ \\/\\/ /| _||   / \n");
    printf("           |_| \\___/ \\_/\\_/ |___|_|_\\ \n");
    printf("                 / _ \\| __|           \n");
    printf("                | (_) | _|            \n");
    printf("           _  _  \\___/|_|_  ___ ___   \n");
    printf("          | || | /_\\ | \\| |/ _ \\_ _| \n");
    printf("          | __ |/ _ \\| .` | (_) | | \n");
    printf("          |_||_/_/ \\_\\_|\\_|\\___/___| \n\n");

    printf("+ = + = + = + = + = + = + = + = + = + = + = + =\n");
    printf("\n\n");
    
    //input
    Word Source, Dest; 
    infotype temp;
    Stack *SourceTiang, *DestTiang;
    Stack Tiang1, Tiang2, Tiang3; 
    boolean play=true;
    CreateEmpty(&Tiang1);
    CreateEmpty(&Tiang2);
    CreateEmpty(&Tiang3);
    //ISI TIANG 1
    for (int i=5;i>=1;i--){
        Push(&Tiang1, makeInfo(i));
    }

    while (play){
        boolean valid=false;
        printTiang(Tiang1, Tiang2, Tiang3);
        while (!valid){
            printf("TIANG ASAL : ");
            STARTFILE();
            Source = currentWord;
            printf("TIANG TUJUAN : ");
            STARTFILE();
            Dest = currentWord;
            if ((1 > WordToInt(Source)) || (WordToInt(Source) > 3) || (1 > WordToInt(Dest)) || (WordToInt(Dest) > 3)){
                printf("-- INPUT TIDAK VALID! MASUKKAN 1, 2 ATAU 3! --\n");
            }
            else{
                if (IsEmpty(*AssignTiang(Source, &Tiang1, &Tiang2, &Tiang3))){
                    printf("-- INPUT TIDAK VALID! TIANG ASAL YANG DIPILIH KOSONG! --\n");
                }
                else{
                    valid=true;
                }
            }
        }
        
        MoveTower(AssignTiang(Source, &Tiang1, &Tiang2, &Tiang3), AssignTiang(Dest, &Tiang1, &Tiang2, &Tiang3) );
    }

    return 0;
}