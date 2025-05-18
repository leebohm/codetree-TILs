#include <iostream>

using namespace std;

#define MAX_N 105

int n;
int arr[MAX_N];

int main(){

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int i=1; i<=n ;i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j+1; k<=n; k++){
                if(arr[i] <= arr[j] && arr[j] <= arr[k]){
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}