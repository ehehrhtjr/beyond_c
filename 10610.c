#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void sort(int* arr, int size) {
	int i, j, temp;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {		
				if (arr[i] < arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
}

int count(char* in) {
	int cnt = 0;
	while (in[cnt] != '\0') {
		cnt++;
	}
	return cnt;
}
int check(int* arr, int cnt) {
	int	state = 0, result=0 , i, s = 0;
	
	for (i = 0; i < cnt; i++) {
		s += arr[i];
		if (arr[i] == 0) {
			state = 1;
		}
	}
	if (state == 1) {
		if(s % 3 == 0){
			result = 1;
		}
	}
	return result;
}
int main() {
	char* in = malloc(sizeof(char) * 100000);
	char state=0;
	int number,cnt,i;
	
	scanf("%s",in);

	cnt = count(in);
	int* arr = (int*)malloc(sizeof(int) * cnt);

	for (i = 0; i < cnt; i++) {
		arr[i] = in[i] - 48;
	}

	if (check(arr,cnt)==1){
		sort(arr,cnt);
		for (i = 0; i < cnt;i++) {
			printf("%d", arr[i]);
		}
	}
	else {
		printf("-1");
	}
}
