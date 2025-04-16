#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Week { SUN, MON, TUE, WED, THU, FRI, SAT };
enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int LeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(enum Month month, int year) {
    switch (month) {
        case APR: case JUN: case SEP: case NOV: return 30;
        case FEB: return LeapYear(year) ? 29 : 28;
        default: return 31;
    }
}

void printCalendar(int year, enum Month month) {
    int days = daysInMonth(month, year);
    int startDay;

    int totalDays = 0;
    for (int y = 2025; y < year; y++) {
        totalDays += LeapYear(y) ? 366 : 365;
    }
    for (enum Month m = JAN; m < month; m++) {
        totalDays += daysInMonth(m, year);
    }

    startDay = (3 + totalDays) % 7;

    printf("\n\n          %d월\n", month);
    printf("===========================\n");
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

void Calendar() {
    int year_input;
    int month_input;

    printf("연도를 입력하세요: ");
    if (scanf("%d", &year_input) != 1 || year_input < 0) {
        printf("잘못된 연도 입력입니다.\n");
        while (getchar() != '\n');
        return;
    }

    printf("월을 입력하세요: ");
    if (scanf("%d", &month_input) != 1 || month_input < 1 || month_input > 12) {
        printf("잘못된 월 입력입니다.\n");
        while (getchar() != '\n');
        return;
    }

    printCalendar(year_input, (enum Month)month_input);
}

void CalendarWithDDay() {
    long long dateDifference(int year1, int month1, int day1, int year2, int month2, int day2) {
        struct tm t1 = {0, 0, 0, day1, month1 - 1, year1 - 1900};
        struct tm t2 = {0, 0, 0, day2, month2 - 1, year2 - 1900};

        time_t time1 = mktime(&t1);
        time_t time2 = mktime(&t2);

        if (time1 == -1 || time2 == -1) {
            return -1;
        }

        double diff_seconds = difftime(time2, time1);
        return (long long)(diff_seconds / (60 * 60 * 24));
    }

    int dday_input;
    int dday_year, dday_month, dday_day;

    printf("\n\nD-day를 계산할 날짜를 YYYYMMDD 형식으로 입력하세요: ");
    if (scanf("%d", &dday_input) == 1) {
        if (dday_input >= 20250101 && dday_input <= 21001231) {
            dday_year = dday_input / 10000;
            dday_month = (dday_input % 10000) / 100;
            dday_day = dday_input % 100;

            if (dday_month >= 1 && dday_month <= 12 && dday_day >= 1 && dday_day <= daysInMonth((enum Month)dday_month, dday_year)) {
                time_t now;
                struct tm *now_tm;

                time(&now);
                now_tm = localtime(&now);

                long long days_left = dateDifference(now_tm->tm_year + 1900, now_tm->tm_mon + 1, now_tm->tm_mday, dday_year, dday_month, dday_day);

                if (days_left >= 0) {
                    printf("D-%lld일 남았습니다.\n", days_left);
                } else if (days_left < 0) {
                    printf("D+%lld일 지났습니다.\n", -days_left);
                } else {
                    printf("날짜 계산에 오류가 발생했습니다.\n");
                }
            } else {
                printf("잘못된 날짜 입력입니다.\n");
            }
        } else {
            printf("YYYYMMDD 형식으로 입력해주세요.\n");
        }
    } else {
        printf("D-day 입력 오류가 발생했습니다.\n");
        while (getchar() != '\n');
    }
}

int main() {
    Calendar();
    CalendarWithDDay();

    return 0;
}
