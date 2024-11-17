#include "header.h"

void prepare_cmd(char *tokens[], int i)
{
	static int 	start;
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


// printf("cmd[0]: %s, i:%d, start:%d\n", cmd[0], i, start);