#ifndef __QUEUE_H__
#define __QUEUE_H__

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

#endif	/* __QUEUE_H__ */
