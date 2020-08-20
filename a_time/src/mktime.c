#include <time.h>
#include <stdio.h>

int main()
{
    time_t t;
    struct tm *gmp, *locp;
    struct tm gm, loc;

    t = time(NULL);

    gmp = gmtime(&t);
    if (NULL == gmp)
    {
        perror("gmtime");
        return -1;
    }
    gm = *gmp;

    locp = localtime(&t);
    if (NULL == locp)
    {
        perror("localtime");
        return -1;
    }
    loc = *locp;

    printf("mktime() of gmtime() value: %ld secs\n", mktime(&gm));
    printf("mktime() of localtime() value: %ld secs\n", mktime(&loc));
    printf("time(): %ld\n", t);

    return 0;
}
