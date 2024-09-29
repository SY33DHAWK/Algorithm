#include <iostream>
#include <cmath>

using namespace std;

int i = 0;

int mergecall = 0;

void merge_(int A [], int start, int mid, int endd)

{

    mergecall++;

    cout<< "Merge_itera:" << mergecall << "start:" << start << " mid: " << mid << "End:" << endd << endl;

    int i,j;

    int n1 = mid-start+1;
    int n2 = endd - mid;

    cout << "n1:" << n1 << "n2:" << n2 << endl;

    int L[n1+1], R[n2+1];

    for (i=0; i<n1;i++)
    {
        L[i] = A[start+i];
    }

    for (j=0; j<n2; j++)

    {
        R[j] = A[mid+1+j];
    }

    L[n1] = INFINITY;
    R[n2] = INFINITY;

    i = 0 ;
    j = 0;


    for (int k = start; k<=endd; k++ )
    {
        if (L[i]<= R[j])
        {
            A[k] = L[i];
            i++;
        }

        else {
            A[k] = R[j];
            j++;
        }


    }
}

void merge_sort(int A[], int start, int endd){

int mid;
i++;
if(start<endd){
    mid = floor((start+endd)/ 2);

    cout<< "Iteration:" << i << "Mid:" << mid << endl;
    merge_sort(A,start,mid);
    merge_sort(A,mid+1,endd);
    merge_(A,start,mid,endd);
}
}

void printA(int A[],int len){
    for (int i = 0; i<len; i++){
        cout<< A[i] << " ";
    }

    cout<< endl;

}

int main(){

    int arr[8] = {2,7,5,4,1,9,3,6};

    int len = sizeof(arr)/ sizeof(arr[0]);

    printA(arr, len);

    merge_sort(arr,0,len-1);

    cout<< "Sorted Array" << endl;


    printA(arr,len);

    return 0;

}