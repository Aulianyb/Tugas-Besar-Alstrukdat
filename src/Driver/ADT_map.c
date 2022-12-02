#include <stdio.h>
#include "../Function/ADT/map/map.h"

int main()
{
    Map M;
    // Membentuk map baru yang kosong
    // Expected Output: Map kosong
    printf("=========== TEST CreateEmptyMap ===========\n");
    CreateEmptyMap(&M);
    TulisMap(M);

    // Mengecek apakah map yang baru terbentuk kosong
    // Expected Output: 
    printf("\n=========== TEST IsEmptyMap ===========\n");
    printf("\n%d", IsEmptyMap(M));

    // Mengecek apakah map yang baru terbentuk penuh
    // Expected Output: 0
    printf("\n=========== TEST IsFullMap ===========\n");
    printf("\n%d", IsFullMap(M));

    // Memasukkan elemen ke map dalam keadaan sudah disort.
    // Expected Output: pada map elemen ke-1 berisi user Mikasa dengan skor 85
    //                  pada map elemen ke-2 berisi user Eren dengan skor 80
    //                  pada map elemen ke-3 berisi user Levi dengan skor 70
    //                  pada map elemen ke-4 berisi user Erwin dengan skor 70
    //                  pada map elemen ke-5 berisi user Armin dengan skor 65

    printf("\n=========== TEST InsertMap ===========\n");
    InsertMap(&M, strToWord("Eren"), 80);
    InsertMap(&M, strToWord("Mikasa"), 85);
    InsertMap(&M, strToWord("Armin"), 65);
    InsertMap(&M, strToWord("Levi"), 70);
    InsertMap(&M, strToWord("Erwin"), 70);

    // Menulis Isi Map
    // Expected Output:
            // ---------------------------------
            // | Mikasa        | 85            |
            // | Eren          | 80            |
            // | Levi          | 70            |
            // | Erwin         | 70            |
            // | Armin         | 65            |
            // ---------------------------------
    TulisMap(M);

    // Memasukkan elemen ke map menggunakan InsertMapLOAD.
    // Expected Output: pada map elemen ke-1 berisi user Mikasa dengan skor 85
    //                  pada map elemen ke-2 berisi user Eren dengan skor 80
    //                  pada map elemen ke-3 berisi user Annie dengan skor 80
    //                  pada map elemen ke-4 berisi user Levi dengan skor 80
    //                  pada map elemen ke-5 berisi user Erwin dengan skor 70
    //                  pada map elemen ke-6 berisi user Reiner dengan skor 70
    //                  pada map elemen ke-7 berisi user Armin dengan skor 65
    //                  pada map elemen ke-8 berisi user Berutoroto dengan skor 65
    printf("\n=========== TEST InsertMapLOAD ===========\n");
    InsertMap(&M, strToWord("Annie"), 80);
    InsertMap(&M, strToWord("Reiner"), 70);
    InsertMap(&M, strToWord("Berutoruto"), 65);

    // Menulis isi map
    // Expected Output:
        // ---------------------------------
        // | Mikasa        | 85            |
        // | Eren          | 80            |
        // | Annie         | 80            |
        // | Levi          | 70            |
        // | Erwin         | 70            |
        // | Reiner        | 70            |
        // | Armin         | 65            |
        // | Berutoruto    | 65            |
        // ---------------------------------
    TulisMap(M);

}