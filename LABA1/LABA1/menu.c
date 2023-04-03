#include "Program.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

int check(int size) {
    if (size <= 0)
    {
        printf("Array not created\n");
        return 1;
    }
    return 0;
}

void menu() {
    int size = 0;
    Car* cars;
    

    while (1) {
        printf("\nPick Task:\n"
            "1 - Create array\n"
            "2 - Print array\n"
            "3 - Sort array\n"
            "4 - Remove struct from array\n"
            "5 - Exit\n"
            "Your pick: ");
        int pick;
        while (!scanf_s("%d", &pick) || pick < 1 || pick > 5) {
            printf("Invalid pick! Valid pick [1-5]\n");
            rewind(stdin);
            printf("Your pick: ");
        }
        printf("\n");
        switch (pick) {
        case 1: 
            if (size > 0) {
                free(cars);
            }
            array_struct(&cars, &size);
            break;
        case 2:
            if (check(size))
                break;
            print_car(cars, size);
            break;
        case 3:
            if (check(size))
                break;
            sort_car(cars, size);
            break;
        case 4:
            if (check(size))
                break;
            remove_index(&cars, &size);
            break;
        default:
            if (size > 0) free(cars);
            return;
        }
    }
}