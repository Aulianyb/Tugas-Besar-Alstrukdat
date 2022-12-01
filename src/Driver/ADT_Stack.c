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
    printf("Membuat Stack menjadi kosong\n");
    printf("==== IsEmpty_S ====\n");
    printf("IsEmpty : %d\n", IsEmpty_S(S));
    printf("==== isiTiang ====\n");
    printf("Isi Tiang akan mengisi Tiang sesuai input n\n");
    printf("Misal : N = 10\n");
    isiTiang(&S, 24);
    printStack(S, 24);
    printf("==== IsFull_S ====\n");
    printf("Return nilai apakah stack memenuhi kapasitas atau tidak (MaxEL : 24)\n");
    printf("isFull : %d", IsFull_S(S));
    printf("\n");
    printf("Misal : N = 5\n");
    CreateEmpty(&S);
    isiTiang(&S, 5);
    printStack(S, 5);
    printf("==== Pop ====\n");
    infotype temp; 
    Pop(&S, &temp);
    printf("ELEMEN YANG DI POP :\nn : %d\ngraph : ", n(temp));
    PrintKata(graph(temp));
    printf("\n\n");
    printStack(S, 5);
    printf("==== Push ====\n");
    Push(&S, temp);
    printStack(S, 5);
    return 0;
}