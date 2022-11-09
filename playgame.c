#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "RNG.h"
#include "Diner DASH.h"
#include "RockPaperScissors.h"

void playgame(Queue Queue_game){
    printf("Berikut ini adalah daftar Game-mu : \n");
    for (int i = 0; i < length(Queue_game); i++) {
    printf("%d. ",i);
    printf("%s\n",Queue_game.buffer[i]);
    }
    char val;
    dequeue(&Queue_game, val);
    if (val == "Diner DASH")  {
        printf("Loading %s .....\n",val);
        // PLay Diner DASH
    }
    else if (val == "RNG") {
        printf("Loading %s .....\n",val);
        // Play RNG
    }
    else if (val == "RockPaperScissors") {
        printf("Loading %s .....\n",val);
        // Play RockPaperScissors
    }
    else{
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", val);
    }

}
