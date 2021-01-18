#include<iostream>
#include<iomanip>
using namespace std;

void merge(int arr[], int q, int n) {
    int *temp = new int[n];
    int i = 0;
    int left = 0, right = q;
    while (left < q && right < n)
        temp[i++] = arr[left] <= arr[right] ? arr[left++] : arr[right++];
    while (left < q)
        temp[i++] = arr[left++];
    while (right < n)
        temp[i++] = arr[right++];
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
    delete [] temp;
    return ;
}

void mergeSort(int arr[], int n) {
    if(1 == n)
        return ;
    int q = n / 2;
    mergeSort(arr, q);
    mergeSort(arr + q, n - q);
    merge(arr, q, n);
    return ;
}

int main(){
    int arr[9]{5,8,9,6,7,4,3,1,2};
    for (int i = 0; i < 9; i++)
        cout << setw(3) << arr[i];
    cout << endl;
    mergeSort(arr, 9);
    for (int i = 0; i < 9; i++)
        cout << setw(3) << arr[i];
    return 0;
}