all:
	clear
	gcc -Wall -Werror -Wextra helper.c exec.c main.c
	./a.out ls
