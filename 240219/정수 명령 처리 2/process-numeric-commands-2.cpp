#include <iostream>
#include <queue>
#include <string>

using namespace std;

string str;
queue<int> q;
int n;

int main() {

    cin >> n;
    int x;
    for(int i=0; i<n;i++){
        cin >>  str;
        if(str == "push"){
            cin >> x;
            q.push(x);
        }
        if(str == "front"){
            x = q.front();
            cout << x << endl;
        }
        if(str == "empty"){
            cout << q.empty() <<  endl;
        }

        if(str == "pop"){
            x = q.front();
            q.pop();
            cout << x << endl;
        }

        if(str == "size"){
            x = q.size();
            cout << x << endl;
        }
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}