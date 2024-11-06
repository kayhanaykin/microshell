#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> //waitpid

void	close_pipes(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	fork_first_cmd(char **cmd1, int pid, int *fd1)
{
	pipe(fd1);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd1[1], STDOUT_FILENO);
		close_pipes(fd1);
		execvp(cmd1[0], cmd1);
	}
}

void	fork_cmd_out(int pid, int *fd_a, int *fd_b)
{
	int 	i;
	char 	*cmd_out[] = { "/usr/bin/cat", NULL };

	pid = fork();
	if (pid == 0)
	{
		dup2(fd_a[0], STDIN_FILENO);
		close_pipes(fd_a);
		execvp(cmd_out[0], cmd_out);
	}
	close_pipes(fd_a);
	close_pipes(fd_b);
	i = 0;
	while (i++ < 6)
		waitpid (-1, NULL, 0);
}

void	fork_cmds(char **cmd, int pid, int *fd_a, int *fd_b)
{
	pipe(fd_b);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd_a[0], STDIN_FILENO);
		dup2(fd_b[1], STDOUT_FILENO);
		close_pipes(fd_a);
		close_pipes(fd_b);
		execvp(cmd[0], cmd);
	}
	close_pipes(fd_a);
}

int main() 
{
	int fd1[2];
	int fd2[2];
	int pid;
	int i;
	char *cmd1[] = { "/bin/cat", "/etc/passwd", NULL };
	char *cmd2[] = { "/usr/bin/cut", "-d:", "-f1", NULL };
	char *cmd3[] = { "/usr/bin/grep", "^_m", NULL };
	char *cmd4[] = { "/usr/bin/sort", NULL };
	char *cmd5[] = { "/usr/bin/wc", NULL };
	fork_first_cmd(cmd1, pid, fd1);
	fork_cmds(cmd2, pid, fd1, fd2);
	fork_cmds(cmd3, pid, fd2, fd1);
	fork_cmds(cmd4, pid, fd1, fd2);
	fork_cmds(cmd5, pid, fd2, fd1);
	fork_cmd_out(pid, fd1, fd2);
    return 0;
	printf("test1\n");
}