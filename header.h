#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

extern int pid;
extern int fd1[2];
extern int fd2[2];
extern char **cmd;
extern int cmd_count;

void	prepare_cmd(char *tokens[], int i);
void	close_pipes(int *fd1, int *fd2);
void	exec_first_cmd();
void	exec_cmd();
void	execute_cmd(void);
void	execute_out();
void	wait_pids();

#endif