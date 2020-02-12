#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void	log_wrapper(FILE *log, char *msg, char *filename)
{
	char	*cpy;

	strcpy(cpy, msg);
	snprintf(cpy + strlen(cpy), 254 - strlen(cpy), filename);
	cpy[strcspn(cpy, "\n")] = '\0';
	fprintf(log, "LOG: %s\n", cpy);
}

int	main(int argc, char **argv)
{
	FILE	*log;
	FILE	*file;
	char	*path;
	char	c;
	int	fd;

	if (argc != 2)
		printf("Usage: %s filename\n", argv[0]);
	if (!(log = fopen("./backups/.log", "w")))
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(log, "Starting back up: ", argv[1]);
	if (!(file = fopen(argv[1], "r")))
	{
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}
	strcpy(path, "./backups/");
	strncat(path, argv[1], 99 - strlen("./backups/"));
	if ((fd = open(path, O_EXCL | O_CREAT | O_WRONLY, 0660)) < 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
		exit(1);
	}
	while ((c = fgetc(file)) != EOF)
		write(fd, &c, 1);
	log_wrapper(log, "Finished back up ", argv[1]);
	fclose(file);
	close(fd);
}
