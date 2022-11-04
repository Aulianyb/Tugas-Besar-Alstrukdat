#include "Create_Game.h"

void CreateGame(TabGame* List_Game) {
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTFILE();

    int i = IdxMin;
    boolean found = false;

    while (i <= (*List_Game).Neff && !found) {
        int k = 0;
        boolean equal = true;
        while ((*List_Game).TI[i][k] != '\0' && currentWord.TabWord[k] != '\0' && equal) {
            if ((*List_Game).TI[i][k] != currentWord.TabWord[k]) {
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
        SetEl(List_Game,i,currentWord.TabWord);
        printf("Game berhasil ditambahkan\n");
    }
    else {
        printf("Game sudah tersedia\n");
    }
}
