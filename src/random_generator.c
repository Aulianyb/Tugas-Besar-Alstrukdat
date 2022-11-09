#include <stdio.h>
#include "random_generator.h"

int GenRand(int low, int up, int mod){
	srand(time(NULL));
	int X = rand() % mod;
	return (X % (up - low + 1)) + low;
}
/*membuat suatu random generator dalam range tertentu*/