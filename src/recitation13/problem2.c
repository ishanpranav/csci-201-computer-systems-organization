#include <stdio.h>
#include <unistd.h>

typedef char *String;

int main()
{
    String childArgs[] = {"problem1", NULL};

    execv(childArgs[0], childArgs);
    fprintf(stderr, "Error: execv() failed.\n");

    return 1;
}
