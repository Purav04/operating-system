#include <stdio.h>
typedef struct
{
        int pid,sop,ah;
}process;
typedef struct
{
        int hid,soh,ex;
}hole;
int i,j,k,los;
void Table(process p[],hole h[],int np,int nh);
void main()
{
        int min=9999,np,nh,max=-1;
        printf ("Enter the number of Process : ");
        scanf("%d",&np);
        printf("\n");
        process p[np];
        for (i=0;i<np;i++)
        {
                printf ("Enter size of process P%d : ",i+1);
                scanf ("%d",&p[i].sop);
                p[i].pid=i+1;
                p[i].ah=-1;
        }
        printf("\n");
        printf ("Enter the number of Holes : ");
        scanf ("%d",&nh);
        hole h[nh];
        printf("\n");
        for(i=0;i<nh;i++)
        {
                printf ("Enter size of hole H%d : ",i+1);
                scanf ("%d",&h[i].soh);
                //h[i].hsize=h[i].soh;
                h[i].hid=i+1;
                h[i].ex=1;
        }
        for (i=0;i<np;i++)
        {
                for (k=0;k<nh;k++)
                {
                        if (h[k].soh>max && h[k].ex==1)
                        {
                                max=h[k].soh;
                                j=k;
                        }
                }
                if (max>=p[i].sop)
                {
                        p[i].ah=j;
                        h[p[i].ah].ex=0;
                }
                max=0;
        }
        Table(p,h,np,nh);
}
void Table(process p[],hole h[],int np,int nh)
{       int totall=0;
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
                if (p[i].ah!=-1)
                {
                        printf("\n|   P%d      |    %-4d      |      H%d        |      %-4d       |    %-4d      |",p[i].pid,p[i].sop,p[i].ah+1,h[p[i].ah].soh,h[p[i].ah].soh-p[i].sop);
totall=totall+h[p[i].ah].soh-p[i].sop;
        printf("\n");
        for(j=0; j<78; j++){
        printf("-");}
                }
                else
                {
                        printf("\n|   P%d      |    %-4d      |  NOT ALLOCATED |      -          |    -         |",p[i].pid,p[i].sop);
                                printf("\n");
                                for(j=0; j<78; j++){
                                    printf("-");}
                }
        }

        printf("\n");

        printf("\nAccording To Worst Fit,left over Space is : %d",totall);
}
