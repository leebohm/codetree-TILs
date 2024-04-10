#include <iostream>

#define MAX_N 1000
using namespace std;

int n;
int arr[MAX_N];
int arr_len[MAX_N];
int max_val[MAX_N];

int main(){
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    max_val[0] = arr[0];

    for(int i=0; i<n; i++)
        arr_len[i] = 1;

    for(int i=1;i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > max_val[j]){
                arr_len[i] = max(arr_len[i], arr_len[j]+1);
                max_val[i] = arr[i];
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr_len[i] > ans)
            ans = arr_len[i];
    }
    cout << ans;
    
}