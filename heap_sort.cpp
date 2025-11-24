#include <iostream>
using namespace std;

// Heapify makes a subtree rooted at i follow Max Heap rules
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Step 1: Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: One by one extract elements
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // move max to end
        heapify(arr, i, 0);   // heapify reduced heap
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;

    heapSort(arr, n);

    cout << "Heap Sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

