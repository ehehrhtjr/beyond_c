#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	unsigned int temp=1;
	unsigned int n = 1;
	unsigned int S;

	scanf("%d", &S);

	while (temp < S) {
		n++;
		temp = (n * (n + 1)) / 2;
		
	}

	printf("%d", n-1);
}
