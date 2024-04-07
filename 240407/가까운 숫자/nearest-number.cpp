#include <iostream>
#include <set>
#include <climits>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n;
int queries[MAX_N];
set<int> s;

int ans = INT_MAX;

int main(){
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> queries[i];

    s.insert(0);

    for(int i=0; i<n; i++){
        set<int>::iterator it = s.upper_bound(queries[i]);
        if(it != s.end())
            ans = min(ans, *it - queries[i]);

        it--;

        ans = min(ans, queries[i] - *it);

        s.insert(queries[i]);
        cout << ans << endl;
    }
    return 0;
}