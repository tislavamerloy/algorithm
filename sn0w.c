#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char massive[50][200];
	
	for (int i = 0; i < 50; ++i) {
		memset(&massive[i], ' ', 800);
	}

	while (1) {

		for (int i = 0; i < 50; ++i) {
			memset(&massive[i], ' ', 800);
		}

		for (int i = 0; i < 10; ++i) {
			massive[rand(5) % 50][rand(6) % 200] = '*';
		}

		for (int i = 0; i < 50; ++i) {
			for (int ii = 0; ii < 200; ++ii) {
				printf("%c", massive[i][ii]);
			}
			printf("\n");
		}

	}

	return 0;
}
