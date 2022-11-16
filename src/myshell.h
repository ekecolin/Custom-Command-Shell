/* Decided to put my functions here as it is easier to change and write them while I can just call them
 in my myshell.c file by using '#include "myshell.h"' which calls the fnctions, so this place is the
 brains of the program and myshell.c just triggers this which the functions I call.*/

#include <limits.h>
#include <string.h>

void dir() // used https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/
		   // https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
{
    struct dirent *files; // Pointer for the directory
    DIR *dir = opendir(".");  // Opendir() returns any dir with . and of DIR type
    if (dir == NULL){  // Returns NULL if you cant open a directory
        printf("No such file or directory exists, Please try again.");
    }

	//Researched about 'readdir' here -> https://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    while ((files = readdir(dir)) != NULL)  // Returns a pointer representing a directory at that current position
    printf("%s\n", files -> d_name);
    closedir(dir);  // Close directory after opening it, as its not automatically closed
}

extern char **environ;

//function for "environ" command
void environment(char *argv[]) // used https://loop.dcu.ie/mod/book/view.php?id=1796411&chapterid=377037
{
	int i;
   	for (i = 0; environ[i] != NULL; i++)
	   printf("%s\n",environ[i]);
}

//function for "echo" command
void echo(char *argv[]) {
    for (int i = 1; argv[i]; i++)
        printf("%s ", argv[i]);
    printf("\n");
}

// For this section I got some assistance from a class mate in how to get the change directory command
//function for "cd" command
void cd(char *argv[])
{
    char cwd[100];
    getcwd(cwd, sizeof(cwd)); // getting the current working directory

    if(argv[1] == NULL)
    {
        printf("%s\n", cwd); //print current directory
    }
    else
    {
        chdir(argv[1]);
        getcwd(cwd, sizeof(cwd));
        setenv("PWD", cwd, 1);
    }
}

// function for "pause" command
// I called it pause_prog, cause pausse is used in the external command so this conflicts with the program
void pause_prog()
{
    printf("The Program has been paused, press 'Enter' to continue the program.\n");
    while(getchar() != '\n'); // Once a newline is made ('Enter key is pressed on keyboard') the program continues
}

// This is where I got the code for external commands https://brennan.io/2015/01/16/write-a-shell-in-c/
int ext_commands(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
  // Child process
  if (execvp(args[0], args) == -1) {
      perror("myshell");
  }
  exit(EXIT_FAILURE);
} else if (pid < 0) {
  // Error forking
  perror("myshell");
} else {
  // Parent process
  do {
      wpid = waitpid(pid, &status, WUNTRACED);
    }
    while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

/*Author: Colin Ekedigwe - Student Number: 20403046 - I am aware of the Universities regards to breaches of academic
integrity and plagiarism as serious. Any assistance I have gotten by using code to help me has been referenced and
stated with links. I am writing this to acknowledge that a breach of the rules may result in penalties being imposed.*/
