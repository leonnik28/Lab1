#include "Program.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

Car* create_array(int count) {
	return (Car*)calloc(count, sizeof(Car));
}

void remove_array(Car** arr, int* size, int index) {
	if (index < 0 || index >= *size) {
		printf("Invalid index!\nValid index [0-%d]", *size);
		return;
	}

	for (int i = index; i < *size - 1; i++) {
		(*arr)[i] = (*arr)[i + 1];
	}

	*size -= 1;
	*arr = (Car*)realloc(*arr, (*size) * sizeof(Car));
}

void remove_index(Car** arr, int* sizeArr) {
	printf("Enter index: ");
	int index;
	while (!scanf_s("%d", &index) || index < 0 || index >= *sizeArr) {
		printf("Invalid index!\n");
		rewind(stdin);
		printf("Enter index: ");
	}
	remove_array(arr, sizeArr, index);
}

void array_struct(Car** array, int* sizeArr) {
	int size = getint_min("Enter the number of structures: ", 1);
	*array = create_array(size);
	*sizeArr = size;
	for (int i = 0; i < size; i++) {
		char name[100];
		int weight;
		int color;
		int v;
		rewind(stdin);
		printf("Struct number: %d \n", i);
		printf("Input name: ");
		scanf("%99s", &name);
		weight = getint("Input weight: ");
		color = getint_minmax("Input number(1 - Red 2 - Black, 3 - White, 4 - Blue) : ", 1, 4);
		v = getint_minmax("Input class engine(1 - v4, 2 - v6, 3 - v8, 4 - v10, 5 - v12): ", 1, 5);
		(*array)[i] = init_arr(name, weight, color, v);
	}
}

Car init_arr(char name[100], int weight, int color, int v) {
	Car car;
	snprintf(car.name, sizeof(car.name), "%s", name);
	car.weight = weight;
	car.color = color;
	car.v = v;
	return car;
}