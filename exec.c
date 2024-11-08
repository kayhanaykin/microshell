#include "header.h"

void execute_cmd(void)
{
	if (cmd_count == 1)
	{
		exec_first_cmd();
	}
	exec_cmd();
}
void	exec_first_cmd()
{
	pipe(fd1);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd1[1], 1);
		close_pipes(fd1, NULL);
		execve(cmd[0], cmd, environ);
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
			execve(cmd[0], cmd, environ);
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
			execve(cmd[0], cmd, environ);
		}
		close_pipes(NULL, fd2);
	}
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
			execve(cmd_out[0], cmd_out, environ);
		}
		write(1, "\n", 1);
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
			execve(cmd_out[0], cmd_out, environ);
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