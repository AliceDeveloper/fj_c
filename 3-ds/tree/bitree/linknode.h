#ifndef __LINKNODE_H__
#define __LINKNODE_H__

#include "bitnode.h"
#include <stdlib.h>

typedef bitnode_st * lndata_st;

typedef struct _linknode_ {
	lndata_st data;
	struct _linknode_ *next;
}linknode_st;

linknode_st *create_linknode(lndata_st value);

#endif /* __LINKNODE_H__*/
