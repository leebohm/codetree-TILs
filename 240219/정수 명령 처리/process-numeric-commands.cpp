#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
string str;
stack<int> s;

int main() {

    cin>> n;
    int x;

    for(int i=0; i<n;i++){
        cin >> str;

        if(str == "push"){
            cin >> x;
            s.push(x);
        }

        if(str == "size"){
            cout << s.size() << endl;
        }

        if(str == "empty"){
            cout << s.empty() << endl;
        }

        if(str == "pop"){
            x = s.top();
            cout << x << endl;
            s.pop();
        }

        if(str == "top"){
            x = s.top();
            cout <<  x << endl;
        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}