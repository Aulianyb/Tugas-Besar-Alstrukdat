#include <stdio.h>
#include "RockPaperScissor.h"

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

void RockPaperScissor() {
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

    SetEl(&T,1,strToWord("Rock"));
    SetEl(&T,2,strToWord("Paper"));
    SetEl(&T,3,strToWord("Scissor"));

    int botPoints = 0, playerPoints = 0;
    int Round = 1;
    Word pilihanBot;
    Word pilihanPlayer;
    while (Round <= 11) {
        printf("========================= RONDE %d =========================\n",Round);
        printf("Masukkan pilihanmu! (rock/paper/scissor) : ");
        STARTFILE();

        while (!validRock(currentWord) && !validPaper(currentWord) && !validScissor(currentWord)) {
            resetCurrWord(currentWord);
            printf("Pilihan tidak valid! masukkan ulang pilihanmu : ");
            STARTFILE();
        }

        if (validRock(currentWord)) {
            pilihanPlayer = strToWord("Rock");
        }
        else if (validPaper(currentWord)) {
            pilihanPlayer = strToWord("Paper");
        }
        else if (validScissor(currentWord)) {
            pilihanPlayer = strToWord("Scissor");
        }

        int i = GenRand(1,3,3);
        pilihanBot = T.TI[i];

        printf("Pilihan lawan : ");
        PrintKata(pilihanBot);
        printf("\n");
        if (isTwoWordEqual(pilihanBot,pilihanPlayer)) {
            printf("Seri!\n");
        }
        else {
            if (isWordEqual(pilihanBot,"Rock")) {
                if (isWordEqual(pilihanPlayer,"Paper")) {
                    printf("Player menang! Point +100.\n");
                    playerPoints += 100;
                }
                else {
                    printf("Player kalah!\n");
                    botPoints += 100;
                }
            }
            else if (isWordEqual(pilihanBot,"Paper")) {
                if (isWordEqual(pilihanPlayer,"Scissor")) {
                    printf("Player menang! Point +100.\n");
                    playerPoints += 100;
                }
                else {
                    printf("Player kalah!\n");
                    botPoints += 100;
                }
            }
            else {
                if (isWordEqual(pilihanPlayer,"Rock")) {
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
        Round++;
    }

    printf("========================= END OF MATCH =========================\n");
    printf("Permainan selesai!\n");
    if (playerPoints > botPoints) {
        printf("Player memenangkan permainan!\n");
        printf("Skor Player : %d\n",playerPoints);
        printf("Skor Lawan : %d\n",botPoints);
    }
    else if (playerPoints == botPoints) {
        printf("Player dan lawan seri!\n");
        printf("Skor Player : %d\n",playerPoints);
        printf("Skor Lawan : %d\n",botPoints);
    }
    else {
        printf("Player kalah dalam permainan!\n");
        printf("Skor Player : %d\n",playerPoints);
        printf("Skor Lawan : %d\n",botPoints);
    }
}