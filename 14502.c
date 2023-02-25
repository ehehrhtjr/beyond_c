/* int형 스택 IntQueue (소스) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;      /* 스택 용량 */
    int num;
    int front;      /* 스택 포인터 */
    int rear;
    int* que;      /* 스택의 첫 요소에 대한 포인터 */
} IntQueue;

/*--- 스택 초기화 ---*/
int Initialize(IntQueue* q, int max)
{
    q->front = 0;
    q->rear = 0;

    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;                        /* 배열의 생성에 실패 */
        return -1;
    }

    q->num = 0;
    q->max = max;
    return 0;
}

/*--- 스택에 데이터를 푸시---*/
int Push(IntQueue* q, int x)
{
    if (q->num >= q->max)                  /* 스택이 가득 참 */
        return -1;
    q->que[q->front] = x;
    q->num++;
    q->front = (q->front == 0) ? q->max - 1 : q->front - 1;
    return 0;
}

/*--- 스택에서 데이터를 팝 ---*/
int Pop(IntQueue* q, int* x)
{
    if (q->num <= 0)                     /* 스택이 비어 있음 */
        return -1;
    *x = q->que[q->rear];
    q->num--;
    q->rear = (q->rear == 0) ? q->max - 1 : q->rear - 1;
    return 0;
}

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntQueue* q, int* x)
{
    if (q->num <= 0)                     /* 스택이 비어 있음 */
        return -1;
    *x = q->que[q->rear];
    return 0;
}

/*--- 스택 비우기 ---*/
void Clear(IntQueue* q)
{
    q->num = 0;
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

    for (i = q->rear; i != q->front; i = (i == 0) ? q->max - 1 : i - 1)   /* 꼭대기(top) → 바닥(bottom)으로 선형 검색 */
        if (q->que[i] == x)
            return i;      /* 검색 성공 */
    return -1;            /* 검색 실패 */
}

/*--- 모든 데이터 표시 ---*/
void Print(const IntQueue* q)
{
    int i;

    for (i = q->front; i != q->rear; i = (i == q->max - 1) ? 0 : i + 1)      /* 바닥(bottom) → 꼭대기(top)로 스캔 */
        printf("%d ", q->que[i]);
    printf("%d", q->que[i]);
    putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntQueue* q)
{
    if (q->que != NULL)
        free(q->que);      /* 배열을 삭제 */
    q->max = q->num = q->front = q->rear = 0;
}

int bfs(int M, int N, int temp[8][8], IntQueue* q) {
    int x, y, i, j, k;
    int count = 0;
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    while (1) {

        if (Pop(q, &y) == -1) {
            for (j = 0; j < N; j++) {
                for (k = 0; k < M; k++) {
                    if (temp[j][k] == 0) {
                        count++;
                    }
                }
            }
            return count;
        }
        else {
            Pop(q, &x);
        }
        for (i = 0; i < 4; i++) {
            if (x + dx[i] >= 0 && x + dx[i] < M && y + dy[i] >= 0 && y + dy[i] < N) {
                if (temp[y + dy[i]][x + dx[i]] ==0) {
                    Push(q, y + dy[i]);
                    Push(q, x + dx[i]);
                    temp[y + dy[i]][x + dx[i]] =2;
                }
            }
        }
    }
}

void copy(IntQueue *q, int temp[8][8], int map[8][8],int N,int M) {
    Clear(q);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp[i][j] = map[i][j];
            if (map[i][j] == 2) {
                Push(q, i);
                Push(q, j);
            }
        }
    }
}

int main(void)
{
    IntQueue q;

    if (Initialize(&q, 10000) == -1) {
        puts("큐 생성에 실패하였습니다.");
        return 1;
    }
    int max = -1;
    int count;
    int N, M;
    int i, j,k;
    int map[8][8];
    int temp[8][8];
    scanf("%d %d", &N, & M);

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            
        }
    }
    for (i = 0; i < N * M; i++) {
        for (j = i + 1; j < N * M; j++) {
            for (k = j + 1; k < N * M; k++) {
                copy(&q, temp, map,N,M);
                if ((temp[i / M][i % M] == 0) && (temp[j / M][j % M] == 0) && (temp[k / M][k % M] == 0)) {
                    temp[i / M][i % M] = 1;
                    temp[j / M][j % M] = 1;
                    temp[k / M][k % M] = 1;  
                }
                else {
                    continue;
                }
                
                
                
                count=bfs(M, N, temp, &q);
                
                if (max < count) {
                    max = count;
                }
            }
        }
    }
    printf("%d", max);
}
