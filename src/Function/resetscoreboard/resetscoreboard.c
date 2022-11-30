#include "resetscoreboard.h"

void resetScoreboard(TabScore *TS, TabGame TG)
{
    printf("\nDAFTAR SCOREBOARD: \n");
    printf("\n 0. ALL\n");
    for (int i = IdxMin; i <= TS->Neff; i++)
    {
        printf(" %d. ", i);
        PrintKata(TG.TI[i]);
        printf("\n");
    }
    printf("\nSCOREBOARD YANG INGIN DIHAPUS: ");
    STARTFILE();
    printf("\n");
    int ans = WordToInt(currentWord);
    if (ans == 0){
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL?\n");
        STARTFILE();
        if (isWordEqual(currentWord, 'Y') || isWordEqual(currentWord, 'N')){
            for (int i = IdxMin; i <= TG.Neff; i++){
                CreateEmptyMap(&TS->TI[i]);
            }
        }

    } else {
        boolean valid = false;
        while (!valid)
        {
            if (ans > TG.Neff){
                printf("Game tidak ada di daftar! ulangi input!\n");
            } else {
                CreateEmptyMap(&TS->TI[ans]);
            }
        }
    }
    printf("\nScoreboard berhasil direset!\n");
}