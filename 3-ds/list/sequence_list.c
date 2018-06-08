#include <stdio.h>
#include <stdlib.h>

typedef struct _seqlist_{
	int current;
	int total;
	int *data;
}seqlist_st;

seqlist_st *seqlist_init(int len);
int seqlist_free(seqlist_st *list);
int seqlist_insert(seqlist_st *list, int value);
int seqlist_show(seqlist_st *list);
int _seqlist_locate_(seqlist_st *list, int obj);
int seqlist_search(seqlist_st *list, int value);
int seqlist_modify(seqlist_st *list, int obj, int value);
int seqlist_delete(seqlist_st *list, int obj);

int main(int argc, const char *argv[])
{
	int num = 100;
	seqlist_st *list = NULL;
	int value;

	list = seqlist_init(10);

	while (-1 != seqlist_insert(list, num)) {
		num ++;
	}

	value = 1001;
	if (seqlist_search(list, value))
		printf("%d exists\n", value);
	else
		printf("%d NOT exists\n", value);
	
	seqlist_modify(list, 1090, 100);

	seqlist_delete(list, 1090);

	seqlist_show(list);
	seqlist_free(list);
	return 0;
}

seqlist_st *seqlist_init(int len)
{
	seqlist_st *list = NULL;

	list = (seqlist_st *)malloc(sizeof(seqlist_st));
	list->current = 0;
	list->total = len;
	list->data = (int *)malloc(sizeof(int) * len);

	return list;
}


int seqlist_free(seqlist_st *list)
{
	free(list->data);
	free(list);

	return 0;
}

int seqlist_insert(seqlist_st *list, int value)
{
	if (list->current >= list->total)
		return -1;
	list->data[list->current++] = value;

	return 0;
}

int seqlist_show(seqlist_st *list)
{
	int index;
	
	printf("Total: %d\t Current: %d\n", list->total, list->current);

	for (index = 0; index < list->current; index ++)
		printf("%5d", list->data[index]);
	putchar('\n');

	return 0;
}

int _seqlist_locate_(seqlist_st *list, int obj)
{
	int index;

	for (index = 0; index < list->current; index ++) {
		if (list->data[index] == obj)
			return index;
	}
	return -1;
}

int seqlist_search(seqlist_st *list, int value)
{
	if (-1 == _seqlist_locate_(list, value))
		return 0;
	return 1;
}

int seqlist_modify(seqlist_st *list, int obj, int value)
{
	int position;
	
	if (-1 == (position = _seqlist_locate_(list, obj)))
		return -1;
	list->data[position] = value;

	return 0;
}

int seqlist_delete(seqlist_st *list, int obj)
{
	int position;
	int index;

	if (-1 == (position = _seqlist_locate_(list, obj)))
		return -1;

	for (index = position; index < list->current - 1; index ++)
		list->data[index] = list->data[index + 1];
	list->current --;

	return 0;
}
