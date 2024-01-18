#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcodee: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcodee;
	void (*f)(stack_t **stck, unsigned int lin_nmbr);
} instruction_t;

extern stack_t *head;
typedef void (*oprt_fnct)(stack_t **, unsigned int);

/*file operations*/
void open_th_file(char *name_of_th_file);
int prs_th_line(char *bufr, int lin_nmbr, int frmt);
void read_th_file(FILE *);
int len_chars(FILE *);
void find_th_fnct(char *, char *, int, int);

/*Stack operations*/
stack_t *create_a_node(int num);
void free_th_nodes(void);
void print_th_stack(stack_t **, unsigned int);
void adih_to_st(stack_t **, unsigned int);
void adih_to_qu(stack_t **, unsigned int);

void call_th_fnct(oprt_fnct, char *, char *, int, int);

void print_th_top(stack_t **, unsigned int);
void pop_th_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_th_nodes(stack_t **, unsigned int);

void add_th_nodes(stack_t **, unsigned int);
void sub_th_nodes(stack_t **, unsigned int);
void div_th_nodes(stack_t **, unsigned int);
void mul_th_nodes(stack_t **, unsigned int);
void mod_th_nodes(stack_t **, unsigned int);

void print_th_char(stack_t **, unsigned int);
void print_th_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

void error_find(int err_of_code, ...);
void error_more(int err_of_code, ...);
void error_of_th_str(int err_of_code, ...);
void rotr(stack_t **, unsigned int);

#endif

