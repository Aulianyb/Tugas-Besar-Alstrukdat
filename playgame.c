#include "queue.h"
#include "playgame.h"
#include "Dinner_dash.h"
#include "rng.h"
#include "RockPaperScissor.h"

void PlayGame(Queue game_queue){
    printf("Berikut ini adalah daftar Game-mu : \n");
    PrintQueueGame(game_queue);
    Word val;
    dequeue(&game_queue, &val);
    printf("Game yang akan dimainkan adalah %s\n", val);
    if (isWordEqual(val, "Diner DASH"))
    {
        printf("Loading ");
        PrintKata(val);
        printf("....\n");
        // PLay Diner DASH
        Dinner_Dash();
    }
    else if (isWordEqual(val, "RNG"))
    {
        printf("Loading ");
        PrintKata(val);
        printf("....\n");
        // Play RNG
        RNG();
    }
    else if (isWordEqual(val, "RockPaperScissors"))
    {
        printf("Loading ");
        PrintKata(val);
        printf("....\n");
        // Play RockPaperScissors PLACEHOLDER
    }
    else {
        printf("Game ");
        PrintKata(val);
        printf("masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
    }

}
