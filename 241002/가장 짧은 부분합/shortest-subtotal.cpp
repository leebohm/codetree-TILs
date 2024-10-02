#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100001

using namespace std;

int arr[MAX_N];
int n, s;

int main(){
    cin >> n >> s;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int ans = INT_MAX;

    int sum_val = 0;
    int j = 0;

    for(int i=1; i<=n; i++){
        while(j+1 <= n && sum_val < s){
            sum_val += arr[j+1];
            j++;
        }
        if(sum_val < s)
            break;
        
        ans = min(ans, j-i+1);
        sum_val -= arr[i];
    }

    if(ans == INT_MAX)
        ans = -1;

    cout << ans;
    return 0;
}