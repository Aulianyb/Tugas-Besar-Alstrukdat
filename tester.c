#include <stdio.h>
#include "array_pesanan.c"
#include "queue_cook.c"

//INI FILE BUAT NYOBA NYOBA AJA

int main(){
	Tab Tester;
	Pesanan val;
	MakeEmpty(&Tester);
	Insert(&Tester, 1, 2, 3, 10000);
	Insert(&Tester, 2, 4, 2, 15300);
	Insert(&Tester, 3, 5, 2, 56290);
	Insert(&Tester, 4, 5, 2, 50000);
	Delete(&Tester, 4, &val);
	TulisIsi_Cook(Tester);
	// char test[3];
	// test[0] = 'M';
	// test[1] = 1 + '0';
	// test[1] = 2 + '0';
	// printf("%s\n", test);
	return 0; 
}