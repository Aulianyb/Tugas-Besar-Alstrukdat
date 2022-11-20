#include <stdio.h>
#include <stdlib.h>

#include "history.h"

void history(StackHistory SH, int n)
{
    if (IsEmptyHistory(SH)) printf("Kamu belum punya history game! >:( \n\n");
    else {
        printf("Berikut adalah daftar Game yang telah dimainkan: ");
        printf("\n\n");
        if (n > Top(SH) + 1){
            n = Top(SH) + 1;
        }
        PrintStackHistory(SH, n);
        printf("\n");
    }
}