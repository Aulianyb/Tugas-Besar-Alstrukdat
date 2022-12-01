#ifndef pohon_h
#define pohon_h

/* ADT Pohon Biner */

#include <stdio.h>
#include <stdlib.h>
#include "../../../boolean.h"

/* Modul lain yang digunakan */
#include "../mesinkarakter.h"

#define NilTree NULL
//typedef char Infotype

/*** Definisi Type Pohon Biner ***/
typedef int Infotype;
typedef struct tNode *AddressTree;
typedef struct tNode {
	Infotype Info;
	AddressTree Left;
	AddressTree Right;
} Node;
typedef AddressTree BinTree;

/*
	BEBERAPA CATATAN
	1. Pohon merupakan pohon biner dengan representasi karakter
	2. pita karakter merupakan stdin (di-supply dari stdin)
*/

/*** PROTOTYPE ***/
/*** Selektor ***/
#define Akar(P) (P)->Info
/* Mengirimkan nilai Akar pohon biner P */

#define Left(P) (P)->Left
/* Mengirimkan Anak Kiri pohon biner P */

#define Right(P) (P)->Right
/* Mengirimkan Anak Kanan pohon biner P */

/*** Konstruktor ***/
BinTree Tree (Infotype X, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NilTree) jika alokasi gagal */

void MakeTree (Infotype X, BinTree L, BinTree R, BinTree *P);
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon P */
/* Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon P yang kosong (NilTree) jika alokasi gagal */

/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */

boolean IsOneElmt (BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1
elemen */

boolean IsUnerLeft (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya
mempunyai subpohon kiri */

boolean IsUnerRight (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya
mempunyai subpohon kanan */

boolean IsBiner (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai
subpohon kiri dan subpohon kanan */

/*** Searching ***/
boolean SearchTree (BinTree P, Infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/*** Fungsi-Fungsi Lain ***/
int NbElmt (BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */

int NbDaun (BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */

boolean IsSkewLeft (BinTree P);
/* Mengirimkan true jika P adalah pohon condong kiri */

boolean IsSkewRight (BinTree P);
/* Mengirimkan true jika P adalah pohon condong kanan */

/*** Operasi lain ***/
void AddDaunTerkiri (BinTree *P, Infotype X);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */

void AddDaun (BinTree *P, Infotype X, Infotype Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
sebagai anak k@anan X (jika Kiri = false) */

void DelDaunTerkiri (BinTree *P, Infotype *X);
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
disimpan pada daun terkiri yang dihapus */

void DelDaun (BinTree *P, Infotype X);
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. Semua daun bernilai X dihapus dari P */

#endif