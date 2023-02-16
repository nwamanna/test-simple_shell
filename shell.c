#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#define BUFSIZE 1024

char *_which(char* argv)
{
	char *ptr = malloc(BUFSIZE);
	char path[BUFSIZE];
	struct stat st;
	if (ptr == NULL)
	{
		perror("malloc");
		free(ptr);
		exit(EXIT_FAILURE);
	}
	snprintf(path, BUFSIZE, "%s", argv);
	if (stat(path, &st) == 0)
	{
		printf(" this is the %s\n", path);
		strcpy(ptr, path);
		return (ptr);
	}
	else
	{
		char* p = getenv("PATH");
		if (p != NULL)
		{
			char* dir = strtok(p, ":");
			while (dir != NULL)
			{
				snprintf(path, BUFSIZE, "%s/%s", dir, argv);
				if (stat(path, &st) == 0)
				{
					printf("this is path %s\n", path);
					strcpy(ptr, path);
					return (ptr);
					break;
				}
				dir = strtok(NULL, ":");
			}
		}
	}
	free(ptr);
	return (NULL);
}
int display()
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}
int main(void)
{
	int i = 1, j, status, result;
//	char *line = NULL;
//	size_t len = 0;
	ssize_t nread;
	char *argv[i + 1];
	const char delim[] = " ";
	char *token;
	pid_t pid;
	char *value;


	while (1)
	{
		char *line = NULL;
		size_t len = 0;
		printf("$ ");
		if ((nread = getline(&line, &len, stdin)) == -1)
		{
			free(line);
			printf("error\n");
		}
		if (line != NULL)
			printf("NON NULL LINE\n");
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		if ((result = strcmp(line, "exit")) == 0)
		{
			free(line);
			break;
		}
		if ((result = strcmp(line, "env")) == 0)
		{
			free(line);
			display();
			continue;
		}
		
		token = strtok(line, delim);
		if (token != NULL)
		{
			printf("token");
//			free(line);
//			free(argv);
		}
		printf("this is the seg\n");
		value = _which(token);
		if (value == NULL)
		{
			free(line);
			free(value);
			printf("empty value\n");
			exit(99);
		}
		printf("this is the value - %s\n", value);
		argv[0] = value;
//		free(value);
		token = strtok(NULL, delim);
//		while (token != NULL)
//		{
//			argv[i] = token;
//			printf("This is token %s" 		"%d\n", argv[i], i);
//			token = strtok(NULL, delim);
//			i++;
//		}
		argv[i] = NULL;
		for (j = 0; argv[j] != NULL; j++)
			printf("This is the number %d array element -- %s", j, argv[j]);
		pid = fork();
		if (pid == -1)
		{
			free(argv[0]);
			free(line);
			free(value);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(argv[0],argv, NULL) == -1)
			{
				printf("something is wrong");
				perror("Error");
				free(argv);
				free(value);
				free(line);
				exit(EXIT_FAILURE);
			}
			free(argv);
			free(value);
			free(line);
			line = NULL;
			len = 0;

		}
		else
		{
			wait(&status);
//			free(argv);
			free(value);
			free(line);
			line = NULL;
			len = 0;
		}
	
	
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
	}
}
