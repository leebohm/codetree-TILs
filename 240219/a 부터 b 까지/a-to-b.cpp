#include <iostream>

int a,b;
using namespace std;

int main() {

    cin >> a >> b;
    
    int i = a;

    while(i<=b){
        cout << i <<" ";
        if(i%2==1) i*=2;
        else i +=3;
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}