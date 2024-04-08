#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;
int x,y;

int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        pq.push(x);
    }

    while((int) pq.size() > 1){
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        if(abs(x-y) != 0){
            pq.push(abs(x-y));
        }
    }

    if(pq.empty() == true)
        cout << -1;
    else{
        int ans = pq.top();
        cout << ans;
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}