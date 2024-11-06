#include "header.h"

int pid;
int fd1[2];
int fd2[2];
char **cmd;
int cmd_count = 0;

int main(int ac, char*tokens[])
{
	int i;

	(void)ac;
	i = 1;
	while (tokens[i])
	{
		if (tokens[i][0] == '|')
		{
			prepare_cmd(tokens, i);
			execute_cmd();
		}
		if (tokens[i][0] == ';')
		{
			execute_out();
			wait_pids();
			cmd_count = 0;
		}
		i++;
	}
	prepare_cmd(tokens, i);
	execute_cmd();
	execute_out();
	wait_pids();
	return (0);
}
