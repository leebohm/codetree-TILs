#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n;
int s,e;
priority_queue<pair<int,int> > pq;

int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> s >> e;

        pq.push(make_pair(-e,-s));
    }

    int cnt = 1;
    tie(e,s) = pq.top();
    int end_time = -e; 
    pq.pop();

    while(pq.empty() == false){
        tie(e,s) = pq.top();
        if( -s >= end_time){
            end_time = -e;
            cnt++;
        }
        pq.pop();
    }

    cout << cnt;

    // 여기에 코드를 작성해주세요.
    return 0;
}