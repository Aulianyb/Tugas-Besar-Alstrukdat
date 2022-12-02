#include "Hanoi.h"
/* Prosedur printTiang mencetak ketiga tiang untuk display game */
void printTiang(Stack S1, Stack S2, Stack S3, int n){
    for (int i=n-1;i>=0;i--){
        printf(" ");
        if (i > Top(S1)){
            int j=0;
            while (j<(2*n-1)/2){
                printf(" ");
                j++;    
            }
            printf("|");
            j++;
            while (j<(2*n-1)){
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

/* Fungsi isTowerOrdered yang melakukan cek bila Stack sudah berurutan atau belum */
boolean isTowerOrdered(Stack S, int n){
    boolean ordered=true;
    if (Top(S) == n-1){
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

/* Fungsi printDivider mencetak divider sesuai panjang n */
void printDivider(int n){
    printf("+");
    for (int i=0;i<((2*n-1)*3)+20;i++){
        printf("-");
    }
    printf("+");
    printf("\n");
}

/* Fungsi printLabel mencetak label untuk setiap menara */
void printLabel(int n){
    printf("|");
    int j=0;
    int len=0;
    for (int i=0;i<3;i++){
        while (j<((2*n-1)/2)){
            printf(" ");
            j++;  
            len++;  
        }
        switch (i)
        {
        case 0:
            printf("A");
            break;
        
        case 1:
            printf("B");
            break;
        case 2:
            printf("C");
            break;
        default:
            break;
        }
        j++;
        len++;  
        while (j<(2*n-1)){
            printf(" ");
            j++;
            len++;  
        }
        j=0;  
        if (i < 2){
           printf("   |   ");
            len+=8;   
        }   
    } 
    while (len<((2*n-1)*3)+22){
        printf(" ");
        len++; 
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
//MAIN GAME
void Hanoi(int *score){
    *score = 10; 
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
    printDivider(12);
    printf("|  _____  _____  _ _ _  _____  _____   _____  _____   _____  _____  _____  _____  _____   |\n");
    printf("| |_   _||     || | | ||   __|| __  | |     ||   __| |  |  ||  _  ||   | ||     ||     |  |\n");
    printf("|   | |  |  |  || | | ||   __||    -| |  |  ||   __| |     ||     || | | ||  |  ||-   -|  |\n");
    printf("|   |_|  |_____||_____||_____||__|__| |_____||__|    |__|__||__|__||_|___||_____||_____|  |\n|                                                                                         |\n");
    printDivider(12);
    printf("\n");

    //input
    Word Source, Dest; 
    infotype temp;
    int turn=0, min_steps = pow(2, n) - 1;
    Stack *SourceTiang, *DestTiang;
    Stack Tiang1, Tiang2, Tiang3; 
    boolean play=true;
    CreateEmpty(&Tiang1);
    CreateEmpty(&Tiang2);
    CreateEmpty(&Tiang3);

    /* Fungsi AssignTiang mengembalikan Tiang/Stack berdasarkan input */
    Stack *AssignTiang(Word input){
    if (isWordEqual(input, "A")){
            return &Tiang1;
        }
        else if(isWordEqual(input, "B")){
            return &Tiang2;
        }
        else if(isWordEqual(input, "C")){
            return &Tiang3;
        }
    }

    infotype val;

    //ISI TIANG
    isiTiang(&Tiang1, n);

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
            boolean Source_valid = isWordEqual(Source, "A") || isWordEqual(Source, "B") || isWordEqual(Source, "C");
            boolean Dest_valid = isWordEqual(Dest, "A") || isWordEqual(Dest, "B") || isWordEqual(Dest, "C");
            
            /* Validasi Input */
            if (!(Source_valid && Dest_valid)){
                printf("-- INPUT TIDAK VALID! MASUKKAN A, B ATAU C! --\n");
            }
            else if(isTwoWordEqual(Dest, Source)){
                printf("-- TIANG ASAL DAN TIANG TUJUAN TIDAK BOLEH SAMA! --\n");
            }
            else{
                if (IsEmpty_S(*AssignTiang(Source))){
                    printf("-- INPUT TIDAK VALID! TIANG ASAL YANG DIPILIH KOSONG! --\n");
                }
                else{
                    if (!(IsEmpty_S(*AssignTiang(Dest)))&&(n(InfoTop(*AssignTiang(Source))) > n(InfoTop(*AssignTiang(Dest))))){
                        printf("-- DISK YANG DIPINDAHKAN HARUS LEBIH KECIL --\n");
                    }
                    else{
                        valid=true;                    
                    }
                }
            }
        }

        /* Update Score */
        if ((turn > min_steps) && (turn % (n/2) == 0) && (*score != 0)){
            *score--;
        }
    
        MoveTower(AssignTiang(Source), AssignTiang(Dest));
        turn++;
        
        /* Cek Kondisi Tower */
        if (isTowerOrdered(Tiang3, n)){
            play=false;
        }
        printDivider(n);
        printf("\n");
    }
    printf("  _____ _____ _____ _____    _____ _____ _____ _____ \n");
	printf(" |   __|  _  |     |   __|  |     |  |  |   __| __  |\n");
	printf(" |  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n");
	printf(" |_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n");
    printf("SCORE : %d\n", *score);
}