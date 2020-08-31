#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    int ret = 0;
    if (argc < 3)
    {
        printf("kill <pid> <signal>\n");
        return -1;
    }

    long pid = strtol(argv[1], NULL, 10);
    int sig = atoi(argv[2]);

    printf("pid: %ld, sig: %d\n", pid, sig);
    ret = kill(pid, sig);
    if (0 == ret)
    {
        printf("sig:%d send to pid: %ld\n", sig, pid);
    }
    else
    {
        if (EPERM == errno)
        {
            perror("permision denied");
        }
        else if (ESRCH == errno)
        {
            perror("search");
            printf("pid: %ld does not exist\n", pid);
        }
        else
        {
            perror("EINVAL error");
        }
    }

    return 0;
}
