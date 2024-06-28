#include <iostream>
#include <tuple>
#include<queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
vector<tuple<int,int,int> > vec;
int a,t,idx;
priority_queue<tuple<int,int,int> > pq;
int main(){
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> a>> t;
        vec.push_back(make_tuple(a,i+1,t));
    }
    vec.push_back(make_tuple(INT_MAX,n+1, 0));

    sort(vec.begin(), vec.end());

    int ans  = 0;
    int exit_time = 0;

    for(int i=0; i<n; i++){
        tie(a,idx,t) = vec[i];

        while(a > exit_time && pq.empty() == false){
            int na,nt;
            tie(ignore, na,nt) = pq.top();
            pq.pop();
            ans = max(ans, exit_time - na);
            exit_time += nt;
        }

        if(a > exit_time){
            exit_time = a+t;
        }
        else{
            pq.push(make_tuple(-idx,a,t));
        }
    }
    
    cout << ans;
    return 0;

}