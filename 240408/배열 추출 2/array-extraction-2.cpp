#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

priority_queue<pair<int,int>> pq;

int n;
int x,y;

int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;

        if(x == 0){
            if(pq.empty() == false){
                tie(x,y) = pq.top();
                pq.pop();
                cout << -y << endl;
            }
            else{
                cout << 0 << endl;
            }

        }
        else{
            pq.push(make_pair(-abs(x),-x));
        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}