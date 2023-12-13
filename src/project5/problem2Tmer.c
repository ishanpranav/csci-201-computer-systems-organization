#include <signal.h>
#include <stdio.h>
#include <unistd.h>

typedef char *String;

int seconds;
int resets;

void sigint(int signal)
{
    resets++;

    if (resets == 0)
    {
        pid_t ppid = getppid();

        kill(ppid, SIGINT);
    }
    else
    {
        seconds = 0;
    }
}

int main(int count, String args)
{
    sleep(1);
    signal(SIGINT, sigint);

    while (seconds < 10)
    {
        fprintf(stdout, "Time: %i\n", seconds);
        fflush(stdout);
        sleep(1);

        seconds++;
    }

    return 0;
}
