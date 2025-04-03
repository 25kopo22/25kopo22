/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_COUNT 6  // 뽑을 로또 번호 개수
#define MAX_NUM 45      // 로또 번호 최대값

int main()
{
    int numbers[LOTTO_COUNT] = {0}; //로또 번호를 저장할 배열
    int used[MAX_NUM + 1] = {0}; //사용된 숫자를 체크하는 배열
    srand(time(NULL)); //난수 생성을 위한 시드 설정
    
    //중복 없이 6개의 난수를 생성
    for (int i = 0; i < LOTTO_COUNT; ) {
        int num = (rand() % MAX_NUM) + 1; //1~45 사이의 난수 생성
        if (!used[num]) { //중복이 없을 경우에만 배열에 추가
            numbers[i++] = num;
            used[num] = 1; //해당 숫자 사용 표시
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
    
    //정렬된 로또 번호 출력
    for (int i = 0; i < LOTTO_COUNT; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}