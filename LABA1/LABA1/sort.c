#include "Program.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_name(const Car* a, const Car* b) {
	return strcmp(a->name, b->name);
}

int compare_weight(const Car* a, const Car* b) {

	return (int)a->weight - (int)b->weight;
}

int compare_color(const Car* a, const Car* b) {
    return (int)a->color - (int)b->color;
}

int compare_engine(const Car* a, const Car* b) {
    return (int)a->v - (int)b->v;
}

int first_sort(int (*compare_types[4]) (Car*, Car*), Car* a, Car* b) {
    int comp = 0;
    for (int i = 0; i < 4; i++) {
        if (compare_types[i] == NULL || comp != 0) break;
        comp = ((*compare_types[i])(a, b));
    }
    return comp;
}

void sort_car(Car* arr, int size) {
    int (*compare_types[4]) (Car*, Car*) = 
    { 
        &compare_name,
        &compare_weight, 
        &compare_color,
        &compare_engine
    };
    int count;
    printf("Choose sort count: ");
    while (!scanf_s("%d", &count) || count < 1 || count > 4) {
        printf("Invalid sort count!\n");
        rewind(stdin);
        printf("Choose sort count: ");
    }
    printf("0 - Name\n"
        "1 - Width\n"
        "2 - Color\n"
        "3 - Engine\n");
    int (*second_types[4]) (Car*, Car*);
    for (int i = 0; i < count; i++) {
        int ss;
        printf("Choose sort type: ");
        while (!scanf_s("%d", &ss) || ss < 0 || ss > 3) {
            printf("Invalid sort type!\n");
            rewind(stdin);
            printf("Choose second sort type: ");
        }
        second_types[i] = compare_types[ss];
    }
    for (int i = count; i < 4; i++) {
        second_types[i] = NULL;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int comp = first_sort(second_types, &arr[j], &arr[j + 1]);
            if (comp > 0) {
                Car tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}