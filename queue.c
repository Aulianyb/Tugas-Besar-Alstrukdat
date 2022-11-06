#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void CreateQueue(Queue *q){
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

boolean isEmpty(Queue q){
    return (q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF);
}
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull(Queue q){
    return ((q.idxHead == 0 && q.idxTail == CAPACITY-1) || (q.idxTail == q.idxHead-1));
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q){
    if(isEmpty(q)){
        return 0;
    }
    else {
        int panjang = ((CAPACITY+q.idxTail-q.idxHead)%CAPACITY)+1;
        return panjang;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

void enqueue(Queue *q, ElType val){
    if (isEmpty(*q)){
        (*q).idxHead = 0;
        (*q).idxTail = 0;
    }
    else{
        (*q).idxTail += 1;
        (*q).idxTail %= CAPACITY;
    }
    (*q).buffer[(*q).idxTail] = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val){
    *val = (*q).buffer[(*q).idxHead];
    if((*q).idxHead == (*q).idxTail){
        (*q).idxHead = IDX_UNDEF;
        (*q).idxTail = IDX_UNDEF;
    }
    else{
        (*q).idxHead += 1;
        (*q).idxHead %= CAPACITY;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

void displayQueue(Queue q){
    if (!isEmpty(q)){
        printf("[%d,",q.buffer[q.idxHead]);
        for (int i=1;i<=(length(q)-2);i++){
            printf("%d,",q.buffer[(q.idxHead+i)%CAPACITY]);
        }
        printf("%d]\n",q.buffer[q.idxTail]);
    }
    else{
        printf("[]\n");
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */