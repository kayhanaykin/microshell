#include "header.h"

int pid;
int fd1[2];
int fd2[2];
char **cmd;
int cmd_count = 0;
int start = 0;

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
			wait_pids();
			cmd_count = 0;
		}
		if (strcmp (tokens[i], "cd") == 0 && cmd_count == 0)
		{
			cd_check_args(tokens + i);
			if (chdir(tokens[i + 1]) == -1)
			{
				write(2, "error: cd: cannot change directory to ", 38);
				write(2, tokens[i + 1], ft_strlen(tokens[i + 1]));
				write(2, "\n", 1);
			}
			i++;
			start += 3;
		}
		i++;
	}
	prepare_cmd(tokens, i);
	execute_cmd();
	execute_out();
	wait_pids();
	return (0);
}
