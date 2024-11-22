#include "minishell.h"

char		**arg_ptr = NULL;
char		**env_ptr = NULL;
int			i = 1;
int			cmd_count = 0;
int			fork_count = 0;
int			fd1[2];
int			fd2[2];
int			pid;
char		**cmd = NULL;
int			start = 1;
int			status;

int	main(int ac, char *arg[], char *env[])
{
	arg_ptr = arg;
	env_ptr = env;
	if (ac == 1)
		return (0);
	while (1)
	{
		if (arg[i] == NULL || strcmp(arg[i], ";") == 0 ||
			(arg[i + 1] == NULL && strcmp(arg[i], "|") == 0))
		{
			exec_out();
			if (arg[i] == NULL)
				break ;
		}
		else if (strcmp(arg[i], "|") == 0)
		{
			exec_pipe();
		}
		else if (strcmp(arg[i], "cd") == 0)
		{
			exec_cd(); 
		}
		i++;
	}
	exit(WIFEXITED(status) && WEXITSTATUS(status));
}
// {printf("i:%d, cmd[0];%s, cmd[1]:%s, cmd_count:%d, fork_count:%d\n", i, cmd[0], cmd[1], cmd_count, fork_count);

// printf("test i:%d, arg[i]:%s\n", i, arg[i]);