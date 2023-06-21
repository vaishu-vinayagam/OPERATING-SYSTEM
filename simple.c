#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
   printf("Process id ie. Process1: %d \n Parent id: %d",getpid(),getppid());
   int p=fork();
   if(p==0)
   {
      printf("\nChild process ie. Process 2 created\n%d \t %d",getpid(),getppid());
      int q=fork();
      if(q==0)
      {
          printf("\nChild process ie. Process 3 created\n%d \t %d",getpid(),getppid());
      }
      else if(q<0)
      {
          printf("\nChild process ie. Process 3 not created");
      }
      else
      {
          wait(NULL);
      }
   }
   else if(p<0)
   {
      printf("\nChild process ie. Process 2 not created");
   }
   else
   {
      wait(NULL);
   }
   return 0;
}
