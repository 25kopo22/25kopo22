#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

struct group {
    char name[20];
    int age;
    char sex;
    char hobby[30];
};

void printMembers(struct group *p, int count) {
    printf("\n현재까지 입력된 사용자 정보:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s %d %c %s\n",
            i + 1, (p + i)->name, (p + i)->age, (p + i)->sex, (p + i)->hobby);
    }
}

void inputMembers(struct group *p, int *count) {
    int add;
    char tempSex[10];

    printf("몇 명의 추가 사용자 정보를 입력하시겠습니까? ");
    scanf("%d", &add);

    for (int i = 0; i < add; i++) {
        printf("\n[%d번째 사용자]\n", *count + 1);

        printf("이름: ");
        scanf("%s", (p + *count)->name);

        while (TRUE) {
            printf("나이: ");
            scanf("%d", &(p + *count)->age);
            if ((p + *count)->age > 0 && (p + *count)->age <= 150) break;
            printf("잘못된 나이입니다. 다시 입력해주세요.\n");
        }

        while (TRUE) {
            printf("성별 (M/F): ");
            scanf("%s", tempSex);
            if (strlen(tempSex) == 1 && (tempSex[0] == 'M' || tempSex[0] == 'F')) {
                (p + *count)->sex = tempSex[0];
                break;
            }
            printf("잘못된 성별입니다. 다시 입력해주세요.\n");
        }

        printf("취미: ");
        scanf("%s", (p + *count)->hobby);

        (*count)++;
        printMembers(p, *count);
    }
}

int main() {
    struct group people[100];
    struct group *p = people;
    int count = 3;

    strcpy(p[0].name, "hong"); p[0].age = 30; p[0].sex = 'M'; strcpy(p[0].hobby, "soccer");
    strcpy(p[1].name, "kim");  p[1].age = 25; p[1].sex = 'F'; strcpy(p[1].hobby, "music");
    strcpy(p[2].name, "park"); p[2].age = 20; p[2].sex = 'M'; strcpy(p[2].hobby, "movie");

    printf("초기 사용자 정보:\n");
    printMembers(p, count);
    printf("\n");
    
    while (TRUE) {
        inputMembers(p, &count);
    }

    return 0;
}

