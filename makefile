all:
	clear
	gcc -Wall -Wextra -Werror helper.c exec.c main.c
	./a.out ls
