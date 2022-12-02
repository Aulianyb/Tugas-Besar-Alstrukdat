#include <stdio.h>
#include "../Function/ADT/stackhistory/stackhistory.h"

int main()
{
    StackHistory S, Sout; Word word; int n;
    // ----- Membuat stack baru kosong dan dicek -----
    // Expected Output: 1
    //                  1
    printf("\n=========== TEST CreateEmptyHistory & IsEmptyHistory ===========\n");
    CreateEmptyHistory(&S);
    CreateEmptyHistory(&Sout);
    printf("%d\n", IsEmptyHistory(S));
    printf("%d\n", IsEmptyHistory(Sout));

    // ------ Mengecek apakah stack yang baru dibuat penuh? ------
    // Expected Output: 0
    printf("\n=========== TEST IsFullHistory ===========\n");
    printf("%d\n", IsFullHistory(S));

    // ------ Memasukkan beberapa elemen ke dalam stack -----
    // Expected Output: elemen ke-0 stack adalah Naruto
    //                  elemen ke-1 stack adalah Sakura
    //                  elemen ke-2 stack adalah Sasuke
    printf("\n=========== TEST PushHistory ===========\n");
    PushHistory(&S, strToWord("Naruto"));
    PushHistory(&S, strToWord("Sakura"));
    PushHistory(&S, strToWord("Sasuke"));

    // ------ Mengecek apakah stack yang sudah diisi kosong -------
    // Expected Output: 0
    printf("\n=========== TEST IsEmptyHistory ===========\n");
    printf("%d\n", IsEmptyHistory(S));

    // ------ Menuliskan isi stack setelah diisi beberapa elemen -------
    // Expected Output:
            // 1. Sasuke
            // 2. Sakura
            // 3. Naruto
    printf("\n=========== TEST PrintStackHistory ===========\n");
    PrintStackHistory(S, Top(S)+1);

    // ------ Menghapus beberapa elemen dari stack ------
    // Expected Output:
            // 1. Sakura
            // 2. Naruto
    printf("\n=========== TEST PopHistory ===========\n");
    PopHistory(&S, &word);
    PrintStackHistory(S, Top(S)+1);

    // ------ Melakukan swap dari setiap elemen stack ------
    // Expected Output:
            // 1. Naruto
            // 2. Sakura
    printf("\n=========== TEST SwapStackHistory ===========\n");
    SwapStackHistory(S, &Sout);
    PrintStackHistory(Sout, Top(Sout)+1);
}