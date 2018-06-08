#include <stdio.h>
#include <stdlib.h>

typedef struct _bitree_node_{
	int data;
	struct _bitree_node_ *lchild,
						 *rchild;
}bitnode_st;

bitnode_st *bitree_create(void);
int inorder(bitnode_st *root);
bitnode_st *create_bitnode(int value);
int insert_bitnode(bitnode_st **root, int value);
bitnode_st * search_bitnode(bitnode_st *root, int obj);

int main()
{
	bitnode_st *root = NULL;
	int value;
	bitnode_st *p;

	root = bitree_create();
	inorder(root);
	puts("\ninput number:");
	scanf("%d",&value);
	p = search_bitnode(root, value);
	if(p == NULL)
		printf("%d not found !\n", value);
	else
		printf("%p->%d\n", p, p->data);
	return 0;
}

int insert_bitnode(bitnode_st **root, int value)
{
	bitnode_st *p = *root,
			*site = NULL;
	puts("-----------");
	
	while(NULL != p)
	{
		if(value == p->data)
			return 0;
		site = p;
		p = value > p->data ? p->rchild : p->lchild;
	}

	p = create_bitnode(value);
	if(NULL == *root)
		*root = p;
	else if(value < site->data)
		site->lchild = p;
	else
		site->rchild = p;

	return 0;
}


bitnode_st *bitree_create(void)
{
	int value;
	bitnode_st *root = NULL;

	while(1)
	{
		while( 1 != scanf("%d", &value))
			getchar();
		if(value == 0)
			break;
		
		insert_bitnode(&root, value);
	}
	return root;
}

int inorder(bitnode_st *root)
{
	if(root == NULL)
		return -1;
	inorder(root->lchild);
	printf("%3d ", root->data);
	inorder(root->rchild);

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

bitnode_st * search_bitnode(bitnode_st *root, int obj)
{
	bitnode_st *p = root;

	while(p != NULL && p->data != obj)
	{
		if(obj < p->data)
			p = p->lchild;
		else
			p = p->rchild;
	}
	return p;
}
