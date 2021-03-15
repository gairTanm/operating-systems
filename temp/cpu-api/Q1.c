#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main() {
  pid_t pid;
  int x = 100;
  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "Failed\n");
    return 1;
  }
  else if (pid == 0) {
    signal(SIGINT, SIG_DFL);
    int i = 0;
    while (i < 5) {
      printf("%d\n", x);
      printf("hewwo\n");
      sleep(1);
      i += 1;
    }
  }
  else {
    wait(NULL);
    printf("parent\n");
  }
  return 0;
}