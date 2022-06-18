#define _CRT_SECURE_NO_WARNINGS
#define __STDC_NO_VLA__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void sort(int* arr,int size,int a_d) {
	int i, j,temp;
	for (i = 0; i < size-1; i++) {
		for (j = i + 1; j < size; j++) {
			if (a_d == 0) {
				if (arr[i] > arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
			else {
				if (arr[i] < arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}

int main() {

	int i,size,result=0;
	scanf("%d", &size);
	int* arr1 = (int*)malloc(sizeof(int) * size);
	int* arr2 = (int*)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) {
		scanf("%d", &arr1[i]);
	}
	for (i = 0; i < size; i++) {
		scanf("%d", &arr2[i]);
	}

	sort(arr1, size, 0);
	sort(arr2, size, 1);

	for (i = 0; i < size; i++) {
		result += arr1[i] * arr2[i];
	}
	printf("%d", result);
}

