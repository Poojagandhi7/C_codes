#include <stdio.h>
#include <limits.h>

void print_optimal_parens(int s[][6], int i, int j)
{ // s[row][column]
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrix_chain_order(int p[], int n)
{
    int m[n][n], s[n][n];

    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Optimal Parenthesization: ");
    print_optimal_parens(s, 1, n - 1);
    printf("\nMinimum number of multiplications: %d", m[1][n - 1]);
}

int main()
{
    int p[] = {4, 10, 3, 12, 20, 7};
    int n = 6;
    matrix_chain_order(p, n);
    return 0;
}
