/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

int main() {
    int m;
    int n;
    
    printf("정수 M을 입력하시오: ");
    scanf("%d", &m);
    
    printf("정수 N을 입력하시오: ");
    scanf("%d", &n);
    
    for (int i = m; i <= n; i++) {
        if (i % 7 == 0 || (i / 10 == 7 || i % 10 == 7)) {
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
