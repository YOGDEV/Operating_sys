#include<stdio.h>
#include<stdlib.h>

struct process{
    int at;//arrival time
    int bt;//brust time
    int wt;//waiting time 
    int tat;//turn-around-time
    int ct;//compiliton time
    int pid;//process id
    int rt;//response time
    int st;//start time
}ps[100];

int comparator(const void *p,const void *q)
{
    int x=((struct process*)p)->at;
    int y=((struct process*)q)->at;
    if(x<y)return -1;
    if(x>=y)return 1;
}
int max(int a,int b)
{
    return (a>=b)?a:b;
}
int main(void)
{
    int n;
    printf("\nEnter number of Process : ");
    scanf("%d",&n);

    int length_cycle=0;
    int ideal_time=0;
    float sum_tat=0,sum_wt=0,sum_rt=0;

    //Reading Process arrival time , brust time , pid 
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Arrial time of %d : ",i);
        scanf("%d",&ps[i].at);
        printf("\nEnter Brust time of %d : ",i);
        scanf("%d",&ps[i].bt);
        ps[i].pid=i;
        printf("______________________________");
    }

    //printing initial table
    printf("\nPID    AT     BT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d      %d       %d\n",ps[i].pid,ps[i].at,ps[i].bt);
    }

    qsort(ps,n,sizeof(struct process),comparator);//sorting according to arrival time

    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            ps[i].ct=ps[i].at+ps[i].bt;
        }
        else if(ps[i].at>ps[i-1].ct)
        {
            ps[i].ct=ps[i].at+ps[i].bt;
        }
        else
        {
            ps[i].ct=ps[i-1].ct+ps[i].bt;
        }

      
        ps[i].tat=ps[i].ct-ps[i].at;
        ps[i].wt=ps[i].tat-ps[i].bt;
        ps[i].rt=ps[i].wt;

        sum_tat+=ps[i].tat;
        sum_wt+=ps[i].wt;
        sum_rt+=ps[i].rt;
        ps[i].st=(i==0)?ps[i].at:max(ps[i].at,ps[i-1].ct);
        ideal_time+=(i==0)?0:(ps[i].at-ps[i-1].ct);
    }

    //calculating wt,cp,tat,rp,ideal_time, using start-time
    // for(int i=0;i<n;i++)
    // {
    //     ps[i].st=(i==0)?ps[i].at:max(ps[i].at,ps[i-1].ct);
    //     ps[i].ct=ps[i].st+ps[i].bt;
    //     ps[i].tat=ps[i].ct-ps[i].at;
    //     ps[i].wt=ps[i].tat-ps[i].bt;
    //     ps[i].wt=ps[i].rt;

    //     sum_tat+=ps[i].tat;
    //     sum_wt+=ps[i].wt;
    //     sum_rt+=ps[i].rt;
        
    //     ideal_time+=(i==0)?0:(ps[i].at-ps[i-1].ct);
    // }

    length_cycle=ps[n-1].ct-ps[0].st;

    printf("\nPId\tat\tbt\twt\ttat\tct\trt\n");
    for(int i=0;i<n;i++)
    {    
    printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",ps[i].pid,ps[i].at,ps[i].bt,ps[i].wt,ps[i].tat,ps[i].ct,ps[i].rt);
    }
    printf("\n");

    float cpu=(length_cycle-ideal_time)/length_cycle;

    printf("\nAverage WT : %f ",sum_wt/n);
    printf("\nAverage TAT : %f ",sum_tat/n);
    printf("\nAverage RT : %f ",sum_rt/n);
    printf("\nCpu utilization : %f ",cpu*100);
    printf("\nThroughput : %f",(float)n/length_cycle);
    return 0;

}
