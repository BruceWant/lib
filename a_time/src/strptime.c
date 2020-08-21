#define _XOPEN_SOURCE
#include <time.h>
#include <stdio.h>

int main()
{
    struct tm tm;
    char *str = "9:39:46pm 1 Feb 2011";
    char *format = "%I:%M:%S%p %d %b %Y";

    if (strptime(str, format, &tm) == NULL)
    {
        return -1;
    }

    printf("%s", asctime(&tm));

    return 0;
}
