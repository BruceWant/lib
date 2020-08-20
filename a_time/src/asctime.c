#include <time.h>
#include <stdio.h>

int main()
{
    time_t t;
    struct tm *gmp;
    struct tm gm;

    t = time(NULL);

    gmp = gmtime(&t);
    if (NULL == gmp)
    {
        perror("gmtime");
        return -1;
    }

    gm = *gmp;

    printf("asctime formats the gmtime: %s", asctime(&gm));
    printf("ctime formats the time() as : %s", ctime(&t));

    return 0;
}
