#include <stdio.h>
#include "boolean.h"
#include "array_pesanan.h"
#include "queue_cook.h"
#include "random_generator.h"
#include "mesinkata.h"

/*Ini masih nyoba nyoba aja
Butuh ADT Queue dan Mesin Kata untuk prosesnya
*/

void empty_stdin(void) {
    int c = getchar();
    while (c != '\n' && c != EOF)
        c = getchar();
}

boolean isCook(Word Kata){
	return isWordEqual(GetKataFirst(Kata), "COOK");
}

boolean isServe(Word Kata){
	return isWordEqual(GetKataFirst(Kata), "SERVE");
}


int main(){
	boolean play = true;
	char command[8];
	int saldo=0, order_ctr=3, cook_ctr=0, served_ctr=0, made_ctr=2; 
	Tab Orders, Cook, Served;
	Pesanan temp; 
	boolean valid=false; 
	MakeEmpty(&Orders);
	MakeEmpty(&Cook);
	MakeEmpty(&Served);
	Insert(&Orders, 0, GenRand(1,5), GenRand(1,5), GenRand(10000,50000));
	Insert(&Orders, 1, GenRand(1,5), GenRand(1,5), GenRand(10000,50000));
	Insert(&Orders, 2, GenRand(1,5), GenRand(1,5), GenRand(10000,50000));
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

		valid=false; 
		//VALIDASI
		while (!valid){
			printf(" MASUKKAN COMMAND: ");
			STARTFILE();
			if ((isCook(currentWord) || isServe(currentWord)) && GetKataSecond(currentWord).TabWord[0] == 'M'){
				if (isCook(currentWord)){
					if (isMember(Orders, ))
				}
			}
			else{
				printf(" Maaf, Input tidak valid... :(\n");
			}

		}

		printf(" MASUKKAN COMMAND: ");
		scanf("%[^\n]", command);
		if (isCook(currentWord) || isServe(currentWord)){
			UpdateCook_Tab(&Cook);
			UpdateServed_Tab(&Served);
			int ctr=0;
			while ((Durasi(Cook.buffer[ctr]) == 0) && !(IsEmpty(Cook))){
				dequeue(&Cook, &temp);
				enqueue(&Served, temp);
				ctr++;
			}

			if (isCook(currentWord)) {
				Delete(&Orders, command[6] - 48, &temp);
				enqueue(&Cook, temp);
				printf(" Berhasil Memasak M%d\n", command[6] - 48);
				empty_stdin();
			}
			else{
				dequeue(&Served, &temp);
				saldo += Harga(temp);
				served_ctr++;
				printf(" Berhasil Menyajikan M%d\n", command[6] - 48);
				empty_stdin();
			}
			made_ctr++;
			Insert(&Orders, made_ctr, GenRand(1,5), GenRand(1,5), GenRand(10000,50000));
			
			for (int i=0; i < Neff(Served);i++){
				if (Ketahanan(Served.buffer[i]) == 0){
					play = false; 		
				}
			}

		}
		else{
			printf(" TIDAK VALID\n");
			play = false;	
		}
		printf("=====================================================\n");
	}
	printf(" _____ _____ _____ _____    _____ _____ _____ _____ \n");
	printf("|   __|  _  |     |   __|  |     |  |  |   __| __  |\n");
	printf("|  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n");
	printf("|_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n");
	printf("SCORE AKHIR : %d\n", saldo);                                                                  
	return 0; 
}