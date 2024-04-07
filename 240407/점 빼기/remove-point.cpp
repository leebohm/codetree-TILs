#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int n,m;
set<pair<int,int>> s;

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        s.insert(make_pair(x,y));
    }

    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        int x,y;
        pair<int,int> tmp = *s.lower_bound(make_pair(k,-1));
        tie(x,y) = tmp;
        if(s.lower_bound(make_pair(k,-1)) == s.end())
            cout << -1 << " " << -1 << endl;
        else{
            cout << x << " " << y << endl;
            s.erase(tmp);
        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}