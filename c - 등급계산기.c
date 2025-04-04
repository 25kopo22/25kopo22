/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int a;
    float bonus = 0;

    printf("점수를 입력해주세요: ");
    scanf("%d", &a);

    if (a < 0 || a > 100) {
        printf("잘못된 입력입니다. 점수는 0부터 100 사이여야 합니다.\n");
    } else {
        switch (a / 10)
        {
            case 10: // 100점도 A 등급
            case 9:
                printf("A 등급\n");
                bonus = a * 0.10;  // 10% 보너스
                break;
            case 8:
                printf("B 등급\n");
                bonus = a * 0.05;  // 5% 보너스
                break;
            case 7:
                printf("C 등급\n");
                break;
            case 6:
                printf("D 등급\n");
                break;
            default:
                printf("F 등급\n");
                break;
        }

        if (bonus > 0) {
            printf("보너스 점수: %.2f\n", bonus);
            printf("최종 점수: %.2f\n", a + bonus);
        }
    }

    return 0;
}
