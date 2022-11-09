#include <stdio.h>
#include "array_pesanan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty_pesanan(Tab *T){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong */
	T->Neff = 0;
	T->buffer[MaxEl];
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty_pesanan(Tab T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull_pesanan (Tab T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	return (T.Neff == MaxEl);
}

/* ********** MODIFIKASI TAB ********** */
void Insert_pesanan(Tab *T, int label, int durasi, int ketahanan, int harga){
	Label(T->buffer[Neff(*T)])->TabWord[0] = 'M';
	Label(T->buffer[Neff(*T)])->Length = 1;
	MergeWord(Label(T->buffer[Neff(*T)]), IntToWord(label));
	Durasi(T->buffer[Neff(*T)]) = durasi;
	Ketahanan(T->buffer[Neff(*T)]) = ketahanan;
	Harga(T->buffer[Neff(*T)]) = harga;
	Neff(*T)++;
}
/* Memasukkan suatu pesanan ke dalam Tab */

void Delete_pesanan(Tab *T, int label, Pesanan *val){
	boolean found=false;
	int i=0;
	while (i < Neff(*T) && !found){
		if (WordToInt((GetLabel(Label(*T->buffer[i])))) == label){
			found = true;
		}
		else{
			i++;
		}
	}

	if (found){
		Move(val->label, Label(*T->buffer[i]));
		val->durasi = Durasi(T->buffer[i]);
		val->ketahanan = Ketahanan(T->buffer[i]);
		val->harga = Harga(T->buffer[i]);

		for (int j=i;j<Neff(*T)-1;j++){
		Move(Label(T->buffer[j]), Label(*T->buffer[j+1]));
		Durasi(T->buffer[j]) = Durasi(T->buffer[j+1]);
		Ketahanan(T->buffer[j]) = Ketahanan(T->buffer[j+1]);
		Harga(T->buffer[j]) = Harga(T->buffer[j+1]);
		}
		Neff(*T)--; 
	}
}
/* Menghapus suatu pesanan ke dalam Tab */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi_pesanan(Tab T){
	if (!(IsEmpty_pesanan(T))){
		for(int i=0;i<T.Neff;i++){
			printf(" ");
			PrintKata(Label(*T.buffer[i]));
			printf("      | %d              | %d         | %d\n", Durasi(T.buffer[i]), Ketahanan(T.buffer[i]), Harga(T.buffer[i]));
		}
	}
	else{
		printf("         |                |           |  \n"); 
	}
}

int Label_int(Pesanan P){
    return WordToInt((GetLabel(Label(*P)))); 
}
//MENGAMBIL NILAI INT LABEL