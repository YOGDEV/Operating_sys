
#include<stdio.h>
#include <stdlib.h>
struct s{
int arival_time;
int burst_time;
int wating_time;
int complition_time;
int id;
int turn_around_time;
int rt;//response time

};
int comparator(const void *p, const void *q) 
{
    int l = ((struct s *)p)->arival_time;
    int r = ((struct s *)q)->arival_time; 
    return (l - r);
}




int  main(void)
{

//reading number of process
int n;
printf("\nEnter number of PROCESS : ");
scanf("%d",&n);

struct s arr[n]; //structure array of process array
float avg_tat; //average turn around time
float avg_wt;  // average wating time


//for reading structure array element



for(int i=0;i<n;i++)
{ printf("\nEnter arrival time\t burst time : \n");
  arr[i].id=i+1;
  scanf("%d%d",&arr[i].arival_time,&arr[i].burst_time);
} 

qsort (arr, n, sizeof(struct s), comparator);
//for(int i=0;i<n;i++)
//printf("%d\n",arr[i].arival_time);
 int swt = 0, stat = 0;

for(int i=0;i<n;i++)
   {
      if(i==0)
      {
        arr[i].complition_time = arr[i].arival_time + arr[i].burst_time;
      }
      else if(arr[i-1].complition_time <= arr[i].arival_time)
        arr[i].complition_time = arr[i].arival_time + arr[i].burst_time;
      else
        arr[i].complition_time =arr[i-1].complition_time +arr[i].burst_time;
 
     arr[i].turn_around_time = arr[i].complition_time-arr[i].arival_time;
     
     arr[i].wating_time= arr[i].turn_around_time - arr[i].burst_time;
 
      swt += arr[i].wating_time;
      stat += arr[i].turn_around_time;
      arr[i].rt = arr[i].complition_time -arr[i].burst_time;
   }
 
   avg_wt = swt/n;
   avg_tat = stat/n;
   
   printf("\nID\t A_t \t B_t\t C_t\t T_A_t\t W_t\t R_t\n");
 
   for(int i=0;i<n;i++)
   {
      printf("P%d\t %d\t %d\t %d\t %d\t  %d\t %d\n",arr[i].id,arr[i].arival_time,arr[i].burst_time,arr[i].complition_time,arr[i].turn_around_time,arr[i].wating_time,arr[i].rt);
   }
   
   printf("\nSum of Turn Around Time: %d\nAverage of Turn Around Time: %f\n",stat,avg_tat);
   printf("Sum of Waiting Time: %d\nAverage of Waiting Time: %f\n\n",swt,avg_wt);
 
return 0; 
}
