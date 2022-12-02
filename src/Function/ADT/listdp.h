/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address_L adalah pointer */
/* infotype_L adalah integer */

#ifndef listdp_H
#define listdp_H

#include "../../boolean.h"
#include "point.h"

#define Nil_L NULL

/* Definisi Type Data */
typedef int infotype_L;
typedef struct tElmtlist *address_L;
typedef struct tElmtlist { 
	infotype_L info;
	address_L next;
	address_L prev;
	POINT point;
} ElmtList;
typedef struct {
	address_L First;
	address_L Last;
	int Length;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil_L dan Last(L) = Nil_L */
/* Setiap elemen dengan address_L P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define Length(L) ((L).Length)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty_L(List L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty_L (List *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address_L Alokasi (infotype_L X, int abs, int ord);
/* Mengirimkan address_L hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_L tidak Nil_L. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil_L, Prev(P)=Nil_L */
/* Jika alokasi gagal, mengirimkan Nil_L. */
void Dealokasi (address_L P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_L P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address_L Search (List L, infotype_L X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address_L elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil_L */

boolean SearchPoint (List L, int abs, int ord);
/* Mencari apakah ada elemen list dengan absis = abs dan ordinat = ord */
/* Jika ada, mengembalikan true */
/* Jika tidak, mengembalikan false */

address_L SearchAdrPoint (List L, int abs, int ord);
/* Mencari apakah ada elemen list dengan absis = abs dan ordinat = ord */
/* Jika ada, mengembalikan address_L elemen tersebut. */
/* Jika tidak, mengirimkan Nil_L */

boolean SearchPointInGrid (POINT p, int abs, int ord);
/* Mencari apakah ada POINT yang memiliki absis = abs dan ordinat = ord */
/* Jika ada, mengembalikan true */
/* Jika tidak, mengembalikan false */

/****************** PRIMITIF BERDASARKAN Nil_LAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype_L X, int abs, int ord);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Nil_Lai X jika alokasi berhasil */
void InsVLast (List *L, infotype_L X, int abs, int ord);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNil_Lai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype_L *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Nil_Lai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype_L *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: Nil_Lai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address_L P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_L P sebagai elemen pertama */
void InsertLast (List *L, address_L P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address_L P, address_L Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address_L P, address_L Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address_L *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address_L *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype_L X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress_L P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address_L *Pdel, address_L Prec);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address_L *Pdel, address_L Succ);
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNil_Lai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen berNil_Lai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

#endif