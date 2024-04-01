#include "monty.h"
/**
 * _pall - the function prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void _pall(stack_t **head, unsigned int counter)
{
	stack_t *new_h;
	(void)counter;

	new_h = *head;
	if (new_h == NULL)
		return;
	while (new_h)
	{
		printf("%d\n", new_h->n);
		new_h = new_h->next;
	}
}
