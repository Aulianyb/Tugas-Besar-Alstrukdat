#include <stdio.h>
#include "../ADT/mesinkata.h"
#include "../ADT/stack.h"

void printTiang(Stack S1, Stack S2, Stack S3){
    for (int i=4;i>=0;i--){
        printf("%d",Top(S1));
        if (i > Top(S1)){
            printf("    |    ");
        }
        else{
            PrintKata(graph(S1.T[i]));
        }
        
        printf("%d",Top(S2));
        if (i > Top(S2)){
            printf("    |    ");
        }
        else{
            PrintKata(graph(S2.T[i]));
        }

        printf("%d",Top(S3));
        if (i > Top(S3)){
            printf("    |    ");
        }
        else{
            PrintKata(graph(S3.T[i]));
        }
        
        printf("\n");
    }
}

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
    Stack Tiang1, Tiang2, Tiang3; 
    CreateEmpty(&Tiang1);
    CreateEmpty(&Tiang2);
    CreateEmpty(&Tiang3);

    //ISI TIANG 1
    for (int i=5;i>=1;i--){
        Push(&Tiang1, makeInfo(i));
    }

    //ISI TIANG 2, 3

    // printf("TIANG ASAL : ");
    // STARTFILE();
    // Source = currentWord;
    // printf("TIANG TUJUAN : ");
    // STARTFILE();
    // Dest = currentWord;


    printf("BEFORE : \n");
    printTiang(Tiang1, Tiang2, Tiang3);
    MoveTower(&Tiang1, &Tiang2);
    MoveTower(&Tiang1, &Tiang3);
    MoveTower(&Tiang1, &Tiang3);
    printf("AFTER\n");
    printTiang(Tiang1, Tiang2, Tiang3);

    return 0;
}