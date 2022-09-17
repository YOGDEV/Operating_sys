/*write a C prog in which parent compute the sum of even numbers and parent compute the sum of odd numbers , stored in an array using 
fork() function.
fisrt, the child proces should print the answer that is sum of off numbers and then the parent should print the answer that is sum of 
even numbers.
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  
    printf("\nName : Yogesh Singh Yadav :  Sec : A\n");
    printf("\nEnter number of elements : " );
    int n;
    scanf("%d",&n);
    //reading elements in array
    int arr[n];
    for(int i=0;i<n;i++)
    {
     scanf("%d",&arr[i]); 
    }
    int pid=fork();
    if(pid!=0)
    {
     int sum=0;
     for(int i=0;i<n;i++)
     {
      if(arr[i]%2!=0)sum=sum+arr[i];
     }
     printf("\n odd no :%d and pid is :%d",sum,getpid());
    }
    else{
     int sum=0;
     for(int i=0;i<n;i++) 
     {
      if(arr[i]%2==0)sum=sum+arr[i];
     }
     printf("\n Even no :%d and pid is : %d ",sum,getpid());
    }

}
