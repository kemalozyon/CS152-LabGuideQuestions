// LG16_Q4 

#define _CRT_SECURE_NO_WARNINGS 1 

# include <stdio.h>
# include "queue_char.h"   //queue for characters

#define DEL_CHAR '*'		// * character is for delete the first character
#define EMPTY_QUEUE '+'		// " character is for empty the whole queue
#define DISP_QUEUE1 ':'		// : and ! characters are for display the queue
#define DISP_QUEUE2 '!' 
#define ENTER '\n'			// \n character is to check the end of line

void displayQueue(queue_t q)
{
	printf("\n\nThe content of the queue is: ");
	while (!isEmptyQ(&q))
		printf("%c ", remove(&q));
}
int main(void)
{
	char ch, item;

	queue_t myqueue;
	initializeQ(&myqueue);

	printf("\n*	Erase the first character (remove it from the queue)");
	printf("\n+	Kill the entire line (Empty the queue)");
	printf("\n: or !	Display the queue content");
	printf("\nEnter	Terminate the string entry and display the queue content");

	printf("\nEnter characters to be inserted to the queue (press enter to stop)..:\n");
	scanf("%c", &ch);

	// You may read the characters as a string. 
	// Then you have to check every character of the string
	// i.e. str[i]
	while (ch != ENTER)
	{
		switch (ch)
		{
		case DEL_CHAR:	if (!isEmptyQ(&myqueue))
		{
			item = remove(&myqueue);
			printf("\nThe character <%c> is removed from the queue", item);
		}
						break;
		case EMPTY_QUEUE:
			while (!(isEmptyQ(&myqueue)))
				item = remove(&myqueue);

			printf("\nAll the characters are removed from the queue");
			break;
		case DISP_QUEUE1:
		case DISP_QUEUE2:
			displayQueue(myqueue);
			break;
		default:	insert(&myqueue, ch);
		}
		scanf("%c", &ch);
	}

	displayQueue(myqueue);
	printf("\n");

	return(0);
}
