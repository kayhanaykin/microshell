#include <stdio.h> //printf
#include <unistd.h> // pipe
#include <stdlib.h>
#include <errno.h> //errno
#include <string.h> //strcmp

void 	exec();
void 	exec_first();
void	exec_out();
void	close_pipes(int *fd1, int *fd2);
void	create_cmd();
void	exec_cd();
void	wait_pid();


int 			i = 1;
int				start = 1;
int 			cmd_count = 0;
int				fd1[2];
int				fd2[2];
int 			pid;
extern	char 	**environ;
char			**cmd;
char			**arg_ptr;

int main(int ac, char *args[])
{
	(void)ac;
	arg_ptr = args;
	while (args[i])
	{
		if (strcmp(args[i], ";") == 0)
		{
			exec_out();
		}
		if (strcmp(args[i], "|") == 0)
		{
			exec();
		}
		if (strcmp(args[i], "cd") == 0)
		{
			exec_cd();
		}
		i++;
	}
	exec_out();
	wait_pid(); //wait aralarda olursa ne olur
}

void exec_first()
{
	pipe(fd1);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd1[1], STDOUT_FILENO);
		close_pipes(fd1, NULL);
		execve(cmd[0], cmd, environ);
	}
}

void exec()
{
	create_cmd();
	if (cmd_count == 0)
		return ;
	else if (cmd_count == 1)
		exec_first();
	else if (cmd_count % 2 == 1)
	{		
		pipe(fd1);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd2[0], STDIN_FILENO);
			dup2(fd1[1], STDOUT_FILENO);
			close_pipes(fd1, fd2);
		}
		close_pipes(NULL, fd2);
	}
	else
	{
		pipe(fd2);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd1[0], STDIN_FILENO);
			dup2(fd2[1], STDOUT_FILENO);
			close_pipes(fd1, fd2);
		}
		close_pipes(fd1, NULL);
	}
}

void	exec_out()
{
	create_cmd();
	if (cmd_count == 0)
		return ;
	else if (cmd_count == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(cmd[0], cmd, environ);
		}
	}
	else if (cmd_count == 2)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(fd1[0], STDIN_FILENO);
			close_pipes (fd1, NULL);
			execve(cmd[0], cmd, environ);
		}
		close_pipes(fd1, NULL);
	}
	else if (cmd_count % 2 == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(fd2[0], STDIN_FILENO);
			close_pipes (NULL, fd2);
			execve(cmd[0], cmd, environ);
		}
		close_pipes(NULL, fd2);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(fd1[0], STDIN_FILENO);
			close_pipes (fd1, NULL);
			execve(cmd[0], cmd, environ);
		}
		close_pipes(fd1, NULL);
	}
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

void	wait_pid()
{
	while (errno != ECHILD)
		waitpid(-1, NULL, 0);
}

void	create_cmd()
{
	int	j = 0;
	if (i == 1)
		return ;
	cmd = malloc(sizeof(char *) * (i - start + 1));
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

void	exec_cd()
{
	int j = 0;

	j = i + 1;
	while ((arg_ptr[j]) && strcmp(arg_ptr[j], ";"))
		j++;
	j -= (i + 1);
	if (j != 1)
	{
		write (2, "error: cd: bad arguments\n", 25);
		return ;
	}
	if (i != 1 || strcmp(arg_ptr[i - 1], ";") != 0)
		return ;
	chdir(arg_ptr[j + 1]);
}