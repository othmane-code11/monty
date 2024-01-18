#include "monty.h"

/**
 * nop - Does nothing.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode.
 **/

void nop(stack_t **stck, unsigned int lin_nmbr)
{
	(void)stck;
	(void)lin_nmbr;
}
/**
 * swap_th_nodes - Swap the top two elements of the stack.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode
 **/
void swap_th_nodes(stack_t **stck, unsigned int lin_nmbr)
{
	stack_t *t;

	if (!stck || *stck == NULL || (*stck)->next == NULL)
		error_more(8, lin_nmbr, "swap");
	t = (*stck)->next;
	(*stck)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *stck;
	t->next = *stck;
	(*stck)->prev = t;
	t->prev = NULL;
	*stck = t;
}


/**
 * div_th_nodes - Adds the top two elements of the stack.
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode
 **/
void div_th_nodes(stack_t **stck, unsigned int lin_nmbr)
{
	int somme;

	if (!stck || *stck == NULL || (*stck)->next == NULL)
		error_more(8, lin_nmbr, "div");

	if ((*stck)->n == 0)
		error_more(9, lin_nmbr);
	(*stck) = (*stck)->next;
	somme = (*stck)->n / (*stck)->prev->n;
	(*stck)->n = somme;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
/**
 * add_th_nodes - Add the top two elements of the stack.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode
 **/
void add_th_nodes(stack_t **stck, unsigned int lin_nmbr)
{
	int somme;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		error_more(8, lin_nmbr, "add");

	(*stck) = (*stck)->next;
	somme = (*stck)->n + (*stck)->prev->n;
	(*stck)->n = somme;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
/**
 * sub_th_nodes - Sub the top two elements of the stack.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode
 **/
void sub_th_nodes(stack_t **stck, unsigned int lin_nmbr)
{
	int somme;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		error_more(8, lin_nmbr, "sub");

	(*stck) = (*stck)->next;
	somme = (*stck)->n - (*stck)->prev->n;
	(*stck)->n = somme;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}

