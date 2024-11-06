#include "header.h"

void prepare_cmd(char *tokens[], int i)
{
	static int 	start;
	int 		cmd_count;
	int 		j;
	int			k;

	cmd_count = 0;
	if (start == 0)
		start = 1;
	j = start;
	while (start++ < i)
		cmd_count++;
	start++;
	cmd = malloc(++cmd_count * sizeof(char *));
	k = 0;
	while (j < i)
		cmd[k++] = tokens[j++];
	cmd[k] = "\0";
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