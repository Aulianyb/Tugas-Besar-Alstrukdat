#include <stdio.h>
#include "array_pesanan.h"
#include "queue_cook.h"
#include "random_generator.h"
#include "mesinkata.h"

//INI FILE BUAT NYOBA NYOBA AJA

boolean isServe(char *command){
	return (command[0] == 'S') && (command[1] == 'E') && (command[2] == 'R') && (command[3] == 'V') && (command[4] == 'E') && (command[5] == ' ') && (command[6] == 'M');;
}

void Printtest(char *INPUT){
	printf("HASIL : %s\n", INPUT);
}

void PrintKata(Word W){
	// printf("LENGTH : %d\n", W.Length);
	for (int i=0; i<W.Length ; i++){
		printf("%c", W.TabWord[i]);
	}
	printf("\n");
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
	// printf("%d", GenRand(1, 5));
	char command[8];
	printf("len : %d", StringLen("AULIA NADHIRAH YASMIN")); 
	boolean a=false;
	while (!a){
		printf(" MASUKKAN COMMAND:");
		STARTFILE();
		PrintKata(GetKataFirst(currentWord));
		PrintKata(GetKataSecond(currentWord));
		PrintKata(currentWord);
		if (isWordEqual(currentWord, "COOK")){
			printf("IT WORKS!\n");
			a=true;
		}
	}

	return 0; 
}