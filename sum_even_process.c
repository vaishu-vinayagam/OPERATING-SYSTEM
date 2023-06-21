#parent - find sum
#child - find even nos
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
  int p,n,i;
  printf("Enter the count of nos.:\n");
  scanf("%d",&n);
  int a[n];
  printf("Enter the nos,:\n");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  p=fork();
  if(p==0) {
    printf("Child process  Process id:%d\tParent id:%d\t",getpid(),getppid());
    int sum=0;
    for(i=0;i<n;i++) {
      sum+=a[i];
    }
    printf("\nSum:%d",sum);
  }
  else if(p<0) {
    printf("\nChild process not created");
  }
  else
  {
    wait(NULL);
    printf("\nParent process  Process id:%d\tParent id:%d\t",getpid(),getppid());
    printf("\nEven numbers in tha array are...\n");
    for(i=0;i<n;i++)
    {
      if(a[i]%2==0)
      {
        printf("%d\t",a[i]);
      }
    }

  }
  return 0;
}
