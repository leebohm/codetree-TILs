#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n,m;
priority_queue<tuple<int,int,int> > pq;
int xy,x,y;

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        pq.push(make_tuple(-(x+y),-x,-y));
    }

    for(int i=0; i<m; i++){
       tie(xy,x,y) = pq.top();
       pq.pop();
       x = -x+2;
       y = -y+2;
       pq.push(make_tuple(-(x+y),-x,-y));
    }
    tie(xy,x,y) = pq.top();

    cout << -x << " " << -y ;
    // 여기에 코드를  작성해주세요.
    return 0;
}