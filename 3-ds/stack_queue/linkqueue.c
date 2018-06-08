#include <stdio.h>
#include <stdlib.h>

#define DEBUG	1

typedef struct _linknode_ {
	int data;
	struct _linknode_ *next;
}linknode_st;

typedef struct _linkqueue_ {
	int total;
	int current;
	linknode_st *head,
				*tail;
}linkqueue_st;

linknode_st *create_linknode(int value);
linkqueue_st *linkqueue_init(int len);
int linkqueue_free(linkqueue_st *queue);
int linkqueue_enqueue(linkqueue_st *queue, int value);
int linkqueue_dequeue(linkqueue_st *queue, int *value);
int linkqueue_isfull(linkqueue_st *queue);
int linkqueue_isempty(linkqueue_st *queue);
#if DEBUG
void _linkqueue_debug_(linkqueue_st *queue);
#endif

int main()
{
	linkqueue_st *queue = NULL;
	int value = 100;
	
	queue = linkqueue_init(10);

	while (-1 != linkqueue_enqueue(queue, value))
		value += 100;

#if DEBUG
	_linkqueue_debug_(queue);
#endif
	
	while (-1 != linkqueue_dequeue(queue, &value))
		printf("%5d", value);
	putchar(10);
	
	while (-1 != linkqueue_enqueue(queue, value))
		value += 100;
#if DEBUG
	_linkqueue_debug_(queue);
#endif

	linkqueue_free(queue);
	
	return 0;
}

linkqueue_st *linkqueue_init(int len)
{
	linkqueue_st *queue = NULL;

	queue = (linkqueue_st *)malloc(sizeof(linkqueue_st));
	queue->total = len;
	queue->current = 0;
	queue->head = create_linknode(0);
	queue->tail = queue->head;

	return queue;
}

linknode_st *create_linknode(int value)
{
	linknode_st *node = NULL;

	node = (linknode_st *)malloc(sizeof(linknode_st));
	node->data = value;
	node->next = NULL;

	return node;
}

int linkqueue_free(linkqueue_st *queue)
{
	linknode_st *p = queue->head;
	linknode_st *tmp = NULL;
	
	while (NULL != p) {
		tmp = p;
		p = tmp->next;
		free(tmp);
	}
	free(queue);

	return 0;
}

int linkqueue_enqueue(linkqueue_st *queue, int value)
{
	linknode_st *node = NULL;

	if (linkqueue_isfull(queue))
		return -1;

	node = create_linknode(value);
	queue->tail->next = node;
	queue->tail = node;

	queue->current ++;

	return 0;
}

int linkqueue_dequeue(linkqueue_st *queue, int *value)
{
	linknode_st *tmp = queue->head;

	if (linkqueue_isempty(queue))
		return -1;

	queue->head = tmp->next;
	free(tmp);

	*value = queue->head->data;
	queue->current --;
}

int linkqueue_isfull(linkqueue_st *queue)
{
	if (queue->current >= queue->total)
		return 1;
	return 0;
}

int linkqueue_isempty(linkqueue_st *queue)
{
	if (queue->head == queue->tail)
		return 1;
	return 0;
}

#if DEBUG
void _linkqueue_debug_(linkqueue_st *queue)
{
	linknode_st *p = queue->head->next;

	puts("------------------------ DEBUG ---------------------");
	printf("Total: %d\tCurrent: %d\n", queue->total, queue->current);
	while (NULL != p) {
		printf("%5d", p->data);
		p = p->next;
	}
	puts("\n------------------------------------------------");

}
#endif
