#include "listdp.h"
#include "random_generator.h"
#include "mesinkata.h"
#include <stdio.h>

boolean isMoveValid(Word word) {
    return (isWordEqual(word,"w") || isWordEqual(word,"W") || isWordEqual(word,"a") || isWordEqual(word,"A") ||
    isWordEqual(word,"s") || isWordEqual(word,"S") || isWordEqual(word,"d") || isWordEqual(word,"D"));
}

void MoveSnake(List *L, Word input, char keyword) {
    if (keyword == 'w') {
        if (Ordinat(First(*L)->point) == 0) {
            InsVFirst(L,0,Absis(First(*L)->point),4);
        }
        else {
            InsVFirst(L,0,Absis(First(*L)->point),(Ordinat(First(*L)->point)-1)%5);
        }
    }
    else if (keyword == 'a'){
        if (Absis(First(*L)->point) == 0) {
            InsVFirst(L,0,4,Ordinat(First(*L)->point));
        }
        else {
            InsVFirst(L,0,(Absis(First(*L)->point)-1)%5,Ordinat(First(*L)->point));
        }
    }
    else if (keyword == 's') {
        InsVFirst(L,0,Absis(First(*L)->point),(Ordinat(First(*L)->point)+1)%5);
    }
    else if (keyword == 'd') {
        InsVFirst(L,0,(Absis(First(*L)->point)+1)%5,Ordinat(First(*L)->point));
    }

    address p = Next(First(*L));
    while (p != Last(*L)) {
        Info(p) = Info(Next(p));
        p = Next(p);
    }
    DelLast(L,&p);
}

void AddBody(List *L, int abs, int ord) {
    int insAbs = abs;
    int insOrd = ord;
    if ((abs - 1) >= 0 && !SearchPoint(*L,abs-1,ord)) {
        insAbs = abs - 1;
    }
    else {
        if ((ord - 1) >= 0 && !SearchPoint(*L,abs,ord-1)) {
            insOrd = ord - 1;
        }
        else if ((ord + 1) <= 4 && !SearchPoint(*L,abs,ord+1)) {
            insOrd = ord + 1;
        }
        else {
            if ((abs + 1) <= 4 && !SearchPoint(*L,abs+1,ord)) {
                insAbs = abs + 1;
            }
        }
    }

    if (!SearchPoint(*L,insAbs,insOrd)) {
        address p = Alokasi(Info(Last(*L))+1,insAbs,insOrd);
        InsertLast(L,p);
    }
}

void spawnObstacle(List L, POINT *obstacle) {
    Absis(*obstacle) = GenRand(0,4,5);
    Ordinat(*obstacle) = GenRand(0,4,5);

    while (SearchPoint(L,Absis(*obstacle),Ordinat(*obstacle))) {
        Absis(*obstacle) = GenRand(0,4,5);
        Ordinat(*obstacle) = GenRand(0,4,5);
    }
}

void spawnFood(List L, POINT *food, POINT obstacle) {
    Absis(*food) = GenRand(0,4,5);
    Ordinat(*food) = GenRand(0,4,5);

    while (SearchPoint(L,Absis(*food),Ordinat(*food)) || (Absis(*food)==Absis(obstacle) && Ordinat(*food)==Ordinat(obstacle))) {
        Absis(*food) = GenRand(0,4,5);
        Ordinat(*food) = GenRand(0,4,5);
    }
}

void spawnMeteor(POINT food, POINT obstacle, POINT *meteor) {
    Absis(*meteor) = GenRand(0,4,5);
    Ordinat(*meteor) = GenRand(0,4,5);

    while ((Absis(*meteor)==Absis(obstacle) && Ordinat(*meteor)==Ordinat(obstacle)) || (Absis(*meteor)== Absis(food) && Ordinat(*meteor)==Ordinat(food))) {
        Absis(*meteor) = GenRand(0,4,5);
        Ordinat(*meteor) = GenRand(0,4,5);
    }
}

