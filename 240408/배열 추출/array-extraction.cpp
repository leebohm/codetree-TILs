#include <iostream>
#include <queue>

using namespace std;

int n;
int x;
priority_queue<int> pq;

int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        if(x != 0){
            pq.push(x);
        }
        else{
            if(pq.empty() == false){
                x = pq.top();
                cout << x  << endl;
                pq.pop();
            }
            else{
                cout << 0 << endl;
            }

        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}