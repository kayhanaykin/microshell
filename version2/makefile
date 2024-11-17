all:
	@gcc -Wall -Werror -Wextra exec.c exec_cd.c utilities.c main.c -o microshell 

github:
	@gcc -Wall -Werror -Wextra github.c -o microshell 	

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
	./microshell /bin/echo hi "|" /bin/cat -e
7:
	./microshell /bin/echo hi "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e
8:
	./microshell /bin/echo hi ";" /bin/ls
9:
	./microshell /bin/echo hi ";" /bin/ls ";"
10:
	./microshell /usr/bin/grep ex
11:
	./microshell /bin/echo hi ";" /usr/bin/grep ex
12:
	./microshell /bin/echo hi ";" /bin/ls ";" /usr/bin/grep ex
13:
	./microshell /bin/echo hi "|" /bin/echo mi ";" /bin/ls "|"  /usr/bin/grep ex ";" /usr/bin/grep ex
14:
	./microshell /bin/echo hi "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e
15:
	ulimit -n 30; ./microshell /bin/ls -laR "|" /usr/bin/grep mi "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
	 "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e

16:
	./microshell cd