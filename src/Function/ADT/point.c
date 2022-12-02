/*
Nama : Farhan Algani Putra
NIM : 18221108
Tanggal : 18 September 2022
Topik : Pra Praktikum 3
Deskripsi : implementasi fungsi dan prosedur pada file "point.h"
*/

#include <stdio.h>
#include "point.h"
#include <math.h>

POINT MakePOINT(float X, float Y) {

    POINT P;

    Absis(P) = X;
    Ordinat(P) = Y;

    return P;
}

void BacaPOINT(POINT * P) {

    float x;
    float y;

    scanf("%f  %f",&x,&y);

    *P = MakePOINT(x,y);
}

void TulisPOINT(POINT P) {

    printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}

boolean EQ(POINT P1, POINT P2) {
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEQ(POINT P1, POINT P2) {
    return (Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2));
}

boolean IsOrigin(POINT P) {
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX(POINT P) {
    return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P) {
    return (Absis(P) == 0);
}

int Kuadran(POINT P) {
    if (Absis(P) > 0 && Ordinat(P) > 0) {
        return 1;
    }
    else if (Absis(P) < 0 && Ordinat(P) > 0) {
        return 2;
    }
    else if (Absis(P) < 0 && Ordinat(P) < 0) {
        return 3;
    }
    else {
        return 4;
    }
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
    POINT P_Result;

    Absis(P_Result) = Absis(P) + deltaX;
    Ordinat(P_Result) = Ordinat(P) + deltaY;

    return P_Result;
}

void Geser (POINT *P, float deltaX, float deltaY) {
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

float Jarak0 (POINT P) {
    return (sqrt(pow(Absis(P),2) + pow(Ordinat(P),2)));
}

float Panjang (POINT P1, POINT P2) {
    return (sqrt(pow(Absis(P1)-Absis(P2),2) + pow(Ordinat(P1)-Ordinat(P2),2)));
}