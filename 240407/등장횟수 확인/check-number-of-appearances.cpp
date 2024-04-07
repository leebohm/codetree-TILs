#include <iostream>

using namespace std;

int main() {
    int cnt = 0;
    for(int i=0; i<5; i++){
        int tmp;
        cin >> tmp;

        if(tmp % 2 == 0)
            cnt++;
    }
    cout << cnt;
    // 여기에 코드를 작성해주세요.
    return 0;
}