#include "Program.h"
#include "struct.h"
#include <stdio.h>



int getint(const char* msg) {
    printf("%s", msg);
    int i;
    while (!scanf_s("%d", &i) || getchar() != '\n') {
        printf("Invalid value!\n");
        rewind(stdin);
        printf("%s", msg);
    }
    return i;
}

int getint_min(const char* msg, int min) {
    printf("%s", msg);
    int i;
    while (!scanf_s("%d", &i) || i < min || getchar() != '\n') {
        printf("Invalid value!\n");
        rewind(stdin);
        printf("%s", msg);
    }
    return i;
}

int getint_minmax(const char* msg, int min, int max) {
    printf("%s", msg);
    int i;
    while (!scanf_s("%d", &i) || i < min || i > max || getchar() != '\n') {
        printf("Invalid value!\n");
        rewind(stdin);
        printf("%s", msg);
    }
    return i;
}
