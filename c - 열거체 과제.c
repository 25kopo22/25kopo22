/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

enum CarType {SEDAN, SUV, TRUCK, VAN};

int main() {
    enum CarType selectedCar;
    int choice;

    printf("자동차 종류를 선택하세요:\n");
    printf("0. SEDAN\n");
    printf("1. SUV\n");
    printf("2. TRUCK\n");
    printf("3. VAN\n");
    printf("선택: ");
    scanf("%d", &choice);

    switch (choice) {
        case 0:
            selectedCar = SEDAN;
            break;
        case 1:
            selectedCar = SUV;
            break;
        case 2:
            selectedCar = TRUCK;
            break;
        case 3:
            selectedCar = VAN;
            break;
        default:
            printf("잘못된 선택입니다.\n");
            return 1;
    }

    printf("선택하신 자동차 종류는: ");
    switch (selectedCar) {
        case SEDAN:
            printf("SEDAN\n");
            break;
        case SUV:
            printf("SUV\n");
            break;
        case TRUCK:
            printf("TRUCK\n");
            break;
        case VAN:
            printf("VAN\n");
            break;
    }

    return 0;
}