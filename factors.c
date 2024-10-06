#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
/**
 * main - Factorize as many numbers as possible into
 * a product of two smaller numbers
 * @argc: command line arguments count
 * @argv: commmand line arguments vector
 * Return: void
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char buffer[1024];
	unsigned long long int i, num;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		num = strtoull(buffer);
		for (i = 2; i <= sqrt(num); i++)
		{
			if (num % i == 0)
			{
				dprintf(STDOUT_FILENO, "%llu=%llu*%llu\n", num, num / i, i);
				break;
			}
		}

	}
	fclose(file);
	return (0);
}
