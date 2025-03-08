#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100
#define MAXWORD 20
int findFirst(char *s1, char *s2);
void replaceFirstOccur(char *sent, char *srch, char *repStr, int pos);
int main(void)
{
	char	sent[MAX],
			srchStr[MAXWORD],
			repStr[MAXWORD];
	int	pos;
	printf("\nEnter a sentence: ");
	scanf("%[^\n]", sent);
	printf("Enter a String to search: ");
	scanf(" %s", srchStr);
	pos = findFirst(sent, srchStr);
	if (pos == -1)
		printf("\nThe sentence does NOT contain the string <%s>\n", srchStr);
	else
	{
		printf("Enter a String to replace: ");
		scanf(" %s", repStr);
		replaceFirstOccur(sent, srchStr, repStr, pos);
		printf("\nNew form of the sentence: \n%s ", sent);
		printf("\n");
	}
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
void replaceFirstOccur(char *sent, char *srch, char *repStr, int pos)
{
	char	temp[MAX] = "";
	int	srchLen = strlen(srch);
	strcpy(temp, sent + pos + srchLen);
	strcpy(sent + pos, repStr);
	strcat(sent, temp);
}