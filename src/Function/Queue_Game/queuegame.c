#include "queuegame.h"

void QueueGame(Queue* game_queue, TabGame list_game){
    if(!isEmpty(*game_queue)){
        printf("Berikut adalah daftar antrian game-mu\n");
        PrintQueueGame(*game_queue);
        ListGame(list_game);
        printf("Nomor Game yang mau ditambahkan ke antrian: ");
        STARTFILE();
        IdxType idx;
        idx = WordToInt(currentWord);
        boolean valid = IsIdxEff(list_game, idx);
        if(valid){
            enqueue(game_queue, list_game.TI[idx]);
            printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
        }
        else{
            printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        }
    }
    else{
        printf("Belum terdapat game dalam antrian\n");
        PrintQueueGame(*game_queue);
        ListGame(list_game);
        printf("Nomor Game yang mau ditambahkan ke antrian: ");
        STARTFILE();
        IdxType idx;
        idx = WordToInt(currentWord);
        boolean valid = IsIdxEff(list_game, idx);
        if(valid){
            enqueue(game_queue, list_game.TI[idx]);
            printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
        }
        else{
            printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
        }
    }

}