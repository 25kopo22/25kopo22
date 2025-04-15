/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

enum Week { SUN, MON, TUE, WED, THU, FRI, SAT };
enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int LeapYear(int year) {
    return (year % 4 == 0);
}

int Days_Month(enum Month month, int year) {
    switch (month) {
        case APR: case JUN: case SEP: case NOV: return 30;
        case FEB: return LeapYear(year) ? 29 : 28;
        default: return 31;
    }
}

void printCalendar(int year, enum Month month) {
    int days = Days_Month(month, year);
    int startDay;

    int totalDays = 0;
    for (int y = 2025; y < year; y++) {
        totalDays += LeapYear(y) ? 366 : 365;
    }
    for (enum Month m = JAN; m < month; m++) {
        totalDays += Days_Month(m, year);
    }

    startDay = (3 + totalDays) % 7;

    printf("\n\n          %d월\n", month);
    printf("==========================\n");
    printf("일  월  화  수  목  금  토\n");

    for (int i = 0; i < startDay; i++) {
        printf("    ");
    }

    for (int d = 1; d <= days; d++) {
        printf("%2d  ", d);
        startDay++;
        if (startDay == 7) {
            printf("\n");
            startDay = 0;
        }
    }
    printf("\n");
}

void calendar() {
    int year_input;
    int month_input;

    printf("연도를 입력하세요: ");
    scanf("%d", &year_input);
    
    if (year_input < 0) {
        printf("잘못된 연도 입력입니다.\n");
        return;
    }
    
    printf("월을 입력하세요 (1-12): ");
    scanf("%d", &month_input);

    if (month_input < 1 || month_input > 12) {
        printf("잘못된 월 입력입니다.\n");
        return;
    }

    printCalendar(year_input, (enum Month)month_input);
}

int main() {
    calendar();
    return 0;
}