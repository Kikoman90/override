#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv, char **envp)
{
	char	**av = argv;
	char	**ep = envp;
	int	ret = 0;
	char	input[20] = {0};
	char	buff[100] = {0};

	while (*av)
	{
		memset(*av, 0, strlen(*av));
		av++;
	}
	while (*ep)
	{
		memset(*ep, 0, strlen(*ep));
		ep++;
	}
	puts("----------------------------------------------------\n  Welcome to wil's crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n");
	printf("Input command: ");
	fgets(input, 20, stdin);
	input[strlen(input) - 1] = 0;	
}
