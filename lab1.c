#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int main() {
    pid_t pid;
    printf("\nChild process id is %d and parent's id is %d\n", getpid(), getppid());
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "\nFork Failed \n \n");
        return 1;
    }
    else if (pid == 0) {
      //printf("\nCurrent child process id %d\n", getpid());
        signal(SIGINT, SIG_DFL);
        while (1) {
            printf("\nInside Child %d\n", getpid());
            sleep(1);
        }
    }
    else {
        wait(NULL);
        printf("\nChild process finished \n");
    }
    return 0;
}
