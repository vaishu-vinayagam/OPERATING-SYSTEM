#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main () {
   int pfd1[2],pfd2[2],num,n,sum = 0,r,temp;
   pid_t cid,gcid;
   if (pipe(pfd1) == -1) {
       perror("pipe1 failed");
   }
   if (pipe(pfd2) == -1) {
       perror("pipe2 failed");
   }
   cid = fork();
   if(cid != 0) {
       printf("PARENT PROCESS\n");
       printf("Enter a number:\t");
       scanf("%d",&num);
       close(pfd1[0]);
       write(pfd1[1], &num, sizeof(num));
       close(pfd1[1]);
       wait(NULL);
       close(pfd2[1]);
       read(pfd2[0], &sum, sizeof(sum));
       if(num%2==0)  {
           printf("The number %d is even ",num);  }
       close(pfd2[0]);
       } else {
           printf("CHILD PROCESS\n");
           wait(NULL);
           close(pfd1[1]);
           read(pfd1[0], &num, sizeof(num));
           while(num > 0) {
               sum += (num%10)*(num%10);
               num/=10;
           }
           printf("Square is: %d\n",sum);
           close(pfd1[0]);
           close(pfd2[0]);
           write(pfd2[1],&sum,sizeof(sum));
           close(pfd2[1]);
     }
     return 0;
}
