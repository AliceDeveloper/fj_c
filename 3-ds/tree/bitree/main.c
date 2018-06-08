#include <stdio.h>
#include <stdlib.h>
#include "bitnode.h"
#include "queue.h"
#include "stack.h"

bitnode_st *create_bitnode(int value);
bitnode_st *bitree_init(int start, int end);
int bitree_free(bitnode_st *root);
int bitree_preorder(bitnode_st *root);
int bitree_inorder(bitnode_st *root);
int bitree_postorder(bitnode_st *root);
int bitree_numorder(bitnode_st *root);

int main()
{
	bitnode_st *root = NULL;

	root = bitree_init(1, 10);

	puts("PreOrder:");
	bitree_preorder(root);
	putchar('\n');

	puts("InOrder:");
	bitree_inorder(root);
	putchar('\n');

	puts("PostOrder:");
	bitree_postorder(root);
	putchar('\n');

	puts("NumOrder:");
	bitree_numorder(root);
	putchar('\n');
	
	bitree_free(root);

	return 0;
}

bitnode_st *create_bitnode(int value)
{
	bitnode_st *node = NULL;

	node = (bitnode_st *)malloc(sizeof(bitnode_st));
	node->data = value;
	node->lchild = NULL;
	node->rchild = NULL;

	return node;
}

bitnode_st *bitree_init(int start, int end)
{
	bitnode_st *root = NULL;
	
	root = create_bitnode(start);

	if (start * 2 <= end)
		root->lchild = bitree_init(start * 2, end);
	if (start * 2 + 1 <= end)
		root->rchild = bitree_init(start * 2 + 1, end);
	return root;
}

int bitree_free(bitnode_st *root)
{
	if (root->lchild != NULL)
		bitree_free(root->lchild);
	if (root->rchild != NULL)
		bitree_free(root->rchild);
	free(root);

	return 0;
}

#if 0
int bitree_preorder(bitnode_st *root)
{
	printf("%5d", root->data);
	if (root->lchild != NULL)
		bitree_preorder(root->lchild);
	if (root->rchild != NULL)
		bitree_preorder(root->rchild);

	return 0;
}
#else
int bitree_preorder(bitnode_st *root)
{
	linkstack_st *stack = NULL;
	
	stack = linkstack_init(100);
	linkstack_push(stack, root);

	while (!linkstack_isempty(stack)) {
		if (NULL != root) {
			printf("%5d", root->data);
			linkstack_push(stack, root);
			root = root->lchild;
		}else {
			linkstack_pop(stack, &root);
			root = root->rchild;
		}
	}

	linkstack_free(stack);
	return 0;	
}

#endif

int bitree_inorder(bitnode_st *root)
{
	if (root->lchild != NULL)
		bitree_inorder(root->lchild);
	printf("%5d", root->data);
	if (root->rchild != NULL)
		bitree_inorder(root->rchild);

	return 0;
}

int bitree_postorder(bitnode_st *root)
{
	if (root == NULL)
		return 0;
	bitree_postorder(root->lchild);
	bitree_postorder(root->rchild);
	printf("%5d", root->data);

	return 0;
}

int bitree_numorder(bitnode_st *root)
{	
	linkqueue_st *queue = NULL;

	queue = linkqueue_init(10);
	linkqueue_enqueue(queue, root);

	while (!linkqueue_isempty(queue)) {
		linkqueue_dequeue(queue, &root);
		printf("%5d", root->data);
		if (NULL != root->lchild)
			linkqueue_enqueue(queue, root->lchild);
		if (NULL != root->rchild)
			linkqueue_enqueue(queue, root->rchild);
	}

	linkqueue_free(queue);

	return 0;
}

