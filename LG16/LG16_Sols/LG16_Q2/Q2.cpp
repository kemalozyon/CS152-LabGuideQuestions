/* LG16_Q2 -> Bus Stop */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include "queue_str.h"
#define SIZE 20

void displayQueue(queue_t q);

int main(void)
{
	FILE *inp;
	char name[SIZE];
	int	n, i, status;

	queue_t students;
	initializeQ(&students);

	inp = fopen("students.txt", "r");

	//read names of the students from the file and insert all the passengers into the queue
	status = fscanf(inp, "%s", name);

	while (status != EOF)
	{
		insert(&students, name);
		status = fscanf(inp, "%s", name);
	}

	displayQueue(students);

	//remove n students from the queue
	printf("\nThe bus arrived to the bus stop!\nHow many students getting on the bus? ");
	scanf("%d", &n);

	i = 1;
	printf("\nThe list of students getting on the bus:\n");

	while (!isEmptyQ(&students) && i <= n)
	{
		strcpy(name, remove(&students));
		printf("%s\n", name);
		i++;
	}

	displayQueue(students);

	return 0;
}

void displayQueue(queue_t q)
{
	char item[SIZE];
	if (isEmptyQ(&q))
		printf("\nNobody is waiting!\n");
	else
	{
		printf("\nWaiting students:\n");
		while (!isEmptyQ(&q))
		{
			strcpy(item, remove(&q));
			printf("%s\n", item);
		}
	}
}