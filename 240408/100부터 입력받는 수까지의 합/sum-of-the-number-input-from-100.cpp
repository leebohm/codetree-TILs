#include <iostream>

using namespace std;

int n;

int main() {

    cin >> n;

    int ans = 0;
    
    for(int i=n; i<= 100; i++)
        ans += i;
    
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}