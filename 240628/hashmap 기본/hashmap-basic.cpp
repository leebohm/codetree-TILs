#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string str;
int n;
unordered_map<int,int> m;
int x,y;
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        if(str == "add"){
            cin >> x >> y;
            m[x] = y;
        }
        else if(str == "find"){
            cin >> x;
            if(m.find(x)!= m.end()){
                cout << m[x] << endl;
            }
            else
                cout << "None"<< endl;
        }
        else if(str == "remove"){
            cin >> x;
            m.erase(x);
        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}