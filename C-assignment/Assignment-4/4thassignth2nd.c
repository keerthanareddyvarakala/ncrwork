#include<stdio.h>
int main() {
	char *color[6] = { "red", "green", "blue", "white", "black", "yellow" };
	printf("the value of color %d \n", color);
	printf("the value of color+2 %d \n", color+2);
	printf("the value of *color %s \n", *color);
	printf("the value of *(color+2) %s \n", *(color+2));
	printf("the value of color[5] and *(color+5) %s and %s ", color[5],*(color + 5));

	getch();
	return 0;
}

