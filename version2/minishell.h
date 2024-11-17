#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> //NULL, STDIN_FILENO
# include <string.h> //strcmp
# include <unistd.h> //fork, waitpid, close, pipe, chdir, execve, write
# include <sys/wait.h> //waitpid
# include <stdlib.h> //malloc
# include <errno.h>

extern char			**arg_ptr;
extern char			**env_ptr;
extern int			i;
extern int			cmd_count;
extern int			fork_count;
extern int			fd1[2];
extern int			fd2[2];
extern int			pid;
extern char			**cmd; 
extern int			start;

void	exec_cd();
void	exec_pipe(void);
void	exec_out(void);
void	close_pipes(int *fd1, int *fd2);
void	wait_pid();
void	error_handler(char *str, char *str2, int err);

#endif