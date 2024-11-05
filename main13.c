#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int pid;
int fd1[2];
int fd2[2];
char **cmd;
int cmd_count = 0;

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

void	exec_first_cmd()
{
	pipe(fd1);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd1[1], 1);
		close_pipes(fd1, NULL);
		execvp(cmd[0], cmd);
	}
}

void	exec_cmd()
{
	if (cmd_count % 2 == 1)
	{
		pipe(fd2);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd1[0], 0);
			dup2(fd2[1], 1);
			close_pipes(fd1, fd2);
			execvp(cmd[0], cmd);
		}
		close_pipes(fd1, NULL);
	}
	else
	{
		pipe(fd1);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd2[0], 0);
			dup2(fd1[1], 1);
			close_pipes(fd1, fd2);
			execvp(cmd[0], cmd);
		}
		close_pipes(NULL, fd2);
	}
}

void execute_cmd(void)
{
	if (cmd_count == 0)
	{
		cmd_count++;
		exec_first_cmd();
	}
	exec_cmd();
}
void	execute_out()
{
	char *cmd_out[] = { "/bin/cat", NULL };

	if (cmd_count % 2 == 0)
	{
		cmd_count = 0;
		pid = fork();
		if (pid == 0)
		{
			dup2(fd1[0], 0);
			close_pipes(fd1, NULL);
			execvp(cmd_out[0], cmd_out);
		}
		close_pipes(fd1, NULL);
	}
	else
	{
		cmd_count = 0;
		pid = fork();
		if (pid == 0)
		{
			dup2(fd2[0], 0);
			close_pipes(NULL, fd2);
			execvp(cmd_out[0], cmd_out);
		}
		close_pipes(NULL, fd2);
	}
}

void	wait_pids()
{
	while (errno != ECHILD)
	{
		waitpid(-1, NULL, 0);
	}
}

int main(int ac, char*tokens[])
{
	int i;

	(void)ac;
	i = 0;
	while (tokens[i])
	{
		// printf("test1%d, %s\n", i, tokens[i]);
		if (tokens[i][0] == '|')
		{
			prepare_cmd(tokens, i);
			execute_cmd();
		}
		if (tokens[i][0] == ';')
		{
			execute_out();
			wait_pids();
		}
		i++;
	}
	execute_out();
	wait_pids();
	return (0);
}
