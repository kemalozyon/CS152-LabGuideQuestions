#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int findFirst(char *s1, char *s2);
int main(void)
{
	char	sent[MAX],
			str[MAX];
	int	pos;
	printf("\nEnter a sentence: ");
	scanf("%[^\n]", sent);
	printf("\nEnter a string: ");
	scanf("%s", str);
	pos = findFirst(sent, str);
	if (pos == -1)
		printf("The sentence does NOT contain the string <%s>\n", str);
	else
		printf("The first occurence of the str <%s> is %d\n", str, pos);
	return(0);
}
int findFirst(char *s1, char *s2)
{
	int	k,
		len1 = strlen(s1),
		len2 = strlen(s2);
	for (k = 0; k <= len1 - len2; k++)
	{
		if (strncmp(s1 + k, s2, len2) == 0)
			return k;
	}
	return (-1);
}