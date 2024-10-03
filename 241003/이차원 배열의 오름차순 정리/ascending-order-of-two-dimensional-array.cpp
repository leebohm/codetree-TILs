#include <iostream>
#include <algorithm>

using namespace std;

long long n, k;

int main(){

    cin >> n;
    cin >> k;
    
    long long lo = 1;
    long long hi = n*n;
    long long ans = n*n;

    while(lo <= hi){
        long long mid = (lo + hi) / 2;

        long long val = 0;
        for(int i=1; i<=n; i++)
            val += min(n,mid/i);
        
        if(val >= k){
            hi = mid - 1;
            ans = min(ans, mid);
        }
        else lo = mid + 1;
    }

    cout << ans;
    return 0;
}