#include "queue.h"
#include "stack.h"

#define QUE_LEN	27
#define STK_SIZE_M1	4
#define STK_SIZE_M5	11
#define STK_SIZE_H1	11

int queue_check_ok(linkqueue_st *queue);

int main()
{
	int ball;
	int tmp;
	int timer = 0;
	linkqueue_st *queue = NULL;
	seqstack_st *stk_m1 = NULL,
				*stk_m5 = NULL,
				*stk_h1 = NULL;
	
	queue = linkqueue_init(QUE_LEN);
	stk_m1 = seqstack_init(STK_SIZE_M1);
	stk_m5 = seqstack_init(STK_SIZE_M5);
	stk_h1 = seqstack_init(STK_SIZE_H1);

	for (ball = 1; ball <= QUE_LEN; ball ++)
		linkqueue_enqueue(queue, ball);

	while (1) {
		linkqueue_dequeue(queue, &ball);
		
		if (0 == seqstack_push(stk_m1, ball))
			continue;
		while (0 == seqstack_pop(stk_m1, &tmp))
			linkqueue_enqueue(queue, tmp);

		if (0 == seqstack_push(stk_m5, ball))
			continue;
		while (0 == seqstack_pop(stk_m5, &tmp))
			linkqueue_enqueue(queue, tmp);

		if (0 == seqstack_push(stk_h1, ball))
			continue;
		while (0 == seqstack_pop(stk_h1, &tmp))
			linkqueue_enqueue(queue, tmp);

		linkqueue_enqueue(queue, ball);
		timer ++;
	
		_linkqueue_debug_(queue);
		if (queue_check_ok(queue))
			break;
	}

	printf("%dd-%dh\n", timer / 2, (timer % 2) * 12);

	seqstack_free(stk_m1);
	seqstack_free(stk_m5);
	seqstack_free(stk_h1);
	linkqueue_free(queue);
	return 0;
}

int queue_check_ok(linkqueue_st *queue)
{
	linknode_st *p = queue->head->next;

	while (NULL != p && p->next != NULL) {
		if (p->data > p->next->data)
			return 0;
		p = p->next;
	}
	return 1;
}
