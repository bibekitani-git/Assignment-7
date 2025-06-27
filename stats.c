#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float calculate_mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (float)sum / n;
}

float calculate_median(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

void calculate_mode(int arr[], int n) {
    int max_count = 0, mode_count = 0;
    int freq[n], i, j;

    for (i = 0; i < n; i++) freq[i] = 0;

    for (i = 0; i < n; i++) {
        int count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) count++;
        }
        freq[i] = count;
        if (count > max_count) max_count = count;
    }

    printf("Mode: ");
    for (i = 0; i < n; i++) {
        if (freq[i] == max_count) {
            int is_duplicate = 0;
            for (j = 0; j < i; j++) {
                if (arr[i] == arr[j]) {
                    is_duplicate = 1;
                    break;
                }
            }
            if (!is_duplicate) printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int data[] = {2, 6, 11, 1, 18, 2, 4};
    int n = sizeof(data)/sizeof(data[0]);

    printf("Mean: %.2f\n", calculate_mean(data, n));
    printf("Median: %.2f\n", calculate_median(data, n));
    calculate_mode(data, n);

    return 0;
}
