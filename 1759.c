#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int L, C;
char password[18];
char ans[18];
int visited[18];
char v[5] = { 'a','e','i','o','u' };

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	char num1 = *(char*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	char num2 = *(char*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환
	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환
	return 0;    // a와 b가 같을 때는 0 반환
}

void dfs(int depth, int start) {
	if (depth == L) {
		int v_count = 0;
		int c_count = 0;
		for (int i = 0; i < depth; i++) {
			for (int j = 0; j < 5; j++) {
				if (ans[i] == v[j]) {
					v_count++;
					break;
				}
			}
		}
		c_count = depth - v_count;
		
		if (c_count >= 2 && v_count>=1) {
			for (int i = 0; i < depth; i++) {
				printf("%c", ans[i]);
			}
			printf("\n");
			return;
		}
	}


	for (int i = start; i < C; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			ans[depth] = password[i];
			dfs(depth + 1, i + 1);

			visited[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &password[i]);
	}
	qsort(password, C, sizeof(char), compare);
	
	dfs(0, 0);

	return 0;
}
