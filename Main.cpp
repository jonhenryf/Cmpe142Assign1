#include <sys/wait.h>
#include <sys/types.h>
#include <iostream>
#include <err.h>
#include <fstream>
#include <ostream>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;

char **parseline(char *line) {
    int buffersize = 64;
    int index = 0;
    char *parsetoken;
    char **tokens = (char**)malloc(buffersize * sizeof(char*));

    parsetoken = strtok(line, " \n");
    while (parsetoken != NULL) {
        tokens[index] = parsetoken;
        index++;

    }

    tokens[index] = NULL;
    return tokens;


}

int main(int argc, char **argv) {
    char *line = NULL;
    size_t linesize = 0;


    while (1) {
        cout << "@root> ";
        getline(&line, &linesize, stdin);

        if (strncmp("exit", line, 4) == 0) {
            exit(0);
        }

        else if (strncmp("cd", line, 2) == 0) {

            char s[100];

            printf("%s\n", getcwd(s, 100));

            chdir("..");

            printf("%s\n", getcwd(s, 100));

        }

        else if (strncmp("path", line, 4) == 0) {

        }

        else if (strncmp("help", line, 4) == 0) {
            cout << "nahhh" << endl;
        }

        else {

            parseline(line);
            pid_t i = fork();

            if(i == 0) {
                // execv();

            }

            else if(i > 0) {

            }

            else {
                cout << "Fork Failure" << endl;
            }

        }

    }

    free (line);
    if (ferror(stdin)) {
        err(1, "getline");
    }}