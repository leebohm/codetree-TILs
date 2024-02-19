#include <iostream>

int a,b ;
using namespace std;

int main() {
    cin >> a>> b;

    if(a>=1){
        for(int i=0; i<b;i++)
            cout << a;
    }
    else{
        cout << 0;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}