#include "monty.h"
/**
 * open_th_file - open a file.
 * @name_of_th_file : the file name.
 *
 * Return: nothing.
 */

void open_th_file(char *name_of_th_file)
{
	FILE *fdd = fopen(name_of_th_file, "r");

	if (name_of_th_file == NULL || fdd == NULL)
		error_find(2, name_of_th_file);

	read_th_file(fdd);
	fclose(fdd);
}


/**
 * read_th_file - read the file.
 * @fdd: ptr to the file descriptor.
 *
 * Return: nothing.
 */

void read_th_file(FILE *fdd)
{
	int lin_nmbr;
	int frmt = 0;
	char *bufr = NULL;
	size_t len_t = 0;

	for (lin_nmbr = 1; getline(&bufr, &len_t, fdd) != -1; lin_nmbr++)
	{
		frmt = prs_th_line(bufr, lin_nmbr, frmt);
	}
	free(bufr);
}


/**
 * prs_th_line - Separate each line into tokens.
 *
 * @bufr: line from the file.
 * @lin_nmbr: it's the line number.
 * @frmt:  storage format; If (0) Nodes will be entered as a stack.
 *
 * if (1) node will be entered as a queue.
 * Return: Return (0) if the opcode is stack & (1) if the opcode is queue.
 */

int prs_th_line(char *bufr, int lin_nmbr, int frmt)
{
	char *valuee;
	char *opcodee;
	const char *dlm = "\n ";

	if (!bufr)
		error_find(4);

	opcodee = strtok(bufr, dlm);
	if (opcodee == NULL)
		return (frmt);
	valuee = strtok(NULL, dlm);

	if (strcmp(opcodee, "stack") == 0)
		return (0);
	if (strcmp(opcodee, "queue") == 0)
		return (1);

	find_th_fnct(opcodee, valuee, lin_nmbr, frmt);
	return (frmt);
}
/**
 * find_th_fnct - find the function for the opcode.
 *
 * @opcodee: the opcode.
 * @valuee: arguments of the opcode.
 * @format:  storage format;If (0) Nodes will be entered as a stack.
 * @lin_nmbr: the line number.
 *
 * if (1) node will be entered as a queue.
 * Return: void or nothing.
 */
void find_th_fnct(char *opcodee, char *valuee, int lin_nmbr, int frmt)
{
	int x, y;

	instruction_t fnct_list[] = {
		{"push", adih_to_st},
		{"pall", print_th_stack},
		{"pint", print_th_top},
		{"pop", pop_th_top},
		{"nop", nop},
		{"swap", swap_th_nodes},
		{"add", add_th_nodes},
		{"sub", sub_th_nodes},
		{"div", div_th_nodes},
		{"mul", mul_th_nodes},
		{"mod", mod_th_nodes},
		{"pchar", print_th_char},
		{"pstr", print_th_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcodee[0] == '#')
		return;
	for (y = 1, x = 0; fnct_list[x].opcodee != NULL; x++)
	{
		if (strcmp(opcodee, fnct_list[x].opcodee) == 0)
		{
			call_th_fnct(fnct_list[x].f, opcodee, valuee, lin_nmbr, frmt);
			y = 0;
		}
	}
	if (y == 1)
		error_find(3, lin_nmbr, opcodee);
}

/**
 * call_th_fnct - Call the required function.
 *
 * @fnct: Pointer to the function that is about to be called.
 * @oprt: the str representing the opcode.
 * @vlu: the str representing a numeric value.
 * @lin_nmbr: the line numeber for the instruction.
 * @frmt: Format specifier;If (0) Nodes will be entered as a stack.
 *
 * if (1) node will be entered as a queue.
 */
void call_fun(oprt_fnct fnct, char *oprt, char *vlu, int lin_nmbr, int frmt)
{
	stack_t *node;
	int y, x;

	y = 1;
	if (strcmp(oprt, "push") == 0)
	{
		if (vlu && vlu[0] == '-')
		{
			vlu += 1;
			y = -1;
		}
		if (vlu == NULL)
			error_find(5, lin_nmbr);

		for (x = 0; vlu[x] != '\0'; x++)
		{
			if (isdigit(vlu[x]) == 0)
				error_find(5, lin_nmbr);
		}
		node = create_a_node(atoi(vlu) * y);
		if (frmt == 0)
			fnct(&node, lin_nmbr);
		if (frmt == 1)
			adih_to_qu(&node, lin_nmbr);
	}
	else
		fnct(&head, lin_nmbr);
}

