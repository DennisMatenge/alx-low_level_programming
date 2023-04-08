#include "main.h"

/**
* read_textfile - reads a text file and prints its contents to stdout
* @filename: the name of the file to read
* @letters: the maximum number of characters to read
*
* Return: the number of characters read and printed, or 0 if an error occurs
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t nread, nwritten;
char *buffer;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
{
close(fd);
return (0);
}

nread = read(fd, buffer, letters);
if (nread == -1)
{
free(buffer);
close(fd);
return (0);
}

nwritten = write(STDOUT_FILENO, buffer, nread);
if (nwritten == -1 || nwritten != nread)
{
free(buffer);
close(fd);
return (0);
}

free(buffer);
close(fd);

return (nwritten);
}

