#include <stdio.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabGame *T){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
	T->Neff = 0;
	T->TI[IdxMax-IdxMin + 1];
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabGame T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
	return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabGame T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	return IdxMax-IdxMin+1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabGame T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
	return IdxMin;
}


IdxType GetLastIdx (TabGame T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
	return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
Word GetElmt (TabGame T, IdxType i){
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
	return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabGame Tin, TabGame *Tout){
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
	IdxType i=IdxMin;
	Tout->Neff = Tin.Neff;

	for (IdxType i = IdxMin; i <= Tout->Neff; i++) {
		int j = 0;
		while ( Tin.TI[i].TabWord[j] != '\0') {
			Tout->TI[i].TabWord[j] = Tin.TI[i].TabWord[j];
			j++;
		}
		Tout->TI[i].Length = Tin.TI[i].Length;
	}
}

void SetEl (TabGame *T, IdxType i, Word v){
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
	int j = 0;
	T->TI[i].Length = v.Length;
	while (v.TabWord[j] != '\0') {
		T->TI[i].TabWord[j] = v.TabWord[j];
		j++;
	}
	
	T->Neff++;
}

void SetNeff (TabGame *T, IdxType N){
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
	T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabGame T, IdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
	return (IdxMin <= i) && (i <= IdxMax);
}

boolean IsIdxEff (TabGame T, IdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
	return (IdxMin <= i) && (i <= T.Neff);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabGame T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabGame T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	return (T.Neff == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabGame T){
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [Sonic,Mario,Zelda] maka akan diprint
1. Sonic
2. Mario
3. Zelda
*/
/* Jika T kosong : Hanya menulis "Isi kosong" */
	IdxType i;
	if (IsEmpty(T)){
		printf("Isi kosong\n");
	}
	else{
		for (int i = IdxMin; i <= T.Neff; i++) {
			printf("%d. ",i);
			PrintKata(T.TI[i]);
			printf("\n");
		}
	}
}

void DeleteAt (TabGame *T, IdxType x){
/* Proses : Menghapus elemen yang berada di indeks ke-x */
/* I.S. T tidak kosong */
/* F.S. Elemen pada indeks ke-x dihapus dari elemen, elemen setelah elemen yang dihapus bergeser ke kiri,
        elemen efektif berkurang 1 */
	for(int i=x; i<=(*T).Neff; i++){
		(*T).TI[i] = (*T).TI[i+1];
	}
	(*T).Neff = (*T).Neff-1;
}

IdxType findIdxGame(TabGame T, Word game){
	boolean found = false;
	int idx, i, j;
	for (i = IdxMin; i <= T.Neff; i++)
	{
		if (isWordandWordEqual(T.TI[i], game)){
			idx = i;
		}
	}
	return idx;
}