#ifndef LAB1_PROGRAM_HEADER
#define LAB1_PROGRAM_HEADER
#include "struct.h"
int compare_name(const Car* a, const Car* b);
int compare_weight(const Car* a, const Car* b);
int compare_color(const Car* a, const Car* b);
int compare_engine(const Car* a, const Car* b);
void sort_car(Car* arr, int size);
Car init_arr(char name[100], int weight, int color, int v);
void array_struct(Car** array, int* sizeArr);
void print_car(Car* car, int num);
int getint(const char* msg);
int getint_min(const char* msg, int min);
int getint_minmax(const char* msg, int min, int max);
Car* create_array(int count);
void remove_array(Car** arr, int* size, int index);
int check(int size);
int first_sort(int (*compare_types[4]) (Car*, Car*), Car* a, Car* b);
void remove_index(Car** arr, int* sizeArr);
void menu();
#endif