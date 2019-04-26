#include <stdio.h>

struct best
{
	int pid,sop,ah;
};

typedef struct
{
	int hid,soh,ex;
}hole;

int i,j;
void Table(struct best p[],hole h[],int np);

void main()
{
	int min=9999,np,nh,max=-1;
	printf ("Enter the number of Process : ");
	scanf ("%d",&np);
	struct best p[np];
	for (i=0;i<np;i++)
	{
		printf ("Enter size of process P%d : ",i+1);
		scanf ("%d",&p[i].sop);
		p[i].pid=i+1;
		p[i].ah=-1;
	}
	printf ("\nEnter the number of Holes : ");
	scanf ("%d",&nh);
	hole h[nh];
	for(i=0;i<nh;i++)
	{
		printf ("Enter size of hole H%d : ",i+1);
		scanf ("%d",&h[i].soh);
		h[i].hid=i+1;
		h[i].ex=1;
	}
	for (i=0;i<nh;i++)
	{
		if (h[i].soh>max)
		{
			max=h[i].soh;
		}
	}
	for (i=0;i<np;i++)
	{
		for (j=0;j<nh;j++)
		{
			if (p[i].sop<=max)
			{
				if (h[j].ex==1 && h[j].soh>=p[i].sop && (h[j].soh-p[i].sop)<min)
				{
					min=h[j].soh-p[i].sop;
					p[i].ah=j;
				}
			}
		}
		min=99999;
		h[p[i].ah].ex=0;
	}
	Table(p,h,np);
}

void Table(struct best p[],hole h[],int np)
{   int totall=0,y;
	printf("\n\n");
	printf("------------------\n");
	printf("**Best Fit Table**\n");
	printf("------------------\n");
	printf("+");
	for(i=0; i<83; i++){
	printf("-");}
	printf("+");
	printf("\n|            |     Process      |    Allocated    |     Hole       |     Left       |");
	printf("\n|   Process  |     Actual       |      Hole       |     Actual     |     Over       |");
	printf("\n|            |     Size         |                 |     Size       |     Space      |\n");
	for(i=0; i<85; i++)
	printf("-");
	for(i=0; i<np; i++)
	{
		if (p[i].ah!=-1)
		{
			printf("\n|     P%d     |      %-4d        |        H%d       |      %-4d      |      %-4d      |\n",p[i].pid,p[i].sop,p[i].ah+1,h[p[i].ah].soh,h[p[i].ah].soh-p[i].sop);
		for(y=0; y<85; y++)
        printf("-");
        totall=(totall+(h[p[i].ah].soh-p[i].sop));
		}
		else
		{
			printf("\n|     P%d     |      %-4d        |  NOT ALLOCATED  |      -         |      -         |\n",p[i].pid,p[i].sop);
		for(y=0; y<85; y++)
        printf("-");
		}
	}
	printf("\n");
	printf("\nAccording to Best Fit, left over space is = %d\n\n",totall);
}
