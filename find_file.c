#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#define BUFSIZE 1024

int _which(char* argv)
{
	char path[BUFSIZE];
	struct stat st;
	int i;
	snprintf(path, BUFSIZE, "%s", argv);
	if (stat(path, &st) == 0)
		printf("%s\n", path);
	else
	{
		char* p = getenv("PATH");
		if (p != NULL)
		{
			char* dir = strtok(p, ":");
			while (dir != NULL)
			{
				snprintf(path, BUFSIZE, "%s/%s", dir, argv[i]);
				if (stat(path, &st) == 0)
				{
					printf("%s\n", path);
					break;
				}
				dir = strtok(NULL, ":");
			}
		}
	}
	return (0);
}
