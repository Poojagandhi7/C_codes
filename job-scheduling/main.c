#include<stdio.h>
#include<conio.h>

#define MAX_jobs 100

struct job{
    int id;
    int profit;
};

void schedulejob(struct job jobs[],int n)
{
    int schedule=0;
    struct job temp;
    int i,j;
    int maxprofit=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(jobs[j].profit < jobs[j+1].profit){
                temp=jobs[j];
                jobs[j]=jobs[j+1];
                jobs[j+1]=temp;
              
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(schedule<MAX_jobs){
            printf("scheduled job id is %d\n",jobs[i].id);
            maxprofit+=jobs[i].profit;
            schedule++;
        }
    else{
        printf("Maximum job limit reached!\n");
        break;
        }
    }
    printf("total profit %d\n",maxprofit);
}

void main(){
    int i,n;
    struct job jobs[100];
    
    printf("Enter no. of jobs: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("Enter job id: ");
        scanf("%d",&jobs[i].id);
        printf("Enter job profit: ");
        scanf("%d",&jobs[i].profit);
    }
    schedulejob(jobs,n);
}
