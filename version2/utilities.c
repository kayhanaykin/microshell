#include "minishell.h"

void	close_pipes(int *fd1, int *fd2)
{
	if (fd1)
	{
		if (close(fd1[0]) == -1 || close(fd1[1]) == -1)
			error_handler("error: fatal", NULL, 1);
	}
	if (fd2)
	{
		if (close(fd2[0]) == -1 || close(fd2[1]) == -1)
			error_handler("error: fatal", NULL, 1);
	}
}

void	wait_pid()
{
	while(fork_count--)
	{
		if (waitpid(-1, NULL, 0) == -1)
			error_handler("error: fatal", NULL, 1);
	}
	fork_count = 0;
}

static int ft_strlen(char *str);

void	error_handler(char *str, char *str2, int err)
{
	if ((write(2, str, ft_strlen(str)) == -1) ||
	(write(2, str2, ft_strlen(str2)) == -1) ||
	(write(2, "\n", 1) == -1))
		error_handler("error: fatal", NULL, 1);
	if (err)
		exit(1);
}

static int ft_strlen(char *str)
{
	int i = 0;

	while(str && str[i])
		i++;
	return (i);
}