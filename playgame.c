#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "queue.h"
// declare the tabgame with 00 elements


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
    else {
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", val);
    }

}
