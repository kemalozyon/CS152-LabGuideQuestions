/* LG7_Q5 -> Finding the length of the words and their occurences in a sentence */

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define MAX 50

int main(void)
{
	FILE* inp;			  //input file pointer

	inp = fopen("input.txt", "r");  //opening the input file in read mode

	if (inp == NULL)				 //if the file can not be found
		printf("File can not be opened!!");  //error message
	else
	{  //if the file exist

		char sentence[MAX];   //character array to hold the sentence
		char* s1;				//character pointer to hold the address of the sentence array
		int count[MAX] = { 0 };   //count array to hold the ocurrences
		int i,				  //holds the arrays index	
			length,			  //holds the sentence array length
			status;

		s1 = sentence;		  //assigning the character pointer to character array starting point 	

		status = fscanf(inp, "%s", s1);  //reading the first word from the file
		while (status != EOF)           //while not end of file 
		{
			length = strlen(s1);       //find the length of the first word that comes from the file
			count[length - 1]++;		 //increment this length - 1 from the count array
			status = fscanf(inp, "%s", s1); //get the next word from the input file
		}

		FILE *out = fopen("output.txt", "w");
		fprintf(out, "Word length     Occurrences\n");
		fprintf(out, "----------------------------\n");

		for (i = 0; i < MAX; i++)
		{
			if (count[i] != 0)         //if the count array i. value is not 0
				fprintf(out, "%5d %15d\n", i + 1, count[i]); //print it to the file
		}

		fclose(inp);
		fclose(out);
	}
	return(0);
}
