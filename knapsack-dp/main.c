#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];  // Create a 2D array to store the computed values

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            }
            else {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
        }
    }

    // Return the maximum value achievable
    return dp[n][W];
}

int main() {
    int val[] = {4,4,3};  // Values of the items
    int wt[] = {4,4,3};     // Weights of the items
    int W = 50;                  // Total weight capacity of the knapsack
    int n = 3;  // sizeof(val) / sizeof(val[0])  -----------Total number of items

    printf("Maximum value: %d", knapsack(W, wt, val, n));
    
    return 0;
}

//-------------------------------------------------------------
// dp[i][w] = 0                                 if i = 0 or w = 0
//          = dp[i - 1][w]                        if wt[i - 1] > w
//          = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w])    if wt[i - 1] <= w
//-----------------------------------------------------------------

// #include<stdio.h>
// #include<conio.h>
// int max(int a,int b){
//     return(a>b?a:b);
// }

// void knapsack(int W,int val[],int wt[],int n){
//     int dp[n+1][W+1],i,j,w;
    
//     for(i=0;i<=n;i++){
//         for(j=0;j<=W;j++){
//             if (i==0 || W==0){
//                 return;
//             }
//             else if(wt[i-1]>W){
//                 dp[i][j]=dp[i-1][j];
//             }
//             else{
//                 dp[i][w]=max(dp[i-1][j],val[i-1]+dp[i-1][w-wt[i-1]]);
//             }
//         }   
//     }
    
//     return dp[n][W];
// }
// void main(){
//     int val[]={4,4,3};
//     int wt []={4,4,3};
//     int W=50;
//     int n=3;
    
//     printf("min value, %d",knapsack(W,val,wt,n));
//     }
// }


