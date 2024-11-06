#include <stdio.h>

int main(int ac, char *args[])
{
	while(*args)
	{
		printf("%s\n", *args++);
	}
}