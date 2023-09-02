#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main- factoring
 *
 * Return: 0 Always
 */
int main(int argc, char *argv[])
{
	char line[100];
	int i;
	int num;
	FILE *file;

	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return (1);
	}
	if (access(argv[1], F_OK) == -1)
	{
		printf("File does not exist\n");
		return (1);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Error opening file\n");
		return (1);
	}
	while (fgets(line, sizeof(line), file))
	{
		num = atoi(line);
		for (i = 2; i <= num / 2; i++)
		{
			if (num % i == 0)
			{
				printf("%d=%d*%d\n", num, i, num / i);
				break;
			}
		}
	}

	fclose(file);
	return (0);
}
