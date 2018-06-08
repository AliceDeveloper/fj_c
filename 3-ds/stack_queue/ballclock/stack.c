#include "stack.h"

seqstack_st *seqstack_init(int len)
{
	seqstack_st *stack = NULL;

	stack = (seqstack_st *)malloc(sizeof(seqstack_st));
	stack->total = len;
	stack->top = 0;
	stack->data = (int *)malloc(sizeof(int) * len);

	return stack;
}

int seqstack_free(seqstack_st *stack)
{
	free(stack->data);
	free(stack);

	return 0;
}

inline int seqstack_isfull(seqstack_st *stack)
{
	if (stack->top >= stack->total)
		return 1;
	return 0;
}

inline int seqstack_isempty(seqstack_st *stack)
{
	if (stack->top <= 0)
		return 1;
	return 0;
}

int seqstack_push(seqstack_st *stack, int value)
{
	if (seqstack_isfull(stack))
		return -1;
	stack->data[stack->top ++] = value;

	return 0;
}

int seqstack_pop(seqstack_st *stack, int *buff)
{
	if (seqstack_isempty(stack))
		return -1;
	*buff = stack->data[--stack->top];

	return 0;
}

int seqstack_gettop(seqstack_st *stack, int *buff)
{
	if (seqstack_isempty(stack))
		return -1;
	*buff = stack->data[stack->top - 1];
	return 0;
}

#if DEBUG
int _seqstack_debug_(seqstack_st *stack)
{
	int index;
	
	printf("Total: %d\tTop: %d\n", stack->total, stack->top);
	for (index = 0; index < stack->total; index ++)
		printf("%5d", stack->data[index]);
	putchar('\n');

	return 0;
}
#endif
