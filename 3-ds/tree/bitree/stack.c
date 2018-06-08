#include "stack.h"

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

int linkstack_push(linkstack_st *stack, lndata_st value)
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

int linkstack_pop(linkstack_st *stack, lndata_st *buff)
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

int linkstack_gettop(linkstack_st *stack, lndata_st *buff)
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
