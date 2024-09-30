#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
int n;
vector<pair<int,int> > lines;

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        lines.push_back(make_pair(x,1));
        lines.push_back(make_pair(y,-1));
    }
    sort(lines.begin(), lines.end());

    int sum_val = 0;
    int ans = 0;
    for(int i=0; i < 2*n; i++ ){
        int x,v;
        tie(x,v) = lines[i];
        sum_val += v;
        ans = max(ans, sum_val);
    }

    cout << ans;

    return 0;
}