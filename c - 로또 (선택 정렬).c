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

    // 선택 정렬
    for (int i = 0; i < LOTTO_COUNT - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < LOTTO_COUNT; j++) {
            if (numbers[j] < numbers[min_index]) {
                min_index = j;
            }
        }
        // swap
        int temp = numbers[i];
        numbers[i] = numbers[min_index];
        numbers[min_index] = temp;
    }

    printf("로또 번호: ");
    for (int i = 0; i < LOTTO_COUNT; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}

