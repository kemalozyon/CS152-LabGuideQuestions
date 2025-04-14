// LG12_Q3a -> displays the pattern recursively

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// print a line
void printNumbers(int num) {

	if (num != 0)
	{
		printNumbers(num - 1);
		printf("%d ", num);
	}
}

// print the pattern
void printLines(int line)
{
	if (line != 0)
	{
		printLines(line-1);
		printNumbers(line);
		printf("\n");
	}
}


int main() {
	int lineCnt;

	printf("Enter the number of lines: ");
	scanf("%d", &lineCnt);

	printLines(lineCnt);

	return 0;
}