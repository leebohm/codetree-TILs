#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v;
int n;
string str;

int main(){

    cin >> n;
    for(int i=0; i<n;i++) {
        cin >> str;
        int inp;
        if(str == "push_back"){
            cin >>inp;
            v.push_back(inp); 
        }
        if(str == "get") {
            cin >> inp;
            cout << v[inp-1] << endl;
        }

        if(str == "size"){ 
            cout << v.size() << endl ;
        }

        if(str == "pop_back"){
            v.pop_back();
        }
    }
    return 0;
}