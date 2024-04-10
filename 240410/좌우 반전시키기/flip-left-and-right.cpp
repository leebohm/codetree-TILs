#include <iostream>

using namespace std;

#define MAX_N 102
int n;
int arr[MAX_N];

int main() {
    
    cin >> n;
    
    for(int i = 1; i<=n; i++)
        cin >> arr[i];
    
    int ans = 0;

    for(int i = 2; i<=n; i++){
        if(arr[i-1] == 0){
            ans++;
            arr[i-1] = 1;
            arr[i] = 1;
            arr[i+1] = 1;
        }
    }
    bool flag = true;
    for(int i=1; i<=n; i++){
        if(arr[i] == 0)
            flag = false;
    }

    if(flag == true)
        cout << ans;
    else
        cout << -1;
    
    // 여기에 코드를 작성해주세요.
    return 0;
}