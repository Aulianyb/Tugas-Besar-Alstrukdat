#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "Function/ADT/mesinkata.h"
#include "Function/ADT/array.h"
#include "Function/ADT/queue.h"
#include "Function/ADT/stackhistory/stackhistory.h"

#include "Function/Create_Game/Create_Game.h"
#include "Function/List_Game/List_Game.h"
#include "Function/Delete_Game/deletegame.h"
#include "Function/Help/help.h"
#include "Function/Queue_Game/queuegame.h"
#include "Function/Skip_Game/skipgame.h"
#include "Function/Play_Game/playgame.h"
// #include "Function/Dinner_Dash/Dinner_Dash.h"
#include "console.h"
#include "Function/history/history.h"

int main(){
	boolean on=false;
	TabGame T; Queue Q; StackHistory SH;
	
	char command[10]; //ini placeholder
	printf("========== WELCOME TO ==========\n");
	printf(" ______ _______ _______ _______\n");
	printf("|   __ \\    |  |   |   |       |\n");
	printf("|   __ \\    |  |   |   |       |\n");
	printf("|______/__|____|__|_|__|_______|\n\n");
	printf("================================\n");
	printf("\n");

	boolean valid=false;
	while (!valid){
		printf("=== COMMAND LIST === \n");
		printf(" - START\n - LOAD <namafile>\n");
		printf("(catatan: nama file tidak perlu menyertakan .txt)\n");
		printf("ENTER COMMAND : ");
		STARTFILE();
		if (isWordEqual(currentWord, "START")){
	    	MakeEmpty(&T); CreateEmptyHistory(&SH);
			startGAME(&T, &SH);
	    	CreateQueue(&Q);
			valid = true;
			on = true;

		} else if (isWordEqual(GetKataFirst(currentWord),"LOAD")) {
			char* filename = wordToString(GetKataSecond(currentWord));
			MakeEmpty(&T); CreateEmptyHistory(&SH);
			loadGAME(filename, &T, &SH);
			
			if (T.Neff != (-1)){
				CreateQueue(&Q);
				valid = true;
				on = true;
			}
			else printf("Save File tidak ditemukan!\n");
		}
		else printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
	}
	while (on){
		resetCurrWord(currentWord);
		printf("ENTER COMMAND : ");
		STARTFILE();
		if (isWordEqual(GetKataFirst(currentWord),"SAVE")){
			char* filename = wordToString(GetKataSecond(currentWord));
			saveGAME(filename, T, SH);
		}
		else if(isWordEqual(currentWord,"CREATE GAME")){
			CreateGame(&T);
		}
		else if(isWordEqual(currentWord, "LIST GAME")){
			ListGame(T);
		}
		else if(isWordEqual(currentWord, "DELETE GAME")){
			DeleteGame(&T);
		}	
		else if(isWordEqual(currentWord, "QUEUE GAME")){
			QueueGame(&Q, T); //PLACEHOLDER, MASIH KOSONG
		}
		else if(((isWordEqual(GetKataFirst(currentWord), "SKIP")) && (isWordEqual(GetKataSecond(currentWord), "GAME")))){
			int n = wordtoInt(GetKataThird(currentWord));
			SkipGame(&Q,n);
		}
		else if(isWordEqual(currentWord, "QUIT")){
			printf("Sebelum keluar dari program, apakah mau melakukan save terlebih dahulu? (y/n) ");
			STARTFILE();
			boolean close = false;
			while (!close)
			{
				if (isWordEqual(currentWord, "y") || isWordEqual(currentWord, "Y"))
				{
					printf("Masukkan nama file yang diinginkan: ");
					STARTFILE();
					char* filename = wordToString(currentWord);
					saveGAME(filename, T, SH);
					close = true;
				} 
				else if (isWordEqual(currentWord, "n") || isWordEqual(currentWord, "N"))
				{
					close = true;
				} 
				else 
				{
					printf("Input tidak valid!\n");
					printf("Sebelum keluar dari program, apakah mau melakukan save terlebih dahulu? (y/n) ");
					STARTFILE();
				}
			}
			quit();
			on = false;
		}
		else if (isWordEqual(currentWord, "HELP")){
			help();
		}
		else if(isWordEqual(currentWord, "PLAY GAME")){
			PlayGame(&Q, &SH);
		}
		else if(isWordEqual(currentWord, "HISTORY")){
			history(SH);
		}
		else{
			printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
		}
	}
}
