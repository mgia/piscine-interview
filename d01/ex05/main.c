#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	printf("Pushing...");
	// tankPush(tank, 50);
	// tankPush(tank, 51);
	// tankPush(tank, 52);
	// tankPush(tank, 53);
	// tankPush(tank, 1000);
	tankPush(tank, 500);
	tankPush(tank, 510);
	tankPush(tank, 520);
	tankPush(tank, 530);
	tankPush(tank, 540);
	printf("Complete!\n");

	printf("Number of stacks in tank: %d\n", tank->n);
	printf("Popping:\n");
	for (int i = 0; i < 5; i++)
		printf("%d\n", tankPop(tank));

	printf("Check for empty stack: %d\n", tankPop(tank));
	return (0);
}



// Function used for the test
// Don't go further :)
