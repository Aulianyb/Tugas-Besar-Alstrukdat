#include "tree.h"

/*** Konstruktor ***/
BinTree Tree (Infotype Akar, BinTree L, BinTree R) {
	BinTree T;

	T= (AddressTree) malloc (sizeof(Node));
	if (T == Nil) {
		return Nil;
	} else {
		Akar(T)= Akar;
		Left(T)= L;
		Right(T)= R;
		return T;
	}
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void MakeTree (Infotype Akar, BinTree L, BinTree R, BinTree *P) {
	*P= Tree(Akar, L, R);
}
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon P */
/* Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal */

/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (BinTree P) {
	if (P == Nil) {
		return true;
	} else {
		return false;
	}
}
/* Mengirimkan true jika P adalah pohon biner kosong */

boolean IsOneElmt (BinTree P) {
	if (!IsTreeEmpty(P)) {
		if (Left(P) == Nil && Right(P) == Nil) {
			return true;
		}
		else {
			return false;
		}
	} else {
		return false;
	}
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1
elemen */

boolean IsUnerLeft (BinTree P) {
	if (!IsTreeEmpty(P)) {
		if (!IsTreeEmpty(Left(P)) && IsTreeEmpty(Right(P))) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya
mempunyai subpohon kiri */

boolean IsUnerRight (BinTree P) {
	if (!IsTreeEmpty(P)) {
		if (IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P))) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya
mempunyai subpohon kanan */

boolean IsBiner (BinTree P) {
	if (!IsTreeEmpty(P)) {
		if (!IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P))) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

/*** Searching ***/
boolean SearchTree (BinTree P, Infotype X) {
	if (IsTreeEmpty(P)) return false;
	else {
		if (Akar(P) == X) {
			return true;
		} else {
			return (SearchTree(Left(P), X) || SearchTree(Right(P), X));
		}
	}
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/*** Fungsi-Fungsi Lain ***/
int NbElmt (BinTree P) {
	if (IsTreeEmpty(P)) return 0;
	else {
		return (1 + NbElmt(Left(P)) + NbElmt(Right(P)));
	} 
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */

int NbDaun (BinTree P) {
	if (IsTreeEmpty(P)) return 0;
	if (IsOneElmt(P)) return 1;
	return (NbDaun(Left(P)) + NbDaun(Right(P)));
}
/* Mengirimkan banyaknya daun (node) pohon biner P */

boolean IsSkewLeft (BinTree P) {
	if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (IsOneElmt(P)) {
			return true;
		} else if (IsUnerLeft(P)) {
			return IsSkewLeft(Left(P));
		} else {
			return false;
		}
	}
}
/* Mengirimkan true jika P adalah pohon condong kiri */

boolean IsSkewRight (BinTree P) {
	if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (IsOneElmt(P)) {
			return true;
		} else if (IsUnerRight(P)) {
			return IsSkewRight(Right(P));
		} else {
			return false;
		}
	}
}
/* Mengirimkan true jika P adalah pohon condong kanan */

/*** Operasi lain ***/
void AddDaunTerkiri (BinTree *P, Infotype X) {
	if (IsTreeEmpty(*P)) {
		*P= Tree(X, Nil, Nil);
	} else if (IsUnerLeft(*P) || IsBiner(*P) || IsOneElmt(*P)) {
		AddDaunTerkiri(&Left(*P), X);
	} else {
		AddDaunTerkiri(&Right(*P), X);
	}
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */

void AddDaun (BinTree *P, Infotype X, Infotype Y, boolean Kiri) {
	if (!IsTreeEmpty(*P)) {
		if (Akar(*P) == X) {
			if (Kiri) {
				Left(*P)= Tree(Y, Nil, Nil);
			} else {
				Right(*P)= Tree(Y, Nil, Nil);
			}
		} else {
			AddDaun(&Left(*P), X, Y, Kiri);
			AddDaun(&Right(*P), X, Y, Kiri);
		}
	}
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
sebagai anak k@anan X (jika Kiri = false) */

void DelDaunTerkiri (BinTree *P, Infotype *X) {
	if (IsOneElmt(*P)) {
		*X= Akar(*P);
		free(*P);
		*P= Nil;
	} else {
		if (IsUnerRight(*P)) {
			DelDaunTerkiri(&Right(*P), X);
		} else { //left/ biner/ oneelmt
			DelDaunTerkiri(&Left(*P), X);
		}
	}
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
disimpan pada daun terkiri yang dihapus */

void DelDaun (BinTree *P, Infotype X) {
	if (!IsTreeEmpty(*P)) {
		if (Akar(*P) == X) {
			free(*P);
			*P= Nil;
		} else {
			DelDaun(&Left(*P), X);
			DelDaun(&Right(*P), X);
		}
	}
}
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. Semua daun bernilai X dihapus dari P */