/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void main()
{
  int a;
  
  printf("0 ~ 9 사이의 숫자를 입력해주세요: ");
  scanf("%d", &a);
  
  switch (a)
  {
    case 0:
        printf("A");
        break;
        
    case 1:
        printf("B");
        break;
        
    case 2:
        printf("C");
        break;
        
    case 3:
        printf("D");
        break;
        
    case 4:
        printf("E");
        break;
        
    case 5:
        printf("F");
        break;
        
    case 6:
        printf("G");
        break;
    
    case 7:
        printf("H");
        break;
    
    case 8:
        printf("I");
        break;
    
    case 9:
        printf("J");
        break;
    
    default:
        printf("잘못된 입력입니다!");
  }

}