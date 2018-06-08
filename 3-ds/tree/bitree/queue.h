#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "linknode.h"

#define DEBUG	0

typedef struct _linkqueue_ {
	int total;
	int current;
	linknode_st *head,
				*tail;
}linkqueue_st;

linkqueue_st *linkqueue_init(int len);
int linkqueue_free(linkqueue_st *queue);
int linkqueue_enqueue(linkqueue_st *queue, lndata_st value);
int linkqueue_dequeue(linkqueue_st *queue, lndata_st *value);
int linkqueue_isfull(linkqueue_st *queue);
int linkqueue_isempty(linkqueue_st *queue);
#if DEBUG
void _linkqueue_debug_(linkqueue_st *queue);
#endif

#endif /* __QUEUE_H__ */
