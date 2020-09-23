#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int safe_add(int a, int b)
{
    if (a > 0 && b > INT_MAX - a)
    {
        printf("%d + %d = %d; overflow\n", a, b, a+b);
        return -1;
    }
    else if (a < 0 && b < INT_MIN - a)
    {
        printf("%d + %d = %d; underflow\n", a, b, a+b);
        return -1;
    }

    return a + b;
}


int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("%d + %d = %d\n", a, b, safe_add(a,b));

    return 0;
}
