#include <stdio.h>
#include <stdlib.h>

#include "src/boolean.h"
#include "src/Function/List_Game/List_Game.h"
#include "src/Function/ADT/mesinkata.h"
#include "src/Function/ADT/array.h"
#include "src/Function/Help/help.h"
#include "src/Function/ADT/queue.h"
#include "src/console.h"

int main(){
	boolean on=false;
	TabGame T;
	Queue Q; 
	char* val;
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
		printf(" - START\n - LOAD \n");
		printf("ENTER COMMAND : ");
		STARTFILE();
		if (isWordEqual(currentWord, "START")){
	    	MakeEmpty(&T);
    		startGAME(&T);
	    	CreateQueue(&Q);

			valid = true;
			on = true;

		} else if (isWordEqual(GetKataFirst(currentWord),"LOAD")) {
			char* filename = wordToString(GetKataSecond(currentWord));

			loadGAME(filename, &T);
			
			if (T.Neff != (-1)){
				valid = true;
				on = true;
			}
			else printf("Save File tidak ditemukan\n");
		}
		else printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
	}
	while (on){
		printf("ENTER COMMAND : ");
		STARTFILE();
		if (isWordEqual(GetKataFirst(currentWord),"SAVE")){
			char* filename = wordToString(GetKataSecond(currentWord));
			saveGAME(filename, T);
		}
		else if(isWordEqual(currentWord, "LIST GAME")){
			ListGame(T);
		} 
		else if(isWordEqual(currentWord, "QUIT")){
			// while(!isEmpty(Q)){
			// 	dequeue(&Q, &val);
			// }
			on=false;
		}
		else if (isWordEqual(currentWord, "HELP")){
			// help(1);
		}
		else{
			printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
		}
	}
}
