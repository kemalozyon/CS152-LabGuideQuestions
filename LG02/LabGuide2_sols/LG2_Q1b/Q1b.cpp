/* LG2_Q1b -> Checks the results */
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	int mat[8] = { 6, 59, 81, 61, 1, 22, 41 }; //Fill the array

	//display the some of array content by using the pointer notation
	printf("%p\n", mat);
	printf("%p\n", mat + 2);
	printf("%d\n", *(mat + 2));
	printf("%d\n", *mat + 4);
	printf("%p\n", mat + 5);
	printf("%d\n", *(mat + 7));

	return 0;
}

/*
012FFA28
012FFA30
81
10
012FFA3C
0
*/