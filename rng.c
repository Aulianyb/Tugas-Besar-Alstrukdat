#include "rng.h"

void RNG(){
    srand(time(NULL));
    int X = rand()%50;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    STARTFILE();
    while (WordToInt(currentWord) != X)
    {
        if (WordToInt(currentWord) > X)
        {
            printf("Lebih kecil\n");
        }
        else if (WordToInt(currentWord) < X)
        {
            printf("Lebih besar\n");
        }
        printf("Tebakan: ");
        STARTFILE();
    }
    printf("\nYa, X adalah %d.\n", X);
}

int main()
{
    RNG();
}