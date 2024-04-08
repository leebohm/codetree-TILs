#include <iostream>

#define MAX_N 11
using namespace std;

int n,k;
int coins[MAX_N];

int main() {

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    int ans = 0;

    for(int i=n-1; i>=0; i--){
        int tmp = k / coins[i];
        k = k % coins[i];
        ans += tmp; 
    }

    cout << ans;


    // 여기에 코드를 작성해주세요.
    return 0;
}