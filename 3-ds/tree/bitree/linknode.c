#include "linknode.h"

linknode_st *create_linknode(lndata_st value)
{
	linknode_st *node = NULL;

	node = (linknode_st *)malloc(sizeof(linknode_st));
	node->data = value;
	node->next = NULL;

	return node;
}
