#include "bor-util.h"

int main(int argc, char* argv[])
{
    (void) argc;
    (void) argv;

    char buff[200];
    int p1[2];
    int p2[2];

    pid_t pidfils1;
    pid_t pidfils2;

    pidfils1 = fork();
    pidfils2 = fork();

    pipe(p1);
    pipe(p2);

    if(pidfils1 == 0) { // Fils 1
        dup(p1[1]);
        close(p1[1]);

        execl("/bin/ls", "ls", "-l", NULL);

        bor_read_str(0, buff, sizeof(buff));
        bor_write_str(p1[0], buff);

        dup(p1[0]);
        close(p1[0]);
    }

    if(pidfils2 == 0) { // Fils 2
        dup(p1[0]);
        close(p1[0]);

        dup(p2[1]);
        close(p2[1]);

        bor_read_str(p1[0], buff, sizeof(buff));

        bor_write_str(p1[0], buff);

        execl("/bin/sort", "sort", "", NULL);

        bor_read_str(p2[1], buff, sizeof(buff));
        bor_write_str(p2[1], buff);

        dup(p2[0]);
        close(p2[0]);
        dup(p1[1]);
        close(p1[1]);
    }

    close(0);

    dup(p2[0]);

    close(p2[0]);

    execl("/bin/head", "head" ,"-3", NULL);

    bor_read_str(p2[0], buff, sizeof(buff));
 
    bor_write_str(1, buff);

    dup(p2[1]);
    close(p2[1]);

    exit(0);
}
