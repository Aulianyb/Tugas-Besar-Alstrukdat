#include <stdio.h>
#include "Function/ADT/stack.h"
#include "Function/ADT/mesinkata.h"


//INI FILE BUAT NYOBA NYOBA AJA

int main(){
	Stack S;
	CreateEmpty(&S);
	printf("N = ");
	STARTFILE();
	isiTiang(&S, WordToInt(currentWord));

	for (int i=Top(S); i >= 0;i--){
		PrintKata(graph(S.T[i]));
		printf("\n");
	}
	return 0; 
}