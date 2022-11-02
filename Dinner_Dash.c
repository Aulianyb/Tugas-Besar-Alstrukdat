#include <stdio.h>
#include "boolean.h"
#include "array_pesanan.h"
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
	char command[7];
	int saldo=0; 
	Tab Orders;
	MakeEmpty(&Orders);
	// Insert(&Orders, 0, 2, 3, 15000);
	// Insert(&Orders, 1, 3, 1, 10500);
	// Insert(&Orders, 2, 1, 4, 20000);
	while (play){
		printf(" Selamat Datang di Diner Dash!\n\n");
		printf(" SALDO : %d\n\n", saldo);

		printf(" Daftar Pesanan\n");
		printf(" Makanan | Durasi memasak | Ketahanan | Harga\n");
		printf("-------------------------------------------------\n");
		TulisIsi(Orders);

		printf("\n\n");
		printf(" Daftar Makanan yang sedang dimasak\n");
		printf(" Makanan | Sisa durasi memasak\n");
		printf("--------------------------------\n");
		printf("\n\n");

		printf(" Daftar Makanan yang dapat disajikan\n");
		printf(" Makanan | Sisa ketahanan makanan\n");
		printf("--------------------------------\n");
		printf("\n\n");

		printf(" MASUKKAN COMMAND: " );
		scanf("%[^\n]", command);
		printf("%s\n", command);
		if (isCook(command) || isServe(command)){
			printf("VALID\n");
		}
		else{
			printf("TIDAK VALID\n");	
		}

		printf("=======================================================\n");
		play = false;
	}
	return 0; 
}