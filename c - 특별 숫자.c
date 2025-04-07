#include <stdio.h>

int sumdigit(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num;
    
    printf("0부터 999 사이의 숫자를 입력하세요: ");
    if (scanf("%d", &num) != 1 || num < 0 || num > 999) {
        printf("올바른 숫자를 입력하세요.\n");
        return 1;
    }
    
    int first = num;
    while (first >= 10) {
        first /= 10;
    }
    int last = num % 10;
    
    if ((num % 3 == 0 && num % 2 == 1) ||  // 3의 배수이면서 홀수
        (sumdigit(num) % 7 == 0) ||    // 각 자리 숫자의 합이 7의 배수
        (first > last)) {       // 첫 번째 자리 숫자가 마지막 자리 숫자보다 큼
        printf("%d는 특별한 숫자입니다.\n", num);
    } else {
        printf("%d는 특별한 숫자가 아닙니다.\n", num);
    }
    
    return 0;
}
