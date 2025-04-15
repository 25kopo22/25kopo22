#include <stdio.h>

union Data {
    int intVal;
    float floatVal;
    char charVal;
};

int main() {
    union Data myData;
    int intInput;
    float floatInput;
    char charInput;
    int choice;

    printf("정수 값을 입력하세요: ");
    scanf("%d", &intInput);

    printf("실수 값을 입력하세요: ");
    scanf("%f", &floatInput);

    printf("문자 값을 입력하세요: ");
    scanf(" %c", &charInput); 

    printf("\n저장할 데이터 타입을 선택하세요 (1: int, 2: float, 3: char): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            myData.intVal = intInput;
            printf("선택된 타입: 정수\n");
            printf("저장된 정수 값: %d\n", myData.intVal);
            printf("정수 값의 주소: %p\n", &myData.intVal);
            break;
        case 2:
            myData.floatVal = floatInput;
            printf("선택된 타입: 실수\n");
            printf("저장된 실수 값: %f\n", myData.floatVal);
            printf("실수 값의 주소: %p\n", &myData.floatVal);
            break;
        case 3:
            myData.charVal = charInput;
            printf("선택된 타입: 문자\n");
            printf("저장된 문자 값: %c\n", myData.charVal);
            printf("문자 값의 주소: %p\n", &myData.charVal);
            break;
        default:
            printf("잘못된 선택입니다.\n");
            return 1;
    }

    printf("\n--- 값 및 주소 확인 ---\n");
    printf("공용체 전체 주소: %p\n", &myData);
    printf("정수 멤버 주소: %p (값: %d)\n", &myData.intVal, myData.intVal);
    printf("실수 멤버 주소: %p (값: %f)\n", &myData.floatVal, myData.floatVal);
    printf("문자 멤버 주소: %p (값: %c)\n", &myData.charVal, myData.charVal);

    return 0;
}
