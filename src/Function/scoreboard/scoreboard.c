#include <stdio.h>
#include "scoreboard.h"


void SCOREBOARD(TabScore M, TabGame T){
    // printf("\n%d\n", M.Neff);
    for (int i = 1; i <= M.Neff; i++)
    {
        printf("\n***** SCOREBOARD GAME ");
        PrintKata(T.TI[i]);
        printf(" *****\n");
        printf("| NAMA          | SKOR          |\n");
        printf("---------------------------------\n");
        if (IsEmptyMap(M.TI[i])){
            printf("------- SCOREBOARD KOSONG --------\n");
        } else {
            int ctr = M.TI[i].Count;
            for (int j = 0; j < M.TI[i].Count; j++)
            {
                printf("| ");
                PrintKata(M.TI[i].Elements[j].user);
                if (M.TI[i].Elements[j].user.Length <= 13)
                {
                    printf("\t");
                    if (M.TI[i].Elements[j].user.Length <= 5) {
                        printf("\t");
                    }
                }
                printf("| ");
                printf("%d", M.TI[i].Elements[j].score);
                printf("\t\t|\n");
            }
        }
    }
    printf("\n");
}