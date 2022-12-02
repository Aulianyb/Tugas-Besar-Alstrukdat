#include <stdio.h>
#include "playgame.h"

void PlayGame(Queue *game_queue, StackHistory *SH, TabScore *TS, TabGame TG){
    printf("Berikut ini adalah daftar Game-mu : \n");
    PrintQueueGame(*game_queue);
    if (isEmpty(*game_queue)){
        printf("Belum ada game yang di queue!\n");
    }
    else{
        Word val; int score;
        dequeue(game_queue, &val);
        if (isWordEqual(val, "Diner DASH"))
        {
            printf("Loading ");
            PrintKata(val);
            printf("....\n");
            // PLay Diner DASH
            Dinner_Dash(&score);
        }
        else if (isWordEqual(val, "RNG"))
        {
            printf("Loading ");
            PrintKata(val);
            printf("....\n");
            // Play RNG
            score = RNG();
        }
        else if (isWordEqual(val, "TOWER OF HANOI"))
        {
            printf("Loading ");
            PrintKata(val);
            printf("....\n");
            // Play Tower of Hanoi
            Hanoi(&score);
        }
        else if (isWordEqual(val, "HANGMAN"))
        {
            printf("Loading ");
            PrintKata(val);
            printf("....\n");
            hangman(&score);
        }
        else if (isWordEqual(val, "SNAKE ON METEOR"))
        {
            printf("Loading ");
            PrintKata(val);
            printf("....\n");
            SnakeOnMeteor(&score);
        }
        else if (isWordEqual(val, "ROCK PAPER SCISSOR"))
        {
            printf("Loading ");
            PrintKata(val);
            printf("....\n");
            // Play ROCK PAPER SCISSOR
            RockPaperScissor(&score);
        }
        else if (isWordEqual(val, "SLAY THE DRAGON"))
        {
            printf("Loading ");
            PrintKata(val);
            printf("....\n");
            // Play ROCK PAPER SCISSOR
            score = SlayTheDragon();
        }
        // else if (isWordEqual(val, "DINOSAUR IN EARTH") || isWordEqual(val, "RISEWOMAN") || isWordEqual(val, "EIFFEL TOWER")){
        //     printf("Game ");
        //     PrintKata(val);
        //     printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
        // }
        else {
            printf("Loading ");
            PrintKata(val);
            printf("....\n");
            printf("  _____ _____ _____ _____    _____ _____ _____ _____ \n");
            printf(" |   __|  _  |     |   __|  |     |  |  |   __| __  |\n");
            printf(" |  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n");
            printf(" |_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n");
            score = GenRand(100,100,2);
        }
        printf("Skor akhir : %d\n", score);
        printf("\nMasukkan nama (hanya satu kata): \n>>>");
        STARTFILE();
        int idx = findIdxGame(TG, val);
        InsertMap(&TS->TI[idx], currentWord, score);

        printf("\nBerhasil menambahkan score ke SCOREBOARD!\n");
        PushHistory(SH, val);
    }
}
