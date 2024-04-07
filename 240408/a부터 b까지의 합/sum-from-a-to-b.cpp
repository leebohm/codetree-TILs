#include <iostream>

using namespace std;

int a,b;

int main() {

    cin >> a >> b;

    int ans = 0;
    
    for(int i=a; i<=b; i++)
        ans += i;
    
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}