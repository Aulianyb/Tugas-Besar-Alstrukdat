#include "resethistory.h"

void RESETHISTORY(StackHistory *SH){
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK): ");
    STARTFILE();
    
    boolean valid = false;
    while (!valid){
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