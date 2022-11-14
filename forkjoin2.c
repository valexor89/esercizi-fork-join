#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int pid1, pid2, retv1, retv2;
  int r1, r2, r3, ris;

  //siamo nel processo padre
  pid1 = fork();

  if (pid1 == 0) {
    //siamo nel processo figlio 1
    r1 = (2+4);
    exit(r1);
  } else {
    pid2 = fork();
    if (pid2 == 0) {
      //siamo nel processo figlio 2
      r2 = (7+3);
      exit(r2);
    } else {
      //siamo nel processo padre
      r3 = -10;
    }
  }

  //dobbiamo chiudere i processi figli
  waitpid(pid1, &retv1, 0);  
  r1 = WEXITSTATUS(retv1);                // prende il risultato del figlio
  printf("-> r1 = %d \n", r1);
  //printf("-> r1 = %d \n", retv1>>8);

  waitpid(pid2, &retv2, 0);              
  r2 = WEXITSTATUS(retv2);                // prende il risultato del figlio
  printf("-> r2 = %d\n", r2);
  //printf("-> r2 = %d \n", retv2>>8);

  ris = 5*(r1*r2)+r3;
  printf("-> risultato finale ris = %d\n", ris);
  exit(0);
}