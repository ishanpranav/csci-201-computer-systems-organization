#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#define DEFAULT_SECONDS 5
#define MESSAGE_1 "%d seconds starting... Now!                 "
#define MESSAGE_2 "%d seconds remaining...                     "
#define MESSAGE_3 "Out of time! Press <0> <ENTER> to continue.\n"
typedef char *String;

int seconds = DEFAULT_SECONDS;

void sigint(int signal)
{
    seconds = DEFAULT_SECONDS;
}

int main(int count, String args[])
{
    fprintf(stdout, MESSAGE_1, seconds);
    fflush(stdout);
    sleep(1);
    signal(SIGINT, sigint);

    while (seconds)
    {
        fprintf(stdout, "\r\b\r");
        fprintf(stdout, MESSAGE_2, seconds);
        fflush(stdout);
        sleep(1);

        seconds--;
    }

    fprintf(stdout, "\r\b\r");
    fprintf(stdout, MESSAGE_3);
    kill(getppid(), SIGINT);
    
    return 0;
}
