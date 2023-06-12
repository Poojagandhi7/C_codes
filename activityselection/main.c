// #include <stdio.h>
// #include <stdlib.h>

// struct activity{
//     int start;
//     int finish;
//     int act;
// };

// int main()
// {
//     struct activity arr[100];
//     int n,i,j;
//     struct activity temp;
//     printf("Enter a number:");
//     scanf("%d",&n);
//     for(i=0;i<n;i++) {
//         printf("Start time:");
//         scanf("%d",&arr[i].start);
//         printf("Finish time:");
//         scanf("%d",&arr[i].finish);
//         printf("Activity:");
//         scanf("%d",&arr[i].act);
//     }
//     for(i=0;i<n-1;i++) {
//         for(j=0;j<n-i-1;j++) {
//             if(arr[j].finish > arr[j+1].finish) {
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
//     struct activity soln[100];
//     soln[0]=arr[0];
//     int k=1;
//     for(i=1;i<n;i++) {
//         if(arr[i].start >= soln[k-1].finish) {
//             soln[k] = arr[i];
//             k++;
//         }
//     }
//     printf("Solution array is:\n");
//     for(i=0;i<k;i++) {
//          printf("A%d-->",sol[i].act);
//     }
//     return 0;
// }

#include<stdio.h>
#include<conio.h>

struct activity{
    int start;
    int finish;
    int act;
};

void main(){
    int i,j,n;
    struct activity arr[100];
    struct activity temp;
    printf("enter number:");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Start time:");
        scanf("%d",&arr[i].start);
        printf("Finish time:");
        scanf("%d",&arr[i].finish);
        printf("Activity:");
        scanf("%d",&arr[i].act);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j].finish > arr[j+1].finish){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    struct activity soln[100];
    soln[0]=arr[0];
    int k=1;
    for(i=0;i<n;i++){
        if (arr[i].start >= soln[k-1].finish){
            soln[k]=arr[i];
            k++;
        }
    }
    printf("solution array is:");
    for(i=0;i<k;i++){
        printf("A%d-->",soln[i].act);
    }
}

