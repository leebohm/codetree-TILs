#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>

#define MAX_N 100001

using namespace std;

int  n;
tuple<int,int,int> people[MAX_N];
priority_queue<tuple<int,int,int> > pq;

int ans;

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        int a,t;
        cin >> a >> t;
        people[i] = make_tuple(a, i+1, t);
    }

    //people[n] = make_tuple(INT_MAX, n+1, 0);

    sort(people, people+n);

    int exit_time = 0;
    for(int i=0; i<=n; i++){
        int a,num,t;
        tie(a,num,t) = people[i];

        while(a > exit_time && !pq.empty()){

            int na, nt;
            tie(ignore, na,nt) = pq.top();
            pq.pop();

            ans = max(ans, exit_time - na);
            exit_time += nt;
        }

        if( a> exit_time)
            exit_time = a+t;
        else
            pq.push(make_tuple(-num, a,t));
    }

    cout << ans;
    return 0;
}