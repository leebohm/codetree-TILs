#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100000

using namespace std;

int arr[MAX_N];
int n;

int main(){
    
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    sort(arr+1, arr+n+1);

    int ans = INT_MAX;
    int j = n;
    for(int i=1; i<=n; i++){
        if(i < j)
            ans = min(ans, abs(arr[i]+arr[j]));
        
        while(j-1 >i && arr[i]+arr[j-1] > 0){
            j--;
            ans = min(ans, abs(arr[i]+arr[j]));
        }
    }
    
    cout << ans;

    return 0;
}