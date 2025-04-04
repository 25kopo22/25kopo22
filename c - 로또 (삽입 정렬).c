/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_COUNT 6
#define MAX_NUM 45

int main()
{
    int numbers[LOTTO_COUNT] = {0};
    int used[MAX_NUM + 1] = {0};
    srand(time(NULL));

    // 중복 없이 로또 번호 생성
    for (int i = 0; i < LOTTO_COUNT; ) {
        int num = (rand() % MAX_NUM) + 1;
        if (!used[num]) {
            numbers[i++] = num;
            used[num] = 1;
        }
    }

    // 삽입 정렬
    for (int i = 1; i < LOTTO_COUNT; i++) {
        int key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j--;
        }

        numbers[j + 1] = key; 
    }

    printf("로또 번호: ");
    for (int i = 0; i < LOTTO_COUNT; i++) {
        printf("%d ", numbers[i]);
    }
    
    return 0;
}
