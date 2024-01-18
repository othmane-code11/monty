#include "monty.h"

stack_t *head = NULL;

/**
 * main - monty code interpreter.
 * @argc: num of arguments.
 * @argv: monty file location.
 *
 * Return: always 0 (seccess).
 **/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_th_file(argv[1]);
	free_th_nodes();
	return (0);
}
/**
 * create_a_node - Creates a newnode.
 * @num: Numbr with it go inside the node.
 *
 * Return: if success a pointer to the node. Otherwise a NULL.
 **/

stack_t *create_a_node(int num)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
		error_find(4);

	node->prev = NULL;
	node->next = NULL;
	node->num = num;

	return (node);
}
/**
 * free_th_nodes - Free the nodes in the stack.
 **/
void free_th_nodes(void)
{
	stack_t *t;

	if (!head)
		return;
	while (head)
	{
		t = head;
		head = head->next;
		free(t);
	}
}


/**
 * adih_to_qu - Add_liya a node to the queue.
 * @nwnode: Ptr to the new node.
 * @line_num: line numbr of the opcode.
 **/
void adih_to_qu(stack_t **nwnode, __attribute__((unused))unsigned int line_num)
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
	while (t->next != NULL)
	{
		t = t->next;
	}
	t->next = *nwnode;
	(*nwnode)->prev = t;

}

