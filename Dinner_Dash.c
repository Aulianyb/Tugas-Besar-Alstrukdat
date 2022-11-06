#include <stdio.h>
#include "boolean.h"
#include "array_pesanan.h"
#include "queue_cook.h"
#include "random_generator.h"
#include "mesinkata.h"

/*Ini masih nyoba nyoba aja
Butuh ADT Queue dan Mesin Kata untuk prosesnya
*/
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
	Tab Orders, Cook, Served, Data;
	Pesanan temp; 
	boolean valid=false; 
	MakeEmpty(&Orders);
	MakeEmpty(&Cook);
	MakeEmpty(&Served);
	MakeEmpty(&Data);

	for (int i = 0;i<3;i++){
		Insert(&Orders, i, 2, GenRand(1,5), GenRand(10000,50000));
		Insert(&Data, i, Durasi(Orders.buffer[i]), Ketahanan(Orders.buffer[i]), Harga(Orders.buffer[i]));
	}

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
		//VALIDASI INPUT
		while (!valid){
			printf(" MASUKKAN COMMAND: ");
			STARTFILE();
			if ((isCook(currentWord) || isServe(currentWord)) && GetKataSecond(currentWord).TabWord[0] == 'M'){
				if (isCook(currentWord)){
					if (made_ctr >= CommandInt(currentWord)){
						if (cook_ctr < 5){
							valid=true;
						}
						else{
							printf("Jumlah Maksimal Yang dapat dimasak adalah 5 Pesanan!\n");
						}
					}
					else{
						printf(" Belum ada yang memesan M%d!\n", CommandInt(currentWord));
					}
				}
				else{
					if (isMember(Served, CommandInt(currentWord))){
						if (served_ctr >= CommandInt(currentWord)){
							valid=true;
						}
						else{
							printf(" Pesanan M%d belum dapat disajikan karena antrian sebelumnya belum disajikan!\n", CommandInt(currentWord));
						}
					}
					else{
						printf(" Pesanan M%d belum selesai dimasak!\n", CommandInt(currentWord));
					}
				}
			}
			else{
				printf(" UH OH, INPUT TIDAK VALID !\n");
			}
		}

		//UPDATE TABLE
		UpdateCook_Tab(&Cook);
		UpdateServed_Tab(&Served);

		//ALGORITMA UTAMA
		if (isCook(currentWord)) {
			Delete(&Orders, CommandInt(currentWord), &temp);
			temp = Data.buffer[CommandInt(currentWord)];
			enqueue(&Cook, temp);
			cook_ctr++; 
			printf(" Berhasil Memasak M%d\n", CommandInt(currentWord));
		}

		else{
			dequeue(&Served, &temp);
			saldo += Harga(temp);
			served_ctr++;
			printf(" Berhasil Menyajikan M%d\n", CommandInt(currentWord));
		}

		made_ctr++;
		Insert(&Orders, made_ctr, GenRand(1,5), GenRand(1,5), GenRand(10000,50000));
		Insert(&Data, made_ctr, Durasi(Orders.buffer[Neff(Orders)-1]), Ketahanan(Orders.buffer[Neff(Orders)-1]), Harga(Orders.buffer[Neff(Orders)-1]));
		
		int ctr=0;
		while ((ctr < Neff(Cook)) && !(IsEmpty(Cook))){
			printf("CEK DURASI : %d\n", Durasi(Cook.buffer[ctr]));
			if (Durasi(Cook.buffer[ctr]) < 1){
				dequeue(&Cook, &temp);
				enqueue(&Served, temp);
				cook_ctr--;
			}
			ctr++;
		}

		for (int i=0; i < Neff(Served);i++){
			if (Ketahanan(Served.buffer[i]) == 0){
				printf(" PESANAN M%d HANGUS! PESANAN HARUS DIMASAK ULANG!\n", Label_int(Served.buffer[i]));
				temp = Data.buffer[Label_int(Served.buffer[i])];
				enqueue(&Orders, temp);
				Delete(&Served, Label_int(Served.buffer[i]), &temp);
			}
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