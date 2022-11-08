#include "random_generator.h"
#include "mesinkata.h"
#include <stdio.h>
#include "array.h"

boolean validRock(Word word) {
    return (currentWord.Length == 4 && (currentWord.TabWord[0] == 'R' || currentWord.TabWord[0] == 'r') && (currentWord.TabWord[1] == 'O' || currentWord.TabWord[1] == 'o') && (currentWord.TabWord[2] == 'C' || currentWord.TabWord[2] == 'c') && (currentWord.TabWord[3] == 'K' || currentWord.TabWord[3] == 'k'));
}

boolean validPaper(Word word) {
    return (currentWord.Length == 5 && (currentWord.TabWord[0] == 'P' || currentWord.TabWord[0] == 'p') && (currentWord.TabWord[1] == 'A' || currentWord.TabWord[1] == 'a') && (currentWord.TabWord[2] == 'P' || currentWord.TabWord[2] == 'p') && (currentWord.TabWord[3] == 'E' || currentWord.TabWord[3] == 'e') && (currentWord.TabWord[4] == 'R' || currentWord.TabWord[4] == 'r'));
}

boolean validScissor(Word word) {
    return (currentWord.Length == 7 && (currentWord.TabWord[0] == 'S' || currentWord.TabWord[0] == 's') && (currentWord.TabWord[1] == 'C' || currentWord.TabWord[1] == 'c') && (currentWord.TabWord[2] == 'I' || currentWord.TabWord[2] == 'i') && (currentWord.TabWord[3] == 'S' || currentWord.TabWord[3] == 's') &&
        (currentWord.TabWord[4] == 'S' || currentWord.TabWord[4] == 's') && (currentWord.TabWord[5] == 'O' || currentWord.TabWord[5] == 'o') && (currentWord.TabWord[6] == 'R' || currentWord.TabWord[6] == 'r'));
}

int main() {
    printf("*********   **********  **********  *       *                **********  **********  **********  **********  *********                **********  **********  *****  **********  **********  **********  ********* \n");
    printf("*        *  *        *  *           *     *                  *        *  *        *  *        *  *           *        *               *           *           *   *  *           *           *        *  *        *\n");
    printf("*   **   *  *   **   *  *           *   *                    *   **   *  *   **   *  *   **   *  *           *   **   *               *           *           *   *  *           *           *   **   *  *   **   *\n");
    printf("*        *  *   **   *  *           * *         ===========  *        *  *        *  *        *  *           *        *  ===========  *           *           *   *  *           *           *   **   *  *        *\n");
    printf("*********   *   **   *  *           **          ===========  **********  **********  **********  **********  *********   ===========  **********  *           *   *  **********  **********  *   **   *  ********* \n");
    printf("**          *   **   *  *           * *         ===========  *           *        *  *           *           **          ===========           *  *           *   *           *           *  *   **   *  **        \n");
    printf("*  *        *   **   *  *           *   *                    *           *        *  *           *           *  *                              *  *           *   *           *           *  *   **   *  *  *      \n");
    printf("*    *      *        *  *           *     *                  *           *        *  *           *           *    *                            *  *           *   *           *           *  *        *  *    *    \n");
    printf("*      *    **********  **********  *       *                *           *        *  *           **********  *      *                 **********  **********  *****  **********  **********  **********  *      *  \n");

    TabGame T;
    MakeEmpty(&T);

    SetEl(&T,1,"Rock");
    SetEl(&T,2,"Paper");
    SetEl(&T,3,"Scissor");

    int botPoints = 0, playerPoints = 0;
    ElType pilihanBot,pilihanPlayer;
    while (botPoints != 500 && playerPoints != 500) {
        printf("Masukkan pilihanmu! (rock/paper/scissor) : ");
        STARTFILE();

        while (!validRock(currentWord) && !validPaper(currentWord) && !validScissor(currentWord)) {
            resetCurrWord(currentWord);
            printf("Pilihan tidak valid! masukkan ulang pilihanmu : ");
            STARTFILE();
        }

        if (validRock(currentWord)) {
            pilihanPlayer = "Rock";
        }
        else if (validPaper(currentWord)) {
            pilihanPlayer = "Paper";
        }
        else if (validScissor(currentWord)) {
            pilihanPlayer = "Scissor";
        }

        int i = GenRand(1,3,3);
        pilihanBot = T.TI[i];

        printf("Pilihan lawan : %s\n",pilihanBot);
        if (pilihanBot == pilihanPlayer) {
            printf("Seri!\n");
        }
        else {
            if (pilihanBot == "Rock") {
                if (pilihanPlayer == "Paper") {
                    printf("Player menang! Point +100.\n");
                    playerPoints += 100;
                }
                else {
                    printf("Player kalah!\n");
                    botPoints += 100;
                }
            }
            else if (pilihanBot == "Paper") {
                if (pilihanPlayer == "Scissor") {
                    printf("Player menang! Point +100.\n");
                    playerPoints += 100;
                }
                else {
                    printf("Player kalah!\n");
                    botPoints += 100;
                }
            }
            else {
                if (pilihanPlayer == "Rock") {
                    printf("Player menang! Point +100.\n");
                    playerPoints += 100;
                }
                else {
                    printf("Player kalah!\n");
                    botPoints += 100;
                }
            }
        }
        resetCurrWord(currentWord);
    }

    printf("Permainan selesai!\n");
    if (playerPoints == 500) {
        printf("Player memenangkan permainan!\n");
    }
    else {
        printf("Player kalah dalam permainan!\n");
    }

    return 0;
}