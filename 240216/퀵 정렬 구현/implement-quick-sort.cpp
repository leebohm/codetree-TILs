#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n;
int arr[MAX_N];

int Partition(int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j = low; j < high ; j++)
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }

    swap(arr[i+1], arr[high]);

    return i+1;
}

void QuickSort(int low, int high) {
    if(low < high) {
        int pos = Partition(low, high);

        QuickSort(low, pos-1);
        QuickSort(pos+1, high);
    }
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    QuickSort(0,n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    
    return 0;
}