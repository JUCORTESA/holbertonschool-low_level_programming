#include "holberton.h"
/**
 * cp - copy a file
 * @from: file to copy
 * @to: file to copy in
 */

void cp(const char *from, char *to)
{
	int file_r, file_w, r;
	int close1, close2;
	char buff[1024];

	file_r = open(from, O_RDONLY);
	if (file_r == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", from);
		exit(98);
	}
	r = read(file_r, buff, 1024);
	if (r == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", from);
		exit(98);
	}
	file_w = open(to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_w == -1)
	{
		dprintf(2, "Error: Can't write to %s", from);
		exit(99);
	}
	while (r != 0)
	{
		write(file_w, buff, r);
		r = read(file_r, buff, 1024);
	}
	close1 = close(file_w);
	if (close1 == -1)
	{
	dprintf(2, "Error: Can't close fd %d\n", file_w);
	exit(100);
	}
	close2 = close(file_r);
	if (close2 == -1)
	{
	dprintf(2, "Error: Can't close fd %d\n", file_r);
	exit(100);
	}
}
/**
 * main - copy a file into another
 * @argc: size
 * @argv: character.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{

	if (argc != 3)
	{
	dprintf(2, "Usage: cp file_from file_to\n");
	exit(97);
	}
	if (argv[1] == NULL)
	{
	dprintf(2, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	}
	cp(argv[1], argv[2]);
	return (0);
}
