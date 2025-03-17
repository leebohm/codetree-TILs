#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 100005

int n,s;
int arr[MAX_N];

int main() {
    
    cin >> n >> s;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int ans = INT_MAX;

    int j= 0;
    int val = 0;
    for(int i=1; i<=n; i++){
        while(j+1 <=n && val + arr[j+1] <= s ){ // 커지는 순간, j가 안 커지고 나가네 
            val += arr[j+1];
            j++;
        }

        ans = min(ans, j+1-i+1);
        val -= arr[i];
    }

    cout << ans;

    return 0;
}


