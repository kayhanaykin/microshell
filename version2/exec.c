#include "minishell.h"

static void	create_cmd();

void	exec_pipe(void)
{
	create_cmd();
	if (cmd_count == 1)
	{
		if (pipe(fd1) == -1)
			error_handler("error: fatal", NULL, 1);
		pid = fork();
		if (pid == -1)
			error_handler("error: fatal", NULL, 1);
		fork_count++;
		if (pid == 0)
		{
			if (dup2(fd1[1], STDOUT_FILENO) == -1)
				error_handler("error: fatal", NULL, 1);
			close_pipes(fd1, NULL);
			if (execve(cmd[0], cmd, env_ptr) == -1)
				error_handler("error: cannot execute ", cmd[0], 1);
		}
	}
	else if (cmd_count % 2 == 0)
	{
		if (pipe(fd2) == -1)
			error_handler("error: fatal", NULL, 1);
		pid = fork();
		if (pid == -1)
			error_handler("error: fatal", NULL, 1);
		fork_count++;
		if (pid == 0)
		{
			if (dup2(fd1[0], STDIN_FILENO) == -1)
				error_handler("error: fatal", NULL, 1);
			if (dup2(fd2[1], STDOUT_FILENO) == -1)
				error_handler("error: fatal", NULL, 1);
			close_pipes(fd1, fd2);
			if (execve(cmd[0], cmd, env_ptr) == -1)
				error_handler("error: cannot execute ", cmd[0], 1);
		}
		close_pipes(fd1, NULL);
	}
	else if (cmd_count % 2 == 1)
	{
		if (pipe(fd1) == -1)
			error_handler("error: fatal", NULL, 1);
		pid = fork();
		if (pid == -1)
			error_handler("error: fatal", NULL, 1);		
		fork_count++;
		if (pid == 0)
		{
			if (dup2(fd2[0], STDIN_FILENO) == -1)
				error_handler("error: fatal", NULL, 1);
			if (dup2(fd1[1], STDOUT_FILENO) == -1)
				error_handler("error: fatal", NULL, 1);
			close_pipes(fd1, fd2);
			if (execve(cmd[0], cmd, env_ptr) == -1)
				error_handler("error: cannot execute ", cmd[0], 1);
		}
		close_pipes(NULL, fd2);
	}
}

void	exec_out(void)
{
	if (strcmp(arg_ptr[i - 1], "cd") == 0)
		return ;
	if (i >= 2 && arg_ptr[i - 2] && strcmp(arg_ptr[i - 2], "cd") == 0)
		return ;
	create_cmd();
	if (cmd_count == 0)
	{
		return ;
	}
	if (cmd_count == 1)
	{
		pid = fork();
		if (pid == -1)
			error_handler("error: fatal", NULL, 1);
		fork_count++;
		if (pid == 0)
		{	
			if (execve(cmd[0], cmd, env_ptr) == -1)
				error_handler("error: cannot execute ", cmd[0], 1);
		}
	}
	else if (cmd_count % 2 == 0)
	{
		pid = fork();
		if (pid == -1)
			error_handler("error: fatal", NULL, 1);
		fork_count++;
		if (pid == 0)
		{
			if (dup2(fd1[0], STDIN_FILENO) == -1)
				error_handler("error: fatal", NULL, 1);
			close_pipes(fd1, NULL);
			if (execve(cmd[0], cmd, env_ptr) == -1)
				error_handler("error: cannot execute ", cmd[0], 1);
		}
		
		close_pipes(fd1, NULL);
	}
	else if (cmd_count % 2 == 1)
	{
		pid = fork();
		if (pid == -1)
			error_handler("error: fatal", NULL, 1);
		fork_count++;
		if (pid == 0)
		{
			if (dup2(fd2[0], STDIN_FILENO) == -1)
				error_handler("error: fatal", NULL, 1);
			close_pipes(NULL, fd2);
			if (execve(cmd[0], cmd, env_ptr) == -1)
				error_handler("error: cannot execute ", cmd[0], 1);
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
		start = i + 1;
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
// printf("i:%d, cmd[0];%s, cmd[1]:%s, cmd_count:%d, fork_count:%d\n", i, cmd[0], cmd[1], cmd_count, fork_count);
