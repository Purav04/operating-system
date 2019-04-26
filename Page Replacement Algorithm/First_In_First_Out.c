#include<stdio.h>
int main()
{
int ref_string[25],i,j,k, page_faults=0,m,f,n,s,pages,p,frames;
int temp[25],pri[25][25];
printf("Enter Total Number of Pages:");
scanf("%d",&pages);
char c[pages];
for(m=0;m<pages;m++)
{
    printf("enter value of page %d:",m+1);
    scanf("%d",&ref_string[m]);
    c[m]='X';
}
printf("\nEnter Total Number of Frames:");
scanf("%d",&frames);
p=frames;
temp[p];
for(m=0;m<frames;m++)
{
    temp[m]=0;
}
for(m=0;m<pages;m++)
{
    s=0;
    for(n=0;n<frames;n++)
    {
	  if(ref_string[m]==temp[n])
	  {
		s++;
		page_faults--;
		c[m]='*';
	  }
     }
 page_faults++;
 if((page_faults<=frames) && (s==0))
 {
   temp[m]=ref_string[m];
 }
 else if(s==0)
  {
     temp[(page_faults - 1) % frames] = ref_string[m];
  }
 for(f=0;f<frames;f++)
 {
	pri[f][m]=temp[f];
 }

 }	printf("\n");
 printf("\nFIFO Page Replacement Algorithm:\n");
 for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=pages;i++){
            printf("----");
        }
        printf("\n| Frames|");
        for(i=1;i<=(pages*4)/2;i++)
        {
            printf(" ");
        }
        printf("Pages");
        for(i=(pages*4)/2;i<=(pages*4)-6;i++)
        {
            printf(" ");
        }
        printf("\b|\n|");
        for(i=1;i<=9;i++)
        {
            printf(" ");
        }
        printf("\b\b|");
        for(i=1;i<=pages;i++){
            printf("----");
        }
        printf("\b|\n");
        printf("|       |");
        for(i=0;i<pages;i++){
            printf(" %d |",ref_string[i]);
        }printf("\n");
        for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=pages;i++){
            printf("----");
        }
        printf("\n");
 for(m=0;m<frames;m++)
 {
     printf("|   %d   |",m);
      for(f=0;f<pages;f++)
	  {
	      if(pri[m][f]==0)
            printf(" - |");
          else
            printf(" %d |",pri[m][f]);
	  }printf("\n");
}
for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=pages;i++){
            printf("----");
        }
        printf("\n|       |");


for(i=0;i<pages;i++)
{
        printf(" %c |",c[i]);
    }printf("\n");
for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=pages;i++){
            printf("----");
        }

 double fr,hr;
 fr=(double)page_faults/pages;
 hr=(double)(pages-page_faults)/pages;

 	printf("\n\n Total Page Fault =no.of pages-Page Hit");
	printf("\n Total Page Fault =%d",page_faults);


	printf("\n\n Total Page Hit =%d",pages-page_faults);

    printf("\n\n Fault ratio =  Total Page Fault/ total no. of pages");

	printf("\n Fault Ratio=%5.2f",fr);


	printf("\n\n Hit ratio = Total page Hit/total no. of pages ");
	printf("\n Hit ratio=%5.2f\n",hr);



}
