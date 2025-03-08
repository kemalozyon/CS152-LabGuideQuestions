// LG6_Q3 -> Fill the structure array from a file and make some calculations on it */

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

#define CGPAPER 0.3
#define ALESPER 0.45
#define YDSPER 0.25

typedef struct {
	double ales;
	double yds;
}grades_t;

typedef struct {
	char stuName[SIZE];
	double cgpa;
	grades_t examGrades;
	double overallGr;
	int scholar;
}stu_t;

void calculateScholarship(stu_t *gradStu);
void readFromFile(FILE *inp, stu_t *gradStu, int noOfGradStu);
void displayStuReport(stu_t *gradStu, int noOfGradStu);

int main(void)
{
	FILE* inp = fopen("graduateStudents.txt", "r");

	if (inp == NULL)
		printf("The file can NOT be opened!\n");
	else
	{
		stu_t* gradStu;
		int	noOfGradStu, status, i = 0;

		fscanf(inp, "%d", &noOfGradStu);
		gradStu = (stu_t*)malloc(noOfGradStu * sizeof(stu_t));// dynamic memory allocation

		readFromFile(inp, gradStu, noOfGradStu);

		//display the content
		displayStuReport(gradStu, noOfGradStu);

		fclose(inp);
		free(gradStu);
	}
	return(0);
}

void calculateScholarship(stu_t *gradStu)
{
	gradStu->overallGr = gradStu->cgpa * CGPAPER + gradStu->examGrades.ales * ALESPER + gradStu->examGrades.yds * YDSPER;

	gradStu->scholar = 0;

	if (gradStu->overallGr > 90)
		gradStu->scholar = 100;
	else if (gradStu->overallGr > 80)
		gradStu->scholar = 75;
	else if (gradStu->overallGr > 65)
		gradStu->scholar = 50;
}

void readFromFile(FILE *inp, stu_t *gradStu, int noOfGradStu)
{
	int i = 0, status;

	status = fscanf(inp, "%s %lf %lf %lf", (gradStu + i)->stuName, &(gradStu + i)->cgpa, &(gradStu + i)->examGrades.ales, &(gradStu + i)->examGrades.yds);
	while (status != EOF && i < noOfGradStu)
	{
		calculateScholarship(&gradStu[i]);
		
		i++;

		status = fscanf(inp, "%s %lf %lf %lf", (gradStu + i)->stuName, &(gradStu + i)->cgpa, &(gradStu + i)->examGrades.ales, &(gradStu + i)->examGrades.yds);
	}//fill the structure array
}

void displayStuReport(stu_t *gradStu, int noOfGradStu)
{
	printf("\nThere are %d students in the Graduate program\n\n", noOfGradStu);
	printf("STUDENT NAME        CGPA    ALES     YDS       OVERALL   SCHOLARSHIP PERCENTAGE\n");
	printf("************        ****    ****     ***       *******   **********************\n");

	for (int i = 0; i < noOfGradStu; i++)
	{
		
		printf("%-17s %7.2f %7.2f %7.2f %10.2f %14d %%\n", (gradStu + i)->stuName,
			(gradStu + i)->cgpa,
			(gradStu + i)->examGrades.ales,
			(gradStu + i)->examGrades.yds,
			(gradStu + i)->overallGr,
			(gradStu + i)->scholar);
	}
}
