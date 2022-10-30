#include <stdio.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T){
	/* I.S. sembarang */
	/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
	T->Neff = 0;
	T->TI[IdxMax-IdxMin + 1];
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
	/* Mengirimkan banyaknya elemen efektif tabel */
	/* Mengirimkan nol jika tabel kosong */
	return T.Neff;
}


/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
	//MaxNbEl --> Yang IdxMax - IdxMin+1
	/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	return IdxMax-IdxMin+1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen pertama */
	return IdxMin;
}


IdxType GetLastIdx (TabInt T){
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen terakhir */
	return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i){
	/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
	/* Mengirimkan elemen tabel yang ke-i */
	return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout){
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

void SetEl (TabInt *T, IdxType i, ElType v){
	//KENAPA HARUS ADA NEFF AKU JUGA GATAU
	T->TI[i]=v;
	T->Neff++;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

void SetNeff (TabInt *T, IdxType N){
	//Mengubah Neff
	T->Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
	//Valid = antara IdxMin dan IdxMax
	return (IdxMin <= i) && (i <= IdxMax);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i){
	//KALAU EFEKTIF : antara IdxMin sama T.Neff
	return (IdxMin <= i) && (i <= T.Neff);
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
	//KOSONG JIKA T.NEFF = 0
	return (T.Neff == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
	//Penuh jika Neff = IdxMax
	return (T.Neff == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T){
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

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2){
	//Tinggal ditambahin
	TabInt THasil;
	THasil.Neff = T1.Neff;
	IdxType i=IdxMin;
	while(i <= T1.Neff){
		THasil.TI[i] = T1.TI[i] + T2.TI[i];
		i++;
	}
	return THasil;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */


TabInt MinusTab (TabInt T1, TabInt T2){
	//Sama tapi ganti tanda
	TabInt THasil;
	THasil.Neff = T1.Neff;
	IdxType i=IdxMin;
	while(i <= T1.Neff){
		THasil.TI[i] = T1.TI[i] - T2.TI[i];
		i++;
	}
	return THasil;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
	//return valuenya woi
	ElType Max;
	Max = T.TI[IdxMin];
	IdxType i=IdxMin+1;
	while (i <= T.Neff){
		if (T.TI[i] > Max){
			Max = T.TI[i];
		}
		i++;
	}
	return Max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ElType ValMin (TabInt T){
	//sama juga
	ElType Min;
	Min = T.TI[IdxMin];
	IdxType i=IdxMin+1;
	while (i <= T.Neff){
		if (T.TI[i] < Min){
			Min = T.TI[i];
		}
		i++;
	}
	return Min;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T){
	//NILAI MAX SIMPEN DI DALAM FUNGSI INI KALAU NGAK, GAK BENER
	IdxType IMax;
	IMax = IdxMin;
	ElType Max = T.TI[IdxMin];
	IdxType i;
	for (i=IdxMin+1;i<=T.Neff;i++){
		if (T.TI[i] > Max){
			Max = T.TI[i];
			IMax = i;
		}
	}
	return IMax;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

IdxType IdxMinTab (TabInt T){
	//SAMA KAYA YANG MAX
	IdxType IMin;
	IMin = IdxMin;
	IdxType i=IdxMin+1;
	while (i <= T.Neff){
		if (T.TI[i] < T.TI[IMin]){
			IMin = i;
		}
		i++;
	}
	return IMin;
}
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */