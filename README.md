# beyond_c

#define _CRT_SECURE_NO_WARNINGS
#define __STDC_NO_VLA__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int check(char m[8][8]) {
	int count_b = 0, count_w = 0,i,j;
	
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (m[i][j] == 'B') {
						count_w++;
					}
					else {
						count_b++;
					}
				}
				else {
					if (m[i][j] == 'W') {
						count_w++;
					}
					else {
						count_b++;
					}
				}
			}
			else {
				if (j % 2 == 0) {
					if (m[i][j] == 'W') {
						count_w++;
					}
					else {
						count_b++;
					}
				}
				else {
					if (m[i][j] == 'B') {
						count_w++;
					}
					else {
						count_b++;
					}
				}
			}
			
		}
	}
	return count_w < count_b ? count_w : count_b;
}
int main(){
	int t,tt,m_temp,i, j,k,l, N, M,temp_i=0,temp_j=0, mi = 3000;
	char arr[51][51];
	char temp[8][8];
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (i = 0; i < N - 7; i++) {
		for (j = 0; j < M - 7; j++) {
			for (k = i; k < i + 8; k++) {
				for (l = j; l < j + 8; l++) {
					temp[temp_i][temp_j] = arr[k][l];
					temp_j++;
				}
				temp_i++;
				temp_j = 0;
			}
			temp_i = 0;
			
			m_temp = check(temp);
			if (mi > m_temp) {
				mi = m_temp;
			}
				
		}
	}
	printf("%d", mi);
}

