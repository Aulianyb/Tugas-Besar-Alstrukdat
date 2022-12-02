/*
Nama : Farhan Algani Putra
NIM : 18221108
Tanggal : 12 November 2022
Topik : Pra Praktikum 10 - Variasi List Linier
Deskripsi : Implementasi "listdp.h"
*/

#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty_L (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil_L && Last(L) == Nil_L && Length(L) == 0);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty_L (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil_L;
    Last(*L) = Nil_L;
    Length(*L) = 0;
}

/****************** Manajemen Memori ******************/
address_L Alokasi (infotype_L X, int abs, int ord)
/* Mengirimkan address_L hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_L tidak Nil_L. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil_L, Prev(P)=Nil_L */
/* Jika alokasi gagal, mengirimkan Nil_L. */
{
    address_L p;
    p = (address_L) malloc (sizeof(ElmtList));
    if (p != Nil_L) {
        Info(p) = X;
        Next(p) = Nil_L;
        Prev(p) = Nil_L;
        Absis(p->point) = abs;
        Ordinat(p->point) = ord;
        return p;
    }
    else {
        return Nil_L;
    }
}

void Dealokasi (address_L P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_L P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address_L Search (List L, infotype_L X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address_L elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil_L */
{
    address_L p = First(L);
    boolean found = false;
    while (p != Nil_L && !found) {
        if (Info(p) == X) {
            found = true;
        }
        else {
            p = Next(p);
        }
    }
    if (found) {
        return p;
    }
    else {
        return Nil_L;
    }
}

boolean SearchPoint (List L, int abs, int ord) {
/* Mencari apakah ada elemen list dengan absis = abs dan ordinat = ord */
/* Jika ada, mengembalikan true */
/* Jika tidak, mengembalikan false */
    address_L p = First(L);
    boolean found = false;
    while (p != Nil_L && !found) {
        if (Absis(p->point) == abs && Ordinat(p->point) == ord) {
            found = true;
        }
        else {
            p = Next(p);
        }
    }
    return found;
}

address_L SearchAdrPoint (List L, int abs, int ord) {
/* Mencari apakah ada elemen list dengan absis = abs dan ordinat = ord */
/* Jika ada, mengembalikan address_L elemen tersebut. */
/* Jika tidak, mengirimkan Nil_L */
    address_L p = First(L);
    boolean found = false;
    while (p != Nil_L && !found) {
        if (Absis(p->point) == abs && Ordinat(p->point) == ord) {
            found = true;
        }
        else {
            p = Next(p);
        }
    }
    if (found) {
        return p;
    }
    else {
        return Nil_L;
    }
}

boolean SearchPointInGrid (POINT p, int abs, int ord) {
/* Mencari apakah ada POINT yang memiliki absis = abs dan ordinat = ord */
/* Jika ada, mengembalikan true */
/* Jika tidak, mengembalikan false */
    boolean found = false;
    int i = 0;
    int j = 0;
    while (i < 5 && !found) {
        while (j < 5 && !found) {
            if (Absis(p) == abs && Ordinat(p) == ord) {
                found = true;
            }
            else {
                j++;
            }
        }
        i++;
    }
    return found;
}

/****************** PRIMITIF BERDASARKAN Nil_LAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype_L X, int abs, int ord)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Nil_Lai X jika alokasi berhasil */
{
    address_L p = Alokasi(X, abs, ord);
    if (p != Nil_L) {
        if (IsEmpty_L(*L)) {
            First(*L) = p;
            Last(*L) = p;
        }
        else {
            Next(p) = First(*L);
            Prev(First(*L)) = p;
            First(*L) = p;
        }
        Length(*L)++;
    }
}

void InsVLast (List *L, infotype_L X, int abs, int ord)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNil_Lai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address_L p = Alokasi(X, abs, ord);
    if (p != Nil_L) {
        if (IsEmpty_L(*L)) {
            InsVFirst(L,X, abs, ord);
        }
        else {
            Prev(p) = Last(*L);
            Next(Last(*L)) = p;
            Last(*L) = p;
            Length(*L)++;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype_L *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Nil_Lai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address_L p;
    DelFirst(L,&p);
    *X = Info(p);
    Dealokasi(p);
}

void DelVLast (List *L, infotype_L *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: Nil_Lai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address_L p;
    DelLast(L,&p);
    *X = Info(p);
    Dealokasi(p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address_L P) 
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_L P sebagai elemen pertama */
{
    if (IsEmpty_L(*L)) {
        First(*L) = P;
        Last(*L) = P;
    }
    else {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
    Length(*L)++;
}

void InsertLast (List *L, address_L P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty_L(*L)) {
        InsertFirst(L,P);
    }
    else {
        Prev(P) = Last(*L);
        Next(Last(*L)) = P;
        Last(*L) = P;
        Length(*L)++;
    }
}

void InsertAfter (List *L, address_L P, address_L Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    if (Next(P) == Nil_L) {
        Last(*L) = P;
    }
    else {
        Prev(Next(Prec)) = P;
    }
    Next(Prec) = P;
    Length(*L)++;
}

void InsertBefore (List *L, address_L P, address_L Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    Next(P) = Succ;
    Prev(P) = Prev(Succ);
    if (Prev(P) == Nil_L) {
        First(*L) = P;
    }
    else {
        Next(Prev(Succ)) = P;
    }
    Prev(Succ) = P;
    Length(*L)++;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address_L *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    if (First(*L) == Last(*L)) {
        First(*L) = Nil_L;
        Last(*L) = Nil_L;
    }
    else {
        First(*L) = Next(*P);
        Next(*P) = Nil_L;
        Prev(First(*L)) = Nil_L;
    }
    Length(*L)--;
}

void DelLast (List *L, address_L *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    *P = Last(*L);
    if (First(*L) == Last(*L)) {
        First(*L) = Nil_L;
        Last(*L) = Nil_L;
    }
    else {
        Last(*L) = Prev(*P);
        Prev(*P) = Nil_L;
        Next(Last(*L)) = Nil_L;
    }
    Length(*L)--;
}

void DelP (List *L, infotype_L X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress_L P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address_L p = Search(*L,X);
    if (p != Nil_L) {
        if (Prev(p) == Nil_L) {
            DelFirst(L,&p);
        }
        else if (Next(p) == Nil_L) {
            DelLast(L,&p);
        }
        else {
            Next(Prev(p)) = Next(p);
            Prev(Next(p)) = Prev(p);
            Next(p) = Nil_L;
            Prev(p) = Nil_L;
            Length(*L)--;
        }
        Dealokasi(p);
    }
}

void DelAfter (List *L, address_L *Pdel, address_L Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
   *Pdel = Next(Prec);
    if (Next(*Pdel) == Nil_L) {
        Next(Prec) = Nil_L;
        Last(*L) = Prec;
    }
    else {
        Next(Prec) = Next(*Pdel);
        Prev(Next(*Pdel)) = Prec;
    }
    Next(*Pdel) = Nil_L;
    Prev(*Pdel) = Nil_L;
    Length(*L)--;
}

void DelBefore (List *L, address_L *Pdel, address_L Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Prev(Succ);
    if (Prev(*Pdel) == Nil_L) {
        Prev(Succ) = Nil_L;
        First(*L) = Succ;
    }
    else {
        Prev(Succ) = Prev(*Pdel);
        Next(Prev(*Pdel)) = Succ;
    }
    Next(*Pdel) = Nil_L;
    Prev(*Pdel) = Nil_L;
    Length(*L)--;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNil_Lai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmpty_L(L)) {
        address_L p = First(L);
        while (p != Nil_L) {
            printf("%d",Info(p));
            if (p != Last(L)) {
                printf(",");
            }
            p = Next(p);
        }
    }
    printf("]");
}

void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen berNil_Lai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmpty_L(L)) {
        address_L p = Last(L);
        while (p != Nil_L) {
            printf("%d",Info(p));
            if (p != First(L)) {
                printf(",");
            }
            p = Prev(p);
        }
    }
    printf("]");
}