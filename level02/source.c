/* 64 bit */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	FILE	*file = NULL;	// rbp - 8
	size_t	n = 0;		// rbp - 12
	char	username[100];	// rbp - 112
	char	flag[41];	// rbp - 160
	char	password[100];	// rbp - 272

	memset(username, 0, 100);
	username[99] += 4;
	memset(flag, 0, 41);
	flag[40] += 1;
	memset(password, 0, 100);
	password[99] += 4;
	if (!(file = fopen("/home/users/level03/.pass", "r")))
	{
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}
	n = fread(flag, 1, 41, file);
	flag[strcspn(flag, "\n")] = '\0';
	if (n != 41)
	{
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(1);
	}
	fclose(file);
	
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(username, 100, stdin);
	username[strcspn(username, "\n")] = '\0';
	printf("--[ Password: ");
	fgets(password, 100, stdin);
	password[strcspn(password, "\n")] = '\0';
	puts("*****************************************");
	if (!strncmp(flag, password, 41))
	{
		printf(username);
		puts(" does not have access!");
		exit(1);
	}
	printf("Greetings, %s!\n", username);
	system("/bin/sh");
	return (0);
}
