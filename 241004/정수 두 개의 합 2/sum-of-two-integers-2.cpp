#include <iostream>
#include <algorithm>

#define MAX_N 100001

using namespace std;

int arr[MAX_N];
int n,k;

int main(){

    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    sort(arr+1, arr+n+1);

    int ans = 0;

    int j = n;
    for(int i=1; i<=n;i++){
        while(j!= 1 && arr[i] + arr[j] > k)
            j--;
        if(j <= i)
            break;
        
        ans += j-i;
    }
    cout << ans;
    return 0;
}