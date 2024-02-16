#include <iostream>

int main() {
    // 여기에 코드를 작성해주세요.
    return 0;
}

#include <iostream>
#define MAX_N 100000

using namespace std;

int n;
int arr[MAX_N];
int merged_arr[MAX_N];

void Merge(int low, int mid, int high){
    int i = low, j = mid+1;
    int k = low;

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j])
            merged_arr[k++] = arr[i++];
        else 
            merged_arr[k++] = arr[j++];
    }

    while(i<= mid)
        merged_arr[k++] = arr[i++];
    
    while (j<= high)
        merged_arr[k++] = arr[j++];
    
    for(int k=low; k<= high ; k++)
        arr[k] = merged_arr[k];
}

void MergeSort(int low, int high){
    if(low < high){
        int mid = (low + high) /2;
        MergeSort(low, mid);
        MergeSort(mid+1, high);
        Merge(low, mid, high);
    }
}

int main() {
    cin >> n;

    for(int i=0; i<n;i++)
        cin >> arr[i];
    
    MergeSort(0, n-1);

    for(int i=0; i<n;i++)
        cout << arr[i]  << " ";
    
    return 0;
}