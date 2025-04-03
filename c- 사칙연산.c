#include <stdio.h>

int main() {
    int a, b, c, result;
    
    // 사용자 입력 받기
    printf("정수 세 개를 입력하세요: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("정수 세 개를 정확히 입력하세요.\n");
        return 1;
    }
    
    // 0으로 나누는 경우 예외 처리
    if (c == 0) {
        printf("0으로 나눌 수 없습니다.\n");
        return 1;
    }
    
    // 연산 수행
    result = (a + b) * c - (a - b) / c;
    
    // 결과 출력
    printf("결과: %d\n", result);
    
    return 0;
}
