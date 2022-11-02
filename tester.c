#include <stdio.h>
#include "queue_cook.h"

//INI FILE BUAT NYOBA NYOBA AJA

boolean isServe(char *command){
	return (command[0] == 'S') && (command[1] == 'E') && (command[2] == 'R') && (command[3] == 'V') && (command[4] == 'E') && (command[5] == ' ') && (command[6] == 'M');;
}


int main(){
	Tab Tester;
	Pesanan val;
	MakeEmpty(&Tester);
	Insert(&Tester, 1, 2, 3, 10000);
	Insert(&Tester, 2, 4, 2, 15300);
	Insert(&Tester, 3, 5, 2, 56290);
	Insert(&Tester, 4, 5, 2, 50000);
	Delete(&Tester, 4, &val);
	TulisIsi_Cook(Tester);
	char command[8];

	printf(" MASUKKAN COMMAND:");
	scanf("%[^\n]", command);

	if (isServe(command)){
		printf("VALID");
	}
	// char test[3];
	// test[0] = 'M';
	// test[1] = 1 + '0';
	// test[1] = 2 + '0';
	// printf("%s\n", test);
	return 0; 
}