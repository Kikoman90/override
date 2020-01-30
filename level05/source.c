#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	int i = 0;
	char buff[100];

	fgets(buff, 100, stdin);
	while (i < strlen(buff))
	{
		// isupper(buff[i])
		if (buff[i] >= 64 && buff[i] <= 90)
			buff[i] = buff[i] ^ 32;
		i++;
	}
	printf(buff);
	exit(0);
}
