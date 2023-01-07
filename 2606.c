/* int형 스택 IntQueue (소스) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int max;		/* 스택 용량 */
	int num;
	int front;		/* 스택 포인터 */
	int rear;
	int* que;		/* 스택의 첫 요소에 대한 포인터 */
} IntQueue;

/*--- 스택 초기화 ---*/
int Initialize(IntQueue* q, int max)
{
	q-> front= 0;
	q->rear = 0;

	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;								/* 배열의 생성에 실패 */
		return -1;
	}

	q->num = 0;
	q->max = max;
	return 0;
}

/*--- 스택에 데이터를 푸시---*/
int Push(IntQueue* q, int x)
{
	if (q->num >= q->max)						/* 스택이 가득 참 */
		return -1;
	q->que[q->front] = x;
	q->num++;
	q->front = (q->front == 0) ? q->max - 1 : q->front - 1;
	return 0;
}

/*--- 스택에서 데이터를 팝 ---*/
int Pop(IntQueue* q, int* x)
{
	if (q->num <= 0)							/* 스택이 비어 있음 */
		return -1;
	*x = q->que[q->rear];
	q->num--;
	q->rear = (q->rear == 0) ? q->max - 1 : q->rear - 1;
	return 0;
}

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntQueue* q, int* x)
{
	if (q->num <= 0)							/* 스택이 비어 있음 */
		return -1;
	*x = q->que[q->rear];
	return 0;
}

/*--- 스택 비우기 ---*/
void Clear(IntQueue* q)
{
	q->front = 0;
	q->rear = 0;
}

/*--- 스택 용량 ---*/
int Capacity(const IntQueue* q)
{
	return q->max;
}

/*--- 스택에 쌓여 있는 데이터 수 ---*/
int Size(const IntQueue* q)
{
	return q->num;
}

/*--- 스택이 비어 있는가? ---*/
int IsEmpty(const IntQueue* q)
{
	return q->num <= 0;
}

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntQueue* q)
{
	return q->num >= q->max;
}

/*--- 스택에서 검색 ---*/
int Search(const IntQueue* q, int x)
{
	int i;

	for (i = q->rear; i != q->front; i=(i==0)?q->max-1:i-1)	/* 꼭대기(top) → 바닥(bottom)으로 선형 검색 */
		if (q->que[i] == x)
			return i;		/* 검색 성공 */
	return -1;				/* 검색 실패 */
}

/*--- 모든 데이터 표시 ---*/
void Print(const IntQueue* q)
{
	int i;

	for (i = q->front; i != q->rear; i = (i == q->max-1) ? 0 : i + 1)		/* 바닥(bottom) → 꼭대기(top)로 스캔 */
		printf("%d ", q->que[i]);
	printf("%d", q->que[i]);
	putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntQueue* q)
{
	if (q->que != NULL)
		free(q->que);		/* 배열을 삭제 */
	q->max = q->num =q->front=q->rear=0;
}

int main(void)
{
	int computer;
	int connection;
	
	int adj_mat[101][101] = { 0 };
	int visited_mat[101] = { 0 };
	int temp_s, temp_t;
	IntQueue q;

	if (Initialize(&q, 10000) == -1) {
		puts("큐 생성에 실패하였습니다.");
		return 1;
	}
	scanf("%d", &computer);
	scanf("%d", &connection);
	for (int i = 0; i < connection; i++) {
		scanf("%d %d", &temp_s, &temp_t);
		adj_mat[temp_s][temp_t] = 1;
		adj_mat[temp_t][temp_s] = 1;

	}
	int start = 1;
	int count = 0;
	visited_mat[1] = 1;

	while (1) {
		for (int i = 0; i <= computer; i++) {
			if ((adj_mat[start][i] ==1)&&(visited_mat[i]==0)) {
				Push(&q, i);
				visited_mat[i]= 1;
			}
		}
		if (Pop(&q, &start) == -1) {
			break;
		}
		else{
			count++;
		}
	}

	printf("%d", count);
	Terminate(&q);
	

	return 0;
}
