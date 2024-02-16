#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n;
int arr[MAX_N+1];

void Heapify(int n, int i){
    int largest = i;
    int l = i*2;
    int r = i*2+1;

    if(l<= n && arr[l] > arr[largest])
        largest = 1;
    
    if(r<= n && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        Heapify(n, largest);
    }
}

void HeapSort() {
    for(int i=n/2; i>= 1; i--)
        Heapify(n,i);
    
    for(int i=n;i>1;i--){
        swap(arr[1], arr[i]);
        Heapify(i-1, 1);
    }
}

int main() {
    cin >> n;

    for(int i=1; i<=n;i++)
        cin >> arr[i];
    
    HeapSort();

    for(int i=1; i<=n; i++)
        cout << arr[i] << " ";
    return 0;
}