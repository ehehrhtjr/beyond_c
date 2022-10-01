#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int M, N;
int ans[8];
int visited[8];



void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < depth; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}

	 
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			ans[depth] =i+1;
			dfs(depth + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	dfs(0);

	return 0;
}
