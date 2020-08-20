#include <time.h>
#include <stdio.h>


int main()
{
    time_t t;

    t = time(NULL);
    if (-1 == t)
    {
        perror("time(NULL)");
    }

    printf("seconds since the Epoch (1 Jan 1970): %ld\n", t);

    return 0;
}
