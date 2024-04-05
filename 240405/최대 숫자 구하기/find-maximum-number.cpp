#include <iostream>
#include <set>

using namespace std;

int n,m;
set<int> s;

int main() {

    cin >> n >> m;

    for(int i=1; i<=m; i++)
        s.insert(i);
    
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        s.erase(tmp);

        cout << *s.rbegin() << endl;
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}