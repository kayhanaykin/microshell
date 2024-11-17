#include "minishell.h"

static int	prev_check();
static int	next_check();

void	exec_cd()
{
	if (prev_check() == 1 || next_check() == 1)
	{
		return ;
	}
	else if (next_check() == 2)
	{
		error_handler("error: cd: bad arguments", NULL, 0);
	}
	else 
	{
		chdir(arg_ptr[i + 1]);
		i = i + 2;
	}
}

static int	prev_check()
{
	if (i == 1 || strcmp(arg_ptr[i - 1], ";") == 0)
		return (0);
	return (1);
}

static int next_check()
{
	int j = 1;
	while(arg_ptr[i + j] != NULL && strcmp(arg_ptr[i + j], ";") != 0
			&& strcmp(arg_ptr[i + j], "|") != 0)
	{
		j++;
	}
	if (arg_ptr[i + j] != NULL && strcmp(arg_ptr[i + j], "|") == 0)
		return (1);
	if (j == 1)
		return (2);
	else if ((j - 1) == 1)
		return (0);
	else
		return (2);
}