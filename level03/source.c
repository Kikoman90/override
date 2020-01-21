#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void	test(int i, int c)
{
	int diff;

	diff = c - i;
	if (diff <= 21)
	{
		if ((diff >= 1 && diff <= 9) || (diff >= 16 && diff <= 21))
			decrypt(diff);
	}
	decrypt(rand());
}

int	main(void)
{
	int	i;

	srand(time(0));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &i);
	test(i, 0x1337d00d); // 322424845
	return (0);
}
