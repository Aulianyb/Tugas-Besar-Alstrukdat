#include "queue.h"
#include "playgame.h"
#include "Dinner_dash.h"
#include "rng.h"
#include "RockPaperScissor.h"

void PlayGame(Queue game_queue){
    printf("Berikut ini adalah daftar Game-mu : \n");
    PrintQueueGame(game_queue);
    char *val;
    dequeue(&game_queue, &val);
    printf("Game yang akan dimainkan adalah %s\n", val);
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
    else if (isEqual(val, "RockPaperScissor"))
    {
        printf("Loading %s .....\n",val);
        // Play RockPaperScissors PLACEHOLDER
    }
    else{
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", val);
    }

}
