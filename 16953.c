#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	int A, B, count=1;
	
	scanf("%d %d", &A, &B);
	while (1) {
		if (A == B) {
			break;
		}
		else if (B % 10 == 1) {
			B = B / 10;
			count++;
		}
		else if (B % 2 == 0) {
			B = B / 2;
			count++;
		}
		else {
			count = -1;
			break;
		}

		if (A>B){
			count = -1;
			break;
		}
	}

	printf("%d", count);

}
