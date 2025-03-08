/* LG7_Q2 -> Finds the length of a string */

#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
#define SIZE 30

int myStrLen(char str[]);

int main(void)
{
	FILE *inp, *outp;

	inp = fopen("words.txt", "r");

	if (inp == NULL)
		printf("\n File CANNOT be found\n");
	else
	{
		char place[SIZE];
		int len;

		outp = fopen("result.txt", "w");

		while (fscanf(inp, "%s", place) != EOF)
		{
			len = myStrLen(place);
			fprintf(outp, "%s-%d\n", place, len);
		}

		fclose(inp);
		fclose(outp);
	}

	return(0);
}


int myStrLen(char* str)
{
	char* p = str;

	while (*p != '\0')
		p++;

	return (p - str);
}

//ALTERNATIVE SOLUTION
/*
int myStrLen(char str[])
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return i;
}
*/