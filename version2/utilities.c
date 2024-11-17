#include "minishell.h"

void	close_pipes(int *fd1, int *fd2)
{
	if (fd1)
	{
		close(fd1[0]);
		close(fd1[1]);
	}
	if (fd2)
	{
		close(fd2[0]);
		close(fd2[1]);
	}
}

void	wait_pid()
{
	while(fork_count--)
		waitpid(-1, NULL, 0);
	fork_count = 0;
}

static int ft_strlen(char *str);

void	error_handler(char *str, char *str2, int err)
{
	write(2, str, ft_strlen(str));
	write(2, str2, ft_strlen(str2));
	write(2, "\n", 1);
	if (err)
		exit(errno);
}

static int ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}