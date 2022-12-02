#include "../Function/ADT/listdp.h"
#include <stdio.h>

void printElement(address P){
    if (P != Nil){
        printf("INFO : %d\n", Info(P));
        printf("ABSIS : %d\n", Absis(P->point));
        printf("ORDINAT : %d\n", Ordinat(P->point)); 
    }
    else{
        printf("ALAMAT BERNILAI NIL\n");
    }
}

void printKoordinat(List P){
    address loc = First(P);
    while (loc != Nil){
        printf("(%d, %d) ", Absis(loc->point), Ordinat(loc->point));
        loc = Next(loc);
    }
}
int main(){
    List L; 
    printf("==== DRIVER ADT LISTDP ====\n");

    printf("==== CreateEmpty ====\n");
    printf("EKSPETASI : Membuat list double pointer yang kosong\n");
    printf("TEST : Membuat list kosong L\n");
    CreateEmpty(&L);
    printf("\n");

    printf("==== isEmpty_L ====\n");
    printf("EKSPETASI : Memberikan 1 jika list kosong, 0 jika list tidak kosong\n");
    printf("TEST : cek apakah L kosong atau tidak (list L kosong)\n");
    printf("isEmpty_L - L : %d\n", IsEmpty_L(L));
    printf("\n");
    
    printf("==== ALOKASI / DEALOKASI ====\n");
    printf("EKSPETASI : Mengalokasikan address sebuah elemen\n");
    printf("TEST : Alokasi suatu elemen dengan X = 10, abs =  1 dan ord = 2\n");
    printf("bernilai NIL jika alokasi gagal\n");
    address a = Alokasi(10, 1, 2);
    printElement(a);
    printf("\n");
    printf("Fungsi dealokasi akan mendealokasikan address a\n");
    Dealokasi(a);

    printf("==== InsVFirst ====\n");
    printf("EKSPETASI : Memasukkan elemen ke awal list\n");
    printf("TEST : Memasukkan elemen dengan X = 1, abs = 4, ord = 5\n");
    InsVFirst(&L, 1, 4, 5);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n");
    printf("TEST 2: Memasukkan elemen dengan X = 0, abs = 3, ord = 4\n");
    InsVFirst(&L, 0, 3, 4);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");

    printf("==== InsVLast ====\n");
    printf("EKSPETASI : Memasukkan elemen ke akhir list\n");
    printf("TEST : Memasukkan elemen dengan X = 3, abs = 6, ord = 6\n");
    InsVLast(&L, 3, 6, 6);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n");
    printf("TEST 2: Memasukkan elemen dengan X = 4, abs = 8, ord = 2\n");
    InsVLast(&L, 4, 8, 2);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");

    infotype temp;

    printf("==== DelVFirst ====\n");
    printf("EKSPETASI : Menghapus elemen awal list dan menyimpannya di suatu variabel\n");
    printf("TEST : Memasukkan elemen awal L\n");
    DelVFirst(&L, &temp);
    printf("ELEMEN YANG DIHAPUS : %d\n", temp);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");

    printf("==== DelVLast ====\n");
    printf("EKSPETASI : Menghapus elemen akhir list dan menyimpannya di suatu variabel\n");
    printf("TEST : Memasukkan elemen akhir L\n");
    DelVLast(&L, &temp);
    printf("ELEMEN YANG DIHAPUS : %d\n", temp);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");

    printf("==== Search ====\n");
    printf("EKSPETASI : Mengembalikan address suatu infotype dalam List\n");
    printf("TEST : mencari address X = 1 dalam L\nakan mencetak isi dari address yang didapat\n");
    printElement(Search(L, 1));
    printf("\n");

    printf("==== SearchPoint ====\n");
    printf("EKSPETASI : bernilai 1 jika terdapat elemen list dengan abs dan ordinat yang ditentukan\n");
    printf("TEST 1 : cek apakah ada element dengan abs = 4 dan ordinat = 5\n");
    printf("TEST 2 : cek apakah ada element dengan abs = 5 dan ordinat = 4\n");
    printf("TEST 1 : %d\nTEST 2 : %d\n", SearchPoint(L, 4, 5), SearchPoint(L, 5, 4));
    printf("\n");

    printf("==== SearchAdrPoint ====\n");
    printf("EKSPETASI : Mengembalikan address elemen list dengan abs dan ordinat yang ditentukan\n");
    printf("TEST : mencari address abs = 6 dan ordinat = 6 dalam L\nakan mencetak isi dari address yang didapat\n");
    printElement(SearchAdrPoint(L, 6, 6));
    printf("\n");
    
    printf("==== SearchPointInGrid ====\n");
    printf("EKSPETASI : bernilai 1 jika terdapat elemen list dengan abs dan ordinat yang ditentukan\n");
    printf("TEST 1 : cek apakah ada element dengan abs = 4 dan ordinat = 5\n");
    printf("TEST 2 : cek apakah ada element dengan abs = 5 dan ordinat = 4\n");
    printf("TEST 1 : %d\nTEST 2 : %d\n", SearchPoint(L, 4, 5), SearchPoint(L, 5, 4));
    printf("\n");

    printf("==== InsertFirst ====\n");
    printf("EKSPETASI : Memasukkan elemen dengan alamat yang ditentukan ke awal list\n");
    printf("TEST : Memasukkan elemen dengan X = 5, abs = 4, ord = 7\n");
    address p = Alokasi(5, 4, 7);
    InsertFirst(&L, p);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");

    printf("==== InsertLast ====\n");
    printf("EKSPETASI : Memasukkan elemen dengan alamat yang ditentukan ke akhir list\n");
    printf("TEST : Memasukkan elemen dengan X = 7, abs =8, ord = 8\n");
    address p_2 = Alokasi(7, 8, 8);
    InsertLast(&L, p_2);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");

    printf("==== InsertAfter ====\n");
    printf("EKSPETASI : Memasukkan elemen dengan alamat yang ditentukan setelah address yang ditentukan\n");
    printf("TEST : Memasukkan elemen dengan X = 8, abs = 6, ord = 9 setelah alamat dengan info 3\n");
    address p_3 = Alokasi(8, 6, 9);
    InsertAfter(&L, p_3, Search(L, 3));
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");

    printf("==== InsertBefore ====\n");
    printf("EKSPETASI : Memasukkan elemen dengan alamat yang ditentukan sebelum address yang ditentukan\n");
    printf("TEST : Memasukkan elemen dengan X = 9, abs = 1, ord = 2 setelah alamat dengan info 3\n");
    address p_4 = Alokasi(9, 1, 2);
    InsertBefore(&L, p_4, Search(L, 3));
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");
    
    address temp_p; 
    
    printf("==== DelFirst ====\n");
    printf("EKSPETASI : Menghapus elemen pertama dalam list dan menyimpan alamatnya dalam suatu variabel\n");
    printf("TEST : Menghapus elemen pertama L\n");
    DelFirst(&L, &temp_p);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");

    printf("==== DelLast ====\n");
    printf("EKSPETASI : Menghapus elemen terakhir dalam list dan menyimpan alamatnya dalam suatu variabel\n");
    printf("TEST : Menghapus elemen terakhir L\n");
    DelLast(&L, &temp_p);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");

    printf("==== DelP ====\n");
    printf("EKSPETASI : Menghapus elemen dengan info yang ditentukan dalam list dan menyimpan alamatnya dalam suatu variabel\n");
    printf("TEST : Menghapus elemen dengan info = 9\n");
    DelP(&L, 9);
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");

    printf("==== DelAfter ====\n");
    printf("EKSPETASI : Menghapus elemen setelah address yang ditentukan dan menyimpan alamatnya dalam suatu variabel\n");
    printf("TEST : Menghapus elemen setelah elemen yang memiiki info = 3\n");
    DelAfter(&L, &temp_p, Search(L, 3));
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");  

    printf("==== DelBefore ====\n");
    printf("EKSPETASI : Menghapus elemen sebelum address yang ditentukan dan menyimpan alamatnya dalam suatu variabel\n");
    printf("TEST : Menghapus elemen sebelum elemen yang memiiki info = 3\n");
    DelBefore(&L, &temp_p, Search(L, 3));
    PrintForward(L);
    printf("\n");
    printKoordinat(L);
    printf("\n\n");  

    printf("Untuk 2 fungsi selanjutnya harus dilakukan pengisian List\n");
    InsVLast(&L, 4, 7, 7);
    InsVLast(&L, 5, 8, 8);
    InsVLast(&L, 6, 9, 9);
    printf("==== PrintForward ====\n");
    printf("EKSPETASI : Mencetak Info List dari awal ke akhir\n");
    printf("TEST :\n");
    PrintForward(L);
    printf("\n\n"); 
    printf("==== PrintBackward ====\n");
    printf("EKSPETASI : Mencetak Info List dari akhir ke awal\n");
    printf("TEST :\n");
    PrintBackward(L);
    printf("\n\n");   

    return 0; 
}