#include <iostream>
#include <cmath>

int x;

using namespace std;

int main() {

    cin >> x;
    
    int y = sqrt(x);

    if(y*y == x) cout << 2*y-1;
    else if(y*y == x-1) cout << 2*y;

    // 여기에 코드를 작성해주세요.
    return 0;
}