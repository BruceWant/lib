#include <signal.h>
#include <unistd.h>
#include <stdio.h>


static void handler(int sig)
{
    const char str[] = "Ouch\n";
    write(STDIN_FILENO, str, sizeof(str));
}


int main()
{
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = handler;
    if (-1 == sigaction(SIGINT, &sa, NULL))
    {
        return -1;
    }

    for (int i = 0;; i++)
    {
        printf("%d\n", i);
        sleep(3);
    }

    return 0;
}
