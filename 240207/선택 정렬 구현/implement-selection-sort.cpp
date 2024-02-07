#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N];

void SelectionSort(){
    for(int i=0; i<n-1; i++){
        int min_index = i;
        for(int k=i+1; k<n;k++)
            if(arr[min_index]>arr[k])
                min_index = k;
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main(){
    cin >> n;

    for(int i=0; i<n;i++)
        cin >> arr[i];
    
    SelectionSort();

    for(int i=0; i<n;i++)
        cout << arr[i] << " ";
    
    return 0;
}