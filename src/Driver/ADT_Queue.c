#include <stdio.h>
#include "..Function/ADT/queue.h"
#include "..Function/ADT/mesinkata.h"
#include "..Function/ADT/mesinkarakter.h"

int main () {
    // Cek fungsi CreateQueue
    Queue contoh; 
    CreateQueue(&contoh);
    // Expected Output = Tercipta Queue kosong bernama contoh, pengecekan dilakukan berbarengan dengan Cek Fungsi Isempty

    // Cek Fungsi IsEmpty
    printf("Apakah queue kosong?\n");
    if (isEmpty(contoh)) {
        printf("Iya\n");
    } else {
        printf("Tidak\n");
    }
    printf("\n");
    // Expected Output = Queue kosong karena baru dibuat, jadi output = "Tidak"

    // Pengecekan fungsi enqueue
    printf("Isi elemen array = \n");
    for (int i = 0; i < 3; i++) {
        START();
        CopyWord();
        enqueue(&contoh, currentWord);
    }
    printf("\n");
    // Expected output : Queue terisi, pengecekan melalui fungsi uji dequeue (isi queue sebelum di dequeue akan berisi game game yang di input user)

    // Pengecekan fungsi length
    printf("Panjang queue = %d\n", length(contoh));
    printf("\n");
    // Expected output : 3

    // Pengecekan fungsi IsFull
    printf("Apakah queue full?\n");
    if (isFull(contoh)) {
        printf("Iya\n");
    } else {
        printf("Tidak\n");
    }
    printf("\n");
    // Expected Output = Tidak

    
    // Uji dequeue dan printgame
    printf("Isi queue sebelum di dequeue = \n");
    PrintQueueGame(contoh);
    printf("\n");
    // Expected output : Game-game sebelum di dequeue

    Word val;
    dequeue(&contoh, &val);

    printf("Isi queue  setelah di dequeue = \n");
    PrintQueueGame(contoh);
    printf("\n");
    // Expected output = Game no 1 sebelum di dequeue hilang, maka game 2 jadi game pertama

}
