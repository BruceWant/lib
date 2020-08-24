#define _GNU_SOURCE
#include <signal.h>
#include <string.h>
#include <stdio.h>

int main()
{
    for (int i = 1; i < NSIG; i++)
    {
        printf("%d: %s\n", i, strsignal(i));
    }

    return 0;
}
