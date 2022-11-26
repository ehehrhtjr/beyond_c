//hanoi
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count = 0;

void move(int no, int x, int y) {
    if (no > 1) {
        move(no-1,x ,6-x-y );
        count++;
        move(no-1,6-x-y,y);
        count++;
    }
}

int main() {
    int n;
    printf("하노이 탑 개수 : ");
    scanf("%d", &n);
    move(n, 1, 3);
    count++;
    printf("%d", count);
}
