#include <stdio.h>
#include "random_generator.h"

int GenRand(int low, int up, int mod){
	srand(time(NULL));
	int X = rand() % mod;
	return (X % (up - low + 1)) + low;
}
/*membuat suatu random generator dalam range tertentu*/

void delay(int miliseconds)
{
    long pause;
    clock_t now,then;

    pause = miliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}