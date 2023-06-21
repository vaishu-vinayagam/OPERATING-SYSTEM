#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
   int p1,p2,p3,p4,p5;
   p1=fork();
   if(p1==0) {//Process2 created
      printf("Child process created(P2)\nProcess id(p2):%d\tParent process id(P1):%d\n",getpid(),getppid());
   }
   else if(p1<0) {//Process2 not created
      printf("\nChild process not created\n");
   }
   else {//Instance of main(Proces1)
      wait(NULL);
      printf("Process created(P1)\nProcess id(p1):%d\tParent process id:%d\n",getpid(),getppid());
      p2=fork();
      if(p2==0) {//Process3 created
         printf("Child process created(P3)\nProcess id(p3):%d\tParent process id(P1):%d\n",getpid(),getppid());
         p3=fork();
         if(p3==0) {//Process4 created
             printf("Child process created(P4)\nProcess id(p4):%d\tParent process id(P3):%d\n",getpid(),getppid());
             p4=fork();
             if(p4==0) {//Process5 created
                 printf("Child process created(P5)\nProcess id(p5):%d\tParent process id(P4):%d\n",getpid(),getppid());
             }
             else if(p4<0) {//Process5 not created
                 printf("Child process not created\n");
             }
             else {//Instance of Process4
                 wait(NULL);
                 p5=fork();
                 if(p5==0) {//Process6 created
                     printf("Child process created(P6)\nProcess id(p6):%d\tParent process id(P4):%d\n",getpid(),getppid());
                 }
                 else if(p5<0) {//Process6 not created
                     printf("Child process not created\n");
                 }
                 else {//Instance of Process4
                     wait(NULL);
                 }
             }
         }
         else if(p3<0) {//Process4 not created
            printf("Child process not created\n");
         }
         else {//Instance of Process3
            wait(NULL);
         }
      }
      else if(p2<0) {//Process3 not created
         printf("Child process not created\n");
      }
      else {//Instance of main(Process1)
          wait(NULL);
      }
   }
   return 0;
}
