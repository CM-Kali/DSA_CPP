#include <iostream>
using namespace std;

// Partition function returns the index of pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Last element as pivot
    int i = low - 1;        // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // place pivot in correct position
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // pivot index

        quickSort(arr, low, pi - 1); // before pivot
        quickSort(arr, pi + 1, high); // after pivot
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quickSort(arr, 0, n - 1);

    cout << "Quick Sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

