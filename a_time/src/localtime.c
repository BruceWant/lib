#include <time.h>
#include <stdio.h>

int main()
{
    time_t t;
    struct tm *locp;
    struct tm loc;

    t = time(NULL);

    locp = localtime(&t);
    if (NULL == locp)
    {
        perror("localtime");
        return -1;
    }

    loc = *locp;

    printf("year=%d, mon=%d mday=%d hour=%d min=%d sec=%d ",
            loc.tm_year, loc.tm_mon, loc.tm_mday, loc.tm_hour,
            loc.tm_min, loc.tm_sec);
    printf("wday=%d yday=%d isdst=%d\n",
            loc.tm_wday, loc.tm_yday,loc.tm_isdst);
    printf("asctime formats the localtime as: %s", asctime(&loc));

    return 0;
}
