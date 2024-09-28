#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <set>

using namespace std;

#define MAX_N 100001

int n,q;
int points[MAX_N];
pair<int,int> queries[MAX_N]; 
unordered_map<int,int> mapper;
int pre_sum[MAX_N];
set<int> nums;

int Lowerbound(int cur){
    set<int>::iterator it;

    it = nums.lower_bound(cur);
    if(it == nums.end())
        return nums.size()+1;

    
    return mapper[*it];
}

int UpperBound(int cur){
    set<int>::iterator it;

    it = nums.upper_bound(cur);
    
    if(it == nums.begin())
        return 0;
    it--;
    return mapper[*it];
}

int main() {

    cin >> n >> q;

    for(int i=0; i<n; i++){
        cin >> points[i];
        nums.insert(points[i]);
    }
    
    for(int i=0; i<q; i++){
        int x,y;
        cin >> x >> y;
        queries[i] = make_pair(x,y);
    }

    int cnt = 1; 

    for(int i=0; i<n; i++){
        mapper[points[i]] = cnt;
        cnt++;
        pre_sum[mapper[points[i]]]++;
    }

    for(int i=1; i<= cnt; i++){
        pre_sum[i] += pre_sum[i-1];
    }

    for(int i=0; i<q; i++){
        int x,y;
        tie(x,y) = queries[i];
        int nx = Lowerbound(x);
        int ny = UpperBound(y);
        int ans = pre_sum[ny] - pre_sum[nx-1];
        cout << ans  << endl;
    }

    return 0;
}