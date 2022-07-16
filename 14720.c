#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	int count = 0, state = 0, n, i;
	
	scanf("%d", &n);

	int *store= (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &store[i]);
	}

	for (i = 0; i < n; i++) {
		if (state == store[i]) {
			count++;
			state = (state + 1) % 3;
		}
	}

	printf("%d", count);

}
