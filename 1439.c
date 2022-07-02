#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int count(char* in) {
	int cnt = 0;
	while (in[cnt] != '\0') {
		cnt++;
	}
	return cnt;
}

int main() {
	int cnt, i,one=0,zero=0,result;
	char* in = malloc(sizeof(char) * 1000001);
	
	scanf("%s", in);
	cnt = count(in);

	for (i = 0; i < cnt; i++) {
		if (in[i] != in[i + 1]) {
			if (in[i] == '0') {
				zero++;
			}
			else if (in[i] == '1') {
				one++;
			}
		}
	}
	result = zero > one ? one : zero;
	printf("%d", result);
	
}
