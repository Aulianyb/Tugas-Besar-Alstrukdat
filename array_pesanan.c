#include <stdio.h>
#include "array_pesanan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (Tab *T){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong */
	T->Neff = 0;
	T->buffer[MaxEl];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetNeff (Tab *T, IdxType N){
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
	T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (Tab T, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
//Valid = antara IdxMin dan MaxEl
	return (IdxMin <= i) && (i < MaxEl);
}

boolean IsIdxEff (Tab T, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
//KALAU EFEKTIF : antara IdxMin sama T.Neff
	return (IdxMin <= i) && (i < T.Neff);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (Tab T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (Tab T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	return (T.Neff == MaxEl);
}

/* ********** MODIFIKASI TAB ********** */
void Insert(Tab *T, int label, int durasi, int ketahanan, int harga){
	Label(T->buffer[Neff(*T)])[0] = 'M';
	Label(T->buffer[Neff(*T)])[1] = label + '0';
	Durasi(T->buffer[Neff(*T)]) = durasi;
	Ketahanan(T->buffer[Neff(*T)]) = ketahanan;
	Harga(T->buffer[Neff(*T)]) = harga;
	Neff(*T)++;
}
/* Memasukkan suatu pesanan ke dalam Tab */

void Delete(Tab *T, int label, Pesanan *val){
	boolean found=false;
	int i=0;
	while (i < Neff(*T) && !found){
		if (Label(T->buffer[i])[1] == label + '0'){
			found = true;
		}
		else{
			i++;
		}
	}

	val->label[0] =  Label(T->buffer[i])[0];
	val->label[1] =  Label(T->buffer[i])[1];
	val->durasi = Durasi(T->buffer[i]);
	val->ketahanan = Ketahanan(T->buffer[i]);
	val->harga = Harga(T->buffer[i]);

	for (int j=i;j<Neff(*T)-1;j++){
		Label(T->buffer[j])[1] = Label(T->buffer[j+1])[1];
		Durasi(T->buffer[j]) = Durasi(T->buffer[j+1]);
		Ketahanan(T->buffer[j]) = Ketahanan(T->buffer[j+1]);
		Harga(T->buffer[j]) = Harga(T->buffer[j+1]);
	}
	Neff(*T)--; 
}
/* Menghapus suatu pesanan ke dalam Tab */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (Tab T){
	if (!(IsEmpty(T))){
		for(int i=0;i<T.Neff;i++){
			printf(" %c%c      | %d              | %d         | %d\n",Label(T.buffer[i])[0], Label(T.buffer[i])[1], Durasi(T.buffer[i]), Ketahanan(T.buffer[i]), Harga(T.buffer[i]));
		}
	}
	else{
		printf("         |                |           |  \n"); 
	}
}
