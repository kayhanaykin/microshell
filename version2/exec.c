#include "minishell.h"

static void	create_cmd();

void	exec_pipe(void)
{
	create_cmd();
	if (cmd_count == 1)
	{
		pipe(fd1);
		pid = fork();
		fork_count++;
		if (pid == 0)
		{
			dup2(fd1[1], STDOUT_FILENO);
			close_pipes(fd1, NULL);
			execve(cmd[0], cmd, env_ptr);
		}
	}
	else if (cmd_count % 2 == 0)
	{
		pipe(fd2);
		pid = fork();
		fork_count++;
		if (pid == 0)
		{
			dup2(fd1[0], STDIN_FILENO);
			dup2(fd2[1], STDOUT_FILENO);
			close_pipes(fd1, fd2);
			execve(cmd[0], cmd, env_ptr);
		}
		close_pipes(fd1, NULL);
	}
	else if (cmd_count % 2 == 1)
	{
		pipe(fd1);
		pid = fork();		
		fork_count++;
		if (pid == 0)
		{
			dup2(fd2[0], STDIN_FILENO);
			dup2(fd1[1], STDOUT_FILENO);
			close_pipes(fd1, fd2);
			execve(cmd[0], cmd, env_ptr);
		}
		close_pipes(NULL, fd2);
	}
}

void	exec_out(void)
{
	create_cmd();
	if (cmd_count == 0)
	{
		return ;
	}
	if (cmd_count == 1)
	{
		pid = fork();
		fork_count++;
		if (pid == 0)
		{	
			execve(cmd[0], cmd, env_ptr);
		}
	}
	else if (cmd_count % 2 == 0)
	{
		pid = fork();
		fork_count++;
		if (pid == 0)
		{
			dup2(fd1[0], STDIN_FILENO);
			close_pipes(fd1, NULL);
			execve(cmd[0], cmd, env_ptr);
		}
		close_pipes(fd1, NULL);
	}
	else if (cmd_count % 2 == 1)
	{
		pid = fork();
		fork_count++;
		if (pid == 0)
		{
			dup2(fd2[0], STDIN_FILENO);
			close_pipes(NULL, fd2);
			execve(cmd[0], cmd, env_ptr);
		}
		close_pipes(NULL, fd2);
	}
	cmd_count = 0;
	wait_pid();
}

static void	create_cmd()
{
	int j = 0;

	if (i == 1 || strcmp(arg_ptr[i - 1], ";") == 0)
	{
		return ;
	}
	cmd = malloc (sizeof(char *) * (i - start + 1));
	cmd[i - start] = NULL;
	while (start < i)
	{
		cmd[j] = arg_ptr[start];
		j++;
		start++;
	}
	start++;
	cmd_count++;
}

// printf("test%s, %s\n", cmd[0], cmd[1]);
// printf("%d", i);