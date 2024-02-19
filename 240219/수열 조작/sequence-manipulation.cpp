#include <iostream>
#include <deque>

using namespace std;

deque<int> q;
int n;

int main() {
    cin >> n;
    int x;
    for(int i=1; i<=n ; i++){
        q.push_back(i);
    }

    while(q.size() != 1){
        q.pop_front();
        x = q.front();
        q.pop_front();
        q.push_back(x);
    }
    cout << q.front() ;
    // 여기에 코드를 작성해주세요.
    return 0;
}