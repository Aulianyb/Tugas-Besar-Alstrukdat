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
	//MaxNbEl --> Yang IdxMax - IdxMin+1
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
	//Menyalin tabelnya
	IdxType i=IdxMin;
	Tout->Neff = Tin.Neff;
	//Menyamakan Neff
	for (i=IdxMin;i<=IdxMax;i++){
		Tout->TI[i] = Tin.TI[i];
		i++;
	}
	//Menyimpan value
}

void SetEl (TabGame *T, IdxType i, Word v){
	//KENAPA HARUS ADA NEFF AKU JUGA GATAU
	int j = 0;
	T->TI[i].Length = v.Length;
	while (v.TabWord[j] != '\0') {
		T->TI[i].TabWord[j] = v.TabWord[j];
		j++;
	}
	
	//T->TI[i]=v;
	T->Neff++;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

void SetNeff (TabGame *T, IdxType N){
	//Mengubah Neff
	T->Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabGame T, IdxType i){
	//Valid = antara IdxMin dan IdxMax
	return (IdxMin <= i) && (i <= IdxMax);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabGame T, IdxType i){
	//KALAU EFEKTIF : antara IdxMin sama T.Neff
	return (IdxMin <= i) && (i <= T.Neff);
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabGame T){
	//KOSONG JIKA T.NEFF = 0
	return (T.Neff == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabGame T){
	//Penuh jika Neff = IdxMax
	return (T.Neff == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabGame T){
	//JANGAN LUPA SPASI WOY
	//BACA, KALAU TRANSVERSAL YA TULIS TRANSVERSAL
	IdxType i;
	if (IsEmpty(T)){
		printf("Tabel kosong\n");
	}
	else{
		for (i=GetFirstIdx(T);i<=T.Neff;i++){
			printf("%d:%d\n", i, GetElmt(T,i));
		}
	}
	
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

void DeleteAt (TabGame *T, IdxType x){
	for(int i=x; i<=(*T).Neff; i++){
		(*T).TI[i] = (*T).TI[i+1];
	}
	(*T).Neff = (*T).Neff-1;
}