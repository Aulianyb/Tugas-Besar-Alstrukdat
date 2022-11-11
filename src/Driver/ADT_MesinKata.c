#include <stdio.h>
#include "../Function/ADT/mesinkata.h"

int main(){
    printf("=========== DRIVER MESIN KATA ===========\n");
	printf("Tes STARTFILE dari inputan pengguna, masukkan angka\n");
    printf("MASUKKAN INPUT : ");
    STARTFILE();
    printf("INPUT ADALAH : ");
    PrintKata(currentWord);
    printf("\n");
    printf("\n");

    printf("=== Tes WordToInt dari currentWord ===\n");
	int integerkata = WordToInt(currentWord);
	printf("kata -> int = %d\n", integerkata);
    printf("\n");


	printf("=== Tes ADVWORD ===\n");
    printf("MASUKKAN INPUT 3 BUAH KATA : ");
	STARTFILE();
     //    while (!EOP)
    	// {
    	// 	ADVWORD();
    	// 	PrintKata(currentWord);
     //        printf("\n");
    	// }
     //    printf("\n");

    printf("=== Tes resetCurrWord ===\n");
    resetCurrWord(currentWord);
    printf("Mengubah CK menjadi kosong\n");
    printf("CK : \n");
    PrintKata(currentWord);
    printf("\n");

    printf("=== Tes fungsi GetKataFirst, Second, dan Third ===\n");
    printf("Tes GetKataFirst\n");
    Word kata1 = GetKataFirst(currentWord);
    PrintKata(kata1);
    printf("\n");
    printf("\n");


    printf("Tes GetKataSecond\n");
    Word kata2 = GetKataSecond(currentWord);
    PrintKata(kata2);
    printf("\n");
    printf("\n");


    printf("Tes GetKataThird\n");
    Word kata3 = GetKataThird(currentWord);
    PrintKata(kata3);
    printf("\n");
    printf("\n");

    printf("=== Input string untuk tes StringLen dan IsWordEqual ===\n");
    printf("MASUKKAN INPUT : ");
    STARTFILE();
    printf("StringLen = %d", StringLen(currentWord.TabWord));
    printf("\n");
    printf("\n");

    

    printf("=== Input Word untuk dibandingkan dengan word string berkata BNMO ===\n");
    printf("RETURN : %d",isWordEqual(GetKataFirst(currentWord), "BNMO"));
    //dibandingkan dengan kata BNMO

    Word val;
    val.TabWord[0] = 'B';
    val.TabWord[1] = 'N';
    val.TabWord[2] = 'M';
    val.TabWord[3] = 'O';
    val.Length = 4;
    isTwoWordEqual(currentWord, val);
    printf("\n");
    printf("\n");
    
    printf("=== TEST GET LABEL ===\n");
    currentWord.TabWord[0] = 'M';
    currentWord.TabWord[1] = '1';
    currentWord.TabWord[2] = '2';
    currentWord.Length = 3; 
    printf("Dengan input M12, expected output = 12\n" );
    printf("output : ");
    PrintKata(GetLabel(currentWord));
    printf("\n");
    printf("\n");

    printf("=== TEST INTTOWORD ===\n");
    printf("Dengan input 12, expected output = 12 dalam tipe data Word\n" );
    printf("output : ");
    PrintKata(IntToWord(12));

    printf("\n");
    printf("\n");

    printf("=== TEST MERGEWORD ===\n");
    currentWord.TabWord[0] = 'B';
    currentWord.TabWord[1] = 'N';
    currentWord.Length = 2; 
    printf("output kata pertama : ");
    PrintKata(currentWord);
    printf("\n");


    kata1.TabWord[0] = 'M';
    kata1.TabWord[1] = 'O';
    kata1.Length = 2; 
    printf("output kata kedua : ");
    PrintKata(kata1);
    printf("\n");


    MergeWord(&currentWord, kata1);
    printf("output MergeWord : ");
    PrintKata(currentWord);
    printf("\n");
    printf("\n");


    printf("=== TEST STRTOWORD ===\n");
    char temp[5];
    temp[0] = 'B';
    temp[1] = 'N';
    temp[2] = 'M';
    temp[3] = 'O';

    val = strToWord(temp);
    PrintKata(val);
    printf("\n");

}