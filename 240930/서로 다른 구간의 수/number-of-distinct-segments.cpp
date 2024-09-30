#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<tuple<int, int, int> > lines;
set<int> segs;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        lines.push_back(make_tuple(x,1,i));
        lines.push_back(make_tuple(y,-1,i));
    }

    sort(lines.begin(), lines.end());

    int ans = 0;


    for(int i=0; i<2*n; i++){
        int x,t,idx;
        tie(x,t,idx) = lines[i];
        //cout << segs.size() << " ";
        if(segs.size() == 0){
            ans++;
        }
        if(t == 1){
            segs.insert(idx);
        }
        else if(t==-1)
            segs.erase(idx);
    }

    cout << ans;
    return 0;
}