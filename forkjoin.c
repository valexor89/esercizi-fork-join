#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main() {
  int pid1, pid2;
  int r1, r2, r3;
  int retval1, retval2;
  pid1 = fork();
  
  if (pid1 == 0) {
    //processo figlio 1
    printf("processo figlio 1 \n");
    r1 = (2+4);
    exit(r1);
  } else {
    //processo padre
    printf("processo padre 1 \n");
    pid2 = fork();
    if (pid2 == 0) {
      //processo figlio 2
      printf("processo figlio 2 \n");
      r2 = (7+3);
      exit(r2);
    } else {
      //processo padre 2
      printf("processo padre 2 \n");
      r3 = 10;
    }
  }
  
  //fine elaborazione parallela

  //attendo figlio 1
  waitpid(pid1, &retval1, 0);
  r1 = WEXITSTATUS(retval1);
  printf("valore r1: %d \n", r1);

  
  //attendo figlio 2
  waitpid(pid2, &retval2, 0);
  r2 = WEXITSTATUS(retval2);
  printf("valore r2: %d \n", r2);

  r3 = 5*(r1*r2)-r3;

  printf("risultato finale: %d \n", r3);
  
}
