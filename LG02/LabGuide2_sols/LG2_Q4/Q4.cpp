/* LG2_Q4 -> Reading one integer list from a text file, find the average excluding the numbers that can be divisble by 5 */
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//reads a list of numbers from a text file
int readList(FILE *fp, int list[]);
double findPro(int list[], int size);


int main(void)
{
	int list[25]; //list to store the elements
	int	listSize, min, max;
	int pro = 1;

	FILE *fp = fopen("numbers.txt", "r");
	
	if (fp == NULL)
		printf("Error! Can NOT read the file!!!");
	else {
		//read the list
		listSize = readList(fp,list);

		fclose(fp);
		pro = findPro(list,listSize);

		printf("\nProduct excluding the numbers that are divisible by 5: %d",pro);
	}
	return 0;
}

int readList(FILE *fp, int list[])
{
	int listSize = 0;

	while(fscanf(fp,"%d", list+listSize )!=EOF)
		listSize++;

	return listSize;
}


double findPro(int list[], int size)
{
	int i, pro = 1;

	for (i = 0; i < size; i++)
	{
		if (*(list + i) % 5 != 0) {
			pro *= *(list+i);
		}
	}

	return pro;
}