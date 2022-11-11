#include "../ADT/mesinkata.h"

int main(){
	printf("Tes STARTINPUTKATA dari inputan pengguna\n");
    STARTFILE();

    printf("Tes WordToInt dari currentWord\n");
	int integerkata = WordToInt(currentWord);
	printf("kata -> int = %d\n", integerkata);

	printf("Tes ADVWORD\n");
	while (!EOP)
	{
		ADVWORD();
		PrintKata(currentWord);
	}

    printf("Tes resetCurrWord\n");
    resetCurrWord(currentWord);
    PrintKata(currentWord);

    STARTFILE();
    printf("Tes GetKataFirst\n");
    Word kata1 = GetKataFirst(currentWord);
    PrintKata(kata1);

    printf("Tes GetKataSecond\n");
    Word kata2 = GetKataSecond(currentWord);
    PrintKata(kata2);

    printf("Tes GetKataThird\n");
    Word kata3 = GetKataThird(currentWord);
    PrintKata(kata3);
    
}