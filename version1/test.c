# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>

int main()
{
	char **cmd = { "/bin/ls", "-l", NULL };
	execvp(cmd[0], cmd);
	printf("test\n");
}