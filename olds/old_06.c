# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

int main(int ac, char*tokens[]) 
{
	char *cmd[2];

	cmd[0] = strdup(tokens[1]);
	cmd[1] = NULL;
 	execvp(cmd[0], cmd);
    return 0;
}