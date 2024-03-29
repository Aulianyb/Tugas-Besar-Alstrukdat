#include "snakeOnMeteor.h"
#include <stdio.h>
#include "../ADT/listdp.h"

boolean isMoveValid(Word word) {
    /* Mengecek input yang valid */
    return (isWordEqual(word,"w") || isWordEqual(word,"W") || isWordEqual(word,"a") || isWordEqual(word,"A") ||
    isWordEqual(word,"s") || isWordEqual(word,"S") || isWordEqual(word,"d") || isWordEqual(word,"D"));
}

void MoveSnake(List *L, POINT meteor, Word input, char keyword, boolean* valid) {
    /* Menggerakkan badan Snake */
    if (keyword == 'w') {
        if (Ordinat(First(*L)->point) == 0 && !SearchPointInGrid(meteor,Absis(First(*L)->point),4)) {
            InsVFirst(L,0,Absis(First(*L)->point),4);
            *valid = true;
        }
        else {
            if (!SearchPointInGrid(meteor,Absis(First(*L)->point),(Ordinat(First(*L)->point)-1)%5)) {
                InsVFirst(L,0,Absis(First(*L)->point),(Ordinat(First(*L)->point)-1)%5);
                *valid = true;
            }
            else {
                *valid = false;
            }
        }
    }
    else if (keyword == 'a'){
        if (Absis(First(*L)->point) == 0 && !SearchPointInGrid(meteor,4,Ordinat(First(*L)->point))) {
            InsVFirst(L,0,4,Ordinat(First(*L)->point));
            *valid = true;
        }
        else {
            if (!SearchPointInGrid(meteor,(Absis(First(*L)->point)-1)%5,Ordinat(First(*L)->point))) {
                InsVFirst(L,0,(Absis(First(*L)->point)-1)%5,Ordinat(First(*L)->point));
                *valid = true;
            }
            else {
                *valid = false;
            }
        }
    }
    else if (keyword == 's') {
        if (!SearchPointInGrid(meteor,Absis(First(*L)->point),(Ordinat(First(*L)->point)+1)%5)) {
            InsVFirst(L,0,Absis(First(*L)->point),(Ordinat(First(*L)->point)+1)%5);
            *valid = true;
        }
        else {
            *valid = false;
        }
    }
    else if (keyword == 'd') {
        if (!SearchPointInGrid(meteor,(Absis(First(*L)->point)+1)%5,Ordinat(First(*L)->point))) {
            InsVFirst(L,0,(Absis(First(*L)->point)+1)%5,Ordinat(First(*L)->point));
            *valid = true;
        }
        else {
            *valid = false;
        }
    }

    if (*valid) {
        address_L p = Next(First(*L));
        while (p != Last(*L)) {
            Info(p) = Info(Next(p));
            p = Next(p);
        }
        DelLast(L,&p);
    }
}

void AddBody(List *L, int abs, int ord, List obstacle, POINT food, POINT meteor, boolean* emptySpace) {
    /* Menambahkan badan Snake */
    int insAbs = abs;
    int insOrd = ord;
    if ((abs - 1) >= 0 && !SearchPoint(*L,abs-1,ord) && !SearchPoint(obstacle,abs-1,ord) && !SearchPointInGrid(food,abs-1,ord) && !SearchPointInGrid(meteor,abs-1,ord)) {
        insAbs = abs - 1;
        *emptySpace = true;
    }
    else {
        if ((ord - 1) >= 0 && !SearchPoint(*L,abs,ord-1) && !SearchPoint(obstacle,abs,ord-1) && !SearchPointInGrid(food,abs,ord-1) && !SearchPointInGrid(meteor,abs,ord-1)) {
            insOrd = ord - 1;
            *emptySpace = true;
        }
        else if ((ord + 1) <= 4 && !SearchPoint(*L,abs,ord+1) && !SearchPoint(obstacle,abs,ord+1) && !SearchPointInGrid(food,abs,ord+1) && !SearchPointInGrid(meteor,abs,ord+1)) {
            insOrd = ord + 1;
            *emptySpace = true;
        }
        else {
            if ((abs + 1) <= 4 && !SearchPoint(*L,abs+1,ord) && !SearchPoint(obstacle,abs+1,ord) && !SearchPointInGrid(food,abs+1,ord) && !SearchPointInGrid(meteor,abs+1,ord)) {
                insAbs = abs + 1;
                *emptySpace = true;
            }
            else {
                *emptySpace = false;
            }
        }
    }

    if (!SearchPoint(*L,insAbs,insOrd)) {
        address_L p = Alokasi(Info(Last(*L))+1,insAbs,insOrd);
        InsertLast(L,p);
    }
}

