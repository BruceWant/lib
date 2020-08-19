#include <sys/time.h>
#include <stdio.h>


int main()
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
    {
        perror("gettimeofday");
        return -1;
    }
    printf("gettimeofday() returned %ld secs, %ld microsecs\n",
            tv.tv_sec, tv.tv_usec);

    return 0;
}
