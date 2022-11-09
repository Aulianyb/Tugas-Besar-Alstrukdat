#include "Create_Game.h"

void CreateGame(TabGame* List_Game) {
/* I.S. TabGame List_Game terdefinisi */
/* F.S. Game baru hasil masukan pengguna berhasil ditambahkan ke dalam TabGame List_Game */
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTFILE();

    //Word added;
    //int trav = 0;
    //for (trav = 0; trav < currentWord.Length; trav++) {
    //    if (currentWord.TabWord[trav] != '\0') {
    //        added.TabWord[trav] = currentWord.TabWord[trav];
    //    }
    //}
    //added.Length = currentWord.Length;
    
    int i = IdxMin;
    boolean found = false;
    while (i <= (*List_Game).Neff && !found) {
        int k = 0;
        boolean equal = true;
        while ((*List_Game).TI[i].TabWord[k] != '\0' && currentWord.TabWord[k] != '\0' && equal) {
            if ((*List_Game).TI[i].TabWord[k] != currentWord.TabWord[k]) {
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
        SetEl(List_Game,i,currentWord);
        printf("Game berhasil ditambahkan\n");
    }
    else {
        printf("Game sudah tersedia\n");
    }
}
