#include <stdio.h>
#include <stdlib.h>
#include "bor-util.h"

int main(int argc, char* argv[])
{
    (void) argc;
    (void) argv;

    char buff[11];
    int p[2];
    ssize_t r;

    if(pipe(p) < 0)
    {
        perror("Pipe");
        exit(1);
    }

    r = bor_read_str(0, buff, 11);
    if(r <= 0) exit(1);
    r = bor_write_str(p[1], buff);
    if(r <= 0) exit(1);

    r = bor_read_str(p[0], buff, 4);
    r = bor_write_str(1, buff);

    int pid = fork();
    
    if(pid == 0)
    {
        close(p[1]);

        r = bor_read_str(p[0], buff, 8);
        if(r <= 0) exit(1);
        r = bor_write_str(1, buff);
        if(r <= 0) exit(1);

        close(p[0]);
    }

    close(p[0]);
    close(p[1]);

    printf("\n");
    exit(0);
 
}
