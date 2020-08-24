#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void handler(int sig)
{
    /* unsafe, becuase of async */
    printf("Ouch\n");
}

int main()
{
    if (signal(SIGINT, handler) == SIG_ERR)
    {
        perror("signal()");
        return -1;
    }

    for (int i = 0; ; i++)
    {
        printf("%d\n", i);
        sleep(5);
    }

    return 0;
}
