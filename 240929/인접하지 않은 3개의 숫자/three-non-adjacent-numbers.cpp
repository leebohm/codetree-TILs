#include <iostream>
using namespace std;
#define MAX_N 100000

int n;
int arr[MAX_N];
int l[MAX_N];
int r[MAX_N];

int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    l[0] = arr[0];
    for(int i=1; i<n; i++)
        l[i] = max(l[i-1], arr[i]);
    
    r[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
        r[i] = max(r[i+1], arr[i]);

    int ans = 0;
    for(int i=2; i<=n-3; i++){
        ans = max(ans, l[i-2] + arr[i] + r[i+2]);
    }
    cout << ans;
    return 0;
}