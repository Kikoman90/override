#include <stdio.h>
#include <string.h>

void		clear_stdin(void)
{
	unsigned char c = 0;

	while (c != '\n' && c != (unsigned char)EOF)
		c = (unsigned char)getchar();
}

unsigned int	get_unum(void)
{
	unsigned int unum = 0;
	
	fflush(stdout);
	scanf("%u", &unum);
	clear_stdin();
	return (unum);
}

unsigned int	store_number(unsigned int *buffer)
{
	unsigned int num, idx = 0;

	printf(" Number: ");
	num = get_unum();
	printf(" Index: ");
	idx = get_unum();
	if (idx % 3 == 0 || (num >> 24) == 183)
	{
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (1);
	}
	buffer[idx] = num;
	return (0);
}

int		read_number(unsigned int *buffer)
{
	unsigned int idx = 0;
	
	printf(" Index: ");
	idx = get_unum();
	printf(" Number at data[%u] is %u\n", idx, buffer[idx]);
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	char		**av = argv;
	char		**ep = envp;
	unsigned int	ret = 0;
	char		input[20] = {0};
	unsigned int	tab[100] = {0};

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
	puts(	"----------------------------------------------------\n"\
		"  Welcome to wil's crappy number storage service!   \n"\
		"----------------------------------------------------\n"\
	       	" Commands:                                          \n"\
	    	"    store - store a number into the data storage    \n"\
	    	"    read  - read a number from the data storage     \n"\
	    	"    quit  - exit the program                        \n"\
		"----------------------------------------------------\n"\
	     	"   wil has reserved some storage :>                 \n"\
		"----------------------------------------------------\n");
	while (1)
	{
		printf("Input command: ");
		ret = 1;
		fgets(input, 20, stdin);
		input[strlen(input) - 1] = 0;
		if (strncmp(input, "store", 5) == 0)
			ret = store_number(tab);
		else if (strncmp(input, "read", 4) == 0)
			ret = read_number(tab);
		else if (strncmp(input, "quit", 4) == 0)
			break;
		if (ret == 0)
			printf(" Completed %s command successfully\n", input);
		else
			printf(" Failed to do %s command\n", input);
		memset(input, 0, 20);
	}
	return (0);
}
