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

struct group initialMembers[] = {
    {"hong", 30, 'M', "soccer"},
    {"kim", 25, 'F', "music"},
    {"park", 20, 'M', "movie"}
};
int initialCount = sizeof(initialMembers) / sizeof(initialMembers[0]);

struct group people[100];
struct group *p = people;
int count = 0;

void initializePeopleArray() {
    for (int i = 0; i < initialCount; i++) {
        people[i] = initialMembers[i];
    }
    count = initialCount;
}

void printMembers(struct group *ptr, int currentCount) {
    printf("\n현재까지 입력된 사용자 정보:\n");
    for (int i = 0; i < currentCount; i++) {
        printf("%d. %s %d %c %s\n",
               i + 1, ptr[i].name, ptr[i].age, ptr[i].sex, ptr[i].hobby);
    }
}

void inputOneMember(struct group *ptr, int *currentCount) {
    char tempSex[10];

    printf("\n[%d번째 사용자]\n", *currentCount + 1);

    printf("이름: ");
    scanf("%s", ptr[*currentCount].name);

    while (TRUE) {
        printf("나이: ");
        if (scanf("%d", &ptr[*currentCount].age) == 1 && ptr[*currentCount].age > 0 && ptr[*currentCount].age <= 100) {
            break;
        } else {
            printf("잘못된 나이입니다. 다시 입력해주세요.\n");
            while (getchar() != '\n');
        }
    }

    while (TRUE) {
        printf("성별 (M/F): ");
        scanf("%s", tempSex);
        if (strlen(tempSex) == 1 && (tempSex[0] == 'M' || tempSex[0] == 'F')) {
            ptr[*currentCount].sex = tempSex[0];
            break;
        }
        printf("잘못된 성별입니다. 다시 입력해주세요.\n");
    }

    printf("취미: ");
    scanf("%s", ptr[*currentCount].hobby);

    (*currentCount)++;
    printMembers(ptr, *currentCount);
}

int main() {
    initializePeopleArray();
    printMembers(p, count);
    while (TRUE) {
        inputOneMember(p, &count);
    }
    return 0;
}
