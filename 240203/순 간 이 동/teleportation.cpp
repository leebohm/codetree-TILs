#include <iostream>

using namespace std;

int a,b,x,y;

int main() {

    cin >> a >> b>> x>> y;

    int dist1 = abs(a-b);
    int dist2 = abs(a-x)+abs(y-b);
    int dist3 = abs(a-y)+abs(x-b);
    int ans = 1e9;

    ans = min(ans, dist1);
    ans = min(ans, dist2);
    ans = min(ans, dist3);

    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}