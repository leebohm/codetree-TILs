#include <iostream>

int n;
using namespace std;

int main() {

    cin >> n;

    for(int i=1; i<=n; i++){
        if(i%3==0) cout << "0 ";
        else if(i/10 == 3 ||  i/10 == 6 ||  i/10 == 9)  cout << "0 ";
        else if(i%10 == 3 || i%10 == 6 || i%10 == 9) cout << "0 ";
        else cout << "1 ";
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}