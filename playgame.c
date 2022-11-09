#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "RNG.h"
#include "Diner DASH.h"
#include "RockPaperScissors.h"

void playgame(Queue game_queue){
    printf("Berikut ini adalah daftar Game-mu : \n");
    for (int i = 0; i < length(game_queue); i++) {
    printf("%d. ",i);
    printf("%s\n",game_queue.buffer[i]);
    }
    char val;
    dequeue(&game_queue, val);
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
