#include <iostream>

using namespace std;

int n;
int idx;
int ans = 11;
int arr[10];

void Jump (int idx, int cnt){
    if(idx == n-1){
        ans = min(ans, cnt);
    }
    
    for(int i=1; i<=arr[idx]; i++){
        idx += i;
        Jump(idx, cnt+1);
        idx -=i;
    }

}

int main() {
    
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    Jump(0,0);
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}