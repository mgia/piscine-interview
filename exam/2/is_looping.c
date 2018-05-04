/*
IS_LOOPING
Assignment name  : is_looping
Expected files   : is_looping.c
Allowed functions:
--------------------------------------------------------------------------------
ALERT: OPTIMIZED SOLUTION REQUIRED.
Given the first node of a linked list as parameter, create a function which
returns 1 if the linked list is looping, otherwise 0.
The linked list uses the following structure:
struct s_node {
    int value;
    struct s_node *next;
};
The function must be declared as follows:
int is_looping(struct s_node *node);
Considerations:
- Be careful: the naive solution won't work on our big input, you have to
find a solution with better complexity than O(N^2) time (where N is the
number of nodes).
- The values of each node does not matter.
- The bigger test we will do is on a linked list of 500.000 nodes, with the
beginning of the loop at the middle. It should run in less than 2 seconds.
Example 1:
1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |         v
          |         6
           \        |
            \______/
In this case, it should return 1 (at the node 3 begins the loop).
Example 2:
12 -> 150 -> 30 -> 50 -> 345 -> 120
       ^                         |
       |                         v
       |                        200
        \                      /
         \____________________/
In this case, it should return 1 (the loop begins at node 150).
Example 3:
12 -> 150 -> 30 -> 50 -> 345 -> 120
In this case, it should return 0 (no loop begins).
Example 4:
12 -> 19 -> 14
            ^ \
            | |
            \/
In this case, it should return 1 (the loop begins at node 14).
*/

struct s_node {
	int value;
	struct s_node *next;
}

int is_looping(struct s_node *node)
{
	struct s_node *tmp1 = node;
	struct s_node *tmp2 = node;
	while (tmp1 && tmp2)
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		if (tmp2)
			tmp2 = tmp2->next;
		if (tmp1 && tmp2 && tmp1 == tmp2)
			return (1);
	}
	return (0);
}