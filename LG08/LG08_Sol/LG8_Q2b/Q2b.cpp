#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100
int findFirst(char *s1, char *s2);
int delAllOccur(char *sent, char *strToDel);
int delAllOccur(char *sent, char *strToDel);
int main(void)
{
	char sent[MAX], str[MAX];
	int	check;
	printf("Enter a sentence: ");
	scanf("%[^\n]", sent);
	printf("Enter a string: ");
	scanf("%s", str);
	check = delAllOccur(sent, str);
	if (check == 0)
		printf("Word is not found in the string..\n");
	else
		printf("Final format of the str : %s\n", sent);
	return 0;
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
	return -1;
}
int delAllOccur(char *sent, char *strToDel)
{
	int pos, flag = 0;
	int lenDel = strlen(strToDel);
	pos = findFirst(sent, strToDel);
	while (pos != -1) {
		strcpy(sent + pos, sent + pos + lenDel);
		flag = 1;

		pos = findFirst(sent, strToDel);
	}
	return flag;
}