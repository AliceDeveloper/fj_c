#include <stdio.h>
#include <stdlib.h>

typedef struct _clinknode_ {
	int data;
	struct _clinknode_ *next;
}clinknode_st;

clinknode_st *joseph_init(int number);
clinknode_st *create_clinknode(int value);
int joseph_show(clinknode_st *head);
clinknode_st *joseph_begin(clinknode_st *head, int rule);
int joseph_free(clinknode_st *head);

int main()
{
	clinknode_st *list = NULL;
	int num, rule;

	puts("input two number:");

	scanf("%d%d", &num, &rule);
	
	list = joseph_init(num);
	list = joseph_begin(list, rule);

	joseph_show(list);
	joseph_free(list);
	return 0;
}

clinknode_st *joseph_init(int number)
{
	clinknode_st *head = NULL;
	clinknode_st *new = NULL;
	int i;

	head = create_clinknode(1);

	for (i = number; i > 1; i --) {
		new = create_clinknode(i);
		new->next = head->next;
		head->next = new;
	}

	return head;
}

clinknode_st *create_clinknode(int value)
{
	clinknode_st *node = NULL;

	node = (clinknode_st *)malloc(sizeof(clinknode_st));
	node->data = value;
	node->next = node;

	return node;
}

int joseph_show(clinknode_st *head)
{
	clinknode_st *p = head;

	if (head == NULL)
		return 0;

	do {
		printf("%5d", p->data);
		p = p->next;
	} while (head != p);
	putchar('\n');

	return 0;
}

clinknode_st *joseph_begin(clinknode_st *head, int rule)
{
	clinknode_st *tmp = NULL;
	int counter;

	for (counter = 1; head->next != head; counter ++) {
		if (counter == rule - 1) {
			tmp = head->next;
			head->next = tmp->next;
			free(tmp);
			counter = 0;
		}
		head = head->next;
	}

	return head;
}

int joseph_free(clinknode_st *head)
{
	free(head);
}
