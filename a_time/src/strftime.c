#include <time.h>
#include <stdio.h>


int main()
{
    time_t t;
    struct tm *locp;
    struct tm loc;
    char buf[256] = { 0 };

    t = time(NULL);
    locp = localtime(&t);
    if (NULL == locp)
    {
        return -1;
    }

    strftime(buf, 256, "%c", locp);

    printf("%s\n", buf);

    return 0;
}
