#include <stdio.h>
#include<stdlib.h>

typedef struct _dlink_node_ {
	int data;
	struct _dlink_node_ *pre;
	struct _dlink_node_ *next;
}dlinknode_st;

typedef struct _dlink_list_ {
	int current;
	int total;
	dlinknode_st *head;
}dlinklist_st;

dlinknode_st *create_dlinknode(int value);
dlinklist_st *dlinklist_init(int len);
int dlinklist_insert(dlinklist_st *list, int value);
int dlinklist_show(dlinklist_st *list);
int dlinklist_free(dlinklist_st *list);
int dlinklist_delete(dlinklist_st *list, int obj);
int dlinklist_modify(dlinklist_st *list, int obj, int value);
int dlinklist_search(dlinklist_st *list, int obj);
dlinknode_st *_dlinklist_locate_(dlinklist_st *list, int obj);

int main()
{
	dlinklist_st *list;
	int value = 100;
	int obj;
	
	list = dlinklist_init(10);
	while (-1 != dlinklist_insert(list, value))
		value += 100;
#if 0	
	dlinklist_modify(list, 100, 2000);

	dlinklist_delete(list, 20000);
	
	obj = 300;
	if (dlinklist_search(list, obj))
		printf("%d ok\n", obj);
	else 
		printf("%d error \n", obj);
#endif
	dlinklist_show(list);
	dlinklist_free(list);
	return 0;
}

dlinklist_st *dlinklist_init(int len)
{
	dlinklist_st *list = NULL;

	list = (dlinklist_st *)malloc(sizeof(dlinklist_st));
	list->current = 0;
	list->total = len;
	list->head = create_dlinknode(0);

	return list;
}

int dlinklist_insert(dlinklist_st *list, int value)
{
	dlinknode_st *new = NULL;

	if (list->current >= list->total)
		return -1;

	new = create_dlinknode(value);
	new->next = list->head->next;
	if (new->next != NULL)
		new->next->pre = new;
	new->pre = list->head;
	list->head->next = new;

	list->current ++;

	return 0;
}

dlinknode_st *create_dlinknode(int value)
{
	dlinknode_st *node = NULL;

	node = (dlinknode_st *)malloc(sizeof(dlinknode_st));
	node->data = value;
	node->next = NULL;
	node->pre = NULL;

	return node;
}

int dlinklist_show(dlinklist_st *list)
{
	int counter = 0;
	dlinknode_st *p = list->head;

#if 0
	if (p->next == NULL)
		return 0;
	do {
		printf("%5d", p->next->data);
		p = p->next;
	} while (p->next != NULL);
#else
	while (p->next != NULL) {
		printf("%5d", p->next->data);
		p = p->next;
	}
	putchar('\n');
#endif

	while (p->pre != NULL) {
		printf("%5d", p->data);
		p = p->pre;
	}
	putchar('\n');
	return counter;
}

int dlinklist_free(dlinklist_st *list)
{
	dlinknode_st *p = list->head;
	dlinknode_st *tmp = NULL;
	
	while (NULL != p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(list);

	return 0;
}

int dlinklist_delete(dlinklist_st *list, int obj)
{
	dlinknode_st *p = NULL;

	if (NULL == (p = _dlinklist_locate_(list, obj)))
		return -1;

	p->pre->next = p->next;
	if (p->next != NULL)
		p->next->pre = p->pre;
	free(p);

	return 0;
}

int dlinklist_modify(dlinklist_st *list, int obj, int value)
{
	dlinknode_st *p = NULL;

	if (NULL == (p = _dlinklist_locate_(list, obj)))
		return -1;
	p->data = value;

	return 0;
}

int dlinklist_search(dlinklist_st *list, int obj)
{
	if (NULL == _dlinklist_locate_(list, obj))
		return 0;
	return 1;
}

dlinknode_st *_dlinklist_locate_(dlinklist_st *list, int obj)
{
	dlinknode_st *p = list->head->next;

	while (NULL != p && p->data != obj)
		p = p->next;
	if (NULL == p)
		return NULL;
	return p;
}
