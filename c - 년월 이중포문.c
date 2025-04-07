#include <stdio.h>

int main() {
    for (int year = 2020; year <= 2025; year++) {
        for (int month = 1; month <= 12; month++) {
            if (year == 2025 && month > 4) break;
            if (year == 2023 && month >= 2 && month <= 5) continue;
                printf("%04d%02d\n", year, month);
        }
    }
    return 0;
}

   
