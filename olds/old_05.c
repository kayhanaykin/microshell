# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

int main() 
{
	char *cmd[] = { "ls", NULL };
	execvp(cmd[0], cmd);
    return 0;
}