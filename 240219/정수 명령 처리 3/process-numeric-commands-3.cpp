#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int> q;
string str;
int x;

int main() {
    
    cin >> n;
    for(int i=0; i<n;i++){
        cin>> str;
        if(str == "push_back"){
            cin >> x;
            q.push_back(x);
        }

        if(str == "push_front"){
            cin >> x;
            q.push_front(x);
        }

        if(str == "pop_back"){
            x = q.back();
            q.pop_back();
            cout << x<< endl;
        }

        if(str == "pop_front"){
            x = q.front();
            q.pop_front();
            cout << x << endl;
        }

        if(str == "front"){
            x = q.front();
            cout << x << endl;
        }

        if(str == "back"){
            x = q.back();
            cout << x << endl;
        }

        if(str == "empty"){
            cout << q.empty() << endl;
        }

        if(str == "size"){
            x = q.size();
            cout << x << endl;
        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}