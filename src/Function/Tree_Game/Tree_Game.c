#include "Tree_Game.h"

void MoveTree(BinTree *Move){
    *Move = Tree (-1, NilTree, NilTree);
    AddDaun (Move, -1, -2, true);
    AddDaun (Move, -1, -3, false);
    AddDaun (&Left(*Move), -2, 3, true);
    AddDaun (&Left(*Move), -2, 5, false);
    AddDaun (&Right(*Move), -3, 2, true);
    AddDaun (&Right(*Move), -3, 6, false);
}
int SlayTheDragon(){
    boolean alive=true, win=false;
    BinTree PlayerMove;
    MoveTree(&PlayerMove);
    int hp_player=100, hp_monster=100, score=0, RNG, heal, sword, spell, skip;
    heal = Akar(Left(Left(PlayerMove)));
    skip = Akar(Right(Left(PlayerMove)));
    spell = Akar(Left(Right(PlayerMove)));
    sword = Akar(Right(Right(PlayerMove)));
    
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
    printf("You slowly make your way up to snowy mountains,\nthe beast's lair.\n\n");
    delay(1000);
    printf("You finally reached the lair's entrance. \nYou tried sneaking in but suddenly \na loud roar came from inside the cave. \n\n");
    delay(1000);
    printf("Two yellow eyes emerge from the dark, followed by\nthe grand entrance of the Red Dragon.\n\n");
    delay(1000);
    printf("                \\||/\n");
        printf("                |  @___oo\n");
        printf("      /\\  /\\   / (__,,,,|\n");
        printf("     ) /^\\) ^\\/ _)\n");
        printf("     )   /^\\/   _)\n");
        printf("     )   _ /  / _)\n");
        printf(" /\\  )/\\/ ||  | )_)\n");
        printf("<  >      |(,,) )__)\n");
        printf(" ||      /    \\)___)                O\n");
        printf(" | \\____(      )___) )___          /|\\ \n");
        printf("  \\______(_______;;; __;;;         / \\ \n\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    while (alive && (!win)){
        printf("HP MONSTER : %d\n", hp_monster);
        printf("YOUR HP : %d\n", hp_player);
        printf("THIS IS THE NUMBER OF MOVES AVAILABLE TO YOU:\n");
        printf("ACTION:\n");
        printf("1. HEAL: %d\n", heal);
        printf("2. SKIP: %d\n", skip);
        printf("ATTACK:\n");
        printf("3. SWORD: %d\n", sword);
        printf("4. SPELL: %d\n\n", spell);
        printf("> WHAT DO YOU DO? (ATTACK/ACTION)\n > "); 
        STARTFILE();

            //INSERT BIT TREE APPLICATION HERE
        if (isWordEqual(currentWord, "ATTACK")){
            BinTree p = PlayerMove;
            p = Right(PlayerMove);
            printf("> WHAT ATTACK DO YOU WANT? (SWORD/SPELL)\n > ");
            STARTFILE();
            if (isWordEqual(currentWord, "SWORD")){
                p = Right(p);
                if(p->Info > 0){
                    p->Info -= 1;
                    sword = p->Info;
                    printf("You slashed the Dragon.\n\n");
                    hp_monster-= 25;
                }
                else{
                    printf("Your sword has become dull, the Dragon attacks you!!\n\n");
                    
                }
            } 
            else if(isWordEqual(currentWord, "SPELL")){
                p = Left(p);
                if(p->Info > 0){
                    p->Info -= 1;
                    spell = p->Info;
                    printf("You casted a spell and hit the Dragon.\n\n");
                    hp_monster-= 40;
                }
                else{
                    printf("You ran out of Mana, the Dragon attacks you!!\n\n");
                    
                }
            }
            else{
                printf("Command not recognized, the Dragon attacks you for wasting your turn!!\n\n");
                
            }
        }
        else if(isWordEqual(currentWord, "ACTION")){
            BinTree p = PlayerMove;
            p = Left(PlayerMove);
            printf("> WHAT ACTION DO YOU DO? (SKIP/HEAL)\n> ");
            STARTFILE();
            if (isWordEqual(currentWord, "HEAL")){
                p = Left(p);
                if(p->Info > 0){
                    p->Info -= 1;
                    heal = p->Info;
                    printf("You drank your healing potion and heal yourself.\n");
                    hp_player += 25;
                    printf("HP +25\n\n");
                }
                else{
                    printf("You ran out of healing potions, the Dragon attacks you!!\n\n");
                    
                }
            } 
            else if(isWordEqual(currentWord, "SKIP")){
                p = Right(p);
                if(p->Info > 0){
                    p->Info -= 1;
                    skip = p->Info;
                    printf("You take a rest and prepare yourself.\n");
                    int Generate = GenRand(1, 3, 3);
                    if(Generate == 1){
                        Akar(Left(Left(PlayerMove))) += 1;
                        heal = Akar(Left(Left(PlayerMove)));
                        printf("Heal +1\n\n");
                    }
                    else if(Generate == 2){
                        Akar(Left(Right(PlayerMove))) += 1;
                        spell = Akar(Left(Right(PlayerMove)));
                        printf("Spell +1\n\n");
                    }
                    else if(Generate == 3){
                        Akar(Right(Right(PlayerMove))) += 1;
                        sword = Akar(Right(Right(PlayerMove)));
                        printf("Sword +1\n\n");
                    }
                }
                else{
                    printf("You rested too many times, the Dragon attacks you!!\n\n");
                    
                }
            }
            else{
                printf("Command not recognized, the Dragon attacks you for wasting your turn!!\n\n");
                
            }
        }
        else{
            printf("Command not recognized, the Dragon attacks you for wasting your turn!!\n\n");
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
        if(hp_player >= 100){
            score = 100;
        } 
        else{
            score = hp_player;
        }
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