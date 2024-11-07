# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

int main(int ac, char*tokens[], char *env[]) 
{
	char *cmd[3];

	(void)tokens;
	(void)ac;
	cmd[0] = strdup("/bin/ls");
	cmd[1] = NULL;
 	execve(cmd[0], cmd, env);
    return 0;
}