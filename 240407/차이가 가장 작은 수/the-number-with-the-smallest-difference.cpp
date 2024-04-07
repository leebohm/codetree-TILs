#include <iostream>
#include <set>
#include <climits>

using namespace std;

#define MAX_N 100000
set<int> s;
int n,m;

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    set<int>::iterator it = s.begin();
    int ans = INT_MAX;
    while(it != s.end()){

        int tmp = *it + m;
        if(s.lower_bound(tmp)!= s.end()){

            ans = min(ans, *s.lower_bound(tmp)-*it );
        }
        it++;
    }

    if(ans != INT_MAX)
        cout << ans;
    else
        cout << -1;    

    // 여기에 코드를 작성해주세요.
    return 0;
}