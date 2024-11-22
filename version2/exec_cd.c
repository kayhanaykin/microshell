#include "minishell.h"

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