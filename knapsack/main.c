#include<stdio.h>
int main()
{
     float weight[50],profit[50],ratio[50],Totalvalue,temp,capacity,amount;
     int n,i,j;
     printf("Enter the number of items :");
     scanf("%d",&n);   
    for (i = 0; i < n; i++)
    {
        printf("Enter Weight and Profit for item[%d] :\n",i);
        scanf("%f %f", &weight[i], &profit[i]);
    } 
    printf("Enter the capacity of knapsack :\n");
    scanf("%f",&capacity);
     
     for(i=0;i<n;i++)
         ratio[i]=profit[i]/weight[i];
         
    for (i = 0; i < n; i++) 
      for (j = i + 1; j < n; j++) 
         if (ratio[i] < ratio[j]) 
        {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
    
    printf("Knapsack problems using Greedy Algorithm:\n");
    for (i = 0; i < n; i++) 
    {
        if (weight[i] > capacity)
        {
          break;  
        }
        else 
        {
          Totalvalue = Totalvalue + profit[i];
          capacity = capacity - weight[i];
        }
    } 
      if (i < n)
      Totalvalue = Totalvalue + (ratio[i]*capacity);
     printf("\nThe maximum value is :%f\n",Totalvalue);     
     return 0;
}

// #include<stdio.h>
// #include<conio.h>
// void main()
// {
//     float weight[10],profit[10],ratio[10],max_profit,temp,capacity;
//     int n,i,j;
//     printf("Enter no of items:");
//     scanf("%d",&n);
//     for(i=0;i<n;i++)
//     {
//         printf("enter weight");
//         scanf("%f",&weight[i]);

//         printf("enter profit");
//         scanf("%f",&profit[i]);
//     }
//     printf("Enter max capacity:");
//     scanf("%f",&capacity);
//     for(i=0;i<n;i++){
//         ratio[i]=profit[i]/weight[i];
//     }
//     for(i=0;i<n;i++)
//     {
//         for(j=0;j<n-i-1;j++)
//         {
//             if(ratio[j]<ratio[j+1])
//             {
//                 temp=ratio[j];
//                 ratio[j]=ratio[j+1];
//                 ratio[j+1]=temp;

//                 temp=weight[j];
//                 weight[j]=weight[j+1];
//                 weight[j+1]=temp;

//                 temp=profit[j];
//                 profit[j]=profit[j+1];
//                 profit[j+1]=temp;
//             }
//         }
//     }
//     printf("Knapsack problem using greedy is:");
//     for(i=0;i<n;i++)
//     {
//       if(weight[i]>capacity) {
//         break;
//       }
//       else{
//         capacity=capacity=weight[i];
//         max_profit=max_profit+profit[i];
//       }
//     }
//     if(i<n){
//         max_profit=max_profit+(ratio[i]*capacity);
//     }
//     printf("total profit is %f",max_profit);
// }
