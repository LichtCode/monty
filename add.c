#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _add(stack_t **head, unsigned int counter)
{
	stack_t *new_h;
	int temp, len = 0;

	new_h = *head;
	while (new_h)
	{
		new_h = new_h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_s(*head);
		exit(EXIT_FAILURE);
	}
	new_h = *head;
	temp = new_h->n + new_h->next->n;
	new_h->next->n = temp;
	*head = new_h->next;
	free(new_h);
}
