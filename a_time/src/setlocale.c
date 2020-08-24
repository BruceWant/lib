#include <locale.h>
#include <time.h>
#include <stdio.h>


int main()
{
    char *locale = NULL;
    time_t t;
    struct tm *locp;

    locale = setlocale(LC_ALL, "zh_CN.utf8");
    if (NULL == locale)
    {
        perror("setlocale");
        return -1;
    }

    t = time(NULL);
    printf("ctime: %s\n", ctime(&t));
    locp = localtime(&t);
    printf("asctime: %s\n", asctime(locp));

    printf("%s\n", locale);

    return 0;
}
