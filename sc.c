#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;


	printf("$ ");
	if ((nread = getline(&line, &len, stdin)) == -1)
	{
		printf("error\n");
	}
	printf("%s", line);
	
	if (feof(stdin))
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
}
