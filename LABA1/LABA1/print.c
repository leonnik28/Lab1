#include "Program.h"
#include "struct.h"
#include <stdio.h>
const char* colors[] = { "NONE", "Red", "Black", "White", "Blue" };
const char* engines[] = { "NONE", "v4", "v6", "v8", "v10", "v12" };
void print_car(Car* car, int num) {
	for (int i = 0; i < num; i++) {
		printf_s("Name car: %s\n", car[i].name);
		printf_s("Weight: %d\n", car[i].weight);
		printf_s("Color: %s\n", colors[car[i].color]);
		printf_s("Engine: %s\n", engines[car[i].v]);
		printf_s("\n");
	}
}