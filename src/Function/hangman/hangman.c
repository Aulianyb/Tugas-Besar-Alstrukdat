#include "hangman.h"

void hangman(int *score) {
    
    // Inisiasi beberapa variable
    TabGame listkata;
	srand(time(NULL));
    loadHANGMAN("listkata", &listkata);
    int currentscore = 0;
    int replay = 0;
    int livescount = 10;
    int mainmenu = 0;

    // Looping Main menu (untuk menambahkan kata)
    while (mainmenu == 0){
        printf("Apakah anda ingin menambahkan kata baru? (y/n)\n");
        STARTFILE();
        if (currentWord.TabWord[0] == 'y'){
            printf("Masukkan kata yang ingin ditambahkan (seluruh huruf wajib dalam bentuk KAPITAL): ");
            STARTFILE();
            // Check if the added word is already in the list
            int j = 0;
            int found = 0;
            while (j <= listkata.Neff && found == 0){
                if (isTwoWordEqual(currentWord, listkata.TI[j])){
                    found = 1;
                }
                j++;
            }
            if (found == 1){
                printf("Kata sudah ada dalam list kata! Masukkan kata lain\n");
            }
            else{
            int i;
            // memasukkan kata ke listkata
            for (i = 0; i < currentWord.Length; i++)
            {
                listkata.TI[listkata.Neff].TabWord[i] = currentWord.TabWord[i];
            }
            listkata.TI[listkata.Neff].Length = currentWord.Length;
            listkata.Neff++;
            saveHANGMAN("listkata", listkata);
            printf("Kata berhasil ditambahkan!\n");
            }
        }
        else if (currentWord.TabWord[0] == 'n'){
            printf("Selamat bermain hangman!\n");
            mainmenu = 1;
            }
        }

    // memasuki looping game
    while (replay == 0){	

    // inisialisasi variable
	int randomIndex = rand() % 10;
	
	int numCorrect = 0;
	int oldCorrect = 0;
	
	int lengthOfWord = listkata.TI[randomIndex].Length;
	int letterGuessed[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	
    int IndexLetter = 0;	
	
	int IndexLooping = 0;
	int reguessed = 0;
	
	char InputLetter;
    char AllEnteredLetters[27] = {0};
        // looping untuk proses penjawaban soal
        while ( numCorrect < lengthOfWord ) {

            printf("\n\n\n\n\n\nSeluruh huruf yang telah dicoba: ");
            for (int i = 0; i < IndexLetter; i++){
                printf("%c ", AllEnteredLetters[i]);
                }
            printf("\nNyawamu masih ada %d nih!", livescount);
            printf("\n\nLengkapi bagian yang kosong dibawah!:\n");
            
            printf("Panjang Kata: %d\n", lengthOfWord);
            for( IndexLooping = 0; IndexLooping < lengthOfWord; IndexLooping++) {
                // Looping print soal
                if(letterGuessed[IndexLooping] == 1) {
                    printf("%c", listkata.TI[randomIndex].TabWord[IndexLooping]);				
                } else {
                    printf(" _ ");
                }
            
            }	
            
            printf("\n");
        
            printf("\nMasukkan huruf tebakanmu! :\n");
            STARTFILE();

            InputLetter = currentWord.TabWord[0];
            reguessed = 0; 
            oldCorrect = numCorrect;

            // Konversi huruf kecil ke huruf besar
            if(InputLetter >= 'a' && InputLetter <= 'z') {
                InputLetter = InputLetter - 32;
            } else if (InputLetter < 'A' || InputLetter > 'Z') {
                printf("Input yang diperbolehkan hanya huruf!\n");
                continue;
            }
            
            for ( IndexLooping = 0; IndexLooping < lengthOfWord; IndexLooping++) {
                for (int i = 0; i < 26; i++) {
                    // Loop untuk pengecekan apabila huruf pernah dimasukkan sebelumnya
                    if (AllEnteredLetters[i] == InputLetter) {
                        reguessed = 1;
                        }
                    }

                if( InputLetter == listkata.TI[randomIndex].TabWord[IndexLooping] && reguessed == 0) {
                    letterGuessed[IndexLooping] = 1;
                    numCorrect++;				
                }		
            
            }
            if (reguessed == 0){
                // Penambahan huruf yang belum pernah di masukkan ke list huruf yang pernah dimasukkan
                AllEnteredLetters[IndexLetter] = InputLetter;
                IndexLetter++;
            }

            if( oldCorrect == numCorrect && reguessed == 0) {
                livescount--;
                printf("\nJawabanmu salah! Nyawamu berkurang satu!\n");
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
                printf("Tebakan-mu Benar!\n ");
            }
        }
        
        if (livescount == 0) {
            // Jika nyawa habis, maka game akan langsung berhenti dan jawaban di spill
            printf("\nKamu kalah :( Kata yang benar adalah: %s\n",
            wordToString(listkata.TI[randomIndex]));
            replay = 1;	
        } else  {	
            currentscore = currentscore + listkata.TI[randomIndex].Length ;
            printf("\nYeayy! Kamu Menang :D, Kamu mendapatkan %d poin!\n", listkata.TI[randomIndex].Length);
            replay = 0;
            printf("Kata yang kamu tebak adalah %s\n", wordToString(listkata.TI[randomIndex]));
        } 
    }
    *score = currentscore;
}
