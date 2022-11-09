#include "queue.h"
#include "skipgame.h"
#include "Dinner_dash.h"
#include "rng.h"
#include "RockPaperScissor.h"

void SkipGame(Queue game_queue, int n){
    printf("Berikut ini adalah daftar Game-mu : \n");
    PrintQueueGame(game_queue);
    char *val;
    for (int i = 0; i < n; i++) {
        dequeue(&game_queue, &val);
    }

    if (isEqual(val, "Diner DASH"))
    {
        printf("Loading %s .....\n",val);
        // PLay Diner DASH
        Dinner_Dash();
    }
    else if (isEqual(val, "RNG"))
    {
        printf("Loading %s .....\n",val);
        // Play RNG
        RNG();
    }
    else if (isEqual(val, "RockPaperScissors"))
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
