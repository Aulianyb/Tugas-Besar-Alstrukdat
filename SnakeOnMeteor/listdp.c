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
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil && Last(L) == Nil && Length(L) == 0);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
    Length(*L) = 0;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X, int abs, int ord)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    address p;
    p = (address) malloc (sizeof(ElmtList));
    if (p != Nil) {
        Info(p) = X;
        Next(p) = Nil;
        Prev(p) = Nil;
        Absis(p->point) = abs;
        Ordinat(p->point) = ord;
        return p;
    }
    else {
        return Nil;
    }
}

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address p = First(L);
    boolean found = false;
    while (p != Nil && !found) {
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
        return Nil;
    }
}

boolean SearchPoint (List L, int abs, int ord) {
    address p = First(L);
    boolean found = false;
    while (p != Nil && !found) {
        if (Absis(p->point) == abs && Ordinat(p->point) == ord) {
            found = true;
        }
        else {
            p = Next(p);
        }
    }
    return found;
}

address SearchAdrPoint (List L, int abs, int ord) {
    address p = First(L);
    boolean found = false;
    while (p != Nil && !found) {
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
        return Nil;
    }
}

boolean SearchPointInGrid (POINT p, int abs, int ord) {
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

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X, int abs, int ord)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address p = Alokasi(X, abs, ord);
    if (p != Nil) {
        if (IsEmpty(*L)) {
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

void InsVLast (List *L, infotype X, int abs, int ord)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address p = Alokasi(X, abs, ord);
    if (p != Nil) {
        if (IsEmpty(*L)) {
            InsVFirst(L,X, abs, ord);
        }
        else {
            Prev(p) = Last(*L);
            Next(Last(*L)) = p;
            Last(*L) = p;
        }
        Length(*L)++;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address p;
    DelFirst(L,&p);
    *X = Info(p);
    Dealokasi(p);
    Length(*L)--;
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address p;
    DelLast(L,&p);
    *X = Info(p);
    Dealokasi(p);
    Length(*L)--;
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) 
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    if (IsEmpty(*L)) {
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

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L)) {
        InsertFirst(L,P);
    }
    else {
        Prev(P) = Last(*L);
        Next(Last(*L)) = P;
        Last(*L) = P;
    }
    Length(*L)++;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    if (Next(P) == Nil) {
        Last(*L) = P;
    }
    else {
        Prev(Next(Prec)) = P;
    }
    Next(Prec) = P;
    Length(*L)++;
}

void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    Next(P) = Succ;
    Prev(P) = Prev(Succ);
    if (Prev(P) == Nil) {
        First(*L) = P;
    }
    else {
        Next(Prev(Succ)) = P;
    }
    Prev(Succ) = P;
    Length(*L)++;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    if (First(*L) == Last(*L)) {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else {
        First(*L) = Next(*P);
        Next(*P) = Nil;
        Prev(First(*L)) = Nil;
    }
    Length(*L)--;
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    *P = Last(*L);
    if (First(*L) == Last(*L)) {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else {
        Last(*L) = Prev(*P);
        Prev(*P) = Nil;
        Next(Last(*L)) = Nil;
    }
    Length(*L)--;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address p = Search(*L,X);
    if (p != Nil) {
        if (Prev(p) == Nil) {
            DelFirst(L,&p);
        }
        else if (Next(p) == Nil) {
            DelLast(L,&p);
        }
        else {
            Next(Prev(p)) = Next(p);
            Prev(Next(p)) = Prev(p);
            Next(p) = Nil;
            Prev(p) = Nil;
        }
        Dealokasi(p);
        Length(*L)--;
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
   *Pdel = Next(Prec);
    if (Next(*Pdel) == Nil) {
        Next(Prec) = Nil;
        Last(*L) = Prec;
    }
    else {
        Next(Prec) = Next(*Pdel);
        Prev(Next(*Pdel)) = Prec;
    }
    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
    Length(*L)--;
}

void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Prev(Succ);
    if (Prev(*Pdel) == Nil) {
        Prev(Succ) = Nil;
        First(*L) = Succ;
    }
    else {
        Prev(Succ) = Prev(*Pdel);
        Next(Prev(*Pdel)) = Succ;
    }
    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
    Length(*L)--;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmpty(L)) {
        address p = First(L);
        while (p != Nil) {
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
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmpty(L)) {
        address p = Last(L);
        while (p != Nil) {
            printf("%d",Info(p));
            if (p != First(L)) {
                printf(",");
            }
            p = Prev(p);
        }
    }
    printf("]");
}