#include <stdio.h>
int main()
{
    float weight[50], profit[50], ratio[50], Totalvalue = 0, capacity, amount;
    int n, i, j;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Weight and Profit for item[%d]: ", i);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                float temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    printf(" Fractional Knapsack problem using Greedy Algorithm:\n");
    for (i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            Totalvalue += profit[i];
            capacity -= weight[i];
        }
        else
        {
            Totalvalue += ratio[i] * capacity;
            break;
        }
    }

    printf("The maximum value is: %.2f\n", Totalvalue);
    return 0;
}

// #include<stdio.h>
// #include<conio.h>

// void main(){
//     float weight[100],value[100],ratio[100],max_profit=0,capacity,temp;
//     int i,j,n;
//     printf("enter items:");
//     scanf("%d",&n);
//     for(i=0;i<n;i++){
//         printf("weight:");
//         scanf("%f",&weight[i]);
//         printf("value:");
//         scanf("%f",&value[i]);
//     }
//     for(i=0;i<n;i++){
//         ratio[i]=value[i]/weight[i];
//     }
//     printf("enter capacity:");
//     scanf("%f",&capacity);
    
//     for(i=0;i<n-1;i++){
//         for(j=0;j<n-i-1;j++){
//             if (ratio[j]<ratio[j+1]){
                
//                 temp=weight[j];
//                 weight[j]=weight[j+1];
//                 weight[j+1]=temp;
                
//                 temp=value[j];
//                 value[j]=value[j+1];
//                 value[j+1]=temp;
                
//                 temp=ratio[j];
//                 ratio[j]=ratio[j+1];
//                 ratio[j+1]=temp;
                
//             }
//         }
//     }
    
//     for(i=0;i<n;i++){
//         if(weight[i]<=capacity){
//             max_profit+=value[i];
//             capacity-=weight[i];
//         }
//         else{
//             max_profit+= ratio[i]*capacity;
//             break;
//         }
//     }
//     printf("max profit is %f",max_profit);
    
// }


