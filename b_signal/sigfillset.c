#include <signal.h>
#include <string.h>
#include <stdio.h>

int main()
{
    sigset_t set;

    if (-1 == sigfillset(&set))
    {
        perror("sigfillset");
        return -1;
    }

    for (int i = 1; i < NSIG; i++)
    {
        if (sigismember(&set, i))
        {
            printf("%d: %s\n", i, strsignal(i));
        }
    }

    return 0;
}
