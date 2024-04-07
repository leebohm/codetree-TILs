#include <iostream>

using namespace std;

int n;

int main() {

    cin >> n;

    int cnt = 0;

    for(int i=1; i<=n; i++){
        bool flag = true;

        if(i % 4 == 0)
            flag = false;

        if(i % 100 == 0 && i % 400 != 0)
            flag = true;

        if(flag == false)
            cnt++;
    }

    cout << cnt;

    // 여기에 코드를 작성해주세요.
    return 0;
}