#include<stdio.h>
#include<conio.h>

struct proc
{
    int pid;
    int ptime;
    int wtime;
    int ttime;
    int atime;
}p[20];

int main(){
int i,j,k,n,y;

printf("enter number of process:");
scanf("%d",&n);
for(i=1; i<=n;i++){
    printf("enter arrival time for process p%d (in sec):",(i));
    scanf("%d",&p[i].atime);
}
for(i=1; i<=n;i++){
    printf("enter processing time for process p%d (in sec):",(i));
    scanf("%d",&p[i].ptime);
    p[i].pid=i;
}

p[1].wtime=0;

for(i=1;i<=n;i++){
    p[i+1].wtime=p[i].wtime + p[i].ptime;
    p[i].ttime = p[i].wtime + p[i].ptime;
}
int ttur=0,twat=0;

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
	if(p[i].ttime>10){
		printf("     %d",p[i].ttime);
	}
	else{

    printf("      %d",p[i].ttime);
	}
}

printf("\n\nFCFS scheduling::\n");

//printf("\n\nt-time = t(process complete) - t(process submitted)");
//printf("\nw-time = t(t-time) - t(processing time)\n");

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
    //printf("\n");

    printf("\n|  %d\t|\tp%d\t    |\t\t%d\t |\t  %d\t      |\n",p[i].ttime,p[i].pid,p[i].ttime,p[i].wtime);
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
