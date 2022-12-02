#include <stdio.h>
#include "../Function/ADT/arrayofmap/arrayofmap.h"

int main()
{
    TabScore T; Map M1; Map M2; Map M3;

    // Mengisi Map M1
    InsertMap(&M1, strToWord("Armin"), 65);
    InsertMap(&M1, strToWord("Levi"), 70);
    InsertMap(&M1, strToWord("Erwin"), 70);

    // Mengisi Map M2
    InsertMap(&M2, strToWord("Shinomiya"), 100);
    InsertMap(&M2, strToWord("Shirogane"), 99);
    InsertMap(&M2, strToWord("Fujiwara"), 60);

    // Mengisi Map M2
    InsertMap(&M3, strToWord("Shani"), 88);
    InsertMap(&M3, strToWord("Gracia"), 83);
    InsertMap(&M3, strToWord("Feni"), 85);

    // Membuat TabScore baru yang kosong
    // Expected Output: Elemen kosong
    printf("\n=========== TEST MakeEmptyTabScore ===========\n");
    MakeEmptyTabScore(&T);
    TulisIsiTabScore(T);

    // Mengecek apakah TabScore kosong
    // Expected Output: 1
    printf("\n=========== TEST IsEmptyTabScore ===========\n");
    printf("%d\n", IsEmptyTabScore(T));

    // Memasukkan beberapa elemen pada TabScore menggunakan InsertLast
    // Expected Output: Elemen ke-1 berisi M1
    //                  Elemen ke-2 berisi M3
    printf("\n=========== TEST InsertLastTabScore ===========\n");
    InsertLastTabScore(&T, M1);
    InsertLastTabScore(&T, M3);

    // Mengecek apakah TabScore kosong
    // Expected Output: 0
    printf("\n=========== TEST IsEmptyTabScore ===========\n");
    printf("%d\n", IsEmptyTabScore(T));
    

    // Mengecek banyak elemen dalam TabScore
    // Expected Output: 2
    printf("\n=========== TEST NbElmtTabScore ===========\n");
    printf("%d\n", NbElmtTabScore(T));

    // Mengecek TulisIsiTabScore
    // Expected Output:
        // ***** ELEMEN KE-1  *****
        // | NAMA          | SKOR          |
        // ---------------------------------
        // | Erwin         | 70            |
        // | Levi          | 70            |
        // | Armin         | 65            |

        // ***** ELEMEN KE-2  *****
        // | NAMA          | SKOR          |
        // ---------------------------------
        // | Shani         | 88            |
        // | Feni          | 85            |
        // | Gracia        | 83            |
    printf("=========== TEST TulisIsiTabScore ===========\n");
    TulisIsiTabScore(T);
    
    // Memasukkan elemen pada indeks tertentu pada TabScore
    // Expected Output: Elemen ke-1 TabScore adalah M1
    //                  Elemen ke-2 TabScore adalah M2
    //                  Elemen ke-3 TabScore adalah M3
    printf("\n=========== TEST SetElTabScore ===========\n");
    SetElTabScore(&T, 2, M2);

    // Mengecek isi elemen ke-2 TabScore
    // Expected Output:
            // ---------------------------------
            // | Shinomiya     | 100           |
            // | Shirogane     | 99            |
            // | Fujiwara      | 60            |
            // ---------------------------------
    printf("\n=========== TEST GetElmtTabScore ===========\n");
    TulisMap(GetElmtTabScore(T, 2));
    printf("\n");


    // Mengecek Indeks pertama efektif TabScore
    // Expected Output: 1
    printf("\n=========== TEST GetFirstIdxTabScore ===========\n");
    printf("%d\n", GetFirstIdxTabScore(T));

    // Mengecek Indeks efektif terakhir TabScore
    // Expected Output: 3
    printf("\n=========== TEST GetLastIdxTabScore ===========\n");
    printf("%d\n", GetLastIdxTabScore(T));

    // Mengecek apakah TabScore sudah penuh
    // Expected Output: 0
    printf("\n=========== TEST IsFullTabScore ===========\n");
    printf("%d\n", IsFullTabScore(T));

    // Menghapus elemen ke-2 pada TabScore
    // Expected Output:
    printf("\n=========== TEST DeleteAtTabScore ===========\n");
    DeleteAtTabScore(&T, 2);

    // Menampilkan Seluruh isi TabScore
    // Expected Output:
            // ***** ELEMEN KE-1  *****
            // | NAMA          | SKOR          |
            // ---------------------------------
            // | Erwin         | 70            |
            // | Levi          | 70            |
            // | Armin         | 65            |

            // ***** ELEMEN KE-2  *****
            // | NAMA          | SKOR          |
            // ---------------------------------
            // | Shani         | 88            |
            // | Feni          | 85            |
            // | Gracia        | 83            |
    printf("\n=========== TEST TulisIsiTabScore ===========\n");
    TulisIsiTabScore(T);
}