#include <iostream>
#include <algorithm>
#include <tuple>
#include <climits>
#include <vector>

#define MAX_N 20

using namespace std;

int n,m;
pair<int,int> points[MAX_N];

vector<pair<int, int> > selected_points;

int ans = INT_MAX;

int Dist(pair<int,int> p1, pair<int,int> p2){
    int x1, y1;
    tie(x1, y1) = p1;

    int x2, y2;
    tie(x2, y2) = p2;

    return(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1-y2);
}

int Calc(){
    int max_dist = 0;

    for(int i =0; i<m; i++)
        for(int j=i+1; j<m; j++)
            max_dist = max(max_dist, Dist(selected_points[i], selected_points[j]));
    
    return max_dist;
}

void FindMin(int idx, int cnt){
    if(cnt == m){
        ans = min(ans, Calc());
        return;
    }

    if(idx == n)
        return;
    
    selected_points.push_back(points[idx]); 
    FindMin(idx + 1, cnt + 1);
    selected_points.pop_back();

    FindMin(idx + 1, cnt);
}

int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        points[i]  = make_pair(x,y);
    }

    FindMin(0,0);

    cout << ans;

    return 0;
}