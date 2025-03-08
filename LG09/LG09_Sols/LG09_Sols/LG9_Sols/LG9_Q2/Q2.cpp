#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100
int findAllOccur(char *s1, char *s2, int indexes[]);
int main(void)
{
	char	sent[MAX],
		str[MAX];

	int	cnt, indexes[MAX];
	printf("\nEnter a sentence: ");
	scanf("%[^\n]", sent);

	printf("\nEnter a string: ");
	scanf("%s", str);
	cnt = findAllOccur(sent, str, indexes);
	if (cnt == 0)
		printf("The sentence does NOT contain the string <%s>\n", str);
	else
	{
		printf("All occurences of the str <%s>:\n", str);
		for (int i = 0; i < cnt; i++)
			printf("%3d", indexes[i]);
		printf("\n");
	}
	return(0);
}
int findAllOccur(char *s1, char *s2, int indexes[])
{
	int	k,
		len1 = strlen(s1),
		len2 = strlen(s2),
		cnt = 0;
	for (k = 0; k <= len1 - len2; k++)
	{
		if (strncmp(s1 + k, s2, len2) == 0)
		{
			indexes[cnt] = k;
			cnt++;
		}
	}
	return(cnt);
}
