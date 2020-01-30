#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ptrace.h>

int	auth(char *login, unsigned int serial)
{
	size_t		len, i;
	unsigned int	v1, v2, v3;

	login[strcspn(login, "\n")] = '\0';
	len = strnlen(login, 32);
	if (len <= 5)
		return (1);
	if (ptrace(PTRACE_TRACEME, 0, 1, NULL) == -1)
	{
		puts("\033[32m.---------------------------.");
        	puts("\033[31m| !! TAMPERING DETECTED !!  |");
        	puts("\033[32m'---------------------------'");
		return (1);
	}
	v1 = (login[3] ^ 0x1337) + 0x5eeded;
	i = 0;
	while (i < len)
	{
		if (login[i] <= 31)
			return (1);
		v2 = login[i] ^ v1;
		v3 = ((uint64_t)v2 * 0x88233b2b) >> 32;
		v1 += v2 - ((v2 - v3) / 2 + v3) / 1024 * 0x539;
		i++;
	}
	return (v1 != serial);
}

int	main(void)
{
	char 		login[32]; // esp + 44
	unsigned int	serial; // esp + 40

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");

	printf("-> Enter Login: ");
	fgets(login, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &serial);
	if (auth(login, serial) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return (0);
	}
	return (1);
}
