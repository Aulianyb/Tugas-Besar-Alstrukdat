#include <stdio.h>
#include "../ADT/mesinkata.h"

int main(){
	printf("Tes STARTFILE dari inputan pengguna\n");
    STARTFILE();

    printf("Tes WordToInt dari currentWord\n");
	int integerkata = WordToInt(currentWord);
	printf("kata -> int = %d\n", integerkata);

	printf("Tes ADVWORD\n");
	while (!EOP)
	{
		ADVWORD();
		PrintKata(currentWord);
        printf("\n");
	}

    printf("Tes resetCurrWord\n");
    resetCurrWord(currentWord);
    PrintKata(currentWord);
    printf("\n");

    printf("Tes STARTFILE dari untuk fungsi GetKataFirst, Second, dan Third\n");
    STARTFILE();
    printf("Tes GetKataFirst\n");
    Word kata1 = GetKataFirst(currentWord);
    PrintKata(kata1);
    printf("\n");

    printf("Tes GetKataSecond\n");
    Word kata2 = GetKataSecond(currentWord);
    PrintKata(kata2);
    printf("\n");

    printf("Tes GetKataThird\n");
    Word kata3 = GetKataThird(currentWord);
    PrintKata(kata3);
    printf("\n");

    printf("Input string untuk tes StringLen dan IsWordEqual\n");
    STARTFILE();
    printf("StringLen = %d", StringLen(currentWord.TabWord));
    
    printf("Input Word untuk dibandingkan dengan word string berkata BNMO\n");
    STARTFILE();
    isWordEqual(currentWord, "BNMO");
    //dibandingkan dengan kata BNMO

    Word val;
    val.TabWord[0] = 'B';
    val.TabWord[1] = 'N';
    val.TabWord[2] = 'M';
    val.TabWord[3] = 'O';
    isTwoWordEqual(currentWord, val);
    
}