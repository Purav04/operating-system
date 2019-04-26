#include <stdio.h>
struct process
{
	int pid1,pid2,pid3,sop,ah1,ah2,ah3;
};
typedef struct
{
	int hid1,hid2,hid3,soh,ex1,ex2,ex3;
}hole;
struct hole{
	int hid1,hid2,hid3,soh,ex1,ex2,ex3;
};
int i,j;

void main()
{
	int min=9999,np,nh,max=-1;
	printf ("Enter the number of Process : ");
	scanf ("%d",&np);
	struct process p[np];
	for (i=0;i<np;i++)
	{
		printf ("Enter size of process P%d : ",i+1);
		scanf ("%d",&p[i].sop);
		p[i].pid1=p[i].pid2=p[i].pid3=i+1;
		p[i].ah1=p[i].ah2=p[i].ah3=-1;
	}
	printf ("\nEnter the number of Holes : ");
	scanf ("%d",&nh);
	struct hole h[nh];
	for(i=0;i<nh;i++)
	{
		printf ("Enter size of hole H%d : ",i+1);
		scanf ("%d",&h[i].soh);
		h[i].hid1=h[i].hid2=h[i].hid3=i+1;
		h[i].ex1=h[i].ex2=h[i].ex3=1;
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
				if (h[j].soh>=p[i].sop && h[j].ex1==1)
				{
					p[i].ah1=j;
					h[p[i].ah1].ex1=0;
					break;
				}
			}
		}
	}
    int y,totall=0;
	printf("\n\n");
	printf("-------------------\n");
	printf("**First Fit Table**\n");
	printf("-------------------\n");
	printf("+");
	for(i=0; i<83; i++){
	printf("-");}
	printf("+");
	printf("\n|            |      Process     |    Allocated    |      Hole      |      Left      |");
	printf("\n|   Process  |      Actual      |      Hole       |      Actual    |      Over      |");
	printf("\n|            |      Size        |                 |      Size      |      Space     |\n");
	for(i=0; i<85; i++)
	printf("-");
	for(i=0; i<np; i++)
	{
		if (p[i].ah1!=-1)
		{
			printf("\n|     P%d     |      %-4d        |        H%d       |      %-4d      |      %-4d      |\n",p[i].pid1,p[i].sop,p[i].ah1+1,h[p[i].ah1].soh,h[p[i].ah1].soh-p[i].sop);
			for(y=0; y<85; y++)
            printf("-");
            totall=(totall+(h[p[i].ah1].soh-p[i].sop));
		}
		else
		{
			printf("\n|     P%d     |      %-4d        |  NOT ALLOCATED  |      -         |      -         |\n",p[i].pid1,p[i].sop);
				for(y=0; y<85; y++)
                printf("-");
		}
	}
	printf("\n");

    printf("\nAccording to First Fit, left over space is = %d\n\n",totall);





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
				if (h[j].ex2==1 && h[j].soh>=p[i].sop && (h[j].soh-p[i].sop)<min)
				{
					min=h[j].soh-p[i].sop;
					p[i].ah2=j;
				}
			}
		}
		min=99999;
		h[p[i].ah2].ex2=0;
	}
	 totall=0,y;
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
		if (p[i].ah2!=-1)
		{
			printf("\n|     P%d     |      %-4d        |        H%d       |      %-4d      |      %-4d      |\n",p[i].pid2,p[i].sop,p[i].ah2+1,h[p[i].ah2].soh,h[p[i].ah2].soh-p[i].sop);
		for(y=0; y<85; y++)
        printf("-");
        totall=(totall+(h[p[i].ah2].soh-p[i].sop));
		}
		else
		{
			printf("\n|     P%d     |      %-4d        |  NOT ALLOCATED  |      -         |      -         |\n",p[i].pid2,p[i].sop);
		for(y=0; y<85; y++)
        printf("-");
		}
	}
	printf("\n");
	printf("\nAccording to Best Fit, left over space is = %d\n\n",totall);






        int k;
        max=-1;
        for (i=0;i<np;i++)
        {
                for (k=0;k<nh;k++)
                {
                        if (h[k].soh>max && h[k].ex3==1)
                        {
                                max=h[k].soh;
                                j=k;
                        }
                }
                if (max>=p[i].sop)
                {
                        p[i].ah3=j;
                        h[p[i].ah3].ex3=0;
                }
                max=0;
        }
        totall=0;
        printf("\n\n");
        printf("-------------------\n");
        printf("**Worst Fit Table**\n");
        printf("-------------------\n");
        printf("+");
        for(i=0; i<76; i++){
        printf("-");}
        printf("+");
        printf("\n|           |    Process   |    Allocated   |      Hole       |   Left Over  |");
        printf("\n|  Process  |    Actual    |      Hole      |      Actual     |   Space      |");
        printf("\n|           |    Size      |                |      Size       |              |\n");
        for(i=0; i<78; i++){
        printf("-");}
        for(i=0; i<np; i++)
        {
                if (p[i].ah3!=-1)
                {
                        printf("\n|   P%d      |    %-4d      |      H%d        |      %-4d       |    %-4d      |",p[i].pid3,p[i].sop,p[i].ah3+1,h[p[i].ah3].soh,h[p[i].ah3].soh-p[i].sop);
totall=totall+h[p[i].ah3].soh-p[i].sop;
        printf("\n");
        for(j=0; j<78; j++){
        printf("-");}
                }
                else
                {
                        printf("\n|   P%d      |    %-4d      |  NOT ALLOCATED |      -          |    -         |",p[i].pid3,p[i].sop);
                                printf("\n");
                                for(j=0; j<78; j++){
                                    printf("-");}
                }
        }

        printf("\n");

        printf("\nAccording To Worst Fit,left over Space is : %d",totall);

}


