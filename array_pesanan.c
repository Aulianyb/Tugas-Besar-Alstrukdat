#include <stdio.h>
#include "array_pesanan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong */
	T->Neff = 0;
	T->TI[MaxEl];
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
	return T.Neff;
}


/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	return MaxEl;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
	return IdxMin;
}

IdxType GetLastIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
	return T.Neff;
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetNeff (TabInt *T, IdxType N){
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
//Mengubah Neff
	T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
//Valid = antara IdxMin dan MaxEl
	return (IdxMin <= i) && (i < MaxEl);
}

boolean IsIdxEff (TabInt T, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
//KALAU EFEKTIF : antara IdxMin sama T.Neff
	return (IdxMin <= i) && (i < T.Neff);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
//KOSONG JIKA T.NEFF = 0
	return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
//Penuh jika Neff = MaxEl
	return (T.Neff == MaxEl);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T){
	
}
