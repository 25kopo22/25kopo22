#include <stdio.h>

int seven(int num) {
    while (num > 0) {
        if (num % 10 == 7) {
            return 1; 
        }
        num /= 10;
    }
    return 0; 
}

int main() {
    int m, n;
    
    printf("정수 M을 입력하시오: ");
    scanf("%d", &m);
    
    printf("정수 N을 입력하시오: ");
    scanf("%d", &n);
    
    for (int i = m; i <= n; i++) {
        if (i % 7 == 0 || seven(i)) {
            continue;
        } else if (i % 5 == 0) {
            printf("%d\n", i);
            break;
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}
