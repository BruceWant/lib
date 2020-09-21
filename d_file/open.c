#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>


int main()
{
    int fd = 0;
    char buf[64] = { 't', 'e', 's', 't' };
    char buf2[64] = { 0 };
    ssize_t ret = 0;

    fd = open("test", O_RDWR | O_CREAT | O_EXCL, 00664);
    if (-1 == fd)
    {
        if (errno == EEXIST)
        {
            fd = open("test", O_RDWR, 00664);
        }
        else
        {
            perror("create test");
            return -1;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        if (-1 == write(fd, buf, 64))
        {
            perror("write");
            return -1;
        }
    }

    if (-1 == lseek(fd, 0, SEEK_SET))
    {
        perror("lseek");
        return -1;
    }

    if (-1 == (ret = read(fd, buf2, 64)))
    {
        perror("read");
        return -1;
    }
    buf2[4] = '\0';

    printf("buf: %s, ret: %ld\n", buf2, ret);

    close(fd);
    return 0;
}
