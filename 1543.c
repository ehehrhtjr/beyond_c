#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int count(char str[]) {
	int count=0;
	
	while (1) {
		if (str[count] == '\0') {
			break;
		}
		else {
			count++;
		}
	}

	return count;
}

int main() {
	int i, j, do_size, wd_size, cnt=0;
	char str[2501],word[51],state=0;
	
	scanf("%[^\n]", str);
	do_size=count(str);
	scanf(" %[^\n]", word);
	wd_size = count(word);
	
	for (i = 0; i < do_size; i++) {
		for (j = 0; j < wd_size; j++) {
			if (str[i + j] != word[j]) {
				state = 1;
				break;
			}
		}
		if (state == 0) {
			cnt++;
			i += j-1;
		}
		state = 0;
	}
	printf("%d", cnt);
}
