#include <iostream>

using namespace std;


void countingSort(int arr[], int n, int k) {
    int C[k + 1];
    int B[n];

    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }


    for (int j = 0; j < n; j++) {
        C[arr[j]] = C[arr[j]] + 1;
    }

  cout << "Counting array after counting elements: ";
    for (int i = 0; i <= k; i++) {
        cout << C[i] << " ";
    }
    cout << endl;


    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    cout << "Show Counting array after modification: ";
    for (int i = 0 ; i <= k ; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    for (int j = n - 1; j >= 0; j--) {
            
        B[C[arr[j]] - 1] = arr[j];
        
        C[arr[j]] = C[arr[j]] - 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = B[i];
    }
}

void binarySearch(int arr[], int n, int searchh) {
      int left = 0;

    int right = n - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == searchh) {

            cout << "Element found at index: " << mid << endl;
            return ;

        }
        if (arr[mid] < searchh){
                left = mid + 1;
        }

        else {
                right = mid - 1;
    }
    }

cout << "Element not found" << endl;

}


int main() {
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 8;

     int searchh = 9;


    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

   countingSort(arr, n, k);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

     binarySearch(arr, n, searchh);

    return 0;
}