#include <iostream>
#include <queue>

using namespace std;

int n;
int tmp;
priority_queue<int> pq;
int arr[3];

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> tmp;
        pq.push(-tmp);
    
        if(pq.size() < 3)
            cout << -1 << endl;
        
        else{
            int output = 1;
            for(int i=0; i<3; i++){
                tmp = -pq.top();
                output *= tmp;
                arr[i] = tmp;
                pq.pop();
            }
            cout << output << endl;
            for(int i=0; i<3; i++){
                pq.push(-arr[i]);
            }
        }

    }
    
    // 여기에 코드를 작성해주세요.
    return 0;
}