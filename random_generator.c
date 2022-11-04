#include <stdio.h>
#include "random_generator.h"

int GenRand(int low, int up){
	srand(time(NULL));
	int X = rand() % 50;
	return (X % (up - low + 1)) + low;
}
/*membuat suatu random generator dalam range tertentu*/