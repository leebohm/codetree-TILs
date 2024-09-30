#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int> > lines;

int main() {

    cin >> n;
    for(int i=0; i<n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        lines.push_back(make_pair(x1, 1));
        lines.push_back(make_pair(x2, -1));
    }

    sort(lines.begin(), lines.end());

    int ans = 0;
    int tmp = 0;
    for(int i=0; i<2*n; i++){
        int x,t;
        tie(x,t) = lines[i];
        tmp += t;
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}