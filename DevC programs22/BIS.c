#include <stdio.h>

int binSearch(int a[], int key, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

void binInsertionSort(int a[], int n) {
	int i;
    for ( i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        int pos = binSearch(a, key, 0, j);

        while (j >= pos) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main() {
	int i;
    int a[] = {37, 23, 0, 17, 12, 72, 31};
    int n = 7;

    binInsertionSort(a, n);

    for ( i = 0; i < n; i++)
        printf("%d ", a[i]);
}
