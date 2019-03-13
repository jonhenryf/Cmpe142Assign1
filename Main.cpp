//
// Created by jonhenryf on 3/12/19.
//

#include <iostream>
#include <fstream>
#include <ostream>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;
#define token_buffsize 64 // for parse function
#define delimiter " \t\r\n\a"

char *readline()
{
    char *line = NULL;
    ssize_t buffersize = 0;
    cin.getline(line, buffersize);
    return line;
}

char parseline (char *line) {
    int buffersize = token_buffsize;
    int position = 0;
    char **tokens = (char**)malloc(buffersize * sizeof(char*));
    char *token;
    char **tokensback;

    token = strtok(line, delimiter);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= buffersize) {
            buffersize += token_buffsize;
            tokensback = tokens;
            tokens = (char**)realloc(tokens, buffersize * sizeof(char*));
        }

        token = strtok(NULL, delimiter);

    }

    token[position] = NULL;
    return tokens;

}

int execute() {

}

void unixloop(void) {
    char * line;
    char ** arguments;
    int stat;

    do {
        cout << ("BB> ") << std::endl;
        line = readline();
        arguments = parseline(line);
        stat = execute(arguments);

        free(line);
        free(arguments);
    }

    while (stat);

}

int main() {

        unixloop();
        return 0;

}


