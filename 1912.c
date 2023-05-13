#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;

	int  d[100000];
	int m;
	int arr[100000];


	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	m = -1001;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			d[i] = arr[i];
		}
		else {
			d[i] = d[i - 1] < 0 ? arr[i] : d[i - 1] + arr[i];
		}
		if (m < d[i]) {
			m = d[i];
		}
	}
	printf("%d", m);
}
