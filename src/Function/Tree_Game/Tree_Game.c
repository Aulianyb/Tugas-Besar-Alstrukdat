#include "Tree_Game.h"
void MoveTree(){
    BinTree Move;
    MakeTree (move, -1, NilTree, NilTree, BinTree *Move);
    AddDaun (&Move, move, action, -2, true);
    AddDaun (&Move, move, attack, -3, false);
    AddDaun (&Left(*Move), action, heal, 2, true);
    AddDaun (&Left(*Move), action, skip, 5, false);
    AddDaun (&Right(*Move), action, spell, 2, true);
    AddDaun (&Right(*Move), action, sword, 6, false);
}
int main(){
    boolean alive=true, win=false;
    int hp_player=100, hp_monster=100, score=0, RNG;
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
        printf(" > WHAT DO YOU DO?\n > "); 
        STARTFILE();

        //INSERT BIT TREE APPLICATION HERE
        
        if (isWordEqual(currentWord, "ATTACK")){
            hp_monster-= 25; 
        }
        else{
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