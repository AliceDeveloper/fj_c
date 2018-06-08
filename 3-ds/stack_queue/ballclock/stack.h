#ifndef __STACK_H__
#define __STACK_H__

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

#endif /* __STACK_H__ */
