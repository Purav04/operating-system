#include<stdio.h>


int main()
{
int page,frame,page_faults=0,s,m,n,f,i,j,ref_string[25],pri[25][25];

printf("Enter Total Number of Pages:");
scanf("%d",&page);
char ch[page],cha[25];
cha[1]='-';
for(m=0;m<page;m++)
{
    printf("enter value of page %d:",m+1);
    scanf("%d",&ref_string[m]);
    ch[m]='X';
}
printf("\nEnter Total Number of Frames:");
scanf("%d",&frame);


int temp[frame];
for(m=0;m<frame;m++)
{
    temp[m]=0;
}
for(m=0;m<page;m++)
{
    s=0;
    for(n=0;n<frame;n++)
    {
	  if(ref_string[m]==temp[n])
	  {
		s++;
		page_faults--;
		ch[m]='*';
	  }
     }
 page_faults++;
 if((page_faults<=frame) && (s==0))
 {
   temp[m]=ref_string[m];
 }
 else if(s==0){
    for(n=0;n<frame;n++){
        if(ref_string[m-1]==temp[n]){
            temp[n]=ref_string[m];
        }
    }
 }
 for(f=0;f<frame;f++)
 {
	pri[f][m]=temp[f];
 }

 }

 printf("\nMFU Page Replacement Algorithm:\n");
 for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=page;i++){
            printf("----");
        }
        printf("\n| Frame |");
        for(i=1;i<=(page*4)/2;i++)
        {
            printf(" ");
        }
        printf("Page");
        for(i=(page*4)/2;i<=(page*4)-5;i++)
        {
            printf(" ");
        }
        printf("\b|\n|");
        for(i=1;i<=9;i++)
        {
            printf(" ");
        }
        printf("\b\b|");
        for(i=1;i<=page;i++){
            printf("----");
        }
        printf("\b|\n");
        printf("|       |");
        for(i=0;i<page;i++){
            printf(" %d |",ref_string[i]);
        }printf("\n");
        for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=page;i++){
            printf("----");
        }
        printf("\n");
 for(m=0;m<frame;m++)
 {
     printf("|   %d   |",m);
      for(f=0;f<page;f++)
	  {
		printf(" %d |",pri[m][f]);
	  }printf("\n");
}
for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=page;i++){
            printf("----");
        }
        printf("\n|       |");


for(i=0;i<page;i++)
{
        printf(" %c |",ch[i]);
    }printf("\n");
for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=page;i++){
            printf("----");
        }

 double fr,hr;
 fr=(double)page_faults/page;
 hr=(double)(page-page_faults)/page;

 	printf("\n\n Total Page Fault =no.of pages-Total Page Hit");
	printf("\n Total Page Fault =%d",page_faults);


	printf("\n\n Total Page Hit =%d",page-page_faults);

    printf("\n\n Fault ratio =  Total no. of Page Fault/ total no. of pages");

	printf("\n Fault Ratio=%5.2f",fr);


	printf("\n\n Hit ratio = Total no. of Page Hit/total no. of pages ");
	printf("\n Hit ratio=%5.2f\n",hr);




}
