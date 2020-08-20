#include <time.h>
#include <stdio.h>

int main()
{
    time_t t;
    char *ct;

    t = time(NULL);

    ct = ctime(&t);
    if (NULL == ct)
    {
        perror("ctime()");
        return -1;
    }
    printf("%s", ct);

    return 0;

}
