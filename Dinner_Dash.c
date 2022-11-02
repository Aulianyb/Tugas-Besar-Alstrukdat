#include <stdio.h>
#include "boolean.h"
#include "array_pesanan.h"
#include "queue_cook.h"
/*Ini masih nyoba nyoba aja
Butuh ADT Queue dan Mesin Kata untuk prosesnya
*/

boolean isCook(char *command){
	return (command[0] == 'C') && (command[1] == 'O') && (command[2] == 'O') && (command[3] == 'K') && (command[4] == ' ') && (command[5] == 'M');
}

boolean isServe(char *command){
	return (command[0] == 'S') && (command[1] == 'E') && (command[2] == 'R') && (command[3] == 'V') && (command[4] == 'E') && (command[4] == ' ') && (command[5] == 'M');;
}

int main(){
	boolean play = true;
	char command[8];
	int saldo=0; 
	Tab Orders, Cook, Served;
	Pesanan temp; 

	MakeEmpty(&Orders);
	MakeEmpty(&Cook);
	MakeEmpty(&Served);
	Insert(&Orders, 0, 2, 3, 10000);
	Insert(&Orders, 1, 3, 1, 20000);
	Insert(&Orders, 2, 1, 4, 30000);
	printf(" Selamat Datang di Diner Dash!\n\n");
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
		printf("\n\n");

		printf(" MASUKKAN COMMAND:");
		scanf("%[^\n]", command);
		printf("%s\n", command);
		if (isCook(command) || isServe(command)){
			if (isCook(command)) {
				Delete(&Orders, command[6] - 48, &temp);
				printf("%s, %d",Label(temp), Durasi(temp));
				Insert(&Cook, Label(temp)[1] - 48, Durasi(temp), Ketahanan(temp), Harga(temp));
				printf(" Daftar Pesanan\n");
				printf(" Makanan | Durasi memasak | Ketahanan | Harga\n");
				printf("-------------------------------------------------\n");
				TulisIsi(Orders);
				printf(" Daftar Makanan yang sedang dimasak\n");
				printf(" Makanan | Sisa durasi memasak\n");
				printf("--------------------------------\n");
				TulisIsi_Cook(Cook);
			printf("\n\n");
			}
			else{

			}
		}
		else{
			printf("ENDED\n");	
		}
		play = false;
		printf("=====================================================\n");
	}
	return 0; 
}