/* File : StackHistory.h */
/* deklarasi StackHistory yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef StackHistory_H
#define StackHistory_H

#include "../../../boolean.h"
#include "../mesinkata.h"

#define Nil -1
#define MaxElStack 100
/* Nil adalah StackHistory dengan elemen kosong . */

typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype StackHistory dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  Word T[MaxElStack]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} StackHistory;
/* Definisi StackHistory S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai StackHistory T[0]..T[MaxEl-1] */
/* Jika S adalah StackHistory maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyHistory(StackHistory *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah StackHistory S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri StackHistory kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyHistory(StackHistory S);
/* Mengirim true jika StackHistory kosong: lihat definisi di atas */
boolean IsFullHistory(StackHistory S);
/* Mengirim true jika tabel penampung nilai elemen StackHistory penuh */

/* ************ Menambahkan sebuah elemen ke StackHistory ************ */
void PushHistory(StackHistory* S, Word X);
/* Menambahkan X sebagai elemen StackHistory S. */
/* I.S. S mungkin kosong, tabel penampung elemen StackHistory TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackHistory ************ */
void PopHistory(StackHistory* S, Word* X);
/* Menghapus X dari StackHistory S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void PrintStackHistory(StackHistory S, int n);

void SwapStackHistory(StackHistory S, StackHistory *Sout);

void DeleteGameHistory(StackHistory *SH, Word word);

#endif