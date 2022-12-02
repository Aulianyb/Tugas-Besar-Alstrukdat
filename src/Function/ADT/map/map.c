#include "map.h"
/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M){
    M->Count = NilMap;
}

boolean IsEmptyMap(Map M){
    return (M.Count == NilMap);
}

boolean IsFullMap(Map M){
    return (M.Count == MaxElMap);
}

void InsertMap(Map *M, Word k, int v)
{
    if (!IsMemberMap(*M, k)){
        int j = 0;
        M->Elements[M->Count].user.Length = k.Length;
        while (k.TabWord[j] != '\0') {
            M->Elements[M->Count].user.TabWord[j] = k.TabWord[j];
            j++;
        }
        (*M).Elements[(*M).Count].score = v;
        (*M).Count += 1;
    } else {
        boolean found = false;
        int idx;
        int i = 0;

        while (i < (*M).Count && !found){
            if (isWordandWordEqual(M->Elements[i].user, k)){
                found = true;
                idx = i;
            }
            i++;
        }
        if (found)
        {
            M->Elements[idx].score = v;
        }
    }

    // sort mapnya
	int temp_val, n = M->Count;
    Word temp_key;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (M->Elements[j].score <= M->Elements[j+1].score){
				temp_val = M->Elements[j].score; temp_key = M->Elements[j].user;					
				M->Elements[j].score = M->Elements[j+1].score; M->Elements[j].user = M->Elements[j+1].user;
				M->Elements[j+1].score = temp_val; M->Elements[j+1].user = temp_key;
					
			}
		}
	}
}

void InsertMapLOAD(Map *M, Word k, int v)
{
    if (!IsMemberMap(*M, k)){
        int j = 0;
        M->Elements[M->Count].user.Length = k.Length;
        while (k.TabWord[j] != '\0') {
            M->Elements[M->Count].user.TabWord[j] = k.TabWord[j];
            j++;
        }
        (*M).Elements[(*M).Count].score = v;
        (*M).Count += 1;
    } else {
        boolean found = false;
        int idx;
        int i = 0;

        while (i < (*M).Count && !found){
            if (isWordandWordEqual(M->Elements[i].user, k)){
                found = true;
                idx = i;
            }
            i++;
        }
        if (found)
        {
            M->Elements[idx].score = v;
        }
    }

    // sort mapnya
	int temp_val, n = M->Count;
    Word temp_key;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (M->Elements[j].score < M->Elements[j+1].score){
				temp_val = M->Elements[j].score; temp_key = M->Elements[j].user;					
				M->Elements[j].score = M->Elements[j+1].score; M->Elements[j].user = M->Elements[j+1].user;
				M->Elements[j+1].score = temp_val; M->Elements[j+1].user = temp_key;
					
			}
		}
	}
}

boolean IsMemberMap(Map M, Word k){
    boolean found = false;
    int i = 0;

    while (i < M.Count && !found){
        if (isWordandWordEqual(M.Elements[i].user, k)){
            found = true;
        }
        i++;
    }

    return found;
}

void TulisMap(Map M)
{
    if (IsEmptyMap(M)) printf("Map kosong\n");
    else {
        printf("---------------------------------\n");
        for (int j = 0; j < M.Count; j++)
        {
            printf("| ");
            PrintKata(M.Elements[j].user);
            if (M.Elements[j].user.Length <= 13)
            {
                printf("\t");
                if (M.Elements[j].user.Length <= 5) {
                    printf("\t");
                }
            }
            printf("| ");
            printf("%d", M.Elements[j].score);
            printf("\t\t|\n");
        }
        printf("---------------------------------\n");
    }
}
boolean isWordandWordEqual(Word word1, Word word2)
{
    boolean sama = true;
    if (word1.Length != word2.Length) {
        return !sama;
    } else {
        int i = 0;
        while (sama && (i < word2.Length)) {
            if (word1.TabWord[i] != word2.TabWord[i]) {
                sama = false;
            }
            i++;
        }
        return sama;
    }
}