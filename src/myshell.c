/*Author: Colin Ekedigwe - Student Number: 20403046 - I am aware of the Universities regards to breaches of academic
integrity and plagiarism as serious. Any assistance I have gotten by using code to help me has been referenced and
stated with links. I am writing this to acknowledge that a breach of the rules may result in penalties being imposed.*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>                         //https://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
#include <sys/wait.h>
#include <dirent.h>                            // ordered sequence of all directories in a particular order
#include "myshell.h"                           // Calling my functions in this file
#include "utility.c"
#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token separators

int main (int argc, char ** argv)
{
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char ** arg;                               // working pointer thru args
    char * prompt = "--> ";                    // shell prompt
    char * getcwd(char *buf, size_t size);     // Determines the path name of the pwd and stores it in buffer
    /* keep reading input until "quit" command or eof of redirected input */

    // This is where I got the idea to make this welcome section https://www.geeksforgeeks.org/making-linux-shell-c/
    intro();

    while (!feof(stdin)) {
        /* get command line from input */
        fputs (prompt, stdout); // write prompt

        if (fgets (buf, MAX_BUFFER, stdin )) { // read a line
            /* tokenize the input into args array */
            arg = args;
            *arg++ = strtok(buf,SEPARATORS);   // tokenise input

            while ((*arg++ = strtok(NULL,SEPARATORS)));

            // last entry will be NULL
            if (args[0] == NULL) {
            	continue;
            	}                     // if there's anything there
            /* check for internal/external command */
            if (!strcmp(args[0],"clr")) { // "clear" command
                system("clear");
                continue;
            }
            // Used this structure for program to call my functions in 'myshell.h'
            else if (!strcmp(args[0],"dir")) { // "list" command
                dir();
                continue;
            }
            else if (!strcmp(args[0],"environ")) { // "environment" command
                environment(args);
                continue;
            }
            else if (!strcmp(args[0],"cd")) { // "change" directory command
            	cd(args);
            	continue;
            }
            else if (!strcmp(args[0],"echo")) { // "echo" command
            	echo(args);
            	continue;
            }
            else if (!strcmp(args[0],"help")) { // "help" command
            	system("more ../manual/readme.md");
            	continue;
            }
            else if(!strcmp(args[0],"pause")) {  // "pause" command
                pause_prog();
                continue;
            }

            else if (!strcmp(args[0],"quit")) // "quit" command
                break;                        // break out of 'while' loop

            else
            {
                ext_commands(args); // call external commands function
            }
        }
    }
    return 0;
}
