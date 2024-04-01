#include "monty.h"
/**
 * _pchar - the function prints the char at the top
 * of the stack, followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _pchar(stack_t **head, unsigned int counter)
{
	stack_t *new_h;

	new_h = *head;
	if (!new_h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	if (new_h->n > 127 || new_h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", new_h->n);
}
