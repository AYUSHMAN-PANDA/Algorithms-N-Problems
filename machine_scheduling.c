#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int *start,int *end,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(start[j]>start[j+1])
            {
                swap(&start[j],&start[j+1]);
                swap(&end[j],&end[j+1]);
            }
        }
    }
}
void JobSchedule(int *start,int *end,int n)
{
	int *old=(int*)malloc(n*sizeof(int)),task=0,oc=0,oc1,f;
	while(task<n)
	{
		oc1=1;f=0;
		while(oc1<=oc)
		{
			if(start[task]>=old[oc1])
			{
				old[oc1]=end[task];
				f=1;
				break;
			}
			oc1++;	
		}
		if(f==0)
		{
			oc++;
			old[oc]=end[task];	
		}
		task++;
	}
	printf("%d machines are required to complete the job",oc);
    
}
int main()
{
    int i,*start,*end,n;
    printf("Enter no of jobs to be performed: ");
    scanf("%d",&n);
    start=(int*)malloc(n*sizeof(int));
    end=(int*)malloc(n*sizeof(int));
    printf("ENTER THE STARTING AND ENDING TIME OF EACH JOB: \n");
    for(i=0;i<n;i++)
    {
        printf("Enter the starting time of job %d :",(i+1));
        scanf("%d",&start[i]);
        printf("Enter the ending time of job %d :",(i+1));
        scanf("%d",&end[i]);
    }
    sort(start,end,n);
    /*for(i=0;i<n;i++)
    {
        printf ("starting time: %d\n ending time:%d\n",start[i],end[i]);
    }*/
    JobSchedule(start,end,n);
}
