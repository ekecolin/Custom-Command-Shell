-------------------------
NAME
-------------------------
myshell.c

-------------------------
DESCRIPTION
-------------------------
This shell is written in C programming language and supports built-in commands and external
commands. This is the user manual in which will guide you on how to use this shell correctly. When
the shell program starts you are greeted and introduced into the shell before you proceed using the
shell program.

-------------------------
SYNOPSIS
-------------------------
	1. clr
	2. dir [OPTION] ..
	3. environ
	4. cd [DIRECTORY]
	5. echov[STRING]
	6. help
	7. pause
	8. quit

-------------------------
INTERNAL COMMANDS
-------------------------
The shell program consists of internal and external commands. The internal commands are customed to this shell, the external commands are similar
to that on a normal bash shell which can be executed in this shell program. Commands are inputted after the prompt '-->'. Even if you mistakingly
press the wrong key an error will be displayed. Then a new prompt will be issued again.

-------------------------
BUILT-IN COMMANDS 
-------------------------
	1. 'clr' - Clears terminal screen
	2. 'dir' - Lists the contents of the selected directory in a list, if no argument given it lists contents of the current working directory.
	3. 'environ' - Shows a list of all the environment variables.
	4. 'cd' - cd [DIRECTORY] Takes an argument, to change the directory, No argument present, current working directory is the output.
	5. 'echo' - echo [STRING] Prints any words following the command "echo" to standard output, No argument given a newline is printed.
	6. 'help' - Opens the user manual of the shell, explains, internal/external commands, i/o redirection, program environment, background program execution and references used for the shell
	7. 'pause' - Pauses the program until the user presses 'Enter' from the keyboard
	8. 'quit' - Exists the shell program

-------------------------
OPTIONS
-------------------------
No options needed for any of the commands

-------------------------
I/O REDIRECTION
-------------------------
*NOT USED IN THIS SHELL*
It is the changing from where commmands read input to where commands send ouput.

programname arg1 arg2 < inputfile > outputfile
Characters used - ('<', '>' and '>>')

'>' - The program output is redirected into an output file. If an output files doesnt exist, the file will be created.
'>>' - The program output is appended into the end of the ouput file. If the output file doesnt exist, the file will be created

-------------------------
BACKGROUND EXECUTION/PROCESS
-------------------------
Foreground
Processes that require a user to start them or to interact with them. The shell waits for the process to 
end before taking another command
Background
Processes that are run independently of a user. They run in the background while the shell 
take on more commands from the user at the same time as these processes are running.

-------------------------
REFERENCE
-------------------------
[1] Healy, G., 2022, [online] Available at: <https://loop.dcu.ie/mod/assign/view.php?id=1799099> [Accessed 11 March 2022]
[2] Internet Archive. 2022. Operating System Concepts 10th : Abraham Silberschatz, Peter B. Galvin, and Greg Gagne : Free Download, Borrow, and Streaming : Internet Archive. [online] Available at: <https://archive.org/details/operatingsystemconcepts10th> [Accessed 11 March 2022]
[3] Ibm.com. 2022. IBM Docs. [online] Available at: <https://www.ibm.com/docs/en/aix/7.1?topic=processes-> [Accessed 11 March 2022]
[4] Tldp.org. 2022. Simple redirections. [online] Available at: <https://tldp.org/LDP/intro-linux/html/sect_05_01.html#sect_05_01_01> [Accessed 11 March 2022].
-------------------------

Author: Colin Ekedigwe - Student Number: 20403046 - I am aware of the Universities regards to breaches of academic 
integrity and plagiarism as serious. Any assistance I have gotten by using code to help me has been referenced and 
stated with links. I am writing this to acknowledge that a breach of the rules may result in penalties being imposed.
