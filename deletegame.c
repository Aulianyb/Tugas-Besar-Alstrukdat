#include "deletegame.h"
#include <stdio.h>

void DeleteGame (TabGame *T){
    printf("Berikut adalah daftar game yang tersedia\n");
    ListGame(*T);
    printf("Masukkan nomor yang akan dihapus :");
    STARTFILE();
    IdxType idx;
    idx = WordToInt(currentWord);
    if (idx <= 5){
        printf("Game gagal dihapus\n");
    }
    else{
        DeleteAt(T, idx);
        printf("Game berhasil dihapus\n");
    }
}