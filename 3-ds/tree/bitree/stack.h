#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include "linknode.h"

#define DEBUG 0


typedef struct _link_stack_{
	int total;
	int current;
	linknode_st *top;
}linkstack_st;

linkstack_st *linkstack_init(int capability);
int linkstack_free(linkstack_st *stack);
int linkstack_push(linkstack_st *stack, lndata_st value);
int linkstack_pop(linkstack_st *stack, lndata_st *buff);
int linkstack_isfull(linkstack_st *stack);
int linkstack_isempty(linkstack_st *stack);
int linkstack_gettop(linkstack_st *stack, lndata_st *buff);
#if DEBUG
void _linkstack_debug_(lndata_st *stack);
#endif

#endif /* __STACK_H__ */
