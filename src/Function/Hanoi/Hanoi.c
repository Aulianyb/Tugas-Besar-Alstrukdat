#include <stdio.h>
#include "../ADT/mesinkata.h"
#include "../ADT/stack.h"

void printTiang(Stack S1, Stack S2, Stack S3, int n){
    for (int i=n-1;i>=0;i--){
        printf("  ");
        if (i > Top(S1)){
            int j=0;
            while (j<(2*n-1)/2){
                printf(" ");
                j++;    
            }
            printf("|");
            j++;
            while (j<2*n-1){
                printf(" ");
                j++;    
            }
        }
        else{
            PrintKata(graph(S1.T[i]));
        }

        printf("       ");
        
        if (i > Top(S2)){
            int j=0;
            while (j<(2*n-1)/2){
                printf(" ");
                j++;    
            }
            printf("|");
            j++;
            while (j<2*n-1){
                printf(" ");
                j++;    
            }
        }
        else{
            PrintKata(graph(S2.T[i]));
        }

        printf("       ");

        if (i > Top(S3)){
            int j=0;
            while (j<(2*n-1)/2){
                printf(" ");
                j++;    
            }
            printf("|");
            j++;
            while (j<2*n-1){
                printf(" ");
                j++;    
            }
        }
        else{
            PrintKata(graph(S3.T[i]));
        }
        
        printf("\n");
    }
}

boolean isTowerOrdered(Stack S){
    boolean ordered=true;
    if (Top(S) == 4){
        for (int i=0;i<Top(S);i++){
            if(n(S.T[i]) < n(S.T[i+1])){
                ordered = false;
            }
        }
    }
    else{
        ordered = false;
    }
    return ordered;
}

void printDivider(int n){
    printf("+");
    for (int i=0;i<((2*n-1)*3)+20;i++){
        printf("-");
    }
    printf("+");
    printf("\n");
}

void printLabel(int n){
    printf("|");
    int j=0;
    while (j<(2*n-1)/2){
        printf(" ");
        j++;    
    }
    printf("A");
    j++;
    while (j<2*n-1){
        printf(" ");
        j++;    
    }
    printf("|");
    printf("\n");
}

/* MOVE ELEMEN DARI S1 KE S2 */
void MoveTower(Stack *S1, Stack *S2){
    infotype temp;
    Pop(S1, &temp);
    Push(S2, temp);
}

int main(){
    int n;
    printf("Sebelum mulai, tentukan jumlah disk ^_^\n");
    printf("Tentukan jumlah disk : ");
    STARTFILE();
    
    while (!isNumber(currentWord)){
        printf("\n-- INPUT INVALID, HARUS BERUPA ANGKA --\n");
        printf("Tentukan jumlah disk : ");
        STARTFILE();
    }
    n = WordToInt(currentWord);

    printf("\n\n");
    printDivider(n);
    printf("         _____ _____      _____ ___ \n");
    printf("        |_   _/ _ \\ \\    / / __| _ \\ \n");
    printf("          | || (_) \\ \\/\\/ /| _||   / \n");
    printf("          |_| \\___/ \\_/\\_/ |___|_|_\\ \n");
    printf("                / _ \\| __|           \n");
    printf("               | (_) | _|            \n");
    printf("          _  _  \\___/|_|_  ___ ___   \n");
    printf("         | || | /_\\ | \\| |/ _ \\_ _| \n");
    printf("         | __ |/ _ \\| .` | (_) | | \n");
    printf("         |_||_/_/ \\_\\_|\\_|\\___/___| \n\n");

    printDivider(n);
    printf("\n");

    //input
    Word Source, Dest; 
    infotype temp;
    int turn=0, score=10;
    Stack *SourceTiang, *DestTiang;
    Stack Tiang1, Tiang2, Tiang3; 
    boolean play=true;
    CreateEmpty(&Tiang1);
    CreateEmpty(&Tiang2);
    CreateEmpty(&Tiang3);

    Stack *AssignTiang(Word input){
    if ((WordToInt(input)) == 1){
            return &Tiang1;
        }
        else if((WordToInt(input)) == 2){
            return &Tiang2;
        }
        else if((WordToInt(input)) == 3){
            return &Tiang3;
        }
    }

    //ISI TIANG
    isiTiang(&Tiang1, n);
    isiTiang(&Tiang2, n);
    isiTiang(&Tiang3, n);


    printf("\n");
    while (play){
        boolean valid=false;
        printTiang(Tiang1, Tiang2, Tiang3, n);
        printDivider(n);
        printLabel(n);
        printDivider(n);
        printf("TURN : %d\n", turn);
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
            else if(WordToInt(Source) == WordToInt(Dest)){
                printf("-- TIANG ASAL DAN TIANG TUJUAN TIDAK BOLEH SAMA! --");
            }
            else{
                if (IsEmpty(*AssignTiang(Source))){
                    printf("-- INPUT TIDAK VALID! TIANG ASAL YANG DIPILIH KOSONG! --\n");
                }
                else{
                    if (!(IsEmpty(*AssignTiang(Dest)))&&(n(InfoTop(*AssignTiang(Source))) > n(InfoTop(*AssignTiang(Dest))))){
                        printf("-- DISK YANG DIPINDAHKAN HARUS LEBIH KECIL --\n");
                    }
                    else{
                        valid=true;                    
                    }
                }
            }
        }

        if ((turn > 31) && (turn % 3 == 0) && (score != 0)){
            score--;
        }
        
        MoveTower(AssignTiang(Source), AssignTiang(Dest));
        turn++;
        if (isTowerOrdered(Tiang3)){
            play=false;
        }
        printDivider(n);
    }
    printf("GAME OVER!\n");
    printf("SCORE : %d\n", score);
    return 0;
}