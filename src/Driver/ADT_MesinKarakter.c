#include "../ADT/mesinkarakter.h"

int main(){
    printf("Tes STARTINPUT dari inputan pengguna\n");
    START();
	printf("Tes GetCC dan ADV\n");
	while (currentChar != '\n')
	{
		printf("%c\n", GetCC());
		ADV();
	}
    return 0;
}