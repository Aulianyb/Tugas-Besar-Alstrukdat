#include <stdio.h>
#include "skipgame.h"

void SkipGame(Queue game_queue, int n){
    printf("Berikut ini adalah daftar Game-mu : \n");
    PrintQueueGame(game_queue);
    Word val;
    dequeue(&game_queue, &val);
    for (int i = 0; i < n; i++) {
        dequeue(&game_queue, &val);
    }
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
    else if (isWordEqual(val, "RockPaperScissor"))
    {
        printf("Loading ");
        PrintKata(val);
        printf("....\n");
        RockPaperScissor();
    }
    else if (isWordEqual(val, "DINOSAUR IN EARTH") || isWordEqual(val, "RISEWOMAN") || isWordEqual(val, "EIFFEL TOWER")){
        printf("Game ");
        PrintKata(val);
        printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
    }

    else if (n >= length(game_queue)) {
        printf("Tidak ada permainan lagi dalam daftar Game-mu.\n");
        enqueue(&game_queue, val);
    }
    else {
        GenRand(100,100,2);
    }
}
