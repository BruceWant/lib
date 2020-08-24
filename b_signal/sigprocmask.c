#include <signal.h>
#include <string.h>
#include <stdio.h>

int main()
{
    sigset_t curMask;

    if (-1 == sigprocmask(SIG_BLOCK, NULL, &curMask))
    {
        perror("sigprocmask");
        return -1;
    }

    for (int i = 1; i < NSIG; i++)
    {
        if (sigismember(&curMask, i))
        {
            printf("%d: %s", i, strsignal(i));
        }
    }

    return 0;
}
