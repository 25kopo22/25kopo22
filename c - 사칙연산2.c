#include <stdio.h>

int main() {
    int num, sum = 0;
    
    // 사용자 입력 받기
    printf("세 자리 정수를 입력하세요: ");
    if (scanf("%d", &num) != 1 || num < 100 || num > 999) {
        printf("올바른 세 자리 정수를 입력하세요.\n");
        return 1;
    }
    
    // 각 자리 숫자 합 계산
    sum += num / 100;        // 백의 자리
    sum += (num / 10) % 10;  // 십의 자리
    sum += num % 10;         // 일의 자리
    
    // 결과 출력
    printf("각 자리 숫자의 합: %d\n", sum);
    
    return 0;
}
