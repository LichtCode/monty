#include "monty.h"
/**
 * _pstr - the function prints the string starting at the
 * top of the stack, followed by a new
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _pstr(stack_t **head, unsigned int counter)
{
	stack_t *new_h;
	(void)counter;

	new_h = *head;
	while (new_h)
	{
		if (new_h->n > 127 || new_h->n <= 0)
		{
			break;
		}
		printf("%c", new_h->n);
		new_h = new_h->next;
	}
	printf("\n");
}
