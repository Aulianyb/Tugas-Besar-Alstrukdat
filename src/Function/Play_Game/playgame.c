#include <stdio.h>
#include "playgame.h"

void PlayGame(Queue *game_queue){
    printf("Berikut ini adalah daftar Game-mu : \n");
    PrintQueueGame(*game_queue);
    if (isEmpty(*game_queue)){
    printf("Belum ada game yang di queue!\n");
    }
    else{
    Word val;
    dequeue(game_queue, &val);
    if (isWordEqual(val, "Diner Dash"))
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
    else if (isWordEqual(val, "RockPaperScissor"))
    {
        printf("Loading ");
        PrintKata(val);
        printf("....\n");
        // Play RockPaperScissors
        RockPaperScissor();
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
        printf("  _____ _____ _____ _____    _____ _____ _____ _____ \n");
        printf(" |   __|  _  |     |   __|  |     |  |  |   __| __  |\n");
        printf(" |  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n");
        printf(" |_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n");
        printf("SCORE AKHIR : %d\n", GenRand(100,100,2));
    }
}
}
