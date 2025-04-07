#include <stdio.h>

int main() {
    int a, b, c, result;
    
    printf("정수 세 개를 입력하세요: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("정수 세 개를 정확히 입력하세요.\n");
        return 1;
    }
    
    if (c == 0) {
        printf("0으로 나눌 수 없습니다.\n");
        return 1;
    }
    
    result = (a + b) * c - (a - b) / c;
    
    printf("결과: %d\n", result);
    
    return 0;
}
