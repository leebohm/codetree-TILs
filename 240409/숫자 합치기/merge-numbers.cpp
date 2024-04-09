#include <iostream>
#include <queue>

using namespace std;

int n;
int a,b;
priority_queue<int> pq;

int main(){
    
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        pq.push(-tmp);
    }

    int cost = 0;
    while((int) pq.size() > 1){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        cost += -(a+b);
        pq.push(a+b);
    }
    cout << cost;

    return 0;
}