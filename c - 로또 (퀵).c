#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_COUNT 6
#define MAX_NUM 45

void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[left]; // 기준값
    int i = left + 1;
    int j = right;
    int temp;

    while (i <= j) {
        while (i <= right && arr[i] <= pivot) i++;
        while (j > left && arr[j] >= pivot) j--;
        if (i > j) {
            // pivot과 작은 값 교환
            temp = arr[left];
            arr[left] = arr[j];
            arr[j] = temp;
        } else {
            // 큰 값과 작은 값 교환
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

int main() {
    int numbers[LOTTO_COUNT] = {0};
    int used[MAX_NUM + 1] = {0};
    srand(time(NULL));

    for (int i = 0; i < LOTTO_COUNT; ) {
        int num = (rand() % MAX_NUM) + 1;
        if (!used[num]) {
            numbers[i++] = num;
            used[num] = 1;
        }
    }

    quick_sort(numbers, 0, LOTTO_COUNT - 1);

    printf("로또 번호: ");
    for (int i = 0; i < LOTTO_COUNT; i++) {
        printf("%d ", numbers[i]);
    }
    
    return 0;
}
