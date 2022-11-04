#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"

/* Kamus Umum */

#define MaxEl 7
#define IdxMin 0
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
    char label[4];
    int durasi;
    int ketahanan;
    int harga;
} Pesanan;

typedef struct
	{
		Pesanan buffer[MaxEl]; /* memori tempat penyimpan elemen (container) */
		int Neff; /* banyaknya elemen efektif */
	} Tab;

#define Neff(A) (A).Neff
#define Harga(P) P.harga
#define Ketahanan(P) P.ketahanan
#define Durasi(P) P.durasi 
#define Label(P) P.label

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (Tab *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxEl */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetNeff (Tab *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (Tab T, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (Tab T, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (Tab T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (Tab T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** MODIFIKASI TAB ********** */
void Insert(Tab *T, int label, int durasi, int ketahanan, int harga); 
/* Memasukkan suatu pesanan ke dalam Tab */

void Delete(Tab *T, int label, Pesanan *val);
/* Menghapus suatu pesanan ke dalam Tab dan menyimpannya dalam val*/

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (Tab T);
/*Menuliskan Isi Tabel pada Layar Sesuai Format*/

#endif