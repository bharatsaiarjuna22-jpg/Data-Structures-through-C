#include <stdio.h>

int getMax(int a[], int n) {
	int i;
    int max = a[0];
    for ( i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    return max;
}

void countingSort(int a[], int n, int exp) {
	int i;
    int out[50], count[10] = {0};

    for ( i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for ( i = 1; i < 10; i++)
        count[i] += count[i-1];

    for ( i = n-1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        out[count[d] - 1] = a[i];
        count[d]--;
    }

    for ( i = 0; i < n; i++)
        a[i] = out[i];
}

void radixSort(int a[], int n) {
	int exp;
    int max = getMax(a, n);

    for ( exp = 1; max/exp > 0; exp *= 10)
        countingSort(a, n, exp);
}

int main() {
	int i;
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;

    radixSort(a, n);
    printf("Sorted array using radixsort\n");

    for ( i = 0; i < n; i++)
        printf("%d ", a[i]);
}
