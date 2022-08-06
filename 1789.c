#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	float n;
	float S;

	scanf("%f", &S);

	n = (-1 + sqrt(1 + 4 * S *2)) / 2;
	n = floor(n);
	printf("%d",(int)n);
}
