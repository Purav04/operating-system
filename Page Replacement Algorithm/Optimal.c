#include<stdio.h>
int main()
{
    int nof,m,f, nop, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    int pri[20][30];

    printf("Enter number of pages: ");
    scanf("%d", &nop);
    for(i = 0; i < nop; ++i){
	printf("Enter value of page %d:",i+1);
    scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &nof);
    char c[nof];
    for(i = 0; i < nof; ++i){
	frames[i] = 0;
    }

    for(i = 0; i < nop; ++i){
	flag1 = flag2 = 0;

	for(j = 0; j < nof; ++j){
	    if(frames[j] == pages[i]){
		   flag1 = flag2 = 1;
		   c[i]='*';
		   break;
	       }
	}

	if(flag1 == 0){
	    for(j = 0; j < nof; ++j){
		if(frames[j] == -1){
		    faults++;
		    c[i]='X';
		    frames[j] = pages[i];
		    flag2 = 1;
		    break;
		}
	    }
	}

	if(flag2 == 0){
	    flag3 =0;

	    for(j = 0; j < nof; ++j){
		temp[j] = -1;

		for(k = i + 1; k < nop; ++k){
		    if(frames[j] == pages[k]){
			temp[j] = k;
			break;
		    }
		}
	    }

	    for(j = 0; j < nof; ++j){
		if(temp[j] == -1){
		    pos = j;
		    flag3 = 1;
		    break;
		}
	    }

	    if(flag3 ==0){
		max = temp[0];
		pos = 0;

		for(j = 1; j < nof; ++j){
		    if(temp[j] > max){
			max = temp[j];
			pos = j;
		    }
		}
	    }

	    frames[pos] = pages[i];
	    faults++;
	    c[i]='X';
	}

	for(j = 0; j < nof; j++)
	{
	    pri[j][i]=frames[j];
	}
    }
    printf("\nOPTIMAL Page Replacement Algorithm:\n");
 for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=nop;i++){
            printf("----");
        }
        printf("\n| Frames|");
        for(i=1;i<=(nop*4)/2;i++)
        {
            printf(" ");
        }
        printf("Pages");
        for(i=(nop*4)/2;i<=(nop*4)-6;i++)
        {
            printf(" ");
        }
        printf("\b|\n|");
        for(i=1;i<=9;i++)
        {
            printf(" ");
        }
        printf("\b\b|");
        for(i=1;i<=nop;i++){
            printf("----");
        }
        printf("\b|\n");
        printf("|       |");
        for(i=0;i<nop;i++){
            printf(" %d |",pages[i]);
        }printf("\n");
        for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=nop;i++){
            printf("----");
        }
        printf("\n");
 for(m=0;m<nof;m++)
 {
     printf("|   %d   |",m);
      for(f=0;f<nop;f++)
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
        for(i=1;i<=nop;i++){
            printf("----");
        }
        printf("\n|       |");


for(i=0;i<nop;i++)
{
    /*if (c[i]=='X'){printf("033[0;31m");printf(" %c |",c[i]);}
    else if(c[i]=='*'){printf("033[0;32m");printf(" %c |",c[i]);}
        */
        printf(" %c |",c[i]);
    }printf("\n");
     //printf("033[0m");
for(i=1;i<=9;i++)
        {
            printf("-");
        }
        //printf("-");
        for(i=1;i<=nop;i++){
            printf("----");
        }

 double fr,hr;
 fr=(double)faults/nop;
 hr=(double)(nop-faults)/nop;

 	printf("\n\n Total Page Fault =no.of pages-Total no. of Page Hit");
	printf("\n Total Page Fault =%d",faults);


	printf("\n\n Total Page Hit =%d",nop-faults);

    printf("\n\n Fault ratio =  Total no. of Page Fault/ total no. of pages");

	printf("\n Fault Ratio=%5.2f",fr);


	printf("\n\n Hit ratio = Total no. of page Hit/total no. of pages ");
	printf("\n Hit ratio=%5.2f\n",hr);





}
