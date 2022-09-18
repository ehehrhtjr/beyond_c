#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int L, C;
char password[15];
char ans[15];
int visited[15];



void dfs(int depth, int start) {
	if (depth == L) {
		for (int i = 0; i < depth; i++) {
			printf("%c", ans[i]);
		}
		printf("\n");
		return;
	}


	for (int i = start; i < C; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			ans[depth] = password[i];
			dfs(depth + 1, i + 1);
			printf("%d",i);
			visited[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &password[i]);
	}
	dfs(0, 0);

	return 0;
}
