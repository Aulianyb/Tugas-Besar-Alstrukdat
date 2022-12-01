#include "../Function/ADT/stack.h"
#include "../Function/ADT/mesinkata.h"
#include <stdio.h>

int printStack(Stack S, int n){
    for (int i=n-1;i>0;i--){
        PrintKata(graph(S.T[i]));
        printf("\n");
    }
}

int main(){
    printf("==== DRIVER ADT STACK ====\n");
    Stack S; 

    //MEMBUAT STACK EMPTY
    CreateEmpty(&S);
    
    printf("==== CreateEmpty ====\n");
    printf("Membuat Stack menjadi kosong\n");
    printf("==== IsEmpty_S ====\n");
    printf("IsEmpty : %d\n", IsEmpty_S(S));
    printf("==== isiTiang ====\n");
    printf("Isi Tiang akan mengisi Tiang sesuai input n\n");
    printf("Misal : N = 10\n");
    isiTiang(&S, 29);
    printStack(S, 30);
    printf("\n");
    printf("Misal : N = 5\n");
    CreateEmpty(&S);
    isiTiang(&S, 5);
    printStack(S, 5);
    printf("\n");
    printf("==== Push ====\n");
    printf("==== Pop ====\n");
    return 0;
}