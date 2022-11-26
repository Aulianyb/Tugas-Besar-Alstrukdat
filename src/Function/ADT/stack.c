#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S){
	Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S){
	return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S){
	return (Top(S) == MaxEl-1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X){
	if (IsEmpty(*S)){
		Top(*S) = 0;
		InfoTop(*S) = X;
	}
	else{
		Top(*S)++;
		InfoTop(*S) = X;
	}
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X){
	*X = InfoTop(*S);
	Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void isiTiang(Stack *S, int n){
	Word val;
	infotype Info;
	for (int i=n;i>=1;i--){
		val.Length = n*2-1;
		Info.n = i;
		int half = ((2*n-1)-(2*i-1))/2;
		int j=0;
		while(j<half){
			val.TabWord[j] = ' ';
			j++;
		}
		while (j<2*n-1-half){
			val.TabWord[j] = '*';
			j++;
		}
		while (j<n*2-1){
			val.TabWord[j] = ' ';
			j++;
		}
		Info.graph = val;
		Push(S, Info);
	}
	// if (n == 1){
	// 	n(I) = 1;
	// 	graph(I) = strToWord("    *    ");
	// }
	// else if (n == 2){
	// 	n(I) = 2;
	// 	graph(I) = strToWord("   ***   ");
	// }
	// else if (n == 3){
	// 	n(I) = 3;
	// 	graph(I) = strToWord("  *****  ");
	// }
	// else if (n == 4){
	// 	n(I) = 4;
	// 	graph(I) = strToWord(" ******* ");
	// }
	// else if (n == 5){
	// 	n(I) = 5;
	// 	graph(I) = strToWord("*********");
	// } 
}