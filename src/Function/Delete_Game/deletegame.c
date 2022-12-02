#include "deletegame.h"
#include <stdio.h>

void DeleteGame (TabGame *T, StackHistory *SH, TabScore *TS){
    ListGame(*T);
    printf("Masukkan nomor yang akan dihapus :");
    STARTFILE();
    IdxType idx;
    idx = WordToInt(currentWord);
    if (idx <= 8){
        printf("Game gagal dihapus\n");
    }
    else{
        Word game = T->TI[idx];
        DeleteAt(T, idx);
        DeleteAtTabScore(TS, idx);
        DeleteGameHistory(SH, game);
        printf("Game berhasil dihapus\n");
    }
}