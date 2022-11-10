#include <stdio.h>
#include "playgame.h"

void PlayGame(Queue game_queue){
    printf("Berikut ini adalah daftar Game-mu : \n");
    PrintQueueGame(game_queue);
    Word val;
    dequeue(&game_queue, &val);
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
    else if (isWordEqual(val, "DINOSAUR IN EARTH") || isWordEqual(val, "RISEWOMAN") || isWordEqual(val, "EIFFEL TOWER")){
        printf("Game ");
        PrintKata(val);
        printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
    }
    
    else {
        printf("Loading ");
        PrintKata(val);
        printf("....\n");
        GenRand(100,100,2);
    }
}
