//
// Created by jonhenryf on 3/12/19.
//

#include <iostream>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>

using namespace std;


char *readline()
{
    char *line = NULL;
    ssize_t bfsize = 0;
    getline(&line, &bfsize);
    return line;
}

char parseline (char *line)
{


}

int run (char **args) {
    int status;
    pid_t apid, bpid;

    apid = fork();
    if (apid == 0)
    {
        //child

        //use exec function
    }
    else if (apid < 0)
    {
        //error
    }
    else
    {
        //parent

        //wait for child
    }

}

int execute()
{

}

void unixloop()
{

}

int main()
{

        unixloop();
        return 0;

}


