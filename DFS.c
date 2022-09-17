#include <stdio.h>;

int graph[11][11];// 인접행렬로 구현한 그래프 
int visited[11];        // 방문 여부 체크 

int DFS(int cur, int n) {
	int i;
	visited[cur] = 1;    // 현재 노드 방문 체크 
	for (i = 1; i <= n; i++) {    // 모든 인접한 노드 체크 
		if (graph[cur][i] == 1 && visited[i] == 0) {    // 인접하고 방문하지 않은 노드라면 
			printf("%c ", 64+i);
			DFS(i, n);
		}
	}
}

int main()
{
	int start  = 1;
	graph[1][2] = 1; graph[2][3] = 1; graph[3][4] = 1; graph[4][5] = 1;
	graph[2][6] = 1;

	printf("%c ", 64+start);
	DFS(start, 10);

	return 0;
}

