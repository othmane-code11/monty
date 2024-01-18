#include "monty.h"


/**
 * print_th_str - Print a string.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode.
 **/
void print_th_str(stack_t **stck, __attribute__((unused))unsigned int lin_nmbr)
{
	int ascii_codee;
	stack_t *t;

	if (stck == NULL || *stck == NULL)
	{
		printf("\n");
		return;
	}

	t = *stck;
	while (t)
	{
		ascii_codee = t->n;
		if (ascii_codee <= 0 || ascii_codee > 127)
			break;
		printf("%c", ascii_codee);
		t = t->next;													}
	printf("\n");
}
/**
 * print_th_char - Print the Ascii value.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode
 **/
void print_th_char(stack_t **stck, unsigned int lin_nmbr)
{
	int ascii_codee;

	if (stck == NULL || *stck == NULL)
		error_of_th_string(11, lin_nmbr);
	ascii_codee = (*stck)->n;
	if (ascii_codee < 0 || ascii_codee > 127)
		error_of_th_string(10, lin_nmbr);

	printf("%c\n", ascii_codee);
}

/**
 * rotr - Rotates the last_node of the stack to the top.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode.
 **/
void rotr(stack_t **stck, __attribute__((unused))unsigned int lin_nmbr)
{
	stack_t *t;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		return;

	t = *stck;

	while (t->next != NULL)
		t = t->next;

	t->next = *stck;
	t->prev->next = NULL;
	t->prev = NULL;
	(*stck)->prev = t;
	(*stck) = t;
}

/**
 * rotl - Rotates the first_node of the stack to the bottom.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode.
 **/
void rotl(stack_t **stck, __attribute__((unused))unsigned int lin_nmbr)
{
	stack_t *t;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		return;

	t = *stck;
	while (t->next != NULL)
		t = t->next;

	t->next = *stck;
	(*stck)->prev = t;
	*stck = (*stck)->next;
	(*stck)->prev->next = NULL;
	(*stck)->prev = NULL;
}

