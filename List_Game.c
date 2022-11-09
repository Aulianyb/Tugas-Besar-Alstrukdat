#include <stdio.h>
#include "List_Game.h"

void ListGame(TabGame List_Game) {
/*
I.S. Sembarang
F.S. Menampilkan seluruh game yang tersedia di dalam sistem.
*/
    printf("Berikut adalah daftar game yang tersedia :\n");
    for (int i = IdxMin; i <= List_Game.Neff; i++) {
        printf("%d. ",i);
        //printf("%s\n",List_Game.TI[i]);
        PrintKata(List_Game.TI[i]);
        printf("\n");
    }
}