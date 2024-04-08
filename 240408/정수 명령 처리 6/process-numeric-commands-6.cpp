#include <iostream>
#include <queue>
#include <string>

using namespace std;

priority_queue<int> q;
int n;
string str;
int tmp;
int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> str;

        if(str == "push"){
            cin >> tmp;
            q.push(tmp);
        }
        else if(str == "pop"){
            tmp = q.top();
            q.pop();
            cout << tmp << endl;
        }

        else if(str == "size"){
            tmp = q.size();
            cout << tmp << endl;
        }

        else if(str == "empty"){
            tmp = q.empty();
            cout << tmp << endl;
        }

        else if(str == "top"){
            tmp = q.top();
            cout << tmp << endl;
        }
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}