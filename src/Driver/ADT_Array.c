#include <stdio.h>
#include "../Function/ADT/array.h"

int main() {
    /* ***Membuat Array baru yang kosong*** */
    printf("Membuat array baru yang kosong...\n"); 
    TabGame T;
    MakeEmpty(&T);
    TulisIsi(T);
    printf("\n");
    //Expected Output : Terbentuk Array baru yang kosong, menuliskan "Isi kosong" ke layar

    /* ***Mengecek apakah array yang dibuat kosong*** */
    printf("Mengecek apakah array yang dibuat kosong (Menuliskan 0 bila tidak kosong, 1 jika kosong) :\n");
    printf("%d\n",IsEmpty(T));
    printf("\n");
    //Expected output : 1

    /* ***Menuliskan banyaknya elemen yang dapat ditampung dalam array*** */
    printf("Banyaknya elemen yang dapat ditampung : %d\n",MaxNbEl(T));
    printf("\n");
    //Expected output : 100

    /* ***Memasukkan elemen ke dalam array*** */
    printf("Memasukkan elemen ke dalam array...\n");
    SetEl(&T,1,strToWord("SONIC"));
    SetEl(&T,2,strToWord("MARIO KART"));
    SetEl(&T,3,strToWord("ZELDA"));
    SetEl(&T,4,strToWord("SUPER SMASH BROS"));
    SetEl(&T,5,strToWord("PATAPON"));
    printf("\n");
    /*Expected output : pada array, elemen ke-1 menjadi "SONIC",
                        elemen ke-2 menjadi "MARIO KART",
                        elemen ke-3 menjadi "ZELDA",
                        elemen ke-4 menjadi "SUPER SMASH BROS",
                        elemen ke-5 menjadi "PATAPON". */

    /* ***Mengecek apakah array yang sudah diisi kosong*** */
    printf("Mengecek apakah array kosong (Menuliskan 0 bila tidak kosong, 1 jika kosong) :\n");
    printf("%d\n",IsEmpty(T));
    printf("\n");
    //Expected output : 0

    /* ***Menuliskan berapa banyak elemen efektif yang ada pada array*** */
    printf("Banyak elemen efektif pada array : %d\n",NbElmt(T));
    printf("\n");
    //Expected output : 5

    /* ***Menuliskan indeks pertama dan indeks terakhir dari array ke layar*** */
    printf("Indeks pertama dari array : %d\n",GetFirstIdx(T));
    //Expected output : 1
    printf("Indeks terakhir dari array : %d\n",GetLastIdx(T));
    //Expected output : 5
    printf("\n");
    

    /* ***Mengecek apakah indeks valid atau tidak dan apakah indeks efektif atau tidak*** */
    printf("Apakah indeks ke-10 valid? (0 jika tidak valid, 1 jika valid)\n");
    printf("%d\n",IsIdxValid(T,10));
    //Expected output : 1
    printf("Apakah indeks ke-101 valid? (0 jika tidak valid, 1 jika valid)\n");
    printf("%d\n",IsIdxValid(T,101));
    //Expected output : 0
    printf("Apakah indeks ke-90 efektif? (0 jika tidak valid, 1 jika valid)\n");
    printf("%d\n",IsIdxEff(T,90));
    //Expected output : 0
    printf("Apakah indeks ke-3 efektif? (0 jika tidak valid, 1 jika valid)\n");
    printf("%d\n",IsIdxEff(T,3));
    printf("\n");
    //Expected output : 1

    /* ***Menulis isi array setelah diisi elemen*** */
    printf("Menuliskan isi array ke layar...\n");
    TulisIsi(T);
    printf("\n");
    /*Expected output :
      1. SONIC
      2. MARIO KART
      3. ZELDA
      4. SUPER SMASH BROS
      5. PATAPON
    */

    /* ***Membuat salinan array dari T ke array baru yaitu Tcopy*** */
    printf("Membuat array baru hasil salinan array lama...\n");
    TabGame Tcopy;
    MakeEmpty(&Tcopy);
    SetTab(T,&Tcopy);
    printf("\n");
    //Expected output : Terbentuk array baru hasil salinan dari array lama

    /* ***Mengecek apakah array hasil salinan kosong*** */
    printf("Mengecek apakah array hasil salinan kosong (Menuliskan 0 bila tidak kosong, 1 jika kosong) :\n");
    printf("%d\n",IsEmpty(Tcopy));
    printf("\n");
    //Expected output : 0

    /* ***Mengecek apakah array hasil salinan penuh*** */
    printf("Mengecek apakah array hasil salinan penuh (Menuliskan 0 bila tidak kosong, 1 jika kosong) :\n");
    printf("%d\n",IsFull(Tcopy));
    printf("\n");
    //Expected output : 0

    /* ***Menuliskan isi array hasil salinan ke layar*** */
    printf("Menuliskan isi array hasil salinan ke layar...\n");
    TulisIsi(Tcopy);
    printf("\n");
    /*Expected output :
      1. SONIC
      2. MARIO KART
      3. ZELDA
      4. SUPER SMASH BROS
      5. PATAPON
    */

    /* ***Menampilkan elemen pada indeks tertentu ke layar*** */
    printf("Mendapatkan dan menampilkan elemen pada indeks ke-3 di array : \n");
    PrintKata(GetElmt(T,3));
    printf("\n");
    printf("\n");
    //Expected output : ZELDA

    printf("Mendapatkan dan menampilkan elemen pada indeks ke-4 di array : \n");
    PrintKata(GetElmt(T,4));
    printf("\n");
    printf("\n");
    //Expected output : SUPER SMASH BROS

    /* ***Menghapus elemen pada indeks tertentu*** */
    printf("Menghapus elemen pada indeks ke-5 : \n");
    DeleteAt(&T,5);
    TulisIsi(T);
    printf("\n");
    /*Expected output :
      1. SONIC
      2. MARIO KART
      3. ZELDA
      4. SUPER SMASH BROS
    */

    printf("Menghapus elemen pada indeks ke-2 : \n");
    DeleteAt(&T,2);
    TulisIsi(T);
    printf("\n");
    /*Expected output
      1. SONIC
      2. ZELDA
      3. SUPER SMASH BROS
    */

    /* ***Mengeset banyaknya elemen efektif pada array*** */
    printf("Mengubah banyaknya elemen efektif pada array menjadi 2 dan menuliskan isi array ke layar : \n");
    SetNeff(&T,2);
    TulisIsi(T);
    printf("\n");
    /*Expected output :
      1. SONIC
      2. ZELDA
    */

    return 0;
}