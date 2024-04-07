#include <iostream>

using namespace std;

int n;
int main() {
    
    cin >> n;
    int ans = 0;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;

        if(tmp % 2 == 1 && tmp % 3 == 0)
            ans += tmp;
    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}