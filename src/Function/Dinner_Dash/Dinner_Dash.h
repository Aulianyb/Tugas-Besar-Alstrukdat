#ifndef DINNER_DASH_H
#define DINNER_DASH_H

#include <stdio.h>
#include "../../boolean.h"
// #include "../ADT/array_pesanan.h"
// #include "../ADT/queue_cook.h"
#include "../../random_generator.h"
#include "../ADT/mesinkata.h"

#define MaxEl 20 /*Sebenarnya bisa lebih dari 15, misalnya loop terus mengakibatkan terus generate data*/
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

void enqueue_cook(Tab *T, Pesanan val);
/*Memasukkan elemen ke dalam Queue dalam urutan Prioritas*/

void dequeue_cook (Tab *T, Pesanan *val);
/*Memasukkan elemen ke dalam Tab*/

void TulisIsi_Cook(Tab T);
/*menuliskan label dan durasi pesanan*/

void TulisIsi_Served(Tab T);
/*menuliskan label dan ketahanan makanan*/

void UpdateCook_Tab(Tab *T);
/*Update seluruh anggota Tab*/

void UpdateServed_Tab(Tab *T);
/*Update seluruh anggota Tab*/

boolean isMember_cook(Tab T, int label);
/*Cek apakah pesanan dengan label yang dimasukkan pengguna ada di dalam Queue/Array atau tidak*/

boolean isCook(Word Kata);
/* Mengembalikan apakah kata input merupakan "COOK" atau bukan */

boolean isServe(Word Kata);
/* Mengembalikan apakah kata input merupakan "SERVE" atau bukan*/

void buat_pesanan(Tab *T, int label);
/* Membuat Pesanan berdasarkan input */

void Dinner_Dash();
//MAIN GAME

#endif