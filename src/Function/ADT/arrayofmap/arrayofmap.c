#include "arrayofmap.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyTabScore (TabScore *T){
	T->Neff = 0;
	T->TI[IdxMax-IdxMin + 1];
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtTabScore (TabScore T){
	return T.Neff;
}


/* *** Daya tampung container *** */
int MaxNbElTabScore (TabScore T){
	return IdxMax-IdxMin+1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxTabScore (TabScore T){
	return IdxMin;
}


IdxType GetLastIdxTabScore (TabScore T){
	return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
Map GetElmtTabScore (TabScore T, IdxType i){
	return T.TI[i];
}

void SetTabTabScore (TabScore Tin, TabScore *Tout){
	IdxType i=IdxMin;
	Tout->Neff = Tin.Neff;
	//Menyamakan Neff
	for (i=IdxMin;i<=IdxMax;i++){
		Tout->TI[i] = Tin.TI[i];
		i++;
	}
}

void SetElTabScore (TabScore *T, IdxType i, Map map){
	int j = 0;
	// T->TI[i].GameTitle.Length = title.Length;
	// while (title.TabWord[j] != '\0') {
	// 	T->TI[i].GameTitle.TabWord[j] = title.TabWord[j];
	// 	j++;
	// }
	//  T->TI[i].GameTitle = title;
    T->TI[i] = map;
	
	T->Neff++;
}

void InsertLastTabScore (TabScore *T, Map map){
    IdxType idx = T->Neff;
	SetElTabScore(T, idx, map);
}

void SetNeffTabScore (TabScore *T, IdxType N){
	T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidTabScore (TabScore T, IdxType i){
	//Valid = antara IdxMin dan IdxMax
	return (IdxMin <= i) && (i <= IdxMax);
}

boolean IsIdxEffTabScore (TabScore T, IdxType i){
	//KALAU EFEKTIF : antara IdxMin sama T.Neff
	return (IdxMin <= i) && (i <= T.Neff);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyTabScore (TabScore T){
	//KOSONG JIKA T.NEFF = 0
	return (T.Neff == 0);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiTabScore (TabScore T){
	//JANGAN LUPA SPASI WOY
	//BACA, KALAU TRANSVERSAL YA TULIS TRANSVERSAL
	IdxType i, j;
	if (IsEmptyTabScore(T)){
		printf("Tabel kosong\n");
	}
	else {
		printf("---------------------\n");
		for (i=GetFirstIdxTabScore(T); i<=T.Neff; i++){
			for (j = NilMap; j <= T.TI[i].Count; j++){
				PrintKata(T.TI[i].Elements[j].user);
				printf(" %d\n", T.TI[i].Elements[j].score);
			}
		}
		printf("---------------------\n");
	}
}

void DeleteAtTabScore (TabScore *T, IdxType x){
	for(int i=x; i<=(*T).Neff; i++){
		(*T).TI[i] = (*T).TI[i+1];
	}
	(*T).Neff = (*T).Neff-1;
}