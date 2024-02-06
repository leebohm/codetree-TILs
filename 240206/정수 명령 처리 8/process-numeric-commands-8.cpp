#include <iostream>
#include <list>
#include <string>

using namespace std;

list<int> l;
int n;
string str;
int inp;

int main() {

    cin >> n;
    for(int i=0; i<n;i++){
        cin >> str;
        if(str == "push_back"){
            cin >> inp;
            l.push_back(inp);
        }

        if(str == "push_front"){
            cin >> inp;
            l.push_front(inp);
        }

        if(str == "pop_front"){
            inp = l.front();
            l.pop_front();
            cout << inp << endl;
        }

        if(str == "front"  ){
            cout << l.front() << endl;
        }

        if( str == "pop_back"){
            inp = l.back();
            l.pop_back();
            cout << inp << endl;
        }

        if(str == "empty"){
            bool flag = l.empty();
            cout << flag << endl;
        }

        if(str == "back"){
            cout << l.back() << endl;
        }

        if(str == "size")
        {
            cout << l.size() << endl;
        }

    }
    // 여기에 코드를 작성해주세요.
    return 0;
}