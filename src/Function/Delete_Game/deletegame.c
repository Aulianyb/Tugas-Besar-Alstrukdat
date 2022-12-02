#include "deletegame.h"
#include <stdio.h>

void DeleteGame (TabGame *T, StackHistory *SH, TabScore *TS){
    ListGame(*T);
    printf("Masukkan nomor yang akan dihapus :");
    STARTFILE();
    IdxType idx;
    idx = WordToInt(currentWord);
    if (idx <= 6){
        printf("Game gagal dihapus\n");
    }
    else{
        DeleteAt(T, idx);
        DeleteAtTabScore(TS, idx);
        DeleteGameHistory(SH, T->TI[idx]);
        printf("Game berhasil dihapus\n");
    }
}