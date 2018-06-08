#include <stdio.h>
#include <stdlib.h>

#define DEBUG	1

typedef struct _seqstack_ {
	int total;
	int top;
	int *data;
}seqstack_st;

seqstack_st *seqstack_init(int len);
int seqstack_free(seqstack_st *stack);
int seqstack_push(seqstack_st *stack, int value);
int seqstack_pop(seqstack_st *stack, int *buff);
int seqstack_gettop(seqstack_st *stack, int *buff);
inline int seqstack_isfull(seqstack_st *stack);
inline int seqstack_isempty(seqstack_st *stack);
#if DEBUG
int _seqstack_debug_(seqstack_st *stack);
#endif

int main()
{
	seqstack_st *stack = NULL;
	int value = 100;
	int i;
	
	stack = seqstack_init(10);

	while (0 == seqstack_push(stack, value))
		value += 100;
	if (-1 == seqstack_gettop(stack, &value))
		puts("stack empty");
	else
		printf("top data: %d\n", value);
#if DEBUG
	_seqstack_debug_(stack);
#endif

#if 0
	while (0 == seqstack_pop(stack, &value))
		printf("%5d", value);
	putchar('\n');
#else
	for (i = 0; i < 5; i ++) {
		seqstack_pop(stack, &value);
		printf("%5d", value);
	}
	putchar('\n');

	value = 1;
	while (0 == seqstack_push(stack, value))
		value ++;
#endif

#if DEBUG
	_seqstack_debug_(stack);
#endif
	seqstack_free(stack);

	return 0;
}

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
