#include <iostream>

int n;

using namespace std;

int main() {

    cin >> n;

    for(int i=1; i<=n;i++){
        if(i%2==0 || i%3==0)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}