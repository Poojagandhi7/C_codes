#include <stdio.h>
#define MAX 100

int set[MAX], selected[MAX], n;
int targetSum, currentSum;

void subsetSum(int i)
{
    if (currentSum == targetSum)
    {
        printf("Subset found: ");
        for (int j = 0; j < n; j++)
        {
            if (selected[j])
            {
                printf("%d ", set[j]);
            }
        }
        printf("\n");
    }
    else if (i < n)
    {
        selected[i] = 1;
        currentSum += set[i];
        subsetSum(i + 1);
        selected[i] = 0;
        currentSum -= set[i];
        subsetSum(i + 1);
    }
}

int main()
{
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the set elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    subsetSum(0);
    return 0;
}