#include "queue.h"
#include "skipgame.h"
#include "Dinner_dash.h"
#include "rng.h"
#include "RockPaperScissors.h"

void SkipGame(Queue game_queue, int n){
    printf("Berikut ini adalah daftar Game-mu : \n");
    PrintQueueGame(game_queue);
    char *val;
    for (int i = 0; i < n; i++) {
        dequeue(&game_queue, &val);
    }

    if (val[0] == 'D' && val[1] == 'i' && val[2] == 'n' && val[3] == 'e' && val[4] == 'r' && val[5] == ' ' && val[6] == 'D' && val[7] == 'A' && val[8] == 'S' && val[9] == 'H')
    // isEqual(val, "Diner DASH")
    {
        printf("Loading %s .....\n",val);
        // PLay Diner DASH
        Dinner_Dash();
    }
    else if ((val[0] == 'R' && val[1] == 'N' && val[2] == 'G')) 
    // isEqual(val, "RNG")
    {
        printf("Loading %s .....\n",val);
        // Play RNG
        RNG();
    }
    else if (val[0] = 'R' && val[1] == 'o' && val[2] == 'c' && val[3] == 'k' && val[4] == 'P' && val[5] == 'a' && val[6] == 'p' && val[7] == 'e' && val[8] == 'r' && val[9] == 'S' && val[10] == 'c' && val[11] == 'i' && val[12] == 's' && val[13] == 's' && val[14] == 'o' && val[15] == 'r' && val[16] == 's') 
    // isEqual(val, "RockPaperScissors")
    {
        printf("Loading %s .....\n",val);
        // Play RockPaperScissors PLACEHOLDER

    }
    else if (n > length(game_queue)) {
        printf("Tidak ada permainan lagi dalam daftar Game-mu.\n");
    }
    else {
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", val);
    }
}
