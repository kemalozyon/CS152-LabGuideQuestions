#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 250
int findFirstOccWord(char *sent, char *word);
void delAllOccur(char *word, char *myword);
void main()
{
	char sent[MAX], word[MAX];
	int	check;
	printf("Enter a sentence: ");
	scanf(" %[^\n]", sent);
	printf("Enter a word: ");
	scanf(" %s", word);
	check = findFirstOccWord(sent, word);
	if (check == -1)
		printf("The sentence does NOT contain the WORD <%s>..\n", word);
	else
	{
		delAllOccur(sent, word);
		printf("Final format of the sentence : %s\n", sent);
	}
}
int findFirstOccWord(char *sent, char *word)
{
	int k, sentlen = strlen(sent),
		wordlen = strlen(word);
	for (k = 0; k <= sentlen - wordlen; k++)
	{ //Find the first word
		if (strncmp(sent + k, word, wordlen) == 0 &&
			(k == 0 || sent[k - 1] == ' ') &&
			(k == sentlen - wordlen || sent[k + wordlen] == ' '))
			return k;
	}
	return -1;
}
void delAllOccur(char *word, char *myword)
{
	int pos, wordlen = strlen(myword);
	pos = findFirstOccWord(word, myword);
	while (pos != -1) {

		strcpy(word + pos, word + pos + wordlen);
		pos = findFirstOccWord(word, myword);
	}
}
