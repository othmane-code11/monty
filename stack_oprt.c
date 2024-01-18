nclude "monty.h"


/**
 * mod_th_nodes - Mod the top two elements of the stack.
 *
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode.
 **/
void mod_th_nodes(stack_t **stck, unsigned int lin_nmbr)
{
	int somme;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)

	error_more(8, lin_nmbr, "mod");

	if ((*stck)->n == 0)
		error_more(9, lin_nmbr);
	(*stck) = (*stck)->next;
	somme = (*stck)->n % (*stck)->prev->n;
	(*stck)->n = somme;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}

/**
 * mul_th_nodes - Mult the top two elements of the stack.
 * @stck: Ptr to a ptr pointing to node of the stack.
 * @lin_nmbr: line number of the opcode.
 **/
void mul_th_nodes(stack_t **stck, unsigned int lin_nmbr)
{
	int somme;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		error_more(8, lin_nmbr, "mul");

	(*stck) = (*stck)->next;
	somme = (*stck)->n * (*stck)->prev->n;
	(*stck)->n = somme;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}

