#finding  sum of odd and even position using processes
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
  int p,n,i;
  printf("\nEnter the count of nos.:\n");
  scanf("%d",&n);
  int a[n];
  printf("\nEnter the array elements:\n");
  for(i=0;i<n+1;i++)
  {
    scanf(" %d",&a[i]);
    printf("%d",i);
  }
  p=fork();
  if(p==0)
  {
    printf("Child process  Process id:%d\tParent id:%d\t",getpid(),getppid());
    int osum=0;
    for(i=0;i<n;i+2)
    {
      osum+=a[i];
    }
    printf("Sum of elements in odd position is:%d\n",osum);
  }
  else if(p<0)
  {
    printf("\nChild process not created");
  }
  else
  {
    wait(NULL);
    printf("Parent process  Process id:%d\tParent id:%d\t",getpid(),getppid());
    int esum=0;
    for(i=1;i<n;i+2)
    {
       esum+=a[i];
    }
    printf("Sum of elements in even position is:%d\n",esum);
  }
  return 0;
}
