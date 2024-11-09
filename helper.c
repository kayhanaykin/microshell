#include "header.h"

void prepare_cmd(char *tokens[], int i)
{
	int 		j;
	int			k;
	int			token_count;

	token_count = 0;
	if (start == 0)
		start = 1;
	j = start;
	while (start < i)
	{
		token_count++;
		start++;
	}
	start++;
	cmd = malloc(++token_count * sizeof(char *));
	k = 0;
	while (j < i)
		cmd[k++] = tokens[j++];
	cmd[k] = NULL;
	cmd_count++;
}

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

void	cd_check_args(char **token)
{
	int i;

	i =  1;
	while(token + i && !strcmp(token[i], "|") && !strcmp(token[i], ";"))
		i++;
	if (i != 1)
	{
		write(2, "error: cd: bad arguments\n", 25);
		exit (1);
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}
