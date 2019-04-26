#include<stdio.h>

struct process
{
       int btime,atime,wtime,st,pid,ttime,ctime;
} ps[100];

int get(struct process ps[],int t,int n)
{
       int imin,min=9999,i;
       for(i=0;i<n;i++)
       {
	      if(ps[i].atime<=t&&ps[i].st==0)
		     if(min>ps[i].btime)
		     {
			   min=ps[i].btime;
			   imin=i;
		     }
       }
       return imin;
}

void printGanttimeCharttimeable(struct process ps[],int p[],int n,int nop)
{
       int i,j,a[100],s=0,cpu,total1=0,total2=0,b;
       struct process temp;
	   float awat,atur,thput;
       printf("\n**Gantt Chart**\n");
       printf("---------------\n\n");
       for(i=0;i<n-1;i++)
       {
	      while(i<n-1&&p[i]==p[i+1])
	      {
		     s++;
		     i++;

	      }

	      s++;
	      printf("-------");

       }
       s=0;
	   printf("-\n");
       for(i=0;i<n-1;i++)
       {
	      while(i<n-1&&p[i]==p[i+1])
	      {
		     s++;
		     i++;
	      }

	      s++;
	      printf("|  P%d  ",ps[p[i]].pid);
	      ps[p[i]].wtime=s-ps[p[i]].atime-ps[p[i]].ttime;
       }
       printf("|\n");
       for(i=0;i<n-1;i++)
       {
	      while(i<n-1&&p[i]==p[i+1])
	      {
		     s++;
		     i++;

	      }

	      s++;
	      printf("-------");

       }
       s=0;
	   printf("-\n");
	   printf("0      ");
	for(i=0;i<n-1;i++)
       {
	      while(i<n-1&&p[i]==p[i+1])
	      {
		     s++;
		     i++;
	      }

	      s++;
	      printf("%-3d    ",s);
       }
       for(i=0;i<nop;i++)
       {
	      ps[i].ttime+=ps[i].wtime;
	      awat+=ps[i].wtime;
	      atur+=ps[i].ttime;
	      ps[i].ctime = ps[i].ttime+ps[i].atime;
       }
       for(i=0; i<nop; i++)
	{
		for(j=i+1; j<nop; j++)
		{

		if(ps[i].ctime > ps[j].ctime || ps[i].ctime == ps[i].ctime && ps[i].pid > ps[j].pid)
		{
		temp = ps[i];
		ps[i] = ps[j];
		ps[j] = temp;
		}
		}
	}



       printf("\n\n");
       printf("**SRTN Scheduling**\n");
       printf("-------------------");
       printf("\n\n");
		for(i=0; i<79; i++)
		printf("-");
		printf("\n|  Time  |  Process completed  |  T-time=t(pc)-t(ps)  |  W-time=T-time -time  |\n");
		for(i=0; i<79; i++)
		printf("-");
		printf("\n|  0     |         -           |            -         |         -             |\n");
		for(i=0; i<79; i++)
		printf("-");

		for(i=0; i<nop; i++)
		if(ps[i].pid>=10)
		{
			printf("\n|  %-3d   |         P%d          |            %-3d       |         %-3d           |\n",ps[i].ctime,ps[i].pid,ps[i].ttime,ps[i].wtime);
			total1+=ps[i].ttime;
			b=ps[i].ctime;
			total2+=ps[i].wtime;
			for(j=0; j<79; j++){
            printf("-");}
		}
		else
		{
			printf("\n|  %-3d   |         P%d          |            %-3d       |         %-3d           |\n",ps[i].ctime,ps[i].pid,ps[i].ttime,ps[i].wtime);
			b=ps[i].ctime;
			total1+=ps[i].ttime;
			total2+=ps[i].wtime;
			for(j=0; j<79; j++){
            printf("-");}
		}


		awat = (float)total2/nop;
		atur = (float)total1/nop;
		cpu  = ps[nop-1].ttime*100 / ps[nop-1].ttime-0;
		thput = (float)n / ps[nop-1].ctime;



printf("\n\naverage turn around time = (T.T(p1)");

for (i=2;i<=nop;i++)
{
    printf("+");
    printf("T.T(p%d)",i);
}
printf(")ms/total number of process");

printf("\naverage turnaround time=%5.2f ms\n",atur);
printf("\n\naverage waiting time = (w.t(p1)");

for (i=2;i<=nop;i++)
{
    printf("+");
    printf("w.t(p%d)",i);
}
printf(")ms/total number of process");
printf("\n\nAverage waiting time=%5.2f ms",awat);
float t;
t=(float)nop/b;
printf("\n\nthroughtput = total number of process / total time in sec");
printf("\nthroughput=%-5.2f",t);
printf("\n\nCPU Utilization=cpu busytime/(cpu busy time+cpu idle time) %%\n");
printf("CPU Utilization=%d %%",cpu);



       return;
}

int iscomplite(struct process ps[],int n)
{
       int i;
       for(i=0;i<n;i++)
	      if(ps[i].st==0)
		     return 0;
       return 1;
}
int main()
{
       int n,i,a,t=0;
       int p[100];
       struct process ps[100];

       printf("Enter number of process : ");
       scanf("%d",&n);

	   for(i=0; i<n; i++)
	{
		printf("enter Arrival time for process P%d (in ms) : ",(i+1));
		scanf("%d", &ps[i].atime);

	}
	for(i=0;i<n;i++)
       {
	      printf("enter processing time for process P%d (in ms) : ",(i+1));
	      scanf("%d",&ps[i].btime);
	      ps[i].pid = i+1;
	      ps[i].ctime = ps[i].btime;
	      ps[i].st=0;
	      ps[i].ttime=ps[i].btime;
	      ps[i].wtime=0;
       }
       i=0;
       while(1)
       {
	      if(iscomplite(ps,n))
		     break;
	      a=get(ps,t,n);
	      p[i]=a;
	      ps[a].btime-=1;
              if(ps[a].btime==0)
                     ps[a].st=1;
              t=t+1;
              i++;
       }
      /* for (i=0;i<100;i++)
       {
       		printf ("%d  ",p[i]);
	   }*/
       printGanttimeCharttimeable(ps,p,i,n);

}

