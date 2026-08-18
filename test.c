#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void) {
	srand(time(NULL));
	printf("%d\n",RAND_MAX);

	for (int i = 0; i < 10; i++) {
		printf("%f\n", (float)rand()/RAND_MAX);
	}
	return 0;
}