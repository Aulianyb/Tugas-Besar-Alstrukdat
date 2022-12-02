#include "../Function/ADT/stack.h"
#include "../Function/ADT/mesinkata.h"
#include <stdio.h>

int printStack(Stack S, int n){
    
    for (int i=n-1;i>0;i--){
        if (i > Top(S)){
            int j=0;
            while (j<(2*n-1)/2){
                printf(" ");
                // printf("%d", n);
                j++;    
            }
            printf("|");
            j++;
            while (j<(2*n-1)){
                printf(" ");
                j++;    
            }
        }
        else{
            PrintKata(graph(S.T[i]));
        }
        printf("\n");
    }
}

int main(){
    printf("==== DRIVER ADT STACK ====\n");
    Stack S; 

    //MEMBUAT STACK EMPTY
    CreateEmpty(&S);
    
    printf("==== CreateEmpty ====\n");
    printf("EKSPETASI : Membuat Stack menjadi kosong\n");
    printf("TEST : Membuat Stack S menjadi Kosong\n");
    printf("\n");


    printf("==== IsEmpty_S ====\n");
    printf("EKSPETASI : bernilai 1 jika stack kosong, 0 jika tidak\n");
    printf("TEST : cek apakah S kosong, seharusnya mengembalikan nilai 1\n");
    printf("IsEmpty : %d\n", IsEmpty_S(S));
    printf("\n");


    printf("==== isiTiang ====\n");
    printf("EKSPETASI : Isi Tiang akan mengisi Tiang sesuai input n\n");
    printf("TEST : Mengisi tiang dengan N = 24\n");
    isiTiang(&S, 24);
    printStack(S, 24);
    printf("\n");

    printf("==== IsFull_S ====\n");
    printf("EKSPETASI : Return nilai apakah stack memenuhi kapasitas atau tidak (MaxEL : 24)\n");
    printf("TEST : cek apakah S penuh\n");
    printf("isFull : %d", IsFull_S(S));
    printf("\n");

    printf("TEST 2 : Mengosongkan Stack, lalu mengisinya sebanyak N = 5\n");
    CreateEmpty(&S);
    isiTiang(&S, 5);
    printStack(S, 5);
    printf("\n");

    printf("==== Pop ====\n");
    printf("EKSPETASI : menghapus elemen TOP dan menyimpannya dalam suatu variabel (temp)\n");
    printf("TEST : Pop Stack S dan menyimpan elemn TOPnya dalam temp\n");
    infotype temp; 
    Pop(&S, &temp);
    printf("ELEMEN YANG DI POP :\nn : %d\ngraph : ", n(temp));
    PrintKata(graph(temp));
    printf("\n\n");
    printStack(S, 5);
    printf("\n");

    printf("==== Push ====\n");
    printf("EKSPETASI : menambahkan elemen pada TOP, TOP bertambah\n");
    printf("TEST : Push temp kembali kedalam Stack\n");
    Push(&S, temp);
    printStack(S, 5);
    return 0;
}