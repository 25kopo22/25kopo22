#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

struct personalInfo {
    char name[20];
    int age;
    char sex;
};

union extraInfo {
    char hobby[30];
    char etc[50];
};

struct group {
    struct personalInfo personal;
    union extraInfo extra;
    int isHobby; 
};

struct group initMem[] = {
    {{"hong", 30, 'M'}, {"soccer"}, 1},
    {{"kim", 25, 'F'}, {"music"}, 1},
    {{"park", 20, 'M'}, {"reading"}, 0}
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
        printf("%d. %s %d %c ",
               i + 1, ptr[i].personal.name, ptr[i].personal.age, ptr[i].personal.sex);
        if (ptr[i].isHobby) {
            printf("취미: %s\n", ptr[i].extra.hobby);
        } else {
            printf("기타: %s\n", ptr[i].extra.etc);
        }
    }
}

void inputOneMember(struct group *ptr, int *curCnt) {
    char tempSex[10];
    char choice[10];

    printf("\n[%d번째 사용자]\n", *curCnt + 1);

    printf("이름: ");
    scanf("%s", ptr[*curCnt].personal.name);

    while (TRUE) {
        printf("나이: ");
        if (scanf("%d", &ptr[*curCnt].personal.age) == 1 && ptr[*curCnt].personal.age > 0 && ptr[*curCnt].personal.age <= 100) {
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
            ptr[*curCnt].personal.sex = tempSex[0];
            break;
        } else {
            printf("잘못된 성별입니다. 다시 입력해주세요.\n");
        }
    }

    while (TRUE) {
        printf("취미를 입력하시겠습니까? (Y/N): ");
        scanf("%s", choice);
        if (strlen(choice) == 1 && (choice[0] == 'Y')) {
            printf("취미: ");
            scanf("%s", ptr[*curCnt].extra.hobby);
            ptr[*curCnt].isHobby = 1;
            break;
        } else if (strlen(choice) == 1 && (choice[0] == 'N')) {
            printf("기타 정보: ");
            scanf("%s", ptr[*curCnt].extra.etc);
            ptr[*curCnt].isHobby = 0;
            break;
        } else {
            printf("잘못된 입력입니다. Y 또는 N으로 답해주세요.\n");
            while (getchar() != '\n');
        }
    }

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
