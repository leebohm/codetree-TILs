#include <iostream>
#include <set>
#include <unordered_map>
#include <tuple>

#define MAX_N 2500
#define MAX_Q 300000
#define MAX_M 5000

using namespace std;

int n,q;
pair<int,int> points[MAX_N];
tuple<int,int,int,int> queries[MAX_Q];

set<int> nums;
unordered_map<int,int> mapper;

int prefix_sum[MAX_M+2][MAX_M+2];

int GetLowerBoundary(int x){
    set<int>::iterator it = nums.lower_bound(x);

    if(it == nums.end())
        return (int) nums.size() + 1;
    
    return mapper[*it];
}

int GetUpperBoundary(int x){
    set<int>::iterator it = nums.upper_bound(x);

    if(it == nums.begin())
        return 0;
    
    it--;
    return mapper[*it];
}

int GetSum(int x1, int y1, int x2, int y2){
    return prefix_sum[x2][y2] - prefix_sum[x1-1][y2] -
        prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1];
}

int main(){
    cin >> n >> q;

    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x,y);

        nums.insert(x);
        nums.insert(y);
    }

    for(int i=0; i<q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queries[i] = make_tuple(x1, y1, x2, y2);
    }

    int cnt = 1;
    for(set<int>::iterator it = nums.begin(); it != nums.end(); it++){
        mapper[*it] = cnt;
        cnt++;
    }

    for(int i=0; i<n; i++){
        int x, y;
        tie(x,y) = points[i];

        int nx = mapper[x];
        int ny = mapper[y];

        prefix_sum[nx][ny]++;
    }

    for(int i=1; i<=cnt; i++)
        for(int j=1; j<= cnt; j++)
            prefix_sum[i][j] += prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];

    for(int i=0; i<q; i++){
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = queries[i];

        int nx1 = GetLowerBoundary(x1);
        int ny1 = GetLowerBoundary(y1);
        int nx2 = GetUpperBoundary(x2);
        int ny2 = GetUpperBoundary(y2);

        int ans = GetSum(nx1, ny1, nx2, ny2);
        cout << ans << endl;
    }

    return 0;
}