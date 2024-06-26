#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - the monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *content;
	size_t size = 0;
	ssize_t user_input = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (user_input > 0)
	{
		content = NULL;
		user_input = getline(&content, &size, file);
		bus.content = content;
		count++;
		if (user_input > 0)
		{
			execute(content, &stack, count, file);
		}
		free(content);
	}
	free_s(stack);
	fclose(file);
return (0);
}
