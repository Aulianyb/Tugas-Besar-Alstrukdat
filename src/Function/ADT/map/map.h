#ifndef map_H
#define map_H

#include <stdio.h>
#include "../../../boolean.h"
#include "../mesinkata.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NilMap 0
#define MaxElMap 10
#define Undefined -999

// typedef int bool;
typedef int valuetype;
typedef int address;

typedef struct {
	Word user;
	int score;
} infotype;

typedef struct {
	infotype Elements[MaxElMap];
	address Count;
} Map;

/* Definisi Map M kosong : M.Count = NilMap */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElMap */
/* Ciri Map kosong : count berNilMapai NilMap */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count berNilMapai NilMap */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count berNilMapai MaxElMap */

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, Word k);
/* Mengembalikan NilMapai value dengan User k dari M */
/* Jika tidak ada User k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, Word k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan User k */
/* F.S. v menjadi anggota dari M dengan User k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, Word k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan User k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan User k bukan anggota dari M */

boolean IsMemberMap(Map M, Word k);
/* Mengembalikan true jika k adalah member dari M */

boolean isWordandWordEqual(Word word1, Word word2);

#endif