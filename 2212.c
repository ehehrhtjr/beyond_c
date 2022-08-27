#define _CRT_SECURE_NO_WARNINGS
#define __STDC_NO_VLA__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환

    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환

    return 0;    // a와 b가 같을 때는 0 반환
}


int main() {
    int i, N, K;

    scanf("%d", &N);
    scanf("%d", &K);
    int* P = malloc(sizeof(int) * N);
    int* dis = malloc(sizeof(int) * (N - 1));
    int result = 0;

    for (i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }
    qsort(P, N, sizeof(int),compare);

    for (i = 0; i < N - 1; i++) {
        dis[i] = P[i + 1] - P[i];
    }
    qsort(dis, N-1, sizeof(int), compare);

    for (i = 0; i < N -K; i++) {
        result += dis[i];
    }
    printf("%d", result);
}

