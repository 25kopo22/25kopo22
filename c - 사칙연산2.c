#include <stdio.h>

int main() {
    int num, sum = 0;
    
    printf("세 자리 정수를 입력하세요: ");
    if (scanf("%d", &num) != 1 || num < 100 || num > 999) {
        printf("올바른 세 자리 정수를 입력하세요.\n");
        return 1;
    }
    
    sum += num / 100;        
    sum += (num / 10) % 10;  
    sum += num % 10;         
    
    printf("각 자리 숫자의 합: %d\n", sum);
    
    return 0;
}
