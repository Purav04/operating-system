#include<stdio.h>
struct proc
{
    int atime,btime,wtime,ttime,pid,pnum;
}p[10],temp;

int main()
{
    int n,i,j,y;
    printf("Enter number of process :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter arrival time for process p%d : ",i);
        scanf("%d",&p[i].atime);
        p[i].pid=i;
    }
    for(i=1;i<=n;i++)
    {
        printf("Enter processing time for process p%d : ",i);
        scanf("%d",&p[i].btime);
    }
    for(i=1;i<=n;i++)
    {
        printf("Enter priority for process p%d : ",i);
        scanf("%d",&p[i].pnum);
    }

    for(i=1;i<n;i++)
    {
    for(j=i;j<=n;j++)
    {
        if((p[i].pnum > p[j].pnum) || (p[i].pnum == p[j].pnum && p[i].pid > p[j].pid))
        {
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
    }
p[1].wtime=0;
for(i=1;i<=n;i++)
{
    p[i+1].wtime=p[i].wtime + p[i].btime;
    p[i].ttime = p[i].wtime + p[i].btime;
}
int ttur=0,twat=0;
for(i=1;i<=n;i++)
{
    ttur = ttur+p[i].ttime;
    twat = twat+p[i].wtime;
}

float awat,atur;
awat=(float)twat/n;
atur=(float)ttur/n;
printf("\nGANTT chart\n\n");
for(i=1;i<n*7+2;i++)
{
    printf("-");
}

printf("\n|");

for(i=1;i<=n;i++){

    printf("  p%d  ",p[i].pid);
    printf("|");
}



printf("\n");

for(i=1;i<n*7+2;i++)
{
    printf("-");
}
printf("\n0");

for(i=1;i<=n;i++){
	if(p[i].ttime>100)
    {
        printf("    %d",p[i].ttime);
    }
	else if(p[i].ttime>10){
		printf("     %d",p[i].ttime);
	}
	else{

    printf("      %d",p[i].ttime);
	}
}

printf("\n\n\nPRIORITY scheduling:\n");

for(i=0;i<=70;i++)
{
    printf("-");
}

printf("\n| Time  | Process Completed | T-time=t(pc)-t(ps) | W-time=T-time-time |\n");


for(i=0;i<=70;i++)
{
    printf("-");
}
 printf("\n|  0\t|\t-\t    |\t\t-\t |\t  -\t      |\n");
 for(i=0;i<=70;i++)
{
    printf("-");
}
for(i=1;i<=n;i++){
    printf("\n|  %d\t|\tp%d\t    |\t\t%d\t |\t  %d\t      |\n",p[i].ttime,p[i].pid,p[i].ttime,p[i].wtime);
    for(y=0;y<=70;y++)
{
    printf("-");
}
}
printf("\n");


printf("\n\naverage turn around time = (T.T(p1)");

for (i=2;i<=n;i++)
{
    printf("+");
    printf("T.T(p%d)",i);
}
printf(")sec/total number of process");

printf("\naverage turnaround time= %5.2f sec\n",atur);
printf("\n\naverage waiting time = (w.t(p1)");

for (i=2;i<=n;i++)
{
    printf("+");
    printf("w.t(p%d)",i);
}
printf(")sec/total number of process");



int cpu;
int cit=0;
cpu=p[n].ttime/(p[n].ttime+cit);
printf("\naverage waiting time= %5.2f sec",awat);

printf("\n\nthroughtput = total number of process / total time in sec\n");
float t;
t=(float) n/p[n].ttime;
printf("throughtput: %5.2f",t);

printf("\n\ncpu utiliazation = cpu busy time/(cpu busy time + cpu ideal time)    %%");
int c = cpu * 100;
printf("\ncpu utilization time : %d",c);
printf("%%");

}
