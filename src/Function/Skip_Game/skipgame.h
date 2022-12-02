#ifndef SKIPGAME_H
#define SKIPGAME_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/queue.h"
#include "../../boolean.h"
#include "../Dinner_Dash/Dinner_Dash.h"
#include "../RNG/rng.h"
#include "../RockPaperScissor/RockPaperScissor.h"
#include "../ADT/mesinkata.h"
#include "../../random_generator.h"
#include "../ADT/stackhistory/stackhistory.h"
#include "../ADT/arrayofmap/arrayofmap.h"
#include "../Hanoi/Hanoi.h"
#include "../hangman/hangman.h"
#include "../SnakeOnMeteor/snakeOnMeteor.h"

void SkipGame(Queue *game_queue, int n);

// I.S Sembarang
// F.S Menampilkan seluruh game yang terdapat di queue dan memainkan game sesuai dengan input user mengenai banyaknya game yang di skip

#endif