void spawnObstacle(List *obstacle) {
    /* Mengenerate obstacle ke dalam permainan */
    int numObs = GenRand(1,3,4);
    POINT tempObs;

    for (int i = 0; i < numObs; i++) {
        Absis(tempObs) = GenRand(0,4,5);
        Ordinat(tempObs) = GenRand(0,4,5);
        while (SearchPoint(*obstacle,Absis(tempObs),Ordinat(tempObs))) {
            Absis(tempObs) = GenRand(0,4,5);
            Ordinat(tempObs) = GenRand(0,4,5);
        }
        address_L p = Alokasi(i+1,Absis(tempObs),Ordinat(tempObs));
        InsertLast(obstacle,p);
    }
}

void spawnFood(List L, List Obs, POINT meteor, POINT *food) {
    /* Mengenerate Food ke dalam permainan */
    Absis(*food) = GenRand(0,4,5);
    Ordinat(*food) = GenRand(0,4,5);

    while (SearchPoint(L,Absis(*food),Ordinat(*food)) || SearchPoint(Obs,Absis(*food),Ordinat(*food)) || (Absis(*food) == Absis(meteor) && Ordinat(*food) == Ordinat(meteor))) {
        Absis(*food) = GenRand(0,4,5);
        Ordinat(*food) = GenRand(0,4,5);
    }
}

void spawnMeteor(List obstacle, POINT food, POINT *meteor, int prevAbs, int prevOrd) {
    /* Mengenerate Meteor ke dalam permainan */
    Absis(*meteor) = GenRand(0,4,5);
    Ordinat(*meteor) = GenRand(0,4,5);

    while (SearchPoint(obstacle,Absis(*meteor),Ordinat(*meteor)) || (Absis(*meteor) == Absis(food) && Ordinat(*meteor) == Ordinat(food)) || (Absis(*meteor) == prevAbs && Ordinat(*meteor) == prevOrd)) {
        Absis(*meteor) = GenRand(0,4,5);
        Ordinat(*meteor) = GenRand(0,4,5);
    }
}

void PrintGrid(List L, List obs, POINT food, POINT meteor) {
    /* Menampilkan isi grid/peta permainan */
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 5; i++) {
            address_L p = SearchAdrPoint(L,i,j);
            if (Absis(meteor) == i && Ordinat(meteor) == j) {
                printf("[m ]");
            }
            else if (p != Nil_L) {
                if (Info(p) == 0) {
                    printf("[H ]");
                }
                else {
                    if (Info(p) < 10) {
                        printf("[%d ]",Info(p));
                    }
                    else {
                        printf("[%d]",Info(p));
                    }
                }
            }
            else {
                address_L q = SearchAdrPoint(obs,i,j);
                if (q != Nil_L) {
                    printf("[X ]");
                }
                else {
                    if (Absis(food) == i && Ordinat(food) == j) {
                        printf("[o ]");
                    }
                    else {
                        printf("[  ]");
                    }
                }
            }
        }
        printf("\n");
    }
}


