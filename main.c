#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "Create_Game.h"
#include "List_Game.h"
#include "mesinkata.h"
#include "deletegame.h"
#include "array.h"
#include "help.h"
#include "queuegame.h"
#include "queue.h"
#include "console.h"

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
			// startGAME(&T);
			valid = true;
			on = true;
		} else if (isWordEqual(GetKataFirst(currentWord),"SAVE")) {
			//char* filename = wordToString(GetKataSecond(currentWord));
			//loadGAME(filename, &T);
			valid = true;
			on = true;
		}
		else{
			printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
		}
	}
	if (isWordEqual(currentWord, "START")){
		// PLACEHOLDER
    	MakeEmpty(&T);

    	SetEl(&T,1,"RNG");
    	SetEl(&T,2,"LUNCH SLOW");
	    SetEl(&T,3,"DINOSAUR IN EARTH");
	    SetEl(&T,4,"RISEWOMAN");
	    SetEl(&T,5,"EIFFEL TOWER");

	    CreateQueue(&Q);
	}
	else if (isWordEqual(GetKataFirst(currentWord), "START")){
		printf("LOAD STATE\n");//PLACEHOLDER
	}
	while (on){
		printf("ENTER COMMAND : ");
		STARTFILE();
		if (isWordEqual(GetKataFirst(currentWord),"SAVE")){
			//char* filename = wordToString(GetKataSecond(currentWord));
			//saveGAME(filename, T);
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
		else if(isWordEqual(GetKataFirst(currentWord), "SKIPGAME")){
			printf("SKIP GAME\n"); //PLACEHOLDER, TYPE DATA GAK MATCH
			// int n = wordtoInt(GetKataSecond(currentWord));
			// skipgame(Queue_game,n)
		}
		else if(isWordEqual(currentWord, "QUIT")){
			while(!isEmpty(Q)){
				dequeue(&Q, &val);
			}
			on=false;
		}
		else if (isWordEqual(currentWord, "HELP")){
			help(1);
		}
		else if(isWordEqual(currentWord, "PLAY GAME")){
			printf("PLAY GAME\n"); 
		}
		else{
			printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
		}
	}
}
