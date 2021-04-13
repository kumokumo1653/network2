#include <stdio.h>
int main(void){


    int fd;
    char buf[10];

    fd = open("fdsample.c", 0);
    printf("%d\n",fd);
    read(fd, buf, 10);
    write(1, buf, 10);

    close(fd);
    return 0;
}