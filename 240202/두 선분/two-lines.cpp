#include <iostream>

using namespace std;

int x1, x2, x3, x4;

int main() {

    cin >> x1 >> x2 >> x3 >> x4; 

    bool flag = false;

    if(x1 >= x3 && x1 <= x4)
        flag = true;
    if(x2 >= x3 && x2 <= x4)
        flag = true;
    
    if(x3 >= x1 && x3 <= x2)
        flag = true;
    
    if(x4 >= x1 && x4 <= x2)
        flag = true;
    
    if(flag)
        cout << "intersecting";
    else
        cout << "nonintersecting";
        // 여기에 코드를 작성해주세요.
    return 0;
}