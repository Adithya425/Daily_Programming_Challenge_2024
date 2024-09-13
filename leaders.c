#include <stdio.h>

void findLeaders(int arr[], int n) {
    int max_from_right = arr[n - 1]; 
    int leaders[n]; 
    int index = 0; 

    leaders[index++] = max_from_right;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            max_from_right = arr[i];
            leaders[index++] = arr[i]; 
        }
    }

    printf("Leaders: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d ", leaders[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLeaders(arr, n);

    return 0;
}
