#include <time.h>
#include <stdio.h>

int main()
{
    time_t t;
    struct tm *gmp;
    struct tm gm;

    t = time(NULL);

    gmp = gmtime(&t);
    if (gmp == NULL)
    {
        perror("getime");
        return -1;
    }

    gm = *gmp;
    printf("year=%d, mon=%d mday=%d hour=%d min=%d sec=%d ",
            gm.tm_year, gm.tm_mon, gm.tm_mday, gm.tm_hour,
            gm.tm_min, gm.tm_sec);
    printf("wday=%d yday=%d isdst=%d\n",
            gm.tm_wday, gm.tm_yday,gm.tm_isdst);
    return 0;
}
