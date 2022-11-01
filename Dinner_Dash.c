#include <stdio.h>
#include "boolean.h"
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
	while (play){
		printf("Selamat Datang di Diner Dash!\n");
		printf("SALDO : 0\n\n" );
		printf("MASUKKAN COMMAND: " );
		scanf("%[^\n]", command);
		printf("%s\n", command);
		if (isCook(command) || isServe(command)){
			printf("VALID");
		}
		else{
			printf("TIDAK VALID");	
		}
		play = false;
	}
	return 0; 
}