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

struct group initMem[] = {
    {"hong", 30, 'M', "soccer"},
    {"kim", 25, 'F', "music"},
    {"park", 20, 'M', "movie"}
};
int initCnt = sizeof(initMem) / sizeof(initMem[0]);

struct group people[1000];
struct group *p = people;
int cnt = 0;

void initializePeopleArray() {
    for (int i = 0; i < initCnt; i++) {
        people[i] = initMem[i];
    }
    cnt = initCnt;
}

void printMembers(struct group *ptr, int curCnt) {
    printf("\n현재까지 입력된 사용자 정보:\n");
    for (int i = 0; i < curCnt; i++) {
        printf("%d. %s %d %c %s\n",
               i + 1, ptr[i].name, ptr[i].age, ptr[i].sex, ptr[i].hobby);
    }
}

void inputOneMember(struct group *ptr, int *curCnt) {
    char tempSex[10];

    printf("\n[%d번째 사용자]\n", *curCnt + 1);

    printf("이름: ");
    scanf("%s", ptr[*curCnt].name);

    while (TRUE) {
        printf("나이: ");
        if (scanf("%d", &ptr[*curCnt].age) == 1 && ptr[*curCnt].age > 0 && ptr[*curCnt].age <= 100) {
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
            ptr[*curCnt].sex = tempSex[0];
            break;
        } else {
            printf("잘못된 성별입니다. 다시 입력해주세요.\n");
        }
    }

    printf("취미: ");
    scanf("%s", ptr[*curCnt].hobby);

    (*curCnt)++;
    printMembers(ptr, *curCnt);
}

void Loop() {
    while (TRUE) {
        inputOneMember(p, &cnt);
    }
}

int main() {
    initializePeopleArray();
    printMembers(p, cnt);
    Loop();
    return 0;
}
