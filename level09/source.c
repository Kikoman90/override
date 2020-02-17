#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct		msn {
	char	msg[140];
	char	usn[40];
	int	msg_len;
};

void	secret_back(void)
{
	char	buff[128];

	fgets(buff, 128, stdin);
	system(buff);
}

void	set_msg(struct msn *m)
{
	char	msg[1024] = {0};
	
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(msg, 1024, stdin);
	strncpy(m->msg, msg, m->msg_len);
}

void	set_username(struct msn *m)
{
	char	usn[128] = {0};
	int	i;

	puts(">: Enter your username");
	printf(">>: ");
	fgets(usn, 128, stdin);
	i = 0;
	while (i <= 40 && usn[i])
	{
		m->usn[i] = usn[i];
		i++;
	}
	printf(">: Welcome, %s", m->usn);
}

void	handle_msg(void)
{
	struct msn m;

	memset(m.usn, 0, 40);
	m.msg_len = 140;
	set_username(&m);
	set_msg(&m);
	puts(">: Msg sent!");
}

int	main(void)
{
	puts(	"--------------------------------------------\n"\
		"|   ~Welcome to l33t-m$n ~    v1337        |\n"\
		"--------------------------------------------");
	handle_msg();
	return (0);
}
