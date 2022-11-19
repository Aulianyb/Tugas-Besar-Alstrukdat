#include <stdio.h>
#include <stdlib.h>

#include "history.h"

void history(StackHistory SH)
{
    printf("Berikut adalah daftar Game yang telah dimainkan: ");
    printf("\n");
    printf("\n");
    PrintStackHistory(SH);
}