#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
  int p1,p2,p3,p4,p5;
  int pid1, pid2, pid3;
  int stat;
  char[2] p1 = "p1", p2="p2", p3="p3";
  pid1 = fork();
  if (pid1 == 0) {
    stampaNuovo(p2, getpid(), getppid());
    pid2 = fork();
    if (pid2 == 0) {
      stampaNuovo(p3, getpid(), getppid());
      exit(2);
    } 
    exit(0);
  } else {
    stampaNuovo(p1, getpid(), getppid());
    wait(&stat);
  }
}

void stampaNuovo(char *P, int pid, int pid_padre) {
  printf("processo %c con pid = %d e padre = %d \n", *P, pid, pid_padre);
}