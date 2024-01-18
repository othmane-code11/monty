#include "monty.h"

/**
 * adih_to_st - Add a node to the stack.
 *
 * @nwnode: Ptr to the new node.
 * @lin_nmbr: Int that represent the line number of of the opcode.
 */
void adih_to_st(stack_t **nwnode, __attribute__((unused))unsigned int lin_nmbr)
{
	stack_t *t;

	if (!nwnode || *nwnode == NULL)
		exit(EXIT_FAILURE);

	if (!head)
	{
		head = *nwnode;
		return;
	}
	t = head;
	head = *nwnode;
	head->next = t;
	t->prev = head;
}


/**
 * print_th_stack - Print a node from the stack.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode.
 */
void print_th_stack(stack_t **stck, unsigned int lin_nmbr)
{
	stack_t *t;

	(void) lin_nmbr;
	if (stck == NULL)
		exit(EXIT_FAILURE);

	t = *stck;
	while (t)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}

/**
 * print_th_top - Print the top node of the stack.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode.
 */
void print_th_top(stack_t **stck, unsigned int lin_nmbr)
{
	if (stck == NULL || *stck == NULL)
		error_more(6, lin_nmbr);
	printf("%d\n", (*stck)->n);
}

/**
 * pop_th_top - Pop a node to the stack.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode.
 */
void pop_th_top(stack_t **stck, unsigned int lin_nmbr)
{
	stack_t *t;

	if (stck == NULL || *stck == NULL)
		error_more(7, lin_nmbr);

	t = *stck;
	*stck = t->next;
	if (*stck)
		(*stck)->prev = NULL;
	free(t);
}
