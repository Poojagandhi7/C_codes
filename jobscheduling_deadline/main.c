#include <stdio.h>
#include <conio.h>

struct job
{
    int id;
    int deadline;
    int profit;
};

void schedule(struct job jobs[], int n)
{
    struct job temp;
    int i, j;
    int max_profit = 0;
    int schedule = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
    int slot[100] = {0};
    for (i = 0; i < n; i++)
    {
        for (j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == 0)
            {
                slot[j] = 1;
                max_profit += jobs[i].profit;
                schedule++;
                printf("schedule job is:%d\n", jobs[j].id);
                break;
            }
        }
    }
    printf("Max profit %d", max_profit);
}
void main()
{
    int i, n;
    struct job jobs[100];

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter job id: ");
        scanf("%d", &jobs[i].id);

        printf("Enter job profit: ");
        scanf("%d", &jobs[i].profit);

        printf("Enter job deadline: ");
        scanf("%d", &jobs[i].deadline);
    }

    schedule(jobs, n);
}
