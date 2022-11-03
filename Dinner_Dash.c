#include <stdio.h>
#include "boolean.h"
#include "array_pesanan.h"
#include "queue_cook.h"
/*Ini masih nyoba nyoba aja
Butuh ADT Queue dan Mesin Kata untuk prosesnya
*/

void empty_stdin(void) {
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

boolean isCook(char *command){
	return (command[0] == 'C') && (command[1] == 'O') && (command[2] == 'O') && (command[3] == 'K') && (command[4] == ' ') && (command[5] == 'M');
}

boolean isServe(char *command){
	return (command[0] == 'S') && (command[1] == 'E') && (command[2] == 'R') && (command[3] == 'V') && (command[4] == 'E') && (command[5] == ' ') && (command[6] == 'M');;
}

int main(){
	boolean play = true;
	char command[8];
	int saldo=0, cook_ctr=0,served_ctr=0; 
	Tab Orders, Cook, Served;
	Pesanan temp; 
	boolean valid=false; 

	MakeEmpty(&Orders);
	MakeEmpty(&Cook);
	MakeEmpty(&Served);
	Insert(&Orders, 0, 2, 3, 10000);
	Insert(&Orders, 1, 3, 1, 20000);
	Insert(&Orders, 2, 1, 4, 30000);
	printf("\n");
	printf("===================== Selamat Datang di ... =====================\n");
	printf(" ____  _____ _____ _____ _____ _____    ____  _____ _____ _____\n");
	printf("|    \\|     |   | |   | |   __| __  |  |    \\|  _  |   __|  |  |\n");
	printf("|  |  |-   -| | | | | | |   __|    -|  |  |  |     |__   |     |\n");
	printf("|____/|_____|_|___|_|___|_____|__|__|  |____/|__|__|_____|__|__|\n\n");
	printf("==================================================================\n\n");
	while (play){
		printf(" SALDO : %d\n\n", saldo);

		printf(" Daftar Pesanan\n");
		printf(" Makanan | Durasi memasak | Ketahanan | Harga\n");
		printf("-------------------------------------------------\n");
		TulisIsi(Orders);

		printf("\n\n");
		printf(" Daftar Makanan yang sedang dimasak\n");
		printf(" Makanan | Sisa durasi memasak\n");
		printf("--------------------------------\n");
		TulisIsi_Cook(Cook);
		printf("\n\n");

		printf(" Daftar Makanan yang dapat disajikan\n");
		printf(" Makanan | Sisa ketahanan makanan\n");
		printf("--------------------------------\n");
		TulisIsi_Served(Served);
		printf("\n\n");

		//UNTUK WIP VALIDASI INPUT NANTI
		valid=false; 

		printf(" MASUKKAN COMMAND: ");
		scanf("%[^\n]", command);
		if (isCook(command) || isServe(command)){
			UpdateCook_Tab(&Cook);
			UpdateServed_Tab(&Served);
			int ctr=0;
			while ((Durasi(Cook.buffer[ctr]) == 0) && !(IsEmpty(Cook))){
				dequeue(&Cook, &temp);
				enqueue(&Served, temp);
				ctr++;
			}

			if (isCook(command)) {
				Delete(&Orders, command[6] - 48, &temp);
				enqueue(&Cook, temp);
				printf("Berhasil Memasak M%d\n", command[6] - 48);
				empty_stdin();
			}
			else{
				dequeue(&Served, &temp);
				saldo += Harga(temp);
				served_ctr++;
				empty_stdin();
			}

		}
		else{
			printf(" TIDAK VALID\n");
			play = false;	
		}
		printf("=====================================================\n");
	}
	return 0; 
}