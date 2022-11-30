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
    return (M.Count == MaxEl);
}

int GetScoreMap(Map M, Word k){
    boolean found = false;
    int idx;
    int i = 0;

    while (i < M.Count && !found){
        if (isWordandWordEqual(M.Elements[i].user, k)){
            found = true;
            idx = i;
        }
        i++;
    }

    if (found) return M.Elements[idx].score;
    else return Undefined;
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
    }
}

void DeleteMap(Map *M, Word k){
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
        for (i = idx; i < (*M).Count - 1; i++){
            (*M).Elements[i].user = (*M).Elements[i + 1].user;
            (*M).Elements[i].score = (*M).Elements[i + 1].score;
        }
        (*M).Count -= 1;
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