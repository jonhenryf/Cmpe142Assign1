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

    pid_t pid = fork();
    int status;

    if (pid == -1) {
        cout << "Failed to fork" << endl;
        return;
    }

    else if (pid == 0) {
        if (execv(command[0], command) < 0) {
            cout << " Could not execute" << endl;
        }

        exit(0);
    }

    else {
        waitpid(pid, &status, WUNTRACED);
        return;
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
            char* currentdir = getcwd(s, 100);

            if(command[1] == NULL) {
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

string path(string A)
{

    stack<string> st;
    string dir;
    string res;
    res.append("/");
    int len_A = A.length();

    for (int i = 0; i < len_A; i++) {

        dir.clear();

        while (A[i] == '/')
            i++;

        while (i < len_A && A[i] != '/')
        {
            dir.push_back(A[i]);
            i++;
        }

        if (dir.compare("..") == 0)
        {
            if (!st.empty())
                st.pop();
        }
        else if (dir.compare(".") == 0)
            continue;

        else if (dir.length() != 0)
            st.push(dir);
    }
    stack<string> st1;
    while (!st.empty()) {
        st1.push(st.top());
        st.pop();
    }

    while (!st1.empty()) {
        string temp = st1.top();
        if (st1.size() != 1)
            res.append(temp + "/");
        else
            res.append(temp);

        st1.pop();
    }

    return res;
}

