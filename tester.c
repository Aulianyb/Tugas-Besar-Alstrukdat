#include <stdio.h>
#include "array_pesanan.h"
#include "queue_cook.h"
#include "random_generator.h"

//INI FILE BUAT NYOBA NYOBA AJA

boolean isServe(char *command){
	return (command[0] == 'S') && (command[1] == 'E') && (command[2] == 'R') && (command[3] == 'V') && (command[4] == 'E') && (command[5] == ' ') && (command[6] == 'M');;
}


int main(){
	Tab Tester, Cook;
	Pesanan val;
	MakeEmpty(&Tester);
	MakeEmpty(&Cook);
	Insert(&Tester, 0, 2, 3, 10000);
	Insert(&Tester, 1, 3, 1, 15300);
	Insert(&Tester, 2, 1, 4, 56290);
	Insert(&Tester, 4, 4, 2, 50000);
	Delete(&Tester, 0, &val);
	enqueue(&Cook, val);
	Delete(&Tester, 1, &val);
	enqueue(&Cook, val);
	Delete(&Tester, 2, &val);
	enqueue(&Cook, val);
	printf("---------------------------------------------\n");
	TulisIsi(Tester);
	printf("---------------------------------------------\n");
	TulisIsi_Cook(Cook);
	printf("---------------------------------------------\n");
	if (isMember(Cook, 1)){
		printf("FOUND\n");
	}
	else{
		printf("NOT FOUND\n");
	}
	printf("%d", GenRand(1, 5));
	char command[8];

	// printf(" MASUKKAN COMMAND:");
	// scanf("%[^\n]", command);

	// if (isServe(command)){
	// 	printf("VALID");
	// }
	// char test[3];
	// test[0] = 'M';
	// test[1] = 1 + '0';
	// test[1] = 2 + '0';
	// printf("%s\n", test);
	return 0; 
}