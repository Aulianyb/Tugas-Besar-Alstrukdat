#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "array.h"
#include "help.h"

int main(){
	boolean on=false;
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
		if (isWordEqual(currentWord, "START") || isWordEqual(currentWord, "LOAD")){
			valid=true;
			on=true;
		}
		else{
			printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
		}
	}
	if (isWordEqual(currentWord, "START")){
		printf("START STATE\n");//PLACEHOLDER
	}
	else if (isWordEqual(GetKataFirst(currentWord), "START")){
		printf("LOAD STATE\n");//PLACEHOLDER
	}
	while (on){
		printf("ENTER COMMAND : ");
		STARTFILE();
		if (isWordEqual(GetKataFirst(currentWord),"SAVE")){
			printf("COMMAND SAVE\n");
		}
		else if(isWordEqual(currentWord,"CREATE GAME")){
			printf("CREATE GAME\n");
		}
		else if(isWordEqual(currentWord, "LIST GAME")){
			printf("LIST GAME\n");
		}
		else if(isWordEqual(currentWord, "DELETE GAME")){
			printf("DELETE GAME\n");
		}	
		else if(isWordEqual(currentWord, "QUEUE GAME")){
			printf("QUEUE GAME\n");
		}
		else if(isWordEqual(GetKataFirst(currentWord), "SKIPGAME")){
			printf("SKIP GAME\n");
		}
		else if(isWordEqual(currentWord, "QUIT")){
			on=false;
		}
		else if (isWordEqual(currentWord, "HELP")){
			help(1);
		}
		else{
			printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
		}
	}
}