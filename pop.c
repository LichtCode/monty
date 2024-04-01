#include "monty.h"
/**
 * _pop - the function prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _pop(stack_t **head, unsigned int counter)
{
	stack_t *new_h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	new_h = *head;
	*head = new_h->next;
	free(new_h);
}
