#include <iostream>
#include <climits>

#define MAX_N 100000
using namespace std;

int n;
int arr[MAX_N];

int main() {

    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int ans = INT_MIN;
    int sum_val = 0;
    for(int i = 0; i<n; i++){
        sum_val += arr[i];
        ans = max(ans, sum_val);
        if(sum_val < 0){
            sum_val = 0;
        }

    }
    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}