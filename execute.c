#include "monty.h"

/**
* execute -  the function executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	unsigned int i = 0;
	char *optn;
	instruction_t opst[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop}, {"swap", _swap}, {"add", _add}, {"nop", _nop},
				{"sub", _sub}, {"div", _div}, {"mul", _mul},
				{"mod", _mod}, {"pchar", _pchar}, {"pstr", _pstr},
				{NULL, NULL}
				};


	optn = strtok(content, " \n\t");
	if (optn && optn[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && optn)
	{
		if (strcmp(optn, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (optn && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, optn);
		fclose(file);
		free(content);
		free_s(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
* free_s - the function frees a doubly linked list
* @head: head of the stack
*/
void free_s(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}