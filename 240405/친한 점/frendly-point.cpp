#include <iostream>
#include <set>

using namespace std;

set<pair<int,int> > s;
int n,m;
int x,y;

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        s.insert(make_pair(x,y));
    }

    for(int i=0; i<m; i++){
        cin >> x >> y;
        if(s.lower_bound(make_pair(x,y)) != s.end()){
            pair<int,int> p = *s.lower_bound(make_pair(x,y));
            cout <<p.first  <<" " << p.second <<" " << endl;
        }
        else{
            cout << -1 <<" " << -1 << endl;
        }

    }
    // 여기에 코드를 작성해주세요.
    return 0;
}