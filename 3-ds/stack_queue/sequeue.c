#include <stdio.h>
#include <stdlib.h>

#define DEBUG	1

typedef struct _sequeue_{
	int total;
	int head;
	int tail;
	int *data;
}sequeue_st;

sequeue_st *sequeue_init(int len);
int sequeue_free(sequeue_st *queue);
int sequeue_enqueue(sequeue_st *queue, int value);
int sequeue_dequeue(sequeue_st *queue, int *value);
int sequeue_isempty(sequeue_st *queue);
int sequeue_isfull(sequeue_st *queue);

#if DEBUG
void _sequeue_debug_(sequeue_st *queue);
#endif

int main()
{
	int value = 100;
	sequeue_st *queue = NULL;
	
	queue = sequeue_init(10);
	
	while (-1 != sequeue_enqueue(queue, value))
		value += 100;

#if DEBUG
	_sequeue_debug_(queue);
#endif
	
	while (-1 != sequeue_dequeue(queue, &value))
		printf("%5d", value);
	putchar('\n');

#if DEBUG
	_sequeue_debug_(queue);
#endif

	sequeue_free(queue);
	return 0;
}

sequeue_st *sequeue_init(int len)
{
	sequeue_st *queue = NULL;

	queue = (sequeue_st *)malloc(sizeof(sequeue_st));
	queue->total = len;
	queue->head = 0;
	queue->tail = 0;
	queue->data = (int *)malloc(sizeof(int) * len);

	return queue;
}

int sequeue_free(sequeue_st *queue)
{
	free(queue->data);
	free(queue);

	return 0;
}

int sequeue_enqueue(sequeue_st *queue, int value)
{
	if (sequeue_isfull(queue))
		return -1;

	queue->data[queue->tail] = value;
	queue->tail = (queue->tail + 1) % queue->total;

	return 0;
}

int sequeue_isfull(sequeue_st *queue)
{
	if ((queue->tail + 1) % queue->total == queue->head)
		return 1;
	return 0;
}

int sequeue_dequeue(sequeue_st *queue, int *value)
{
	if (sequeue_isempty(queue))
		return -1;
	
	*value = queue->data[queue->head];
	queue->head = (queue->head + 1) % queue->total;

	return 0;
}

int sequeue_isempty(sequeue_st *queue)
{
	if (queue->head == queue->tail)
		return 1;
	return 0;
}

#if DEBUG
void _sequeue_debug_(sequeue_st *queue)
{
	int index;

	puts("------------------- DEBUG --------------------");
	printf("Total: %d\tHead: %d\tTail: %d\n", 
			queue->total, queue->head, queue->tail);
	for (index = 0; index < queue->total; index ++)
		printf("%5d", queue->data[index]);
	puts("\n---------------------------------------------");
}
#endif
