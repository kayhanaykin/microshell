
# include <stdio.h> //NULL, STDIN_FILENO
# include <string.h> //strcmp
# include <unistd.h> //fork, waitpid, close, pipe, chdir, execve, write
# include <sys/wait.h> //waitpid
# include <stdlib.h> //malloc

void	exec_cd();
void	exec_pipe(void);
void	exec_out(void);
void	close_pipes(int *fd1, int *fd2);
void	wait_pid();
void	error_handler(char *str, char *str2, int err);

char		**arg_ptr = NULL;
char		**env_ptr = NULL;
int			i = 1;
int			cmd_count = 0;
int			fork_count = 0;
int			fd1[2];
int			fd2[2];
int			pid;
char		**cmd = NULL;
int			start = 1;
int			status;

int	main(int ac, char *arg[], char *env[])
{
	arg_ptr = arg;
	env_ptr = env;
	if (ac == 1)
		return (0);
	while (1)
	{
		if (arg[i] == NULL || strcmp(arg[i], ";") == 0)
		{
			exec_out();
			if (arg[i] == NULL)
				break ;
		}
		else if (strcmp(arg[i], "|") == 0)
		{
			exec_pipe();
		}
		else if (strcmp(arg[i], "cd") == 0)
		{
			exec_cd(); 
		}
		i++;
	}
	exit(WIFEXITED(status) && WEXITSTATUS(status));
}
// {printf("i:%d, cmd[0];%s, cmd[1]:%s, cmd_count:%d, fork_count:%d\n", i, cmd[0], cmd[1], cmd_count, fork_count);

// printf("test i:%d, arg[i]:%s\n", i, arg[i]);

static int	prev_check();
static int	next_check();

void	exec_cd()
{
	int next_ret;

	next_ret = next_check();
	if (prev_check() == 1 || next_ret == 1) //on arka sorun checki
	{
		return ;
	}
	if (next_ret == 2)
	{
		error_handler("error: cd: bad arguments", NULL, 0);
		start += 2;
	}
	else 
	{
		if (chdir(arg_ptr[i + 1]) == -1)
		{
			if (arg_ptr[i + 2] == NULL)
				error_handler("error: cd: cannot change directory to ", arg_ptr[i + 1], 1);
			else
				error_handler("error: cd: cannot change directory to ", arg_ptr[i + 1], 0);
			i = i + 2;
		}
		start++;
		start++;
	}
}

static int	prev_check()
{
	if (i == 1 || strcmp(arg_ptr[i - 1], ";") == 0) //sadece ilk veya ; sonrasi ise ok oluyo
		return (0);
	return (1);
}

static int next_check() //arg sayisi yanlissa, pipe geliyosa sonrasinda
{
	int j = 1;
	while(arg_ptr[i + j] != NULL && strcmp(arg_ptr[i + j], ";") != 0 //arguman sayaci
			&& strcmp(arg_ptr[i + j], "|") != 0)
	{
		j++;
		start++;
	}
	// if (arg_ptr[i + j] != NULL && strcmp(arg_ptr[i + j], "|") == 0) // cd directory | checki
	// 	return (1);

	if (j == 1)   //argsiz
		return (2);
	else if (j == 2) //bir argli
		return (0);
	else		//çok argli
		return (2);
}

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

	if (i == 1 || strcmp(arg_ptr[i - 1], ";") == 0  || strcmp(arg_ptr[i - 1], "|") == 0)
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

void	close_pipes(int *fd1, int *fd2)
{
	if (fd1)
	{
		if (close(fd1[0]) == -1 || close(fd1[1]) == -1)
			error_handler("error: fatal", NULL, 1);
	}
	if (fd2)
	{
		if (close(fd2[0]) == -1 || close(fd2[1]) == -1)
			error_handler("error: fatal", NULL, 1);
	}
}

void	wait_pid()
{
	while(fork_count--)
	{
		if (waitpid(-1, &status, 0) == -1)
			error_handler("error: fatal", NULL, 1);
	}
	fork_count = 0;
}

static int ft_strlen(char *str);

void	error_handler(char *str, char *str2, int err)
{
	if ((write(2, str, ft_strlen(str)) == -1) ||
	(write(2, str2, ft_strlen(str2)) == -1) ||
	(write(2, "\n", 1) == -1))
		error_handler("error: fatal", NULL, 1);
	if (err)
		exit(1);
}

static int ft_strlen(char *str)
{
	int i = 0;

	while(str && str[i])
		i++;
	return (i);
}