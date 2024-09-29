#include<iostream>
#include<cmath>

using namespace std;

int partition(int A[], int low, int high) {
    int pivot_item = A[low];
    int left = low;
    int right = high;
    while (left < right) {
        while (A[left] <= pivot_item) {
            left++;
        }
        while (A[right] > pivot_item) {
            right--;
        }
        if (left < right) {
            swap(A[left], A[right]);
        }
    }
    A[low] = A[right];
    A[right] = pivot_item;
    return right;
}

void quicksort(int A[], int low, int high) {
    if (high > low) {
        int pivot = partition(A, low, high);
        quicksort(A, low, pivot - 1);
        quicksort(A, pivot + 1, high);
    }
}

void printA(int A[], int len) {
    for (int i = 0; i < len; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[7] = {2, 1, 6, 4, 7, 5, 3};
    // int arr[10] = {4, 5, 2, 6, 3, 8, 4, 12, -4, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    printA(arr, len);
    quicksort(arr, 0, len - 1);
    cout << "\nSORTED ARRAY\n";
    printA(arr, len);
    return 0;
}