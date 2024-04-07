#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n,m;

int main() {

    cin >> n >>  m;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    int ans = (int) s.size();

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}