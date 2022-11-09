#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "RNG.h"
#include "Dinner_DASH.h"
#include "RockPaperScissor.h"

void skipgame(Queue game_queue, int n){
    printf("Berikut ini adalah daftar Game-mu : \n");
    for (int i = 0; i < length(game_queue); i++) {
    printf("%d. ",i);
    printf("%s\n",game_queue.buffer[i]);
    }
    char val;
    for (int i = 0; i < n; i++) {
        dequeue(&game_queue, val);
    }
    // Dequeue sampai dapet game yang diinginkan
    if ((val == "Diner DASH")) {
        printf("Loading %s .....\n",val);
        // PLay Diner DASH
    }
    else if ((val == "RNG")) {
        printf("Loading %s .....\n",val);
        // Play RNG
    }
    else if ((val == "RockPaperScissors")) {
        printf("Loading %s .....\n",val);
        // Play RockPaperScissors
    }
    else if ((n <= length(game_queue)) && val != "Diner DASH" && val != "RNG") {
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", val);
    }
    else if (n > length(game_queue)) {
        printf("Tidak ada permainan lagi dalam daftar Game-mu.\n");
    }
}
