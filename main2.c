#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <time.h> 

#define   MAX  2

void  ChildProcess(void);                /* child process prototype  */

void  main(void) {
  int status, i;
  int pid[MAX];

  for (i = 0; i < MAX; i++) {
    pid[i] = fork();
    
    if (pid[i] == 0) {
      ChildProcess();
    } else if (pid[i] == -1) {
      printf("Error");
    }
  }
  for (i = 0; i < MAX; i++) {
     wait(&status);
     printf("Child Pid: %d has completed!\n", pid[i]);
  }
}

void  ChildProcess(void) {
  int i;
  srand(time(0));
  int randomNum = (rand() % 30 + 1);

  for (i = 1; i <= randomNum; i++) {
    int randomTime = (rand() % 10 + 1);
    pid_t child = getpid();
    pid_t parent = getppid();

    printf("Child Pid: %d is going to sleep!\n", child);
    sleep(randomTime);
    printf(" Child Pid: %d is awake!\n Where is my Parent: %d?\n", child, parent);
  }
  exit(0);
}