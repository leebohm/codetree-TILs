#include <iostream>

int x1, y1, x2, y2;
int a1, b1, a2, b2;

using namespace std;

int main() {
    
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    bool flag = true;

    if(x2 < a1) flag = false;
    if(a2 < x1) flag = false;
    if(y2 < b1) flag = false;
    if(b2 < y1) flag = false;
    
    if (flag) cout << "overlapping";
    else cout << "nonoverlapping";
    
    // 여기에 코드를 작성해주세요.
    return 0;
}