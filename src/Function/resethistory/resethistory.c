#include "resethistory.h"

void RESETHISTORY(StackHistory *SH){
    boolean valid = false;
    while (!valid){
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK): ");
        STARTFILE();

        if (isWordEqual(currentWord, "YA")) {
            CreateEmptyHistory(SH);
            valid = true;
        }
        else if (isWordEqual(currentWord, "TIDAK")){
            printf("History tidak jadi direset. ");
            history(*SH, Top(*SH)+1);
            valid = true;
        }
        else {
            printf("Input salah. Ulangi!\n");
        }
    }
}