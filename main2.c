#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>

void ParentProcess(void);                /* parent process prototype */
void  ChildProcess(void);                /* child process prototype  */

void  main(void)
{
  pid_t  pid;
  
  pid_t childOne = fork();
  pid_t childTwo = -1;
  
  // Parent
  if(childOne > 0){
    childTwo = fork();
    // Parent
    if(childTwo > 0){
      ParentProcess();
    }else{
      srand(842091);
      // Child 2
      ChildProcess();
    }
  }else{
    srand(298487123);
    // Child 1
    ChildProcess();
  }
  exit(0);
}

void ParentProcess(void){
  int status;
  pid_t copid = waitpid(-1, &status, 0);
  printf("Child Pid: %d has completed!\n", copid);
  pid_t ctpid = waitpid(-1, &status, 0);
  printf("Child Pid: %d has completed!\n", ctpid);
}

void ChildProcess(void)
{
  pid_t pid = getpid();
  pid_t ppid = getppid();
  int i;
  for (i = 1; i <= 30; i++){
    printf("Child Pid: %d is going to sleep!\n", pid);
    sleep(random_int(1, 10));
    printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", pid, ppid);
  }
  exit(0);
}

int random_int(int min, int max)
{
   return min + rand() % (max+1 - min);
}