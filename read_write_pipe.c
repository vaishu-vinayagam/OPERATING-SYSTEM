#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
int isPerfectSquare(int n) {
   int temp=sqrt(n);
   if(temp*temp==n)
      return 1;
}
int isPrime(int n) {
    int i,temp=0;
    for(i=2;i<=(n/2);i++){
       if(n%i==0) {
          temp=1;
          break;
      }
    }
    if(temp==1)
       return 0;
    else
       return 1;
}
int main()
{
   int p1[2],p2[2],p3[2];
   int st1,st2,st3;
   int pid,i,j,k=0,l=0,num1,num;
   int arr[100],evenarr[100],oddarr[100],n;
   st1 = pipe(p1);
   if (st1 == -1) {
      printf("Unable to create pipe 1 \n");
      return 1;
   }
   st2 = pipe(p2);
   if (st2 == -1) {
     printf("Unable to create pipe 2 \n");
     return 1;
   }
   st3 = pipe(p3);
   if (st3 == -1) {
     printf("Unable to create pipe 3 \n");
     return 1;
   }
   printf("Enter the total number of elements:");
   scanf("%d",&n);
   for(i=0;i<n;i++) {
      arr[i]=rand()%1000;
   }
   write(p1[1], arr, sizeof(arr));
   read(p1[0], arr, sizeof(arr));
   for(i = 0;i < n;i++) {
     if(arr[i]%2 == 0)
       evenarr[k++]=arr[i];
     else
       oddarr[l++]=arr[i];
   }
   write(p2[1], evenarr, sizeof(evenarr));
   write(p3[1], oddarr, sizeof(oddarr));
   pid=fork();
   if(pid == 0) {
      read(p2[0], evenarr, sizeof(evenarr));
      printf("Even numbers:");
      for(i = 0;i < k;i++) {
         printf("%d   ",evenarr[i]);
      }
      printf("\nPerfect square numbers:");
      for(i = 0;i < k;i++) {
         num=isPerfectSquare(evenarr[i]);
         if(num == 1)
            printf("%d   ",evenarr[i]);
         else
            continue;
      }
   }
   else if(pid > 0) {
      int pid1 = fork();
      if(pid1 == 0) {
         read(p3[0], oddarr, sizeof(oddarr));
         printf("Odd numbers:");
         for(i = 0;i < l;i++) {
            printf("%d   ",oddarr[i]);
         }
         printf("\nPrime numbers: ");
         for(i=0;i<l;i++) {
             num1 = isPrime(oddarr[i]);
             if(num1 == 1)
                printf("%d   ",oddarr[i]);
             else
                continue;
         }
      }
   }
   return 0;
}
