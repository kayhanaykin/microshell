#include "header.h"

int pid;
int fd1[2];
int fd2[2];
char **cmd;
int cmd_count = 0;

int main(int ac, char **tokens)
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
			prepare_cmd(tokens, i);
			execute_cmd();
			execute_out();
			//wait_pids();
			cmd_count = 0;
		}
		if (strcmp (tokens[i], "cd") == 0 && cmd_count == 0)
		{
			cd_check_args(tokens + i);
			printf("%s\n", tokens[i + 1]);
			chdir(tokens[i + 1]);
			i++;
		}
		i++;
	}
	prepare_cmd(tokens, i);
	//printf("-%s\n", cmd[0]);
	execute_cmd();
	execute_out();
	wait_pids();
	return (0);
}
