#include <iostream>

char c;
int n;
using namespace std;

int main() {

    cin >> c >> n;

    if(c=='A'){
        for(int i=1; i<=n;i++)
            cout << i <<" " ;
    } 
    else if(c=='D'){
        for(int i=n;i=1;i--)
            cout << i << " ";
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}