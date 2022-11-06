#include <stdio.h>
#include "array.h"
#include "List_Game.h"

void ListGame(TabGame List_Game) {
    printf("Berikut adalah daftar game yang tersedia :\n");
    for (int i = IdxMin; i <= List_Game.Neff; i++) {
        printf("%d. ",i);
        printf("%s\n",List_Game.TI[i]);
    }
}