#include <iostream>

using namespace std;

#define MAX_N 105

int n,k;
int arr[MAX_N];

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int ans = 0;
    for(int i=0; i<n; i++){
        int tmp = 0;
        for(int j=i; j< min(i+k,n); j++){
            tmp += arr[j];
        }
        ans = max(tmp,ans);
    }
    cout << ans;
    return 0;
}