void PrintGrid(List L, POINT food) {
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 5; i++) {
            address p = SearchAdrPoint(L,i,j);
            if (p != Nil) {
                if (Info(p) == 0) {
                    printf("[H]");
                }
                else {
                    printf("[%d]",Info(p));
                }
            }
            else {
                if (Absis(food) == i && Ordinat(food) == j) {
                    printf("[o]");
                }
                else {
                    printf("[ ]");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    /* ### Inisialisasi Snake ### */
    List Snake;
    CreateEmpty(&Snake);
    address p = Alokasi(0,GenRand(0,4,5),GenRand(0,4,5));
    InsertFirst(&Snake,p);
    AddBody(&Snake,Absis(Last(Snake)->point),Ordinat(Last(Snake)->point));
    AddBody(&Snake,Absis(Last(Snake)->point),Ordinat(Last(Snake)->point));
    
    /* ### Spawn Food Pertama Kali ### */
    POINT Food;
    spawnFood(Snake,&Food);

    /* ### Print Grid Pertama Kali ### */
    printf("Absis Food : %d\n",Absis(Food));
    printf("Ordinat Food : %d\n",Ordinat(Food));
    PrintGrid(Snake, Food);

    while (Info(First(Snake)) == 0) {
        printf("Masukkan gerakan : ");
        STARTFILE();
        // while (!isMoveValid(currentWord)) {
        //     printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
        //     STARTFILE();
        // }

        boolean valid = false;
        while (!valid) {
            if (!isMoveValid(currentWord)) {
                printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                STARTFILE();
            }
                else {
                if (isWordEqual(currentWord,"a") || isWordEqual(currentWord,"A")) {
                    if (Absis(First(Snake)->point)-1 >= 0) {
                        if (SearchPoint(Snake,(Absis(First(Snake)->point)-1)%5,Ordinat(First(Snake)->point))) {
                            printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                            STARTFILE();
                        }
                        else {
                            valid = true;
                            MoveSnake(&Snake,currentWord,'a');
                        }
                    }
                    else {
                        if (SearchPoint(Snake,4,Ordinat(First(Snake)->point))) {
                            printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                            STARTFILE();
                        }
                        else {
                            valid = true;
                            MoveSnake(&Snake,currentWord,'a');
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
                            MoveSnake(&Snake,currentWord,'w');
                        }
                    }
                    else {
                        if (SearchPoint(Snake,Absis(First(Snake)->point),4)) {
                            printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                            STARTFILE();
                        }
                        else {
                            valid = true;
                            MoveSnake(&Snake,currentWord,'w');
                        }
                    }
                }
                if (isWordEqual(currentWord,"s") || isWordEqual(currentWord,"S")) {
                    if (SearchPoint(Snake,Absis(First(Snake)->point),(Ordinat(First(Snake)->point)+1)%5)) {
                        printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                        STARTFILE();
                    }
                    else {
                        valid = true;
                        MoveSnake(&Snake,currentWord,'s');
                    }
                }
                if (isWordEqual(currentWord,"d") || isWordEqual(currentWord,"D")) {
                    if (SearchPoint(Snake,(Absis(First(Snake)->point)+1)%5,Ordinat(First(Snake)->point))) {
                        printf("Gerakan tidak valid! Masukkan ulang gerakan : ");
                        STARTFILE();
                    }
                    else {
                        valid = true;
                        MoveSnake(&Snake,currentWord,'d');
                    }
                }
            }
        }

        if (Absis(First(Snake)->point) == Absis(Food) && Ordinat(First(Snake)->point) == Ordinat(Food)) {
            AddBody(&Snake,Absis(Last(Snake)->point),Ordinat(Last(Snake)->point));
            spawnFood(Snake,&Food);
        }

        printf("Absis Food : %d\n",Absis(Food));
        printf("Ordinat Food : %d\n",Ordinat(Food));
        PrintGrid(Snake, Food);
    }
    return 0;
}