void SnakeOnMeteor(int *score) {
    /* ### Print Intro Screen ### */
    printf("Selamat datang di . . .\n");
    printf("  ___ _  _   _   _  _____    ___  _  _ \n");
    printf(" / __| \\| | /_\\ | |/ / __|  / _ \\| \\| |\n");
    printf(" \\__ \\ .` |/ _ \\| ' <| _|  | (_) | .` |\n");
    printf(" |___/_|\\_/_/_\\_\\_|\\_\\___|  \\___/|_|\\_|\n");
    printf(" |  \\/  | __|_   _| __/ _ \\| _ \\       \n");
    printf(" | |\\/| | _|  | | | _| (_) |   /       \n");
    printf(" |_|  |_|___| |_| |___\\___/|_|_\\       \n");
    printf("Mengenerate peta, snake, obstacle, dan makanan...\n");
    printf("Berhasil digenerate!\n");
    
    /* Inisialisasi turn */
    int turn = 1;

    /* Inisialisasi boolean yang digunakan dalam permainan */
    boolean GameOver = false;
    boolean isEmptySpace = true;
    boolean moveValid = true;
    boolean hit = false;
    boolean stopGrow = false;
    boolean hitObstacle = false;

    /* ### Inisialisasi Obstacle ### */
    List Obstacle;
    CreateEmpty_L(&Obstacle);
    spawnObstacle(&Obstacle);

    /* ### Inisialisasi Food dan Meteor ### */
    POINT Food;
    POINT Meteor;
    /* Placeholder Meteor */
    Absis(Meteor) = -1;
    Ordinat(Meteor) = -1;
    /* Placeholder Food */
    Absis(Food) = -1;
    Ordinat(Food) = -1;

    /* ### Inisialisasi Snake ### */
    List Snake;
    CreateEmpty_L(&Snake);
    int absHead = GenRand(0,4,5);
    int ordHead = GenRand(0,4,5);
    while (SearchPoint(Obstacle,absHead,ordHead)) {
        absHead = GenRand(0,4,5);
        ordHead = GenRand(0,4,5);
    }
    address_L p = Alokasi(0,absHead,ordHead);
    InsertFirst(&Snake,p);
    AddBody(&Snake,Absis(Last(Snake)->point),Ordinat(Last(Snake)->point),Obstacle,Food,Meteor,&isEmptySpace);
    AddBody(&Snake,Absis(Last(Snake)->point),Ordinat(Last(Snake)->point),Obstacle,Food,Meteor,&isEmptySpace);

    /* ### Spawn Food Pertama Kali ### */
    spawnFood(Snake,Obstacle,Meteor,&Food);

    /* ### Print Grid Pertama Kali ### */
    printf("Berikut merupakan peta permainan:\n");
    PrintGrid(Snake,Obstacle,Food,Meteor);
    printf("\n");

    /* Core Loop dari permainan Snake On Meteor*/
    while (!GameOver) {
        printf("TURN %d\n",turn);
        printf("Masukkan gerakan : ");
        STARTFILE();

        moveValid = true;
        hit = false;
        boolean valid = false;
        while (!valid) {
            /* Mengecek apakah input valid */
            if (!isMoveValid(currentWord)) {
                printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                STARTFILE();
            }
            else {
                /* Mengecek gerakan yang sesuai dengan input yang diberikan pengguna */
                if (isWordEqual(currentWord,"a") || isWordEqual(currentWord,"A")) {
                    if (Absis(First(Snake)->point)-1 >= 0) {
                        if (SearchPoint(Snake,(Absis(First(Snake)->point)-1)%5,Ordinat(First(Snake)->point))) {
                            printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                            STARTFILE();
                        }
                        else {
                            valid = true;
                            MoveSnake(&Snake, Meteor, currentWord,'a',&moveValid);
                            if (moveValid) {
                                printf("Berhasil bergerak!\n");
                            }
                            else {
                                valid = false;
                                printf("Meteor masih panas! Anda belum dapat pergi ke titik tersebut.\n");
                                printf("Silahkan masukkan command lainnya\n");
                                printf("Masukkan gerakan : ");
                                STARTFILE();
                            }
                        }
                    }
                    else {
                        if (SearchPoint(Snake,4,Ordinat(First(Snake)->point))) {
                            printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                            STARTFILE();
                        }
                        else {
                            valid = true;
                            MoveSnake(&Snake, Meteor, currentWord,'a',&moveValid);
                            if (moveValid) {
                                printf("Berhasil bergerak!\n");
                            }
                            else {
                                valid = false;
                                printf("Meteor masih panas! Anda belum dapat pergi ke titik tersebut.\n");
                                printf("Silahkan masukkan command lainnya\n");
                                printf("Masukkan gerakan : ");
                                STARTFILE();
                            }
                        }
                    }
                }
                else if (isWordEqual(currentWord,"w") || isWordEqual(currentWord,"W")) {
                    if (Ordinat(First(Snake)->point)-1 >= 0) {
                        if (SearchPoint(Snake,Absis(First(Snake)->point),(Ordinat(First(Snake)->point)-1)%5)) {
                            printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                            STARTFILE();
                        }
                        else {
                            valid = true;
                            MoveSnake(&Snake, Meteor, currentWord,'w',&moveValid);
                            if (moveValid) {
                                printf("Berhasil bergerak!\n");
                            }
                            else {
                                valid = false;
                                printf("Meteor masih panas! Anda belum dapat pergi ke titik tersebut.\n");
                                printf("Silahkan masukkan command lainnya\n");
                                printf("Masukkan gerakan : ");
                                STARTFILE();
                            }
                        }
                    }
                    else {
                        if (SearchPoint(Snake,Absis(First(Snake)->point),4)) {
                            printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                            STARTFILE();
                        }
                        else {
                            valid = true;
                            MoveSnake(&Snake, Meteor, currentWord,'w',&moveValid);
                            if (moveValid) {
                                printf("Berhasil bergerak!\n");
                            }
                            else {
                                valid = false;
                                printf("Meteor masih panas! Anda belum dapat pergi ke titik tersebut.\n");
                                printf("Silahkan masukkan command lainnya\n");
                                printf("Masukkan gerakan : ");
                                STARTFILE();
                            }
                        }
                    }
                }
                else if (isWordEqual(currentWord,"s") || isWordEqual(currentWord,"S")) {
                    if (SearchPoint(Snake,Absis(First(Snake)->point),(Ordinat(First(Snake)->point)+1)%5)) {
                        printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                        STARTFILE();
                    }
                    else {
                        valid = true;
                        MoveSnake(&Snake, Meteor, currentWord,'s',&moveValid);
                        if (moveValid) {
                            printf("Berhasil bergerak!\n");
                        }
                        else {
                            valid = false;
                            printf("Meteor masih panas! Anda belum dapat pergi ke titik tersebut.\n");
                            printf("Silahkan masukkan command lainnya\n");
                            printf("Masukkan gerakan : ");
                            STARTFILE();
                        }
                    }
                }
                else if (isWordEqual(currentWord,"d") || isWordEqual(currentWord,"D")) {
                    if (SearchPoint(Snake,(Absis(First(Snake)->point)+1)%5,Ordinat(First(Snake)->point))) {
                        printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                        STARTFILE();
                    }
                    else {
                        valid = true;
                        MoveSnake(&Snake, Meteor, currentWord,'d',&moveValid);
                        if (moveValid) {
                            printf("Berhasil bergerak!\n");
                        }
                        else {
                            valid = false;
                            printf("Meteor masih panas! Anda belum dapat pergi ke titik tersebut.\n");
                            printf("Silahkan masukkan command lainnya\n");
                            printf("Masukkan gerakan : ");
                            STARTFILE();
                        }
                    }
                }
            }
        }
        /* Men-generate meteor */
        spawnMeteor(Obstacle,Food,&Meteor,Absis(Meteor),Ordinat(Meteor));

        /* Mengecek apabila Head memakan food, maka badan bertambah panjang (apabila masih bisa menambah panjang) */
        if (Absis(First(Snake)->point) == Absis(Food) && Ordinat(First(Snake)->point) == Ordinat(Food)) {
            if (isEmptySpace) {
                /* Bila berhasil (masih ada slot tersedia untuk penambahan panjang badan) */
                AddBody(&Snake,Absis(Last(Snake)->point),Ordinat(Last(Snake)->point),Obstacle,Food,Meteor,&isEmptySpace);
                spawnFood(Snake,Obstacle,Meteor,&Food);
            }
            else {
                /* Bila gagal (POINT yang adjacent dengan tail sudah terisi semua) */
                stopGrow = true;
                GameOver = true;
            }
        }
        /* Mengecek apabila Head menabrak obstacle */
        if (SearchPoint(Obstacle,Absis(First(Snake)->point),Ordinat(First(Snake)->point))) {
            hitObstacle = true;
            GameOver = true;
        }
        /* Mengecek apabila ada bagian badan Snake yang terkena Meteor */
        if (SearchPoint(Snake,Absis(Meteor),Ordinat(Meteor))) {
            hit = true;
            address_L loc = SearchAdrPoint(Snake,Absis(Meteor),Ordinat(Meteor));
            if (loc == First(Snake)) {
                /* Bila mengenai kepala, game berakhir */
                printf("Kepala Anda terkena meteor! Permainan berakhir!\n");
                DelP(&Snake,Info(loc));
                GameOver = true;
            }
            else {
                /* Bila mengenai badan, panjang badan berkurang satu */
                printf("Berikut merupakan peta permainan:\n");
                PrintGrid(Snake,Obstacle,Food,Meteor);
                printf("\n");
                printf("Anda terkena meteor!\n");
                address_L updInfo = Next(loc);
                DelP(&Snake,Info(loc));
                while (updInfo != Nil_L) {
                    Info(updInfo) -= 1;
                    updInfo = Next(updInfo);
                }
            }
        }

        /* Menampilak Grid/Peta permainan di akhir Turn */
        printf("Berikut merupakan peta permainan:\n");
        PrintGrid(Snake,Obstacle,Food,Meteor);
        printf("\n");

        /* Bila Meteor mengenai badan */
        if (hit) {
            printf("Silahkan lanjutkan permainan\n");
            printf("\n");
        }
        /* Bila tidak ada tempat lagi untuk pertumbuhan panjang badan Snake */
        else if (stopGrow) {
            printf("Tidak ada tempat untuk penambahan panjang tubuh snake. Permainan berakhir!\n");
            printf("\n");
        }
        /* Bila Head dari Snake menabrak obstacle */
        else if (hitObstacle) {
            printf("Anda menabrak obstacle! Permainan berakhir!\n");
            printf("\n");
        }
        /* Bila tidak terjadi apa-apa */
        else {
            printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
            printf("\n");
        }

        /* Apabila Snake sudah tidak bisa bergerak kemana-mana lagi, maka permainan berakhir */
        if (SearchPoint(Snake,(Absis(First(Snake)->point)+1)%5,Ordinat(First(Snake)->point)) && SearchPointInGrid(Meteor,Absis(First(Snake)->point),(Ordinat(First(Snake)->point)+1)%5) ||
            SearchPointInGrid(Meteor,(Absis(First(Snake)->point)+1)%5,Ordinat(First(Snake)->point)) && SearchPoint(Snake,Absis(First(Snake)->point),(Ordinat(First(Snake)->point)+1)%5) ||
            SearchPoint(Snake,(Absis(First(Snake)->point)+1)%5,Ordinat(First(Snake)->point)) && SearchPoint(Snake,Absis(First(Snake)->point),(Ordinat(First(Snake)->point)+1)%5)) {
            if (Absis(First(Snake)->point) == 0) {
                if (SearchPoint(Snake,4,Ordinat(First(Snake)->point)) || SearchPointInGrid(Meteor,4,Ordinat(First(Snake)->point))) {
                    if (Ordinat(First(Snake)->point) == 0) {
                        if (SearchPoint(Snake,Absis(First(Snake)->point),4) || SearchPointInGrid(Meteor,Absis(First(Snake)->point),4)) {
                            printf("Anda sudah tidak bisa bergerak lagi!\n");
                            GameOver = true;
                        }
                    }
                    else {
                        if (SearchPoint(Snake,Absis(First(Snake)->point),Ordinat(First(Snake)->point)-1) || SearchPointInGrid(Meteor,Absis(First(Snake)->point),Ordinat(First(Snake)->point)-1)) {
                            printf("Anda sudah tidak bisa bergerak lagi!\n");
                            GameOver = true;
                        }
                    }
                }
            }
            else {
                if (SearchPoint(Snake,Absis(First(Snake)->point)-1,Ordinat(First(Snake)->point)) || SearchPointInGrid(Meteor,Absis(First(Snake)->point)-1,Ordinat(First(Snake)->point))) {
                    if (Ordinat(First(Snake)->point) == 0) {
                        if (SearchPoint(Snake,Absis(First(Snake)->point),4) || SearchPointInGrid(Meteor,Absis(First(Snake)->point),4)) {
                            printf("Anda sudah tidak bisa bergerak lagi!\n");
                            GameOver = true;
                        }
                    }
                    else {
                        if (SearchPoint(Snake,Absis(First(Snake)->point),Ordinat(First(Snake)->point)-1) || SearchPointInGrid(Meteor,Absis(First(Snake)->point),Ordinat(First(Snake)->point)-1)) {
                            printf("Anda sudah tidak bisa bergerak lagi!\n");
                            GameOver = true;
                        }
                    } 
                }
            }
        }
        turn++;
    }

    /* Menampilkan hasil akhir dari permainan */
    printf("Permainan berakhir!\n");
    *score = Length(Snake)*2;
    printf("Skor : %d\n",(*score));
}