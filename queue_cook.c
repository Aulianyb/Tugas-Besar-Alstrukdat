#include <stdio.h>
#include "queue_cook.h"

void dequeue (Tab *T){
	boolean found=false;
	for (int i=0;i<Neff(*T)-1;i++){
		Label(T->buffer[i])[1] = Label(T->buffer[i+1])[1];
		Durasi(T->buffer[i]) = Durasi(T->buffer[i+1]);
		Ketahanan(T->buffer[i]) = Ketahanan(T->buffer[i+1]);
		Harga(T->buffer[i]) = Harga(T->buffer[i+1]);
	}
	Neff(*T)--; 
}
/*Menghapus elemen pertama ke dalam Tab*/

void TulisIsi_Cook(Tab T){
	if (!(IsEmpty(T))){
		for(int i=0;i<T.Neff;i++){
			printf(" %c%c      | %d\n",Label(T.buffer[i])[0], Label(T.buffer[i])[1], Durasi(T.buffer[i]));
		}
	}
	else{
		printf("         |\n"); 
	}
}
/*Menulis CookTab*/