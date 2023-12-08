#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

/** Represents text as a zero-terminated sequence of characters. */
typedef char *String;

/**
 * The main entry point for the application.
 *
 * @return An exit code. This value is always 0, indicating success.
 */
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
