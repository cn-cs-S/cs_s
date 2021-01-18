#include<iostream>
#include<iomanip>

void input(int arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

void output(int arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << std::setw(10) << arr[i];
    std::cout << std::endl;
}

void input(float arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

void output(float arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << std::setw(10) << arr[i];
    std::cout << std::endl;
}

void mengeSort(int arr[], int q, int n) {
    int *temp = new int[n];
    int i = 0;
    int left = 0, right = q;
    while (left < q && right < n)
        temp[i++] = arr[left] >= arr[right] ? arr[left++] : arr[right++];
    while (left < q)
        temp[i++] = arr[left++];
    while (right < n)
        temp[i++] = arr[right++];
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
    delete [] temp;
}

void sort(int arr[], int n) {
    if (1 == n)
        return ;
    int q = n / 2;
    sort(arr, q);
    sort(arr + q, n - q);
    mengeSort(arr, q, n);
}

void mengeSort(float arr[], int q, int n) {
    float *temp = new float[n];
    int i = 0;
    int left = 0, right = q;
    while (left < q && right < n)
        temp[i++] = arr[left] >= arr[right] ? arr[left++] : arr[right++];
    while (left < q)
        temp[i++] = arr[left++];
    while (right < n)
        temp[i++] = arr[right++];
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
    delete [] temp;
}

void sort(float arr[], int n) {
    if (1 == n)
        return ;
    int q = n / 2;
    sort(arr, q);
    sort(arr + q, n - q);
    mengeSort(arr, q, n);
    return ;
}

int main(){
    int a[5];
    float b[5];
    
    input(a,5);
    sort(a,5);
    output(a,5);
    input(b,5);
    sort(b,5);
    output(b,5);
} 