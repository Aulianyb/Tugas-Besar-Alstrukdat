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
        boolean valid = false;
        while (!valid){
            printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL?(Y/N)\n");
            STARTFILE();
            if (isWordEqual(currentWord, "Y")){
                for (int i = IdxMin; i <= TG.Neff; i++){
                    CreateEmptyMap(&TS->TI[i]);
                }
                valid = true;
            } else if (isWordEqual(currentWord, "N")) {
                printf("\nOke, all scoreboard tidak jadi dihapus!\n");
                valid = true;
            } else {
                printf("\nInput salah, Ulangi!\n");
            }
        }
        printf("\nScoreboard berhasil direset!\n");
        
    } else {
        boolean valid = false;
        while (!valid)
        {
            if (ans > TG.Neff){
                printf("Game tidak ada di daftar! ulangi input!\n");
            } else {
                CreateEmptyMap(&TS->TI[ans]);
                valid = true;
            }
        }
        printf("\nScoreboard berhasil direset!\n");
    }
}