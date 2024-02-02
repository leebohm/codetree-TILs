// 아 두 선분이 서로 겹치지 않는 경우가 더 적은 경우의 수구나.. 
// x2 < x3 이거나 x4 < x1 이면 선분 안겹침... 
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