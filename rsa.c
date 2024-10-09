#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <inttypes.h> /* for PRIu64*/
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
	uint64_t i, num;

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
		num = strtoull(buffer, NULL, 10);
		for (i = 2; i <= (uint64_t)sqrt(num); i++)
		{
			if (num % i == 0)
			{
				dprintf(STDOUT_FILENO, "%" PRIu64 "=%" PRIu64 "*%" PRIu64 "\n", num, num / i, i);
				break;
			}
		}

	}
	fclose(file);
	return (0);
}
