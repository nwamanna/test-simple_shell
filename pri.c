#include <stdio.h>
#include <stdarg.h>
int main(int ac, char **av)
{
	(void)ac;
	av++;
	while (*av != NULL)
	{
		printf("%s\n", *av++);
	}
	return (0);
}


