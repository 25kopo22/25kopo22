#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_COUNT 6  // 뽑을 로또 번호 개수
#define MAX_NUM 45      // 로또 번호 최대값

int main()
{
    int numbers[LOTTO_COUNT] = {0}; 
    int used[MAX_NUM + 1] = {0}; 
    srand(time(NULL));
    
    for (int i = 0; i < LOTTO_COUNT; ) {
        int num = (rand() % MAX_NUM) + 1; 
        if (!used[num]) { //중복이 없을 경우에만 배열에 추가
            numbers[i++] = num;
            used[num] = 1;
        }
    }
    
    //버블 정렬
    for (int i = 0; i < LOTTO_COUNT - 1; i++) {
        for (int j = i + 1; j < LOTTO_COUNT; j++) {
            if (numbers[i] > numbers[j]) { //앞 숫자가 크면 교환
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < LOTTO_COUNT; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
