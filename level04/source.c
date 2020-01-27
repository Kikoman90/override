#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/prctl.h> // only on linux 
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>

int	main(void)
{
	char	buff[128] = {0};
	int	wstatus = 0;

	if ((pid = fork()) == 0)
	{
		prctl(PR_SET_PDEATHSIG, SIGHUP); // set parent-death signal to SIGHUP
		ptrace(PTRACE_TRACEME, 0, NULL, NULL); // PTRACE_TRACEME = 0
		puts("Give me some shellcode, k");
		gets(buff);
	}
	else
	{
		do
		{
			wait(&wstatus);
			if (WIFEXITED(wstatus) || WIFSIGNALED(wstatus)) // child terminated normally or by signal
			{
				puts("child is exiting...");
				return (0);
			}
		}
		while (ptrace(PTRACE_PEEKUSER, pid, ORIG_EAX, NULL) != 11); // PTRACE_PEEKUSER = 3
		puts("no exec() for you");
		kill(pid, SIGKILL); // kills all processes belonging to the same groud (GID)
	}
	return (0);
}

// The SIGHUP (“hang-up”) signal is used to report that the user’s terminal is disconnected, perhaps because a network or telephone connection was broken. This signal is also used to report the termination of the controlling process on a terminal to jobs associated with that session; this termination effectively disconnects all processes in the session from the controlling terminal.
