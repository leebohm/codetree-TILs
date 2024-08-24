#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n;
unordered_map<int,int> m;
string str;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        int a,b;
        if(str == "add"){
            cin >> a >> b;
            m[a] = b;
        }
        else if(str == "find"){
            cin >> a;
            if(m.find(a) != m.end()){
                cout << m[a] << endl;
            }
            else
                cout << "None" << endl;
        }
        else if(str == "remove"){
            cin >> a;
            m.erase(a);
        }
    }
    return 0;
}