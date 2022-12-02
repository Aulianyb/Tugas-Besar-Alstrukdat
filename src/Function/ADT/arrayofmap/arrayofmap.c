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

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyTabScore (TabScore T){
	//KOSONG JIKA T.NEFF = 0
	return (T.Neff == 0);
}

boolean IsFullTabScore (TabScore T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	return (T.Neff == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiTabScore (TabScore M){
	//JANGAN LUPA SPASI WOY
	//BACA, KALAU TRANSVERSAL YA TULIS TRANSVERSAL
    for (int i = 0; i <= M.Neff-1; i++)
    {
        printf("\n***** ELEMEN KE-%d ", i+1);
        printf(" *****\n");
        printf("| NAMA          | SKOR          |\n");
        printf("---------------------------------\n");
        if (IsEmptyMap(M.TI[i])){
            printf("------- ELEMEN KOSONG --------\n");
        } else {
            int ctr = M.TI[i].Count;
            for (int j = 0; j < M.TI[i].Count; j++)
            {
                printf("| ");
                PrintKata(M.TI[i].Elements[j].user);
                if (M.TI[i].Elements[j].user.Length <= 13)
                {
                    printf("\t");
                    if (M.TI[i].Elements[j].user.Length <= 5) {
                        printf("\t");
                    }
                }
                printf("| ");
                printf("%d", M.TI[i].Elements[j].score);
                printf("\t\t|\n");
            }
        }
    }
}

void DeleteAtTabScore (TabScore *T, IdxType x){
	for(int i=x; i<=(*T).Neff; i++){
		(*T).TI[i] = (*T).TI[i+1];
	}
	(*T).Neff = (*T).Neff-1;
}