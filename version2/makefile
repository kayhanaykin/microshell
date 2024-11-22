all:
	@gcc -Wall -Werror -Wextra exec.c exec_cd.c utilities.c main.c -o microshell 

github:
	@gcc -Wall -Werror -Wextra github.c -o microshell

1:
	@./microshell
2:
	@./microshell /bin/ls
3:
	@./microshell /bin/echo hi
4:
	@./microshell ";"
5:
	@./microshell ";" ";"
6:
	@./microshell /bin/echo hi "|" /bin/cat -e
7:
	@./microshell /bin/echo hi "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e
8:
	@./microshell /bin/echo hi ";" /bin/ls
9:
	@./microshell /bin/echo hi ";" /bin/ls ";"
10:
	@./microshell /usr/bin/grep ex
11:
	@./microshell /bin/echo hi ";" /usr/bin/grep ex
12:
	@./microshell /bin/echo hi ";" /bin/ls ";" /usr/bin/grep ex
13:
	@./microshell /bin/echo hi "|" /bin/echo mi ";" /bin/ls "|"  /usr/bin/grep ex ";" /usr/bin/grep ex
14:
	@./microshell /bin/echo hi "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
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
	ulimit -n 30; @./microshell /bin/ls -laR "|" /usr/bin/grep mi "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e \
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
	@./microshell cd
17: 
	@./microshell cd ..
18: 
	@./microshell cd ../dfdf
19:
	@./microshell cd ../dfdf "|" /bin/echo hi
20:
	@./microshell /bin/ls ";" cd ../dfdf "|" /bin/echo hi
21:
	@./microshell cd ../dfdf kkk jj
22:
	@./microshell cd ";"
23:
	@./microshell /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep w ";" /bin/cat reserv_microsh.c
24:
	@./microshell /bin/cat reserv_microsh.c ";" /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep b "|" /usr/bin/grep z ";" /bin/cat reserv_microsh.c
25:
	@./microshell /bin/cat reserv_microsh.c




26:
	ulimit -n 30
27:
	@./microshell /bin/ls
28:
	@./microshell /bin/l@s microshell.c
29:
	@./microshell /bin/ls salut
30:
	@./microshell ";"
31:
	@./microshell ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";"
32:
	@./microshell ";" ";" /bin/echo OK
33:
	@./microshell ";" ";" /bin/echo OK ";"
34:
	@./microshell ";" ";" /bin/echo OK ";" ";"
35:
	@./microshell ";" ";" /bin/echo OK ";" ";" ";" /bin/echo OK
36:
	@./microshell /bin/ls "|" /usr/bin/grep a.out
37:
	@./microshell /bin/ls "|" /usr/bin/gre@p microshell "|" /usr/bin/grep micro
38:
	@./microshell /bin/ls "|" /usr/bin/gre@p microshell "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro
39:
	@./microshell /bin/ls "|" /usr/bin/gre@p microshell "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell
40:
	@./microshell /bin/ls ewqew "|" /usr/bin/grep micro "|" /bin/cat -n ";" /bin/echo dernier ";" /bin/echo
41:
	@./microshell /bin/ls "|" /usr/bin/grep micro "|" /bin/cat -n ";" /bin/echo dernier ";" /bin/echo ftest ";"
42:
	@./microshell /bin/echo ftest ";" /bin/echo ftewerwerwerst ";" /bin/echo werwerwer ";" /bin/echo qweqweqweqew ";" /bin/echo qwewqeqrtregrfyukui ";"
43:
	@./microshell /bin/ls ftest ";" /bin/ls ";" /bin/ls werwer ";" /bin/l@s microshell.c ";" /bin/ls subject.fr.txt ";"
44:
	@./microshell /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";"
45:
	@./microshell /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep b ";" /bin/cat reserv_microsh.c ";"
46:
	@./microshell /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep w ";" /bin/cat reserv_microsh.c ";"
47:
	@./microshell /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep w ";" /bin/cat reserv_microsh.c
48:
	@./microshell /bin/cat reserv_microsh.c ";" /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep b "|" /usr/bin/grep z ";" /bin/cat reserv_microsh.c
49:
	@./microshell ";" /bin/cat reserv_microsh.c ";" /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep b "|" /usr/bin/grep z ";" /bin/cat reserv_microsh.c
50:
	@./microshell blah "|" /bin/echo OK
51:
	@./microshell blah "|" /bin/echo OK ";"
52:
	@./microshell ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" blah "|" /bin/echo OK ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";"
53:
	@./microshell cd ";" /bin/ls
54:
	@./microshell /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|"
