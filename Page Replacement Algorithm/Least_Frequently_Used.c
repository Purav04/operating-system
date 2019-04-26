#include<stdio.h>

int main()
{
	int frame_size, no_of_pages, hit = 0;
    int pages[25], fra[10], arr[25],pri[20][20], time[25];
    int m, n, page, flag, k, minimum_time, temps,i,j,page_faults;
    char x[20];

	printf("Enter Total Number of Pages : ");
    scanf("%d", &no_of_pages);


    for(m = 0; m < no_of_pages; m++)
    {
        printf("Enter the value for page %d : ",m+1);
        scanf("%d", &pages[m]);
    }


    printf("\nEnter Total Number of Frames : \t");
    scanf("%d", &frame_size);


    for(i=0; i< no_of_pages; i++)
   	{
   		x[i]='X';
	}
    for(m = 0; m < frame_size; m++)
    {
        fra[m] = -1;
    }
    for(m = 0; m < 25; m++)
    {
        arr[m] = 0;
    }

    printf("\n");
    for(m = 0; m < no_of_pages; m++)
    {
        arr[pages[m]]++;
        time[pages[m]] = m;
        flag = 1;
        k = fra[0];
        for(n = 0; n < frame_size; n++)
        {
            if(fra[n] == -1 || fra[n] == pages[m])
            {
                if(fra[n] != -1)
                {
                    hit++;
                    x[m]='*';
                }
                flag = 0;
                fra[n] = pages[m];

                break;
            }
            if(arr[k] > arr[fra[n]])
            {
            	k = fra[n];
            }
        }
            if(flag)
            {
                minimum_time = 25;
                for(n = 0; n < frame_size; n++)
                {
                	if(arr[fra[n]] == arr[k] && time[fra[n]] < minimum_time)
                    {
                    	temps = n;
                        minimum_time = time[fra[n]];
                    }
                }
                arr[fra[temps]] = 0;
                fra[temps] = pages[m];
            }

            for(n=0; n < frame_size ; n++)
            {
            	pri[n][m] = fra[n];
			}

    }

printf("\n LFU page replacement Table : \n");
    for(i=0;i<4*no_of_pages+10;i++)
		{
			printf("-");
		}
		printf("\n| Frames |");

		for(i=0;i<2*no_of_pages-3;i++)
		{
			printf(" ");
		}
		printf("Pages");
		for(i=0;i<2*no_of_pages-3;i++)
		{
			printf(" ");
		}

		printf("|\n");
			for(i=0;i<4*no_of_pages+10;i++)
		{
			printf("-");
		}

		printf("\n|        |");


	for(i=0 ; i < no_of_pages ; i++)
	{
		printf(" %d |",pages[i]);
	}
	printf("\n");
	for(i=0;i<4*no_of_pages+10;i++)
		{
			printf("-");
		}

	printf("\n");

    for(m=0; m < frame_size ; m++ )
    {
    	printf("|    %d   |",m);

		for(j = 0; j < no_of_pages; j++)
		{
			if(pri[m][j]== -1)
			{
				printf(" - |");
			}
			else
		    printf(" %d |",pri[m][j]);
		}
		printf("\n");
		for(i=0;i<4*no_of_pages+10;i++)
		{
			printf("-");
		}
    printf("\n");
    }



	printf("|        |");
	for(i = 0; i< no_of_pages; i++)
	{
		if(x[i]=='X')
		{
			//printf("\033[0;31m");
			printf(" %c ",x[i]);
			//printf("\033[0m");
			printf("|");
		}
		else
		{
			//printf("\033[0;32m");
			printf(" %c ",x[i]);
		//	printf("\033[0m");
			printf("|");
		}
	}
	//printf("\033[0m");
	printf("\n");
	for(i=0;i<4*no_of_pages+10;i++)
		{
			printf("-");
		}

/*
	page_faults= ;
	printf("\n\nTotal page Faults = No of pages - No of page Hits");
	 printf("\nTotal Page Faults : %d\n\n", page_faults);
	    printf("Total Page Hits = %d\n\n",hit);
	    printf("Fault ratio = No of page faults/No of page\n");
	    printf("Fault Ratio : %5.2f\n\n",((float)page_faults/no_of_pages));
	     printf("Hit Ratio = No of page Hits/ No of pages\n");
    printf("Hit Ratio : %5.2f\n",((float)hit)/no_of_pages);

*/
 double fr,hr;
 page_faults=no_of_pages - hit;
 fr=(double)page_faults/no_of_pages;
 hr=(double)hit/no_of_pages;

 	printf("\n\n Total Page Fault =no.of pages-Total Page Hit");
	printf("\n Total Page Fault =%d",no_of_pages - hit);


	printf("\n\n Total Page Hit =%d",hit);

    printf("\n\n Fault ratio =  Total no. of Page Fault/ total no. of pages");

	printf("\n Fault Ratio=%5.2f",fr);


	printf("\n\n Hit ratio = Total no. of Page Hit/total no. of pages ");
	printf("\n Hit ratio=%5.2f\n",hr);


}
