#include "tree.h"

/*** Konstruktor ***/
BinTree Tree (Infotype X, BinTree L, BinTree R) {
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NilTree) jika alokasi gagal */
	BinTree P;

	P= (AddressTree) malloc (sizeof(Node));
	if (P != NilTree) {
		Akar(P) = X;
		Left(P)= L;
		Right(P)= R;
		return P;
	}
	else {
		return NilTree;
	}
}

void MakeTree (Infotype X, BinTree L, BinTree R, BinTree *P) {
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon P */
/* Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon P yang kosong (NilTree) jika alokasi gagal */
	*P= Tree(X, L, R);
}

/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (BinTree P) {
/* Mengirimkan true jika P adalah pohon biner kosong */
	if (P == NilTree) {
		return true;
	}
	else {
		return false;
	}
}

boolean IsOneElmt (BinTree P) {
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1
elemen */
	if (!IsTreeEmpty(P)) {
		return ((Left(P) == NilTree) && (Right(P) == NilTree));
	}
	else {
		return false;
	}
}

boolean IsUnerLeft (BinTree P) {
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya
mempunyai subpohon kiri */
	if (!IsTreeEmpty(P)) {
		return (!IsTreeEmpty(Left(P)) && IsTreeEmpty(Right(P)));
	}
	else {
		return false;
	}
}

boolean IsUnerRight (BinTree P) {
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya
mempunyai subpohon kanan */
	if (!IsTreeEmpty(P)) {
		return (IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P)));
	}
	else {
		return false;
	}
}

boolean IsBiner (BinTree P) {
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai
subpohon kiri dan subpohon kanan */
	if (!IsTreeEmpty(P)) {
		return (!IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P)));
	}
	else {
		return false;
	}
}

/*** Searching ***/
boolean SearchTree (BinTree P, Infotype X) {
/* Mengirimkan true jika ada node dari P yang bernilai X */
	if (IsTreeEmpty(P)) {
		return false;
	}
	else {
		if (Akar(P) == X) {
			return true;
		}
		else {
			if (SearchTree(Left(P),X)) {
				return true;
			}
			else {
				SearchTree(Right(P), X);
			}
		}
	}
}

/*** Fungsi-Fungsi Lain ***/
int NbElmtTree (BinTree P) {
/* Mengirimkan banyaknya elemen (node) pohon biner P */
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		return (1 + NbElmtTree(Left(P)) + NbElmtTree(Right(P)));
	} 
}

int NbDaun (BinTree P) {
/* Mengirimkan banyaknya daun (node) pohon biner P */
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		if (IsOneElmt(P)) {
			return 1;
		}
		else {
			if (IsUnerLeft(P)) {
				return (NbDaun(Left(P)));
			}
			else if (IsUnerRight(P)) {
				return (NbDaun(Right(P)));
			}
			else {
				return (NbDaun(Left(P)) + NbDaun(Right(P)));
			}
		}
	}
}

boolean IsSkewLeft (BinTree P) {
/* Mengirimkan true jika P adalah pohon condong kiri */
	if (IsTreeEmpty(P)) {
		return false;
	}
	else {
		if (IsOneElmt(P)) {
			return true;
		}
		else {
			if (IsUnerLeft(P)) {
				return IsSkewLeft(Left(P));
			}
			else {
				return false;
			}
		}
	}
}

boolean IsSkewRight (BinTree P) {
/* Mengirimkan true jika P adalah pohon condong kanan */
	if (IsTreeEmpty(P)) {
		return false;
	}
	else {
		if (IsOneElmt(P)) {
			return true;
		}
		else {
			if (IsUnerRight(P)) {
				return IsSkewRight(Right(P));
			}
			else {
				return false;
			}
		}
	}
}

/*** Operasi lain ***/
void AddDaunTerkiri (BinTree *P, Infotype X) {
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
	if (IsTreeEmpty(*P)) {
		*P= Tree(X, NilTree, NilTree);
	}
	else {
		if (IsUnerRight(*P)) {
			AddDaunTerkiri(&Right(*P), X);
		}
		else {
			AddDaunTerkiri(&Left(*P), X);
		}
	}
}

void AddDaun (BinTree *P, Infotype X, Infotype Y, boolean Kiri) {
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
sebagai anak kanan X (jika Kiri = false) */
	if (!IsTreeEmpty(*P)) {
		if (Akar(*P) == X) {
			if (Kiri) {
				Left(*P)= Tree(Y, NilTree, NilTree);
			}
			else {
				Right(*P)= Tree(Y, NilTree, NilTree);
			}
		}
		else {
			if (IsUnerLeft(*P)) {
				AddDaun(&Left(*P), X, Y, Kiri);	
			}
			else if (IsUnerRight(*P)) {
				AddDaun(&Right(*P), X, Y, Kiri);	
			}
			else {
				if (SearchTree(Left(*P),X)) {
					AddDaun(&Left(*P), X, Y, Kiri);
				}
				else {
					AddDaun(&Right(*P), X, Y, Kiri);
				}
			}
		}
	}
}

void DelDaunTerkiri (BinTree *P, Infotype *X) {
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
disimpan pada daun terkiri yang dihapus */
	if (IsOneElmt(*P)) {
		*X = Akar(*P);
		free(*P);
		*P = NilTree;
	}
	else {
		if (IsUnerRight(*P)) {
			DelDaunTerkiri(&Right(*P), X);
		}
		else { 
			DelDaunTerkiri(&Left(*P), X);
		}
	}
}

void DelDaun (BinTree *P, Infotype X) {
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. Semua daun bernilai X dihapus dari P */
	if (!IsTreeEmpty(*P)) {
		if (Akar(*P) == X) {
			free(*P);
			*P= NilTree;
		}
		else {
			DelDaun(&Left(*P), X);
			DelDaun(&Right(*P), X);
		}
	}
}