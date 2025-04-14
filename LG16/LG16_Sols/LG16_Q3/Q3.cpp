/* LG16_Q3 -> Finds and displays the “the class of the day” */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "queue_struct.h"

void fillQueue(FILE *inp, queue_t *oneOfTheClasses);
void displayQueue(queue_t oneOfTheClasses);
class_t classOfTheDay(queue_t oneOfTheClasses);

int main(void)
{
	class_t	max;
	queue_t	classInfo;

	initializeQ(&classInfo);

	FILE*inp;
	inp = fopen("classes.txt", "r");

	if (inp == NULL)
		printf("Error!\n");
	else
	{
		fillQueue(inp, &classInfo);
		fclose(inp);

		displayQueue(classInfo);

		max = classOfTheDay(classInfo);

		printf("The Class of the day\n");
		printf("*********************\n");
		printf("%-10s %3.2d\n", max.className, max.questions);
	}

	return(0);
}

void fillQueue(FILE * inp, queue_t *classInfo)
{
	int status;
	class_t temp;

	status = fscanf(inp, "%s %d", temp.className, &temp.questions);
	while (status != EOF)
	{
		insert(classInfo, temp);
		status = fscanf(inp, "%s %d", temp.className, &temp.questions);
	}
}

void displayQueue(queue_t classInfo)
{
	class_t temp;
	printf("The list of all classes;\n\n");
	printf("Class Name    # of Questions\n");
	printf("****************************\n");

	while (!isEmptyQ(&classInfo))
	{
		temp = remove(&classInfo);
		printf("%-15s %-8.2d\n", temp.className, temp.questions);
	}
	printf("\n");
}

class_t classOfTheDay(queue_t classInfo)
{
	class_t max, temp;

	max = remove(&classInfo);

	while (!isEmptyQ(&classInfo))
	{
		temp = remove(&classInfo);
		if (temp.questions > max.questions)
			max = temp;
	}
	return max;
}