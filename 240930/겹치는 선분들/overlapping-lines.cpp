#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n,k;
int ans;

vector<pair<int, int> > segments;
vector<pair<int, int> > points;

int main(){
    cin >> n >> k;

    int x = 0;

    for(int i=0; i<n; i++){
        int dist; char c_dir;
        cin >> dist >> c_dir;
        if(c_dir == 'L'){
            segments.push_back(make_pair(x-dist, x));
            x -= dist;
        }
        else{
            segments.push_back(make_pair(x,x+dist));
            x += dist;
        }
    }

    for(int i=0; i<n; i++){
        int x1, x2;
        tie(x1, x2) = segments[i];
        points.push_back(make_pair(x1,1));
        points.push_back(make_pair(x2,-1));
    }

    sort(points.begin(), points.end());

    int sum_val = 0;

    for(int i=0; i< 2*n; i++){
        int x, v;
        tie(x,v) = points[i];

        if(sum_val >= k){
            int prev_x;
            tie(prev_x, ignore) = points[i-1];
            ans += x - prev_x;
        }

        sum_val += v;
    }
    cout << ans;
    return 0;
}