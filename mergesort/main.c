#include <stdio.h>

void merge(int a[], int l, int m, int u) {
    int b[100];
    int i = l;
    int j = m + 1;
    int k = 0;
    while (i <= m && j <= u) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
            k++;
        } else {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= m) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= u) {
        b[k] = a[j];
        k++;
        j++;
    }
    for (i = l, k = 0; i <= u; i++, k++) {
        a[i] = b[k];
    }
}
void mergesort(int a[], int l, int u) {
    int m;
    if (l < u) {
        m = (l + u) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, u);
        merge(a, l, m, u);
    }
}
int main() {
    int i, a[100], n;
    printf("enter number of elements in array\n");
    scanf("%d", &n);
    printf("elements in array are:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}