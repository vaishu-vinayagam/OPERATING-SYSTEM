#create process hierarchy
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
  int p,p1,e;
  p=fork();
  if(p==0) {//Child process1 created
    printf("Child process1  Process id:%d\tParent id:%d\n",getpid(),getppid());
    p1=fork();
    if(p1==0) {//Child process2 created
      printf("Child process2  Process id:%d\tParent id:%d\n",getpid(),getppid());
    
      execlp("cat","cat","process",NULL);
    }
    else if(p1<0) {//Child process2 not created
      printf("\nChild process2 not created");
    }
    else {//Instance of Child process1
      wait(NULL);
    }
  }
  else if(p<0) {//Child process1 not created
    printf("\nChild process1 not created");
  }
  else {//Instance of main process
    wait(NULL);
    printf("Parent process process id:%d\tParent id:%d\n",getpid(),getppid());  }
  return 0;
}
