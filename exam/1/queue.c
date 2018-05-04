/*
QUEUE
Assignment name  : queue
Expected files   : queue.c
Allowed functions: malloc free
--------------------------------------------------------------------------------
Implement a queue data structure in C, using the following structures in your
code:
    struct s_node {
        void *content;
        struct s_node *next;
    };
    struct s_queue {
        struct s_node *first;
        struct s_node *last;
    };
A queue uses FIFO (first-in fist-out) ordering :
items are removed from the data structure in the same order that they are added.
Implement 5 functions for the following queue operations :
    - init() : Initialize the queue.
      The first and last pointers are set to NULL.
    - enqueue(queue, item) : Add an item to the end of the queue.
    - dequeue(queue) : Remove the first item from the queue and return it.
      If the queue is empty, the function returns NULL.
    - peek(queue) : Return the first item of the queue.
      If the queue is empty, the function returns NULL.
    - isEmpty(queue) : Return 1 if the queue is empty, 0 otherwise.
These functions must be declared as follows:
    struct s_queue *init(void);
    void enqueue(struct s_queue *queue, void *content);
    void *dequeue(struct s_queue *queue);
    void *peek(struct s_queue *queue);
    int isEmpty(struct s_queue *queue);
*/

typedef struct s_node {
	void *content;
	struct s_node *next;
} Node;

typedef struct s_queue {
	struct s_node *first;
	struct s_node *last;
} Queue;

struct s_queue *init(void)
{
	Queue *q = malloc(sizeof(Queue));
	q->first = 0;
	q->last = 0;
	return (q);
}

void enqueue(struct s_queue *queue, void *content)
{
	Node *new = malloc(sizeof(Node));
	new->content = content;
	new->next = 0;
	if (!queue->last)
		queue->first = new;
	else
		queue->last->next = new;
	queue->last = new;
}

void *dequeue(struct s_queue *queue)
{
	if (isEmpty(queue))
		return (0);
}

void *peek(struct s_queue *queue)
{
	if (!queue->first)
		return (0);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}
