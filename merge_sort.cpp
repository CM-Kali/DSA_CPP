#include <iostream>
using namespace std;

// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;   // size of left part
    int n2 = right - mid;      // size of right part

    int a[n1], b[n2]; // temporary arrays

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        a[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    // Merge temp arrays into original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }

    while (i < n1) arr[k++] = a[i++]; // remaining left
    while (j < n2) arr[k++] = b[j++]; // remaining right
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       // left half
        mergeSort(arr, mid + 1, right);  // right half
        merge(arr, left, mid, right);    // merge halves
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = 5;

    mergeSort(arr, 0, n - 1);

    cout << "Merge Sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

