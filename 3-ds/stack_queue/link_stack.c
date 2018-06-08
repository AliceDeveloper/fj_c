#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

typedef struct _linknode_ {
	int data;
	struct _linknode_ *next;
}linknode_st;

typedef struct _link_stack_{
	int total;
	int current;
	linknode_st *top;
}linkstack_st;

linkstack_st *linkstack_init(int capability);
int linkstack_free(linkstack_st *stack);
int linkstack_push(linkstack_st *stack, int value);
int linkstack_pop(linkstack_st *stack, int *buff);
int linkstack_isfull(linkstack_st *stack);
int linkstack_isempty(linkstack_st *stack);
linknode_st *create_linknode(int value);
int linkstack_gettop(linkstack_st *stack, int *buff);
#if DEBUG
void _linkstack_debug_(linkstack_st *stack);
#endif

int main()
{
	linkstack_st *stack = NULL;
	int value = 100;
	
	stack = linkstack_init(10);
	
	while (-1 != linkstack_push(stack, value))
		value += 100;

	if (0 == linkstack_gettop(stack, &value))
		printf("topvalue: %d\n", value);

#if DEBUG
	_linkstack_debug_(stack);
#endif
	
	while (-1 != linkstack_pop(stack, &value))
		printf("%5d", value);
	putchar('\n');

#if DEBUG
	_linkstack_debug_(stack);
#endif

	linkstack_free(stack);
	return 0;
}

linkstack_st *linkstack_init(int capability)
{
	linkstack_st *stack = NULL;

	stack = (linkstack_st *)malloc(sizeof(linkstack_st));
	stack->total = capability;
	stack->current = 0;
	stack->top = NULL;

	return stack;
}

int linkstack_free(linkstack_st *stack)
{
	linknode_st *p = stack->top;
	linknode_st *tmp = NULL;
	
	while (NULL != p) {
		tmp = p;
		p = tmp->next;
		free(tmp);
	}
	free(stack);

	return 0;
}

int linkstack_push(linkstack_st *stack, int value)
{
	linknode_st *node = NULL;

	if (linkstack_isfull(stack))
		return -1;

	node = create_linknode(value);
	node->next = stack->top;
	stack->top = node;

	stack->current ++;

	return 0;
}

int linkstack_pop(linkstack_st *stack, int *buff)
{
	linknode_st *tmp = NULL;
	
	if (linkstack_isempty(stack))
		return -1;
	
	*buff = stack->top->data;
	stack->current --;

	tmp = stack->top;
	stack->top = tmp->next;
	free(tmp);

	return 0;
}

int linkstack_gettop(linkstack_st *stack, int *buff)
{
	if (linkstack_isempty(stack))
		return -1;

	*buff = stack->top->data;

	return 0;
}

int linkstack_isfull(linkstack_st *stack)
{
	if (stack->current >= stack->total)
		return 1;
	return 0;
}

int linkstack_isempty(linkstack_st *stack)
{
	if (NULL == stack->top)
		return 1;
	return 0;
}

linknode_st *create_linknode(int value)
{
	linknode_st *node = NULL;

	node = (linknode_st *)malloc(sizeof(linknode_st));
	node->data = value;
	node->next = NULL;

	return node;
}

#if DEBUG
void _linkstack_debug_(linkstack_st *stack)
{
	linknode_st *p = stack->top;
	
	puts("--------------------  DEBUG  ----------------------");
	printf("Total: %d\tCurrent: %d\n", stack->total, stack->current);
	while (NULL != p) {
		printf("%5d", p->data);
		p = p->next;
	}
	puts("\n--------------------------------------------------");
	return ;
}
#endif
