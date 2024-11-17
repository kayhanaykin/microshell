all:
	@gcc -Wall -Werror -Wextra exec.c exec_cd.c utilities.c main.c -o microshell 

1:
	./microshell
2:
	./microshell /bin/ls
3:
	./microshell /bin/echo hi
4:
	./microshell ";"
5:
	./microshell ";" ";"
6:
	./microshell /bin/echo hi "|" cat -e
7:
	./microshell /bin/echo hi "|" cat -e "|" cat -e "|" cat -e
8:
	./microshell /bin/echo hi ";" /bin/ls
9:
	./microshell /bin/echo hi ";" /bin/ls ";"
10:
	./microshell /bin/echo hi ";" /bin/ls ";" /usr/bin/grep ex
