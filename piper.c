#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  int READ = 0;
  int WRITE = 1;
  int fds[2];
  int fds2[2];
  int f;
  pipe(fds);
  pipe(fds2);
  f = fork();
  
  if( f == 0 ){
    close(fds[WRITE]);
    int s;
    int *p = &s;
    read(fds[READ], p, sizeof(s));
    printf("[child] doing maths on: %d\n", s);

    s = s*s;
    close(fds2[READ]);
    write(fds2[WRITE], p, sizeof(s));
  }
  
  else{
    close(fds[READ]);
    int s = 15;
    int *p = &s;
    write(fds[WRITE], p, sizeof(s));
    printf("[parent] sending: %d\n", s);

    int new_s;
    int * new_p = &new_s;
    read(fds2[READ], new_p, sizeof(new_p));
    printf("[parent] received: %d\n", new_s);
  }
}
