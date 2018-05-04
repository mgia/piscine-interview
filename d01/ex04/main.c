#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue *q = queueInit();

	printf("Enqueue...");
	enqueue(q, "one");
	enqueue(q, "two");
	enqueue(q, "three");
	enqueue(q, "four");
	enqueue(q, "five");
	printf(" Done!\n");

	printf("Not empty: %s\n", isEmpty(q) ? "No" : "Yes");
	printf("Peek: %s\n", peek(q));

	printf("Dequeueing...\n");
	for (int i = 0; i < 5; i++)
		printf("%s\t", dequeue(q));
	printf("\n");

	printf("Dequeue empty: %s\n", dequeue(q));
	printf("Not empty: %s\n", isEmpty(q) ? "No" : "Yes");
	printf("Peek: %s\n", peek(q));

	return (0);
}



// Function used for the test
// Don't go further :)
