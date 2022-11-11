#include "Create_Game.h"

void CreateGame(TabGame* List_Game) {
/* I.S. TabGame List_Game terdefinisi */
/* F.S. Game baru hasil masukan pengguna berhasil ditambahkan ke dalam TabGame List_Game */
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTFILE();
    
    int i = IdxMin;
    boolean found = false;
    while (i <= (*List_Game).Neff && !found) {
        if (isTwoWordEqual((*List_Game).TI[i], currentWord)) {
            found = true;
        }
        else {
            i++;
        }
    }

    if (!found) {
        SetEl(List_Game,i,currentWord);
        printf("Game berhasil ditambahkan\n");
    }
    else {
        printf("Game sudah tersedia\n");
    }
}
