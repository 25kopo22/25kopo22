/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

int main() {
    for (int year = 2020; year <= 2025; year++) {
        for (int month = 1; month <= 12; month++) {
            if (year == 2025 && month > 4) break;
                printf("%04d%02d\n", year, month);
        }
    }
    return 0;
}

   
