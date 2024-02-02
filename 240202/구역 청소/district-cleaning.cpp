#include <iostream>

int a,b,c,d;
using namespace std;

int main() {

    cin >> a>> b;
    cin >> c >> d;

    bool flag = true;
    if(b < c) flag = false;
    if(d < a) flag = false;

    int ans = 0;
    if(flag){
        int max_d = max(b,d);
        int min_d = min (a,c);
        ans = max_d- min_d;
    }
    else ans = (b-a)+(d-c); 

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}