#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	int T, D,i;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		int k, j, res = 0, n,state;
		long long bene = 0;
		scanf("%d", &n);
		int* price = malloc(sizeof(int) * n);
		
		for (j = 0; j < n; j++) {
			scanf("%d", &price[j]);
		}

		for (j = 0; j < n-1; j++) {
			state = 0;
			for (k = j + 1; k < n; k++) {
				if (price[j] < price[k]) {
					res++;
					bene -= price[j];
					state = 1;
					break;
				}
			}
			if (state == 0) {
				bene += price[j] * res;
				res = 0;
			}
		}
		bene += price[j] * res;

		printf("%lld\n", bene);
	}

}
