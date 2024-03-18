#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <climits>

#define MAX_N 20
using namespace std;

int n,m;
int ans = INT_MAX;
vector<pair<int,int>> pos;
vector<pair<int,int>> selected_pos;

int Dist(pair<int,int> a, pair<int,int> b){
    int ax,ay;
    tie(ax,ay) = a;

    int bx,by;
    tie(bx,by) = b;

    return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
}

int Calc(){
    int tmp = -1;
    for(int i=0; i<(int) selected_pos.size(); i++){
        for(int j= i+1; j <(int) selected_pos.size(); j++){
            tmp = max(tmp, Dist(selected_pos[i],selected_pos[j]));
        }
    }
    return tmp;
}
void Choose(int curr_idx, int cnt){
    if(cnt == m){
        ans = min(ans, Calc());
        return;
    }
    if(curr_idx == n)
        return;

    selected_pos.push_back(pos[curr_idx]);
    Choose(curr_idx+1, cnt+1);
    selected_pos.pop_back();

    Choose(curr_idx+1, cnt);
}

int main() {

    cin >> n >> m;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        pos.push_back(make_pair(x,y));
    }

    Choose(0,0);

    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}