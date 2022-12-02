#include <stdio.h>
#include "../Function/ADT/point.h"

int main(){
    POINT P;

    printf("==== DRIVER ADT POINT ====\n");
    
    printf("==== MakePOINT ====\n"); 
    printf("EKSPEKTASI : return POINT dengan X dan Y yang ditentukan\n");
    printf("TEST : Membuat POINT P dengan X = 0 dan Y = 1\n");
    P = MakePOINT(0.0, 1.0);
    printf("\n");

    printf("==== TulisPOINT ====\n"); 
    printf("EKSPEKTASI : Menuliskan POINT\n");
    printf("TEST : Menulis POINT P yang telah dibuat\n");
    TulisPOINT(P);
    printf("\n\n");

    printf("==== BacaPOINT ====\n"); 
    printf("EKSPEKTASI : Membuat POINT Sesuai dengan Input (x y)\n");
    printf("TESTING - MASUKKAN INPUT P1:");
    POINT P1;
    BacaPOINT(&P1);
    TulisPOINT(P1);
    printf("\n\n");

    printf("==== EQ ====\n"); 
    printf("EKSPEKTASI : Memberikan nilai 1 jika P1 = P2\n");
    printf("TEST : Membandingkan P dan P1\n");
    printf("EQ(P, P1) : %d\n", EQ(P, P1));
    printf("\n\n");

    printf("==== NEQ ====\n"); 
    printf("EKSPEKTASI : Memberikan nilai 1 jika P1 != P2\n");
    printf("TEST : Membandingkan P dan P1\n");
    printf("NEQ(P, P1) : %d\n", NEQ(P, P1));
    printf("\n\n");

    printf("==== isOrigin ====\n"); 
    printf("EKSPEKTASI : Memberikan nilai 1 jika POINT adalah titik origin\n");
    printf("TEST : cek P dan P1\n");
    printf("isOrigin - P : %d\n", IsOrigin(P));
    printf("isOrigin - P1 : %d\n", IsOrigin(P1));
    printf("\n\n");
    
    printf("==== isOnSbX ====\n"); 
    printf("EKSPEKTASI : Memberikan nilai 1 jika POINT ada pada sumbu X\n");
    printf("TEST : cek P dan P1\n");
    printf("isOnSbX - P : %d\n", IsOnSbX(P));
    printf("isOnSbX - P1 : %d\n", IsOnSbX(P1));
    printf("\n\n");

    printf("==== isOnSbY ====\n"); 
    printf("EKSPEKTASI : Memberikan nilai 1 jika POINT ada pada sumbu Y\n");
    printf("TEST : cek P dan P1\n");
    printf("isOnSbY - P : %d\n", IsOnSbY(P));
    printf("isOnSbY - P1 : %d\n", IsOnSbY(P1));
    printf("\n\n");

    printf("==== Kuadran ====\n"); 
    printf("EKSPEKTASI : Memberikan kuadran suatu POINT\n");
    printf("TEST : cek P dan P1\n");
    printf("Kuadran - P : %d\n", Kuadran(P));
    printf("Kuadran - P1 : %d\n", Kuadran(P1));
    printf("\n\n");

    printf("==== PlusDelta ====\n"); 
    printf("EKSPEKTASI : Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY\n");
    printf("TEST : PlusDelta P dengan deltaX = 3 dan deltaY = 4 dan disimpan dalam P2\n");
    POINT P2;
    P2 = PlusDelta(P, 3, 4);
    TulisPOINT(P2);
    printf("\n\n");

    printf("==== Geser ====\n"); 
    printf("EKSPEKTASI : P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY\n");
    printf("TEST : P2 Absisnya digeser sebanyak 2 dan Ordinatnya sebanyak 3\n");
    Geser(&P2, 2, 3);
    TulisPOINT(P2);
    printf("\n\n");

    printf("==== Jarak0 ====\n"); 
    printf("EKSPEKTASI : Menghitung jarak P ke (0,0)\n");
    printf("TEST : Jarak P2 ke 0\n");
    printf("Jarak0 - P2 : %d\n", Jarak0(P2));
    printf("\n\n");

    printf("==== Panjang ====\n"); 
    printf("EKSPEKTASI : Menghitung panjang garis yang dibentuk P1 dan P2.\n");
    printf("TEST : Panjang garis P ke P2\n");
    printf("Panjang garis P ke P2 : %d\n", Panjang(P, P2));
    printf("\n\n");


    return 0; 
}