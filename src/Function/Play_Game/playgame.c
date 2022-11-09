#include <stdio.h>
#include "playgame.h"

void PlayGame(Queue game_queue){
    printf("Berikut ini adalah daftar Game-mu : \n");
    PrintQueueGame(game_queue);
    Word val;
    dequeue(&game_queue, &val);
    printf("Game yang akan dimainkan adalah %s\n", val);
    if (isWordEqual(val, "Diner DASH"))
    // isEqual(val, "Diner DASH")
    {
        printf("Loading %s .....\n",val);
        // PLay Diner DASH
        Dinner_Dash();
    }
    else if (isWordEqual(val, "RNG")) 
    // isEqual(val, "RNG")
    {
        printf("Loading %s .....\n",val);
        // Play RNG
        RNG();
    }
    else if (isWordEqual(val, "RockPaperScissor"))
        // isEqual(val, "RockPaperScissors")
    {
        printf("Loading %s .....\n",val);
        // Play RockPaperScissor
        //PLACEHOLDER
    }
    else{
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", val);
    }

}
