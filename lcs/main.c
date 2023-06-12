#include<stdio.h>
#include <string.h>

int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];

void print(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'c')
    {
        print(i - 1, j - 1);
        printf("%c", x[i - 1]);
    }
    else if (b[i][j] == 'u')
        print(i - 1, j);
    else
        print(i, j - 1);
}

void lcs()
{
    m = strlen(x);
    n = strlen(y);
    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (i = 0; i <= n; i++)
        c[0][i] = 0;

    // c, u and l denotes cross, upward and downward directions respectively
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
}
int main()
{
    printf("Enter 1st sequence:");
    scanf("%s", x);
    printf("Enter 2nd sequence:");
    scanf("%s", y);
    printf("\nThe Longest Common Subsequence is ");
    lcs();
    print(m, n);
    return 0;
}




// // The longest common subsequence in C

// #include <stdio.h>
// #include <string.h>

// int i, j, m, n, LCS_table[20][20];
// char S1[20] = "ACADB", S2[20] = "CBDA", b[20][20];

// void lcsAlgo() {
//   m = strlen(S1);
//   n = strlen(S2);

//   // Filling 0's in the matrix
//   for (i = 0; i <= m; i++)
//     LCS_table[i][0] = 0;
//   for (i = 0; i <= n; i++)
//     LCS_table[0][i] = 0;

//   // Building the mtrix in bottom-up way
//   for (i = 1; i <= m; i++)
//     for (j = 1; j <= n; j++) {
//       if (S1[i - 1] == S2[j - 1]) {       //i-1 & j-1 bcoz it starts from 0
//         LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
//       } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
//         LCS_table[i][j] = LCS_table[i - 1][j];
//       } else {
//         LCS_table[i][j] = LCS_table[i][j - 1];
//       }
//     }

//   int index = LCS_table[m][n];
//   char lcsAlgo[index + 1];
//   lcsAlgo[index] = '\0';

//   int i = m, j = n;
//   while (i > 0 && j > 0) {
//     if (S1[i - 1] == S2[j - 1]) {
//       lcsAlgo[index - 1] = S1[i - 1];
//       i--;
//       j--;
//       index--;
//     }

//     else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
//       i--;
//     else
//       j--;
//   }

//   // Printing the sub sequences
//   printf("S1 : %s \nS2 : %s \n", S1, S2);
//   printf("LCS: %s", lcsAlgo);
// }

// int main() {
//   lcsAlgo();
//   printf("\n");
// }




