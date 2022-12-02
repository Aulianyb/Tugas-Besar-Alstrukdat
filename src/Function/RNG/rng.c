#include "rng.h"

int RNG(){
    srand(time(NULL));
    int X = rand()%50;
    int skor = 100;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    STARTFILE();
    while (WordToInt(currentWord) != X)
    {
        if (WordToInt(currentWord) > X)
        {
            printf("Lebih kecil\n");
            skor -= 2;
        }
        else if (WordToInt(currentWord) < X)
        {
            printf("Lebih besar\n");
            skor -= 2;
        }
        printf("Tebakan: ");
        STARTFILE();
    }
    printf("\nYa, X adalah %d.\n", X);
    return skor;
}

