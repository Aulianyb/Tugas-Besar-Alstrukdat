#include <stdio.h>
#include "array.h"

void CreateGame(TabGame* List_Game) {
    char game[50];

    printf("Masukkan nama game yang akan ditambahkan: ");
    scanf("%[^\n]",game);

    int i = IdxMin;
    boolean found = false;

    while (i <= (*List_Game).Neff && !found) {
        int k = 0;
        boolean equal = true;
        while ((*List_Game).TI[i][k] != '\0' && game[k] != '\0' && equal) {
            if ((*List_Game).TI[i][k] != game[k]) {
                equal = false;
            }
            else {
                k++;
            }
        }
        if (equal) {
            found = true;
        }
        else {
            i++;
        }
    }
    if (!found) {
        SetEl(List_Game,i,game);
        printf("Game berhasil ditambahkan\n");
    }
    else {
        printf("Game sudah tersedia\n");
    }
}
