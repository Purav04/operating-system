#include<stdio.h>
struct times
{
       int pid,pid2,atime,ptime,wtime,ttime,rtime1,rtime2,fg1,fg2,ttime1;
}temp[100],p[100];


int main()
{
int i,j,h=0,n,y,z=1,tq,flag=0,total=0,a=0,ttur=0,twat=0;
double b;
printf("Enter Number Of Processes : ");
scanf("%d",&n);
int c[n];
for(i=1;i<=n;i++)
{
    printf("Enter arrival time for Process P%d : ",i);
    scanf("%d",&p[i].atime);
    p[i].pid = i;
    p[i].fg1=p[i].fg2=1;
}
for(i=1;i<=n;i++)
{
    printf("Enter processing time for Process P%d : ",i);
    scanf("%d",&p[i].ptime);
    total+=p[i].ptime;
    p[i].rtime1 = p[i].ptime;
    p[i].rtime2 = p[i].ptime;
}
printf("Enter Time Quantum : ");
scanf("%d",&tq);
printf("\nGANTT CHART\n");

printf("\n");
printf("-");
b=(double)total/tq;
double u=0.0;
int r;
for(i=1;i<=n;i++)
{
    if(p[i].ptime<=tq)
    {
        u=u;
    }
    else if(p[i].ptime>tq)
    {
         r=(double) p[i].ptime/tq;
         u+=r+1;
    }

}
for(i=1;i<=u;i++)
{
    printf("-------");
}
printf("\n|");
for(i=1;i<=n;i++){
    if(p[i].rtime1>0)
    {
    printf("  p%d  |",p[i].pid);
    p[i].rtime1=p[i].rtime1-tq;
    }
    if(p[i].rtime1<1){
        if(p[i].rtime1<0){
         p[i].rtime1=0;
        }
        if(p[i].fg1==1){
            flag++;
            p[i].fg1=0;

        }
    }
    if(i==n){
        i=0;
    }
    if (flag==n)
    {
        break;
    }
}
printf("\n");
printf("-");

for(i=1;i<=u;i++)
{
    printf("-------");
}
printf("\n0");
flag=0;
for(i=1;i<=n;i++)
{
    if(p[i].rtime2>0){
        if(p[i].rtime2<=tq){
            p[z].wtime=a;
            a=a+p[i].rtime2;
            p[z].ttime1=a;
            if(a<=10){
            printf("      %d",a);}
            else{printf("     %d",a);}
            p[i].rtime2=0;
            flag++;
            p[z].ttime=p[i].ptime+p[z].wtime;
            c[z]=p[i].pid;
            z++;
        }
        else{
            a=a+tq;
             if(a<=10){
            printf("      %d",a);}
            else{printf("     %d",a);}
           p[i].rtime2=p[i].rtime2-tq;
        }
    }
    if (flag==n)
    {
        break;
    }
    if(i==n){
        i=0;
    }
}

printf("\n\nRR scheduling::\n\n");



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

    printf("\n|  %d\t|\tp%d\t    |\t\t%d\t |\t  %d\t      |\n",p[i].ttime1,c[i],p[i].ttime,p[i].wtime);
     for(y=0;y<=70;y++)
    {
        printf("-");
    }
}

for(i=1;i<=n;i++){
    ttur = ttur+p[i].ttime;
    twat = twat+p[i].wtime;
}
float awat,atur;
awat=(float)twat/n;
atur=(float)ttur/n;

printf("\n\naverage turn around time = (T.T(p1)");

for (i=2;i<=n;i++)
{
    printf("+");
    printf("T.T(p%d)",i);
}
printf(")sec/total number of process");

printf("\naverage turnaround time=%5.2f sec\n",atur);
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
printf("\naverage waiting time=%5.2f sec",awat);

printf("\n\nthroughtput = total number of process / total time in sec\n");
float t;
t=(float) n/p[n].ttime;
printf("throughtput:%5.2f",t);

printf("\n\ncpu utiliazation = cpu busy time/(cpu busy time + cpu ideal time)    %%");
int o = cpu * 100;
printf("\ncpu utilization time :%d",o);
printf("%%");


}
