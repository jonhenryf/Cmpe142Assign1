//
// Created by jonhenryf on 3/12/19.
//

#include <iostream>
#include <ostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
using namespace std;


char readline(void) {

}

char parseline () {

    int token_buffer_size = 64;

}

int execute() {

}

void unixloop(void) {
    char * line;
    char ** arguments;
    int stat;

    do {
        std::cout << ("BB> ") << std::endl;
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


