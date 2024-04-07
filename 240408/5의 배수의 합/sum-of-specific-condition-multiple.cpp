#include <iostream>

using namespace std;

int a,b;

int main() {

    cin >> a >> b;

    int n = min(a,b);
    int m = max(a,b);

    int ans = 0;
    for(int i=n; i <=m; i++){
        if(i % 5 ==0)
            ans += i;
    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}