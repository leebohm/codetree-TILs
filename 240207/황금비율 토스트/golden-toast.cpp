#include <iostream>
#include <list>

using namespace std;

int n,m;
string str;
list<char> l;
char c;

int main() {
    cin >> n >> m;
    cin >> str;
    for(int i=0; i<n;i++)
        l.push_back(str[i]);

    list<char>::iterator it;
    it = l.end();

    for(int i=0;i<m;i++){
        cin >> c;
        if(c == 'L'){
            it --;
        }

        if(c=='P'){
            cin >> c;
            l.insert(it,c);
        }

        if(c=='R'){
            it ++; 
        }

        if(c=='D'){
            l.erase(it);
        }
    }
    
    for(it = l.begin(); it != l.end(); it++)
        cout << *it;
            

    // 여기에 코드를 작성해주세요.
    return 0;
}