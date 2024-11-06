#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h> //waitpid

int pid;
int fd1[2];
int fd2[2];

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

void	wait_pids()
{
	while (errno != ECHILD)
	{
		waitpid(-1, NULL, 0);
	}
}

void	exec_first_cmd(char **cmd1)
{
	pipe(fd1);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd1[1], 1);
		close_pipes(fd1, NULL);
		execvp(cmd1[0], cmd1);
	}
}

void	exec_cmd(int pid, int *fd_a, int *fd_b, char **cmd)
{
	pipe(fd_b);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd_a[0], 0);
		dup2(fd_b[1], 1);
		close_pipes(fd_a, fd_b);
		execvp(cmd[0], cmd);
	}
	close_pipes(fd_a, NULL);
}

void	exec_cmd_out(int pid, int *fd_a, int *fd_b)
{
	char *cmd_out[] = { "/bin/cat", NULL };
	if (!fd_a)
		fd_a = fd_b;
	pid = fork();
	if (pid == 0)
	{
		dup2(fd_a[0], 0);
		close_pipes(fd_a, NULL);
		execvp(cmd_out[0], cmd_out);
	}
	close_pipes(fd_a, NULL);

}

int main() 
{
	char *cmd1[] = { "/bin/cat", "/etc/passwd", NULL };
	char *cmd2[] = { "/usr/bin/cut", "-d:", "-f1", NULL };
	char *cmd3[] = { "/usr/bin/grep", "^_m", NULL };
	char *cmd4[] = { "/usr/bin/sort", NULL };
	char *cmd5[] = { "/usr/bin/wc", NULL };

	// printf("test1\n");
	exec_first_cmd(cmd1);			//pipe fd1
	exec_cmd(pid, fd1, fd2, cmd2);	//pipe fd2
	exec_cmd(pid, fd2, fd1, cmd3);	//pipe fd1
	exec_cmd(pid, fd1, fd2, cmd4);	//pipe fd2
	exec_cmd(pid, fd2, fd1, cmd5);	//pipe fd1
	exec_cmd_out(pid, fd1, NULL);
	wait_pids();
    return 0;
}