#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n,m;

int main() {

    cin >> n >>  m;

    int tmp;
    for(int i=0; i<n; i++){
        cin >> tmp;
        s.insert(tmp);
    }
    for(int i=0; i<m; i++){
        cin >> tmp;
        if(s.lower_bound(tmp) != s.end())
            cout << *s.lower_bound(tmp) << endl;
        else
            cout << -1 << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}