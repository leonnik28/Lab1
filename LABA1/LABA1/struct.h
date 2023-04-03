#ifndef LAB1_STRUCT_HEADER
#define LAB1_STRUCT_HEADER
enum Color {
	NONEcolor,
	Red,
	Black,
	White,
	Blue
};
enum Engine {
	NONEengine,
	v4,
	v6,
	v8,
	v10,
	v12
};

typedef struct {
	char name[100];
	int weight;
	enum Color color;
	enum Engine v;
}Car;
#endif

