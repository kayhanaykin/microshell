#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> //waitpid

typedef struct s_data
{
	char *cmd_head;	

} t_data;

char	**create_cmd(char *agrs[], int i)
{
	static 	start;
	char	**cmd;
	char	*cmd_args;

	cmd = malloc((i - start + 1) * sizeof(char *));
	cmd[i - start] = '\0';
	while (start < i)
	{
		cmd[start] = args[start];
		start++;
	}
	start++;
	return(cmd);
}

int main(int ac, char *args[], char *env[])
{
	int		i;
	char 	**cmd;

	(void)ac;
	i = 0;
	while (args[i] != '|' && args[i] != ';')
	{
		if (args[i] == '|')
		{
			cmd = create_cmd(args, i);
		}
		if (args[i] == ';' || args[i] == '\0') //null ile bitiyor muydu args?
		{
			send_execution(args, env);
		}
		i++;
	}
}	