#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>


typedef struct Student {
    char name[64];
    char program[16], level[16];
    char email[64], phone[16];
    char id[16], section[16];

    struct Student* next;
} Student;


void printLine(char c) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    for (int i = 0; i < w.ws_col; i++) {
        printf("%c", c);
    }
    printf("\n");
}

Student* createStudentEntry(
    char* name, char* program, char* level,
    char* email, char* phone, char* id, char* section
) {
    Student* newEntry = (Student*)malloc(sizeof(Student));
    printLine('-');

    if (newEntry != NULL) {
        strcpy(newEntry->name, name);
        strcpy(newEntry->program, program);
        strcpy(newEntry->level, level);
        strcpy(newEntry->email, email);
        strcpy(newEntry->phone, phone);
        strcpy(newEntry->id, id);
        strcpy(newEntry->section, section);

        newEntry->next = NULL;
    }
    return newEntry;
}

void freeStudentEntries(Student* head) {
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        printLine('-');
        free(temp);
    }
}

int main() {
    int n, m;

    printLine('*');
    printf("==> ENTER NUMBER OF NODES TO CREATE: ");
    scanf("%d", &n);
    getchar();
    printLine('-');
    printf("==> ENTER NUMBER OF NODES TO FREE: ");
    scanf("%d", &m);
    getchar();
    printLine('-');

    Student* head = NULL;
    Student* tail = NULL;

    for (int i = 0; i < n; i++) {
        char name[64];
        char program[16], level[16];
        char email[64], phone[16];
        char id[16], section[16];        

        printf("==> ENTER STUDENT %d's NAME: ", i + 1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        
        printf("==> ENTER STUDENT %d's PROGRAM: ", i + 1);
        fgets(program, sizeof(program), stdin);
        program[strcspn(program, "\n")] = '\0';
        
        printf("==> ENTER STUDENT %d's LEVEL: ", i + 1);
        fgets(level, sizeof(level), stdin);
        level[strcspn(level, "\n")] = '\0';
        
        printf("==> ENTER STUDENT %d's EMAIL: ", i + 1);
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';
        
        printf("==> ENTER STUDENT %d's PHONE: ", i + 1);
        fgets(phone, sizeof(phone), stdin);
        phone[strcspn(phone, "\n")] = '\0';
        
        printf("==> ENTER STUDENT %d's ID: ", i + 1);
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';
        
        printf("==> ENTER STUDENT %d's SECTION: ", i + 1);
        fgets(section, sizeof(section), stdin);
        section[strcspn(section, "\n")] = '\0';

        printLine('-');

        Student* newEntry = createStudentEntry(
            name, program, level, email, phone, id, section
        );
        
        if (newEntry == NULL) {
            printf("MEMORY ALLOCATION FAILED!\n");
            return 1;
        }
        if (head == NULL) {
            head = newEntry;
            tail = newEntry;
        } else {
            tail->next = newEntry;
            tail = newEntry;
        }
    }

    printf("==> FREEING %d STUDENT ENTRIES\n", m);
    printLine('-');

    Student* current = head;
    for (int i = 0; i < m && current != NULL; i++) {
        Student* temp = current;
        current = current->next;
        free(temp);
        printLine('-');
    }

    printf("==> FREEING REMAINING %d STUDENT ENTRIES (FIX-UP)\n", n - m);
    
    // FREE ALL REMAINING NODES
    freeStudentEntries(current);    

    printLine('*');

    return 0;
}
