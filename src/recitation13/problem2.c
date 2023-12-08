#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

typedef char *String;

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Error: fork() failed.\n");

        return 1;
    }

    if (pid == 0)
    {
        String childArgs[] = {"problem1", NULL};

        execv(childArgs[0], childArgs);
        fprintf(stderr, "Error: execv() failed.\n");

        return 1;
    }

    int status = -1;
    pid_t waitResult;

    do
    {
        waitResult = waitpid(pid, &status, WNOHANG);

        if (waitResult < 0)
        {
            fprintf(stderr, "Error: wait() failed.\n");

            return 1;
        }

        sleep(1);
        kill(pid, SIGINT);
    } while (status == -1);

    return 0;
}
