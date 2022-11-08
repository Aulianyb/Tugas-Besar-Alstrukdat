#include <stdio.h>
#include "queue_cook.h"

void enqueue (Tab *T, Pesanan val){
	int i=0;
	boolean found=false;
	if(IsEmpty(*T)){
		Insert(T, Label_int(val), Durasi(val), Ketahanan(val), Harga(val));
	}
	else{
		while((!found) && (i < Neff(*T))){
			if (Label_int(T->buffer[i]) > Label_int(val)){
				found=true;
			}
			else{
				i++;
			}
		}
		for (int j=Neff(*T);j>i;j--){
			Move(Label(T->buffer[j]), Label(*T->buffer[j-1]));
			Durasi(T->buffer[j]) = Durasi(T->buffer[j-1]);
			Ketahanan(T->buffer[j]) = Ketahanan(T->buffer[j-1]);
			Harga(T->buffer[j]) = Harga(T->buffer[j-1]);
		}

		Move(Label(T->buffer[i]), Label(*val));
		Durasi(T->buffer[i]) = Durasi(val);
		Ketahanan(T->buffer[i]) = Ketahanan(val);
		Harga(T->buffer[i]) = Harga(val);
		Neff(*T)++;
	}
}

void dequeue (Tab *T, Pesanan *val){
	boolean found=false;
	Move(val->label, Label(*T->buffer[0]));
	val->durasi = Durasi(T->buffer[0]);
	val->ketahanan = Ketahanan(T->buffer[0]);
	val->harga = Harga(T->buffer[0]);
	for (int i=0;i<Neff(*T)-1;i++){
		Move(Label(T->buffer[i]), Label(*T->buffer[i+1]));
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
			printf(" ");
			PrintKata(Label(*T.buffer[i]));
			printf("      | %d\n", Durasi(T.buffer[i]));
		}
	}
	else{
		printf("         |\n"); 
	}
}
/*Menulis CookTab*/

void TulisIsi_Served(Tab T){
	if (!(IsEmpty(T))){
		for(int i=0;i<T.Neff;i++){
			printf(" ");
			PrintKata(Label(*T.buffer[i]));
			printf("      | %d\n", Ketahanan(T.buffer[i]));
		}
	}
	else{
		printf("         |\n"); 
	}
}
/*menuliskan label dan ketahanan makanan*/

void UpdateCook_Tab(Tab *T){
	for (int i=0; i<Neff(*T);i++){
		Durasi(T->buffer[i])--;
	}
}
/*Update seluruh anggota Tab*/

void UpdateServed_Tab(Tab *T){
	for (int i=0; i<Neff(*T);i++){
		Ketahanan(T->buffer[i])--;
	}
}
/*Update seluruh anggota Tab*/

boolean isMember(Tab T, int label){
	boolean found = false;
	int i=0;
	while ((i < Neff(T)) && (!found)){
		if (Label_int(T.buffer[i]) == label){
			found = true; 
		}
		else{
			i++;
		}
	}
	return found;
}

void buat_pesanan(Tab *T, int label){
	Insert(T, label, GenRand(1,5,5), (GenRand(1,5,5) % 5) + 1, GenRand(10000,50000,50000));
}

/*Cek apakah pesanan dengan label yang dimasukkan pengguna ada di dalam Queue/Array atau tidak*/
