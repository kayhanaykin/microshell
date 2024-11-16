all:
	clear
	gcc -Wall -Wextra -Werror -g helper.c exec.c main.c -o microshell

1:
	./microshell /bin/echo hi

2:
	echo hi | cat -e
	ulimit -n 7; ./microshell /bin/ls -laR "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e \
"|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e \
"|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e \
"|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e \
"|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e \
"|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e \
"|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e \
"|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e \
"|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e \
"|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e \
"|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e "|" /usr/bin/cat -e 
