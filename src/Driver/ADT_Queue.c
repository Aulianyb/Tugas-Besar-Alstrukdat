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
    // Expected output : Queue terisi, pengecekan melalui 

    // Pengecekan fungsi length
    printf("Panjang queue = %d\n", length(contoh));
    printf("\n");

    // Pengecekan fungsi IsFull
    printf("Apakah queue full?\n");
    if (isFull(contoh)) {
        printf("Iya\n");
    } else {
        printf("Tidak\n");
    }
    printf("\n");

    
    // Uji dequeue
    printf("Isi queue sebelum di dequeue = \n");
    PrintQueueGame(contoh);
    printf("\n");

    Word val;
    dequeue(&contoh, &val);

    printf("Isi queue  setelah di dequeue = \n");
    PrintQueueGame(contoh);
    printf("\n");

}
