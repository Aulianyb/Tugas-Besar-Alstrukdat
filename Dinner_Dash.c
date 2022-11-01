#include <stdio.h>
#include "boolean.h"
/*Ini masih nyoba nyoba aja
Butuh ADT Queue dan Mesin Kata untuk prosesnya
*/
int main(){
	boolean play = true;
	char command[7];
	while (play){
		printf("Selamat Datang di Diner Dash!\n");
		printf("SALDO : 0\n\n" );
		printf("MASUKKAN COMMAND: " );
		scanf("%[^\n]", command);
		printf("%s", command);
		play = false;
	}
	return 0; 
}