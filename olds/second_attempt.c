#include <stdio.h> //printf
#include <unistd.h> // pipe
#include <stdlib.h>
#include <errno.h> //errno
#include <string.h> //strcmp
#include <sys/wait.h> //waitpid
#include <sys/types.h>

void 	exec();
void 	exec_first();
void	exec_out();
void	close_pipes(int *fd1, int *fd2);
void	create_cmd();
void	exec_cd();
void	wait_pid();
int		ft_strlen(char *str);
void	exit_handler(char *str, char *str2, int no);

int 			i = 1;
int				start = 1;
int 			cmd_count = 0;
int				fd1[2];
int				fd2[2];
int 			pid = 0;
extern	char 	**environ;
char			**cmd;
char			**arg_ptr;
int				forked_count = 0;

int main(int ac, char *args[])
{
	(void)ac;
	arg_ptr = args;
	while (args[i])
	{
		if (strcmp(args[i], ";") == 0)
		{
			exec_out();
			wait_pid();
		}
		if (strcmp(args[i], "|") == 0)
		{
			exec();
		}
		if (strcmp(args[i], "cd") == 0)
		{
			exec_cd();
			wait_pid();
		}
		i++;
	}
	exec_out();
	wait_pid(); //wait aralarda olursa ne olur
}

void exec_first()
{
	if (pipe(fd1) == -1)
		exit_handler("error: 1fatal", NULL, errno);
	pid = fork();
	if (pid == -1)
		exit_handler("error: 2fatal", NULL, errno);
	forked_count++;
	if (pid == 0)
	{
		if (dup2(fd1[1], STDOUT_FILENO) == -1)
			exit_handler("error: 3fatal", NULL, errno);
		close_pipes(fd1, NULL);
		if (execve(cmd[0], cmd, environ) == -1)
			exit_handler("error: cannot execute ", cmd[0], 0);
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
		if (pipe(fd1) == -1)
			exit_handler("error: 4fatal", NULL, errno);
		pid = fork();
		if (pid == -1)
			exit_handler("error: 5fatal", NULL, errno);
		forked_count++;
		if (pid == 0)
		{
			if (dup2(fd2[0], STDIN_FILENO) == -1)
				exit_handler("error: 6fatal", NULL, errno);
			if (dup2(fd1[1], STDOUT_FILENO) == -1)
				exit_handler("error: 7fatal", NULL, errno);
			if (execve(cmd[0], cmd, environ) == -1)
				exit_handler("error: cannot execute ", cmd[0], 0);
			close_pipes(fd1, fd2);
		}
		close_pipes(NULL, fd2);
	}
	else
	{
		if (pipe(fd2) == -1)
			exit_handler("error: 8fatal", NULL, errno);
		pid = fork();
		if (pid == -1)
			exit_handler("error: 9fatal", NULL, errno);
		forked_count++;
		if (pid == 0)
		{
			if (dup2(fd1[0], STDIN_FILENO) == -1)
				exit_handler("error: 10fatal", NULL, errno);
			if (dup2(fd2[1], STDOUT_FILENO) == -1)
				exit_handler("error: 11fatal", NULL, errno);
			if (execve(cmd[0], cmd, environ) == -1)
				exit_handler("error: cannot execute ", cmd[0], 0);
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
		if (pid == -1)
			exit_handler("error: 12fatal", NULL, errno);
		forked_count++;
		if (pid == 0)
		{
			if (execve(cmd[0], cmd, environ) == -1)
				exit_handler("error: cannot execute ", cmd[0], 0);
		}
	}
	else if (cmd_count == 2)
	{
		pid = fork();
		if (pid == -1)
			exit_handler("error: 13fatal", NULL, errno);
		forked_count++;
		if (pid == 0)
		{
			if (dup2(fd1[0], STDIN_FILENO) == -1)
				exit_handler("error: 14fatal", NULL, errno);
			close_pipes (fd1, NULL);
			if(execve(cmd[0], cmd, environ) == -1)
				exit_handler("error: cannot execute ", cmd[0], 0);
		}
		close_pipes(fd1, NULL);
	}
	else if (cmd_count % 2 == 1)
	{
		pid = fork();
		if (pid == -1)
			exit_handler("error: 14fatal", NULL, errno);
		forked_count++;
		if (pid == 0)
		{
			if (dup2(fd2[0], STDIN_FILENO) == -1)
				exit_handler("error: 15fatal", NULL, errno);
			close_pipes (NULL, fd2);
			if (execve(cmd[0], cmd, environ) == -1)
				exit_handler("error: cannot execute ", cmd[0], 0);
		}
		close_pipes(NULL, fd2);
	}
	else
	{
		pid = fork();
		if (pid == -1)
			exit_handler("error: 16fatal", NULL, errno);
		forked_count++;
		if (pid == 0)
		{
			if (dup2(fd1[0], STDIN_FILENO) == -1)
				exit_handler("error: 17fatal", NULL, errno);
			close_pipes (fd1, NULL);
			if (execve(cmd[0], cmd, environ) == -1)
				exit_handler("error: cannot execute ", cmd[0], 0);
		}
		close_pipes(fd1, NULL);
	}
	cmd_count = 0;
}

void	close_pipes(int *fd1, int *fd2)
{
	if (fd1)
	{
		if (close(fd1[0]) == -1)
			exit_handler("error: 18fatal", NULL, errno);
		if (close(fd1[1]) == -1)
			exit_handler("error: 19fatal", NULL, errno);
	}
	if (fd2)
	{
		if (close(fd2[0]) == -1)
			exit_handler("error: 20fatal", NULL, errno);
		if (close(fd2[1]) == -1)
			exit_handler("error: 21fatal", NULL, errno);
	}
}

void	wait_pid()
{
	if (pid == 0)
		return ;
	while (forked_count)
	{
		if (waitpid(-1, NULL, 0) == 0)
			exit_handler("error: 22fatal", NULL, errno);
		forked_count--;
	}
}

void	create_cmd()
{
	int	j = 0;
	if (i == 1 || strcmp(arg_ptr[i - 1], ";") == 0)
	{
		start = i + 1;
		return ;
	}
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

	pid = fork();
	if (pid == -1)
		exit_handler("error: 23fatal", NULL, errno);
	if (pid == 0)
	{
		j = i + 1;
		while ((arg_ptr[j]) && strcmp(arg_ptr[j], ";"))
			j++;
		j -= (i + 1);
		if (j != 1)
		{
			if (write (2, "error: cd: bad arguments\n", 25) == -1)
				exit_handler("error: 24fatal", NULL, 0);
			return ;
		}
		if (i != 1 && strcmp(arg_ptr[i - 1], ";") != 0)
			return ;
		if (chdir(arg_ptr[j + 1]) == -1)
		{
			exit_handler("error: cd: cannot change directory to ", arg_ptr[j + 1], 0);
			if (write(2, "\n", 1) == -1)
				exit_handler("error: 25fatal", NULL, 0);
		}
	}
}

int	ft_strlen(char *str)
{
	int j = 0;

	while(str[j])
	{
		j++;
	}
	return (j);
}

void	exit_handler(char *str, char *str2, int no)
{
	if (str)
		if (write(2, str, ft_strlen(str)) == -1)
			exit_handler("error: 26fatal", NULL, errno);
	if (str2)
		if (write(2, str2, ft_strlen(str2)) == -1)
			exit_handler("error: 27fatal", NULL, errno);
	if (write(2, "\n", 1) == -1)
		exit_handler("error: 28fatal", NULL, errno);
	if (no)
		exit(no);
}