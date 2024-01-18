#include "monty.h"

/**
 * error_find - Print an error message determined by the error code.
 *
 * @err_of_code: The error codes are in the following lignes.
 * (1) --> The user doesn't give any file or more than 1 file to the program.
 * (2) --> The file provided isn't a file that can be read or opened.
 * (3) --> The file prvdd contains an "invalid instruction".
 * (4) --> When the progrm is unable to malloc more memory.
 * (5) --> When the parametr passed to the instruction ''push''.
 */
void error_find(int err_of_code, ...)
{
	va_list argtm;
	int line_numbr;
	char *oprt;

	va_start(argtm, err_of_code);
	switch (err_of_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argtm, char *));
			break;
		case 3:
			line_numbr = va_arg(argtm, int);
			oprt = va_arg(argtm, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_numbr, oprt);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argtm, int));
			break;
		default:
			break;
	}

	free_th_nodes();
	exit(EXIT_FAILURE);
}

/**
 * error_more - handles the errors.
 * @err_of_code: The error codes are in the following lignes.
 *
 * (6) --> When the stack it empty (khawi) for pint.
 * (7) --> When the stack it empty (khawi) for pop.
 * (8) --> When stack is  short for operation.
 * (9) --> Division by zero (impostahil).
 */
void error_more(int err_of_code, ...)
{
	va_list argtm;
	char *oprt;
	int line_numbr;

	va_start(argtm, err_of_code);

	switch (err_of_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argtm, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argtm, int));
			break;
		case 8:
			line_numbr = va_arg(argtm, unsigned int);
			oprt = va_arg(argtm, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_numbr, oprt);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argtm, unsigned int));
			break;
		default:
			break;
	}

	free_th_nodes();
	exit(EXIT_FAILURE);
}

/**
 * error_of_th_str - handles the errors.
 *
 * @err_of_code: The error codes are the following:
 * (10) --> The numbr inside the node is outside ASCII bounds.
 * (11) --> The stack is empty(khawi).
 */

void error_of_th_str(int err_of_code, ...)
{
	va_list argtm;
	int line_numbr;

	va_start(argtm, err_of_code);
	line_numbr = va_arg(argtm, int);

	switch (err_of_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_numbr);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_numbr);
			break;
		default:
			break;
	}
	free_th_nodes();

	exit(EXIT_FAILURE);
}

