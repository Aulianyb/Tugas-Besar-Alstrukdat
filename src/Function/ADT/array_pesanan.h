#ifndef ARRAY_H
#define ARRAY_H

#include "../../boolean.h"
#include "mesinkata.h"

/* Kamus Umum */

#define MaxEl 50 /*Sebenarnya bisa lebih dari 15, misalnya loop terus mengakibatkan terus generate data*/
#define IdxMin 0
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
    Word label[4];
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
void MakeEmpty_pesanan(Tab *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty_pesanan(Tab T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull_pesanan(Tab T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** MODIFIKASI TAB ********** */
void Insert_pesanan(Tab *T, int label, int durasi, int ketahanan, int harga); 
/* Memasukkan suatu pesanan ke dalam Tab */

void Delete_pesanan(Tab *T, int label, Pesanan *val);
/* Menghapus suatu pesanan ke dalam Tab dan menyimpannya dalam val*/

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi_pesanan(Tab T);
/*Menuliskan Isi Tabel pada Layar Sesuai Format*/

int Label_int(Pesanan P);
//MENGAMBIL NILAI INT LABEL;

#endif