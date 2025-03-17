#include <iostream>

using namespace std;

#define MAX_N 100005

int n;
int arr[MAX_N];
int DAT[MAX_N];

int main(){

    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    int j=0;
    for(int i=1; i<=n; i++){
        while(j+1 <= n && DAT[arr[j+1]] < 1){
            DAT[arr[j+1]]++;
            j++;
        }
        
        ans = max(ans, j-i+1);
        DAT[arr[i]]--;
    }

    cout << ans;

    return 0;
}