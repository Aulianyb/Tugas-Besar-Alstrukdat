#include "hangman.h"

void hangman(int *score) {
    
    TabGame listkata;
	srand(time(NULL));
    loadHANGMAN("listkata", &listkata);
    int currentscore = 0;
    int replay = 0;
    int livescount = 10;
    int mainmenu = 0;

    while (mainmenu == 0){
        printf("Apakah anda ingin menambahkan kata baru? (y/n)\n");
        STARTFILE();
        if (currentWord.TabWord[0] == 'y'){
            printf("Masukkan kata yang ingin ditambahkan: ");
            STARTFILE();
            int i;
            for (i = 0; i < currentWord.Length; i++)
            {
                listkata.TI[listkata.Neff].TabWord[i] = currentWord.TabWord[i];
            }
            listkata.TI[listkata.Neff].Length = currentWord.Length;
            listkata.Neff++;
            saveHANGMAN("listkata", listkata);
            printf("Kata berhasil ditambahkan!\n");
        }
        else if (currentWord.TabWord[0] == 'n'){
            printf("Apakah anda ingin memulai game? (y/n)\n");
            STARTFILE();
            if (currentWord.TabWord[0] == 'y'){
                mainmenu = 1;
            }
            else if (currentWord.TabWord[0] == 'n'){
                printf("Terima kasih sudah bermain!\n");
                mainmenu = 1;
                replay = 1;
                }
            }
        }

    char guessWords[listkata.Neff][16];
    int i;
    for (i = 0; i < listkata.Neff; i++)
    {
        int j;
        for (j = 0; j < listkata.TI[i].Length; j++)
        {
            guessWords[i][j] = listkata.TI[i].TabWord[j];
        }
        guessWords[i][j] = '\0';
    }

    while (replay == 0){	
	int randomIndex = rand() % 6;
	
	int numCorrect = 0;
	int oldCorrect = 0;
	
	int lengthOfWord = StringLen(guessWords[randomIndex]);
	int letterGuessed[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	
	int quit = 0;
    int IndexLetter = 0;	
	
	int IndexLooping = 0;
	int reguessed = 0;
	
	char InputLetter;
    char AllEnteredLetters[27] = {0};

        while ( numCorrect < lengthOfWord ) {

            printf("\n\nSeluruh huruf yang telah dicoba: ");
            for (int i = 0; i < IndexLetter; i++){
                printf("%c ", AllEnteredLetters[i]);
                }
        
            printf("\n\nLengkapi bagian yang kosong dibawah!:\n");
            printf("Kata yang harus diisi: \n");
        
            for( IndexLooping = 0; IndexLooping < lengthOfWord; IndexLooping++) {
            
                if(letterGuessed[IndexLooping] == 1) {
                    printf("%c",guessWords[randomIndex][IndexLooping]);				
                } else {
                    printf("_ ");
                }
            
            }	
            
            printf("\n");
        
            printf("Masukkan huruf tebakanmu! :\n");
            STARTFILE();

            if(isWordEqual(GetKataFirst(currentWord), "quit")) {
                quit = 1;
                break;
            }

            InputLetter = currentWord.TabWord[0];
            reguessed = 0; 
            oldCorrect = numCorrect;

            if(InputLetter >= 'a' && InputLetter <= 'z') {
                InputLetter = InputLetter - 32;
            } else if (InputLetter < 'A' || InputLetter > 'Z') {
                printf("Input yang diperbolehkan hanya huruf!\n");
                continue;
            }
            
            for ( IndexLooping = 0; IndexLooping < lengthOfWord; IndexLooping++) {
                for (int i = 0; i < 26; i++) {
                    if (AllEnteredLetters[i] == InputLetter) {
                        reguessed = 1;
                        }
                    }

                if( InputLetter == guessWords[randomIndex][IndexLooping] && reguessed == 0) {
                    letterGuessed[IndexLooping] = 1;
                    numCorrect++;				
                }		
            
            }
            if (reguessed == 0){
                AllEnteredLetters[IndexLetter] = InputLetter;
                IndexLetter++;
            }

            if( oldCorrect == numCorrect && reguessed == 0) {
                livescount--;
                printf("Jawabanmu salah!, nyawamu tinggal %d\n", livescount);
                if (livescount == 9){
                    printf("       \n");
                    printf("       \n");
                    printf("       \n");
                    printf("       \n");
                    printf("       \n");
                    printf("       \n");
                    printf("___|___\n");
                }
                else if (livescount == 8){
                    printf("       \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("___|___\n");
                }
                else if (livescount == 7){
                    printf("       \n");
                    printf("    __________\n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("___|___\n");
                }
                else if (livescount == 6){
                    printf("       \n");
                    printf("    __________ \n");
                    printf("   |          |\n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("___|___\n");
                }
                else if (livescount == 5){
                    printf("       \n");
                    printf("    __________ \n");
                    printf("   |          |\n");
                    printf("   |          O\n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("___|___\n");
                }
                else if (livescount == 4){
                    printf("       \n");
                    printf("    __________ \n");
                    printf("   |          |\n");
                    printf("   |          O\n");
                    printf("   |          |\n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("___|___\n");
                }
                else if (livescount == 3){
                    printf("       \n");
                    printf("    __________ \n");
                    printf("   |          |\n");
                    printf("   |          O\n");
                    printf("   |         !|\n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("___|___\n");
                }
                else if (livescount == 2){
                    printf("       \n");
                    printf("    __________ \n");
                    printf("   |          |\n");
                    printf("   |          O\n");
                    printf("   |         !|!\n");
                    printf("   |   \n");
                    printf("   |   \n");
                    printf("___|___\n");
                }
                else if (livescount == 1){
                    printf("       \n");
                    printf("    __________ \n");
                    printf("   |          |\n");
                    printf("   |          O\n");
                    printf("   |         !|!\n");
                    printf("   |         |\n");
                    printf("   |   \n");
                    printf("___|___\n");
                }
                else if (livescount == 0){
                    printf("       \n");
                    printf("    __________ \n");
                    printf("   |          |\n");
                    printf("   |          O\n");
                    printf("   |         !|!\n");
                    printf("   |         | |\n");
                    printf("   |   \n");
                    printf("___|___\n");
                    break;
                }
            } else if( reguessed == 1) {
                printf("Yahh, kamu udah pernah nebak huruf ini, coba huruf lain!\n");
            } else {
                printf("Tebakan-mu Benar!\n");
            }
        }
        
        if( quit == 1 ) {	
            printf("\nTelah keluar dari permainan\n");
            replay = 1;
        } else if (livescount == 0) {
            printf("\n Kamu kalah :( Kata yang benar adalah: %s\n",
            guessWords[randomIndex]);
            replay = 1;	
        } else  {	
            currentscore = currentscore + StringLen(guessWords[randomIndex]);
            printf("\nYeayy! Kamu Menang :D, Kamu mendapatkan %d poin!\n", StringLen(guessWords[randomIndex]));
            replay = 0;
        } 
    }
    *score = currentscore;
    printf("Skor finalmu adalah %d\n", currentscore);
}
