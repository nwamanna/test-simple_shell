#include <stdlib.h>
#include <stdio.h>

int display()
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print("%s\n", environ[i]);
	}
	return (0);
}
