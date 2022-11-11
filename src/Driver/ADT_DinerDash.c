#include "../Function/Dinner_Dash/Dinner_Dash.h"
#include <stdio.h>


/*DRIVER INI BERISI SELURUH ADT YANG DIPAKAI DALAM GAME DINER DASH*/

int main(){
	//KAMUS
	Tab T;
	Pesanan temp;
	//KONSTRUKTOR
	MakeEmpty_pesanan(&T);

	//OUTPUT
	printf("Hasil MakeEmpty_Pesanan(Tab *T)\n");
	TulisIsi_pesanan(T);
	printf("\n");

	//TEST KOSONG/PENUH
	printf("Hasil IsEmpty_pesanan(Tab T) kepada Tab T");
	if (IsEmpty_pesanan(T)){
		printf("Tab Pesanan Kosong\n");
	}
	printf("Dilakukan pengisian Tab T sebanyak 20 elemen\n");

	for (int i=0; i < 20; i++){
		buat_pesanan(&T, i);
	}

	if (IsFull_pesanan(T)){
		printf("Tab Pesanan Penuh\n");
	}

}