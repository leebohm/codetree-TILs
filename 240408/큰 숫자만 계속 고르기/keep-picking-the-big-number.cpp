#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
int n,m;
int tmp;

int main() {

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> tmp;
        pq.push(tmp);
    }

    for(int i=0; i<m; i++){
        tmp = pq.top();
        pq.pop();
        tmp -= 1;
        pq.push(tmp);
    }

    int ans = pq.top();
    cout << ans ;
    // 여기에 코드를 작성해주세요.
    return 0;
}