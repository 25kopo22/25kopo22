#include <stdio.h>

int main()
{
    float temp;
    int range;

    printf("온도를 입력하세요: ");
    scanf("%f", &temp);
    
     if (temp < -50 || temp > 50) {
        printf("측정할 수 없는 온도입니다!\n");
        return 1;
    }

    if (temp >= 0) {
        range = (int)(temp / 5);
    } else {
        range = -1; 
    }
        
    switch (range)
    {
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            printf("너무 더워요! 반팔과 반바지를 입으세요.\n");
            break;

        case 5: 
            printf("따뜻한 날씨입니다! 가벼운 옷을 입으세요.\n");
            break;

        case 3:
        case 4: 
            printf("선선한 날씨입니다! 가벼운 겉옷을 챙기세요.\n");
            break;

        case 1:
        case 2: 
            printf("조금 쌀쌀합니다! 따뜻한 옷을 입으세요.\n");
            break;

        case 0: 
            printf("매우 춥습니다! 두꺼운 외투를 꼭 입으세요.\n");
            break;

        default: 
            printf("한파 경고! 패딩과 장갑, 모자를 착용하세요.\n");
            break;
    }
    
    return 0;
}
