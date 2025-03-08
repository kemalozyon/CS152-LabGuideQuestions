/* LG3_Q1 -> Checks the results */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	double array[4][3] = { { 42.90, 60.71, 57.30 }, { 93.21, 82.97, 21.14 }, { 25.91, 92.2, 30.17 }, { 52.87, 75.84, 44.56 } };

	printf("\nValue represented by \"matrix\" is %p", array);
	printf("\nValue represented by (matrix + 1) is %p", (array + 1));
	printf("\nValue represented by *(matrix + 1) is %p", *(array + 1));
	printf("\nValue represented by (*(matrix) + 1) is %p", (*(array)+1));
	printf("\nValue represented by *(*(matrix) + 1) is %.2f", *(*(array)+1));
	printf("\nValue represented by *(*(matrix + 1)) is %.2f", *(*(array + 1)));
	printf("\nValue represented by *(*(matrix) + 1)+2 is %.2f", *(*(array)+1) + 2);
	printf("\nValue represented by (*(matrix + 1)+2) is %p", (*(array + 1) + 2));
	printf("\nValue represented by *(*(matrix+1) + 2) is %.2f\n", *(*(array + 1) + 2));
}

/*
Value represented by "matrix" is 007AFAE8
Value represented by(matrix + 1) is 007AFB00
Value represented by *(matrix + 1) is 007AFB00
Value represented by(*(matrix)+1) is 007AFAF0
Value represented by *(*(matrix)+1) is 60.71
Value represented by *(*(matrix + 1)) is 93.21
Value represented by *(*(matrix)+1) + 2 is 62.71
Value represented by(*(matrix + 1) + 2) is 007AFB10
Value represented by *(*(matrix + 1) + 2) is 21.14
*/