#include <stdio.h>
#include "Dinner_Dash.h"

boolean isCook(Word Kata){
	return isWordEqual(GetKataFirst(Kata), "COOK");
}

boolean isServe(Word Kata){
	return isWordEqual(GetKataFirst(Kata), "SERVE");
}

boolean isSkip(Word Kata){
	return isWordEqual(GetKataFirst(Kata), "SKIP");	
}

void buat_pesanan(Tab *T, int label){
	Insert(T, label, GenRand(1,5,5), (GenRand(1,5,5) % 5) + 1, GenRand(10000,50000,50000));
}


void Dinner_Dash(){
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
		buat_pesanan(&Orders, i);
		Insert(&Data, i, Durasi(Orders.buffer[i]), Ketahanan(Orders.buffer[i]), Harga(Orders.buffer[i]));
	}

	printf("\n");
	printf(" ===================== Selamat Datang di ... =====================\n");
	printf("  ____  _____ _____ _____ _____ _____    ____  _____ _____ _____\n");
	printf(" |    \\|     |   | |   | |   __| __  |  |    \\|  _  |   __|  |  |\n");
	printf(" |  |  |-   -| | | | | | |   __|    -|  |  |  |     |__   |     |\n");
	printf(" |____/|_____|_|___|_|___|_____|__|__|  |____/|__|__|_____|__|__|\n\n");
	printf(" ==================================================================\n\n");
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
			if (((isCook(currentWord) || isServe(currentWord)) && GetKataSecond(currentWord).TabWord[0] == 'M') || (isSkip(currentWord))){
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
				else if(isServe(currentWord)){
					if (isMember_cook(Served, CommandInt(currentWord))){
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
				else{
					valid=true; 
				}
			}
			else{
				printf(" UH OH, INPUT TIDAK VALID !\n");
			}
		}

		//UPDATE TABLE
		UpdateCook_Tab(&Cook);
		UpdateServed_Tab(&Served);
		int ctr = 0;
		while ((ctr < Neff(Cook)) && !(IsEmpty(Cook))){
			printf("CEK M%d = %d\n", Label_int(Cook.buffer[ctr]), (Durasi(Cook.buffer[ctr]))); //-> CHECKER
			if (Durasi(Cook.buffer[ctr]) < 1){
				Delete(&Cook, Label_int(Cook.buffer[ctr]), &temp);
				printf("MOVED\n");
				enqueue_cook(&Served, temp);
				cook_ctr--;
			}
			ctr++;
		}

		//ALGORITMA UTAMA
		if (isCook(currentWord)) {
			order_ctr--;
			Delete(&Orders, CommandInt(currentWord), &temp);
			temp = Data.buffer[CommandInt(currentWord)];
			enqueue_cook(&Cook, temp);
			cook_ctr++; 
			printf(" Berhasil Memasak M%d\n", CommandInt(currentWord));
		}

		else if(isServe(currentWord)){
			dequeue_cook(&Served, &temp);
			saldo += Harga(temp);
			served_ctr++;
			printf(" Berhasil Menyajikan M%d\n", CommandInt(currentWord));
		}

		//UPDATE PESANAN
		made_ctr++;
		buat_pesanan(&Orders, made_ctr);
		order_ctr++; 
		Insert(&Data, made_ctr, Durasi(Orders.buffer[Neff(Orders)-1]), Ketahanan(Orders.buffer[Neff(Orders)-1]), Harga(Orders.buffer[Neff(Orders)-1]));

		for (int i=0; i < Neff(Served);i++){
			if (Ketahanan(Served.buffer[i]) == 0){
				printf(" PESANAN M%d HANGUS! PESANAN HARUS DIMASAK ULANG!\n", Label_int(Served.buffer[i]));
				temp = Data.buffer[Label_int(Served.buffer[i])];
				enqueue_cook(&Orders, temp);
				Delete(&Served, Label_int(Served.buffer[i]), &temp);
				order_ctr++;
			}
		}



		printf("\n =====================================================\n");
		if (served_ctr == 15 || order_ctr > 7){
			play=false;
		}
	}
	printf("  _____ _____ _____ _____    _____ _____ _____ _____ \n");
	printf(" |   __|  _  |     |   __|  |     |  |  |   __| __  |\n");
	printf(" |  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n");
	printf(" |_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n");
	printf(" SCORE AKHIR : %d\n", saldo);         
	printf(" Served Meals : %d\n", served_ctr);                                                       
}