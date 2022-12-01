#include "Tree_Game.h"
void MoveTree(BinTree *PlayerMove){
    BinTree PlayerMove;
    PlayerMove = Tree ("move", -1, NilTree, NilTree);
    AddDaun (&PlayerMove, "move", "action", -2, true);
    AddDaun (&PlayerMove, "move", "attack", -3, false);
    AddDaun (&Left(*PlayerMove), "action", "heal", 2, true);
    AddDaun (&Left(*PlayerMove), "action", "skip", 5, false);
    AddDaun (&Right(*PlayerMove), "attack", "spell", 2, true);
    AddDaun (&Right(*PlayerMove), "attack", "sword", 6, false);
}
int main(){
    boolean alive=true, win=false;
    BinTree PlayerMove;
    MoveTree(&PlayerMove);
    int hp_player=100, hp_monster=100, score=0, RNG, heal, sword, spell, skip;
    heal = Akar(Left(Left(PlayerMove))).Value;
    skip = Akar(Left(Right(PlayerMove))).Value;
    sword = Akar(Right(Right(PlayerMove))).Value;
    spell = Akar(Right(Left(PlayerMove))).Value;
    
    printf("\n _____ _       _____   __  _____ _   _  _____ \n");
    printf("/  ___| |     / _ \\ \\ / / |_   _| | | ||  ___|\n");
    printf("\\ `--.| |    / /_\\ \\ V /    | | | |_| || |__  \n");
    printf(" `--. \\ |    |  _  |\\ /     | | |  _  ||  __| \n");
    printf("/\\__/ / |____| | | || |     | | | | | || |___ \n");
    printf("\\____/\\_____/\\_| |_/\\_/     \\_/ \\_| |_/\\____/ \n\n");
    printf("   ____________  ___  _____ _____ _   _\n");
    printf("   |  _  \\ ___ \\/ _ \\|  __ \\  _  | \\ | | \n");
    printf("   | | | | |_/ / /_\\ \\ |  \\/ | | |  \\| |\n");
    printf("   | | | |    /|  _  | | __| | | | . ` |\n");
    printf("   | |/ /| |\\ \\| | | | |_\\ \\ \\_/ / |\\  |\n");
    printf("   |___/ \\_| \\_\\_| |_/\\____/\\___/\\_| \\_/\n\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("You slowly make your way up to snowy mountains, the beast's lair.\n\n");
    delay(500);
    printf("You finally reached the lair's entrance. \nYou tried sneaking in but suddenly a loud roar came from inside the cave. \n\n");
    delay(500);
    printf("Two yellow eyes emerge from the dark, followed by the grand entrance of the Red Dragon.\n\n");
    delay(500);
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    while (alive && (!win)){
        printf("HP MONSTER : %d\n", hp_monster);
        printf("YOUR HP : %d\n", hp_player);
        printf("INI JUMLAH GERAKAN YANG KAMU MILIKI:\n");
        printf("ACTION:\n");
        printf("1. HEAL: %d\n", heal);
        printf("2. SKIP: %d\n", skip);
        printf("ATTACK:\n");
        printf("3. SWORD: %d\n", sword);
        printf("4. SPELL: %d\n\n", spell);
        printf(" > WHAT DO YOU DO? (ATTACK/ACTION)\n > "); 
        STARTFILE();

            //INSERT BIT TREE APPLICATION HERE
        if (isWordEqual(currentWord, "ATTACK")){
            BinTree p = PlayerMove;
            p = Right(PlayerMove);
            printf("> WHAT ATTACK DO YOU WANT? (SWORD/SPELL)\n > ");
            STARTFILE();
            if (isWordEqual(currentWord, "SWORD")){
                p = Right(p);
                if(p->Info.Value > 0){
                    p->Info.Value -= 1;
                    sword = p->Info.Value;
                    printf("SERANGAN BERHASIL\n");
                    hp_monster-= 25;
                }
                else{
                    printf("PEDANG KAMU SUDAH TUMPUL, DAN KAMU DISERANG\n");
                    
                }
            } 
            else if(isWordEqual(currentWord, "SPELL")){
                p = Left(p);
                if(p->Info.Value > 0){
                    p->Info.Value -= 1;
                    spell = p->Info.Value;
                    printf("MANTRA BERHASIL\n");
                    hp_monster-= 40;
                }
                else{
                    printf("ENERGI MAGIS HABIS, DAN KAMU DISERANG\n");
                    
                }
            }
            else{
                printf("COMMAND TIDAK DIKENALI, DAN KAMU DISERANG\n");
                
            }
        }
        else if(isWordEqual(currentWord, "ACTION")){
            p = PlayerMove;
            p = Left(PlayerMove);
            printf("> WHAT ACTION DO YOU DO? (SKIP/HEAL)\n > ");
            STARTFILE();
            if (isWordEqual(currentWord, "HEAL")){
                p = Left(p);
                if(p->Info.Value > 0){
                    p->Info.Value -= 1;
                    heal = p->Info.Value;
                    printf("HEAL BERHASIL\n");
                    hp_player += 25;
                }
                else{
                    printf("RAMUAN PENYEMBUH HABIS, DAN KAMU DISERANG\n");
                    
                }
            } 
            else if(isWordEqual(currentWord, "SKIP")){
                p = RIGHT(p);
                if(p->Info.Value > 0){
                    p->Info.Value -= 1;
                    skip = p->Info.Value;
                    printf("KAMU BERISTIRAHAT DAN TIDAK BERBUAT APA-APA\n");
                }
                else{
                    printf("KAMU TIDAK BISA BERISTIRAHAT LAGI, DAN KAMU DISERANG\n");
                    
                }
            }
            else{
                printf("COMMAND TIDAK DIKENALI, DAN KAMU DISERANG\n");
                
            }
        }
        else if (isWordEqual(currentWord, "ACTION")){
            printf("So.. You're gonna Stand There and Do Nothing?\n");
        }

        RNG = GenRand(1, 3, 3);

        if (RNG == 1){
            printf("The Dragon uses Fire Breathing!\n");
            hp_player-=35;
        }
        else if (RNG == 2){
            printf("The Dragon uses it's claws!\n");
            hp_player -= 15;
        }
        else if (RNG == 3){
            printf("The Dragon swoops in... BUT IT MISSES!\n");
        }

        if (hp_monster < 1){
            win = true;
        }
        else if (hp_player < 1){
            alive = false; 
        }
        score += 2; 
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    }
    
    if (win){
        printf("YOU SLAYED THE BEAST!\n");
        printf("SCORE : %d\n", score);
    }
    else{
        score = 0;
        printf("YOU LOSE...\n");
        printf("SCORE : %d\n", score);
    }
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}