#include <stdio.h>
#include "queue_cook.h"

void enqueue (Tab *T, Pesanan val){
	int i=0;
	boolean found=false;
	if(IsEmpty(*T)){
		Insert(T, Label(val)[1] - 48, Durasi(val), Ketahanan(val), Harga(val));
	}
	else{
		while((!found) && (i < Neff(*T))){
			if ((Durasi(T->buffer[i]) > Durasi(val))){
				found=true;
			}
			else{
				i++;
			}
		}


		for (int j=Neff(*T);j>i;j--){
			Label(T->buffer[j])[0] = 'M';
			Label(T->buffer[j])[1] = Label(T->buffer[j-1])[1];
			Durasi(T->buffer[j]) = Durasi(T->buffer[j-1]);
			Ketahanan(T->buffer[j]) = Ketahanan(T->buffer[j-1]);
			Harga(T->buffer[j]) = Harga(T->buffer[j-1]);
		}
		Label(T->buffer[i])[0] = 'M';
		Label(T->buffer[i])[1] = Label(val)[1];
		Durasi(T->buffer[i]) = Durasi(val);
		Ketahanan(T->buffer[i]) = Ketahanan(val);
		Harga(T->buffer[i]) = Harga(val);
		Neff(*T)++;
	}
}

void dequeue (Tab *T, Pesanan *val){
	boolean found=false;
	val->label[0] =  Label(T->buffer[0])[0];
	val->label[1] =  Label(T->buffer[0])[1];
	val->durasi = Durasi(T->buffer[0]);
	val->ketahanan = Ketahanan(T->buffer[0]);
	val->harga = Harga(T->buffer[0]);
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

void TulisIsi_Served(Tab T){
	if (!(IsEmpty(T))){
		for(int i=0;i<T.Neff;i++){
			printf(" %c%c      | %d\n",Label(T.buffer[i])[0], Label(T.buffer[i])[1], Ketahanan(T.buffer[i]));
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
	char c_label = label + '0';
	boolean found = false;
	int i=0;
	while ((i < Neff(T)) && (!found)){
		if (Label(T.buffer[i])[1] == c_label){
			found = true; 
		}
		else{
			i++;
		}
	}
	return found;
}


/*Cek apakah pesanan dengan label yang dimasukkan pengguna ada di dalam Queue/Array atau tidak*/
