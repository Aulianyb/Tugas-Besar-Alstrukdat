#include <stdio.h>
#include "boolean.h"

int main(){
	//butuh cara untuk proses string multiple characters
	//sepertinya pake ADT mesin kata
	boolean on=true;
	char command[10]; //ini placeholder
	printf("========== WELCOME TO ==========\n");
	printf(" ______ _______ _______ _______\n");
	printf("|   __ \\    |  |   |   |       |\n");
	printf("|   __ \\    |  |   |   |       |\n");
	printf("|______/__|____|__|_|__|_______|\n\n");
	printf("================================\n");
	printf("\n");
	while (on){
		printf("MASUKKAN COMMAND : ");
		scanf("%s", command); //ini placeholder aja
		on=false;
	}

}