#include <stdio.h>
#include <string.h>

char	a_user_name[256];

int	verify_user_name(void)
{
	puts("verifying username....\n");
	return (strncmp(a_user_name, "dat_wil", 7)); // returns -1, 0 or 1
}

int	verify_user_pass(char *pass)
{
	return (strncmp(pass, "admin", 5));	
}

int	main(void)
{
	char	pass[64] = {0};
	int	ret = 0;
	
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);
	if ((ret = verify_user_name()) != 0)
	{
		puts("nope, incorrect username...\n");
		return (1);
	}
	puts("Enter Password: ");
	fgets(pass, 100, stdin);
	if ((ret = verify_user_pass(pass)) == 0)
	{
		puts("nope, incorrect password...\n");
		return (1);
	}
	else if (ret != 0)
	{
		puts("nope, incorrect password...\n");
		return (1);
	}
	return (0);
}
