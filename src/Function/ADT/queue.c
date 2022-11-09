#include <stdio.h>
#include "../../boolean.h"
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

boolean isEmpty(Queue q)
{
    return (IDX_HEAD(q) = IDX_UNDEF  && IDX_TAIL(q) == IDX_UNDEF);
}
/* Mengirim true jika q kosong: lihat definisi di atas */


boolean isFull(Queue q)
{
    if (IDX_TAIL(q) >= IDX_HEAD(q))
        return IDX_TAIL(q) - IDX_HEAD(q) == CAPACITY - 1;
    else
        return IDX_HEAD(q) - IDX_TAIL(q) == 1;
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/


int length(Queue q){
    if (isEmpty(q)) return 0;
    else if (IDX_TAIL(q) >= IDX_HEAD(q))
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    else
        return IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY + 1;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */


void enqueue(Queue *q, ElType val){
    if (isEmpty(*q)){
        IDX_TAIL(*q) = 0;
        IDX_HEAD(*q) = 0;
        TAIL(*q) = val;
    }
    else{
        IDX_TAIL(*q)++;
        IDX_TAIL(*q) %= CAPACITY;
        TAIL(*q) = val;
    }
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */


void dequeue(Queue *q, ElType *val){
    int i;
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q)++;
        IDX_HEAD(*q) %= CAPACITY;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., */
/*      HEAD "maju" dalam buffer melingkar; */
/*      Jika q menjadi kosong, IDX_TAIL diset IDX_UNDEF. */



void displayQueue(Queue q){
    int i, len = length(q);
    printf("[");
    for (i = 0; i < len; i++)
    {
        printf("%s", q.buffer[(i + IDX_HEAD(q)) % CAPACITY]);
        if (i < (len - 1)) printf(",");
    }
    printf("]\n");
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

void PrintQueueGame(Queue q){
    int i, len = length(q);
    for (i = 0; i < len; i++)
    {
        printf("%d. ", i+1);
        printf("%s\n", q.buffer[(i + IDX_HEAD(q)) % CAPACITY]);
    }
    printf("\n");
}

// boolean isEqual(char* str1, char* str2){
//     int i = 0;
//     while (str1[i] != '\0' && str2[i] != '\0')
//     {
//         if (str1[i] != str2[i]) return false;
//         i++;
//     }
//     return str1[i] == str2[i];
// }
