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

#define token_buffersize 64
#define token_delim " \t\r\n\a"
#define num_children 5

char ** parseline( char *line) {
    int buffersize = token_buffersize;
    int index = 0;
    char **command = (char**)malloc(buffersize * sizeof(char*));
    char *token;

    if (!command) {
        cout << "allocation error" << endl;
        exit(EXIT_FAILURE);
    }

    token = strtok(line, token_delim);
    while (token != NULL) {
        command[index] = token;
        index ++;

        if (index >= buffersize) {
            buffersize += token_buffersize;
            command = (char**)realloc(command, buffersize * sizeof(char*));
            if (!command) {
                cout << stderr << "allocation error" << endl;
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, token_delim);
    }

    command[index] = NULL;
    return command;

}

void execute (char** command) {

    for (int i = 0; i < num_children; i++) {

        pid_t pid = fork();
        int status;

        if (pid == -1) {
            cout << "Failed to fork" << endl;
            return;
        } else if (pid == 0) {
            if (execv(command[0], command) < 0) {
                cout << " Could not execute" << endl;
            }

            exit(0);
        } else {

            for (int i = 0; i <num_children; i++) {
                waitpid(pid, &status, WUNTRACED);
                return;
            }
        }
    }

}


int main(int argc, char **argv) {
    char **command;
    char *line = NULL;
    size_t linesize = 0;


    while (1) {
        cout << "Jontan@root> ";
        getline(&line, &linesize, stdin);

        command = parseline(line);

        if (!strcmp(command[0], "cd")) {
            char s[100];
            char* currentdir;

            if(command[1] == NULL) {

                chdir("/home");
                currentdir = getcwd(s, 100);
                cout << currentdir << endl;
            }

            else {
                chdir(command[1]);
                currentdir = getcwd(s, 100);
                cout << currentdir << endl;
            }
        }

        else if (!strcmp(command[0], "path")) {


        }

        else if (!strcmp(command[0], "exit")) {
            exit(0);
        }

        else {

            execute(command);

        }
    }
}







