#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "queue.h"



void skipgame(Queue Queue_game, int n){
    printf("Berikut ini adalah daftar Game-mu : \n");
    for (int i = 0; i < length(Queue_game); i++) {
    printf("%d. ",i);
    printf("%s\n",Queue_game.buffer[i]);
    }
    char val;
    for (int i = 0; i < n; i++) {
        dequeue(&Queue_game, val);
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
    else if ((n <= length(Queue_game)) && val != "Diner DASH" && val != "RNG") {
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", val);
    }
    else if (n > length(Queue_game)) {
        printf("Tidak ada permainan lagi dalam daftar Game-mu.\n");
    }
}
