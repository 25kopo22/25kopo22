#include <stdio.h>

void main() {
    int i = 1;
    while (i <= 5) {
        printf("%d ", i);
        i = i + 1;
    }
    
    printf("\n");
    
    int j = 1;
    while (j <= 10) {
        if (j % 2 == 0) {
            printf("%d ", j);
        }
        j = j + 1;
    }
